
#include "../../MCAL/GPIO/GPIO.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#define _XTAL_FREQ 8000000L 
void LCD_Init(void)
{
	/* SET Direction for LCD control  pins --> OUTPUT */
	/* Rs-->1 For Read  */
	/* SET Direction for LCD control  pins --> OUTPUT */
	GPIO_SetPinDirection(LCD_ControlPins_PortNum , RS_PinNum , GPIO_OUTPUT );
	GPIO_SetPinDirection(LCD_ControlPins_PortNum , RW_PinNum , GPIO_OUTPUT );
	GPIO_SetPinDirection(LCD_ControlPins_PortNum , EN_PinNum , GPIO_OUTPUT );

	#if LCD_MODE == LCD_8Bit 
		/* SET Direction for LCD Data  pins --> OUTPUT */
		GPIO_SetPortDirection(LCD_DATA_PortNum , OUTPUT_PORT);

		__delay_ms(50);
		/* Function Set */
		LCD_SendCommand(LCD_FUNCTION_SET_8_BIT);
		__delay_ms(1);
		/*   Display ON/OFF Control */
		LCD_SendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
		__delay_ms(1);
		/*  Clear Screen */
		LCD_SendCommand(LCD_CLEAR_SCREEN);
		__delay_ms(5);
		/* Entry mode set */
		LCD_SendCommand(LCD_ENTRY_MODE_INC_SHIFT_OFF);
		__delay_ms(1);

	#elif LCD_MODE == LCD_4Bit

		
		/* SET Direction for LCD Data  pins --> OUTPUT */
		#if   LCD_4_BIT_DATA_PIN ==  LCD_HIGH_NIBBLE
			GPIO_SetHighNibbleDirection(LCD_DATA_PortNum , OUTPUT_PORT);
		#elif LCD_4_BIT_DATA_PIN ==  LCD_LOW_NIBBLE
			GPIO_SetLowNibbleDirection(LCD_DATA_PortNum , OUTPUT_PORT);
		#endif

		LCD_SendCommand(LCD_RETURN_HOME);
		__delay_ms(50);
		/* Function Set */
		LCD_SendCommand(LCD_FUNCTION_SET_4_BIT);
		__delay_ms(1);
		/*   Display ON/OFF Control */
		LCD_SendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
		__delay_ms(1);
		/*  Clear Screen */
		LCD_SendCommand(LCD_CLEAR_SCREEN);
		__delay_ms(5);
		/* Entry mode set */
		LCD_SendCommand(LCD_ENTRY_MODE_INC_SHIFT_OFF);
		__delay_ms(5);

	#endif

}


static void LCD_SendData( uint8_t Data)
{
	
	/* Set RS to 1 and RW to 0  */
	GPIO_SetPinValue(LCD_ControlPins_PortNum , RS_PinNum, GPIO_HIGH );
	GPIO_SetPinValue(LCD_ControlPins_PortNum , RW_PinNum, GPIO_LOW );

	#if LCD_MODE == LCD_8Bit
		/* Send Data to the LCD Port */
		GPIO_SetPortValue(LCD_DATA_PortNum , Data);
		LCD_SendFallingEndgPulse();

	#elif LCD_MODE == LCD_4Bit	
		#if LCD_4_BIT_DATA_PIN == LCD_HIGH_NIBBLE
			GPIO_SetHighNibbleValue(LCD_DATA_PortNum , (Data>>4) );
			LCD_SendFallingEndgPulse();
			GPIO_SetHighNibbleValue(LCD_DATA_PortNum , Data);
			LCD_SendFallingEndgPulse();
		#elif LCD_4_BIT_DATA_PIN == LCD_LOW_NIBBLE
			GPIO_SetLowNibbleValue(LCD_DATA_PortNum , (Data>>4) );
			LCD_SendFallingEndgPulse();
			GPIO_SetLowNibbleValue(LCD_DATA_PortNum , Data);
			LCD_SendFallingEndgPulse();
		#endif

	#endif
}
static void LCD_SendCommand(uint8_t Command)
{
	/* Set RS to 0 and RW to 0  */
	GPIO_SetPinValue(LCD_ControlPins_PortNum , RS_PinNum , GPIO_LOW );
	GPIO_SetPinValue(LCD_ControlPins_PortNum , RW_PinNum , GPIO_LOW );

	#if LCD_MODE == LCD_8Bit
		/* Send Command to the LCD Port */
		GPIO_SetPortValue(LCD_DATA_PortNum , Command);
		LCD_SendFallingEndgPulse();

	#elif LCD_MODE == LCD_4Bit	
		#if LCD_4_BIT_DATA_PIN == LCD_HIGH_NIBBLE
			GPIO_SetHighNibbleValue(LCD_DATA_PortNum , (Command>>4));
			LCD_SendFallingEndgPulse();
			GPIO_SetHighNibbleValue(LCD_DATA_PortNum , Command);
			LCD_SendFallingEndgPulse();
		#elif LCD_4_BIT_DATA_PIN == LCD_LOW_NIBBLE
			GPIO_SetLowNibbleValue(LCD_DATA_PortNum , (Command>>4) );
			LCD_SendFallingEndgPulse();
			GPIO_SetLowNibbleValue(LCD_DATA_PortNum , Command);
			LCD_SendFallingEndgPulse();
		#endif

	#endif
	
}
static void LCD_SendFallingEndgPulse(void)
{
	GPIO_SetPinValue(LCD_ControlPins_PortNum , EN_PinNum, GPIO_HIGH );
	__delay_ms(1);
	GPIO_SetPinValue(LCD_ControlPins_PortNum , EN_PinNum, GPIO_LOW );
	__delay_ms(1);
	
}
void LCD_ClearScreen(void)
{
	LCD_SendCommand(LCD_CLEAR_SCREEN);
	__delay_ms(1);
}
void LCD_SendtChar(uint8_t Ch)
{
	LCD_SendData(Ch);
}
void LCD_SendString(uint8_t *str)
{
	uint8_t Iterator =  0 ; 
	while(str[Iterator]!= '\0')
	{
		LCD_SendData(str[Iterator++]);
	}
} 

void LCD_SetPosition(uint8_t Row_Num ,uint8_t Column_Num)
{
	uint8_t LocCommand ;
	/* if the user enter invaild     location AC will point to the First place in DDRAM (0 , 0 )  */
	if( Row_Num>LCD_ROW_2 || Row_Num < LCD_ROW_1 || Column_Num > LCD_COL_16 || Column_Num < LCD_COL_1 )
	{
		LocCommand =  LCD_DDRAM_START ;
	}
	else if(Row_Num == LCD_ROW_1 )
	{
		LocCommand = LCD_DDRAM_START + Column_Num -1 ;
	}
	else if(Row_Num == LCD_ROW_2 )
	{
		LocCommand = LCD_DDRAM_START + 64 +  Column_Num -1 ;
	}
	LCD_SendCommand(LocCommand);
	__delay_ms(1);
}
void LCD_SendNumber(sint16_t Num)
{ 
	sint16_t Loc_Temp = Num ; 
	uint8_t Iterator = 0 ;
	uint8_t Iterator_2 = 0 ;
	uint8_t Negative_Flag = 0 ;
	char Num_Arr[5] = {};
	/* Store Number in Num_Arr as a string 
		but the number will be stored in reverse order in the array so we need to reverse this array again 
	 */
	if(Num==0)
	{
		LCD_SendtChar('0');
		return;
	}
	if(Num<0)
	{
		Num = Num * (-1) ;  
		Negative_Flag = 1 ; 
	}
	while(Num != 0 )
	{
		Loc_Temp = Num % 10 ; 
		Num_Arr[Iterator++] = ( Loc_Temp + '0' ) ;
		Num = Num / 10 ;
	}
	/* Revers Num_arr */
	for(Iterator_2 = 0 ; Iterator_2 < Iterator/2 ; Iterator_2++)
	{
		char temp = Num_Arr[Iterator_2];
		Num_Arr[Iterator_2 ] = Num_Arr[Iterator-Iterator_2-1];
		Num_Arr[Iterator-Iterator_2-1] = temp;
	}

	for(Iterator_2 = 0 ; Iterator_2 < Iterator ; Iterator_2++ )
	{
		if(Negative_Flag)
		{
			LCD_SendtChar('-');
			Negative_Flag = 0 ; 
		}
		LCD_SendtChar(Num_Arr[Iterator_2]);
	}
}


void LCD_SendCustomChar(uint8_t pChar_Arr[] , uint8_t Row_Num , uint8_t Col_Num){
	uint8_t Iterator ;
	/* 1- Make AC point to CGRAM */

	LCD_SendCommand(LCD_CGRAM_START  );
	/* 2- Copy Character To CGRAM and it Automatically will be cobied ib the DDRAM */
	for(Iterator = 0 ; Iterator<8 ; Iterator++){
		LCD_SendData(pChar_Arr[Iterator]);
	}
	/* 2- Back To DDRAM */
	LCD_SendCommand(LCD_DDRAM_START);
	/* Now Display The Character From DDRAM */
	LCD_SetPosition(Row_Num , Col_Num);
	for(Iterator = 0 ; Iterator<8 ; Iterator++){
			LCD_SendData(Iterator);
	}
}


void LCD_EnableCursor(void)
{
	LCD_SendCommand(LCD_DISPLAY_ON_CURSOR_ON);
}
void LCD_DisableCursor(void)
{
	LCD_SendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	
}



void LCD_ShiftRight(void)
{
	LCD_SendCommand(LCD_SHIFT_RIGHT);
	
}
void LCD_ShiftLeft(void)
{
	LCD_SendCommand(LCD_SHIFT_LEFT);
}	


void LCD_Display_On(void)
{
	LCD_SendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
}
void LCD_Display_Off(void)
{
	LCD_SendCommand(LCD_DISPLAY_OFF_CURSOR_OFF);
}



void LCD_Blink_On(void)
{
	LCD_SendCommand(LCD_BLINK_ON);
}

void LCD_Blink_Off(void)
{
	LCD_SendCommand(LCD_BLINK_OFF);
}

void LCD_Cursor_Decrement()
{
	LCD_SendCommand(LCD_ENTRY_MODE_DEC_SHIFT_OFF);
}

void LCD_Cursor_Increment()
{
	LCD_SendCommand(LCD_ENTRY_MODE_INC_SHIFT_OFF);
}

