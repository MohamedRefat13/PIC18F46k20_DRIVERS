   
#include "../../MCAL/GPIO/GPIO.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Config.h"

#define _XTAL_FREQ 8000000L 


void KEYPAD_Init(void)
{
	/*Define KeyPad Rows Pin as Input and Remeber to connect them with GND*/
	/* PIN-->0 (INPUT) */
	uint8_t Row_Iterator;
   	uint8_t Col_Iterator;
	uint8_t Row_Pins[]={KEYPAD_R1_PIN , KEYPAD_R2_PIN , KEYPAD_R3_PIN , KEYPAD_R4_PIN};	
	uint8_t Col_Pins[]={KEYPAD_C1_PIN , KEYPAD_C2_PIN , KEYPAD_C3_PIN , KEYPAD_C4_PIN};	
   	for(Row_Iterator = KEYPAD_R1 ; Row_Iterator <= KEYPAD_R4 ; Row_Iterator++){
	    GPIO_SetPinDirection(KEYPAD_Port , Row_Pins[Row_Iterator] , GPIO_INPUT);
   	}
	

	/*Define KeyPad Column Pin as OUTPUT Pins And Set there value to Low*/
    for(Col_Iterator = KEYPAD_C1 ; Col_Iterator <= KEYPAD_C4 ; Col_Iterator++){
	   	GPIO_SetPinDirection(KEYPAD_Port , Col_Pins[Col_Iterator] , GPIO_OUTPUT);
		GPIO_SetPinValue(KEYPAD_Port , Col_Pins[Col_Iterator] , GPIO_LOW);
   	}
	
	
	
}
uint8_t KEYPAD_GetPressedKey(void)
{
	uint8_t LocReturnKey  = KEYPAD_NOTPRESSED ;
	uint8_t LocPressedVal ;
	uint8_t Col_Iterator ; 
	uint8_t Row_Iterator;

	uint8_t Row_Pins[4]={KEYPAD_R1_PIN , KEYPAD_R2_PIN , KEYPAD_R3_PIN , KEYPAD_R4_PIN};	
	uint8_t Col_Pins[4]={KEYPAD_C1_PIN , KEYPAD_C2_PIN , KEYPAD_C3_PIN , KEYPAD_C4_PIN};	

	for(Col_Iterator = KEYPAD_C1 ; Col_Iterator<= KEYPAD_C4 ; Col_Iterator++ ){

		GPIO_SetPinValue(KEYPAD_Port , Col_Pins[Col_Iterator] ,  GPIO_HIGH );

		for(Row_Iterator=KEYPAD_R1 ; Row_Iterator<=KEYPAD_R4 ; Row_Iterator++ ){

			GPIO_GetPinValue(KEYPAD_Port , Row_Pins[Row_Iterator] , &LocPressedVal);
			if(LocPressedVal == GPIO_HIGH ){

				__delay_ms(50); // Sovle Depouncing issue by sw
				if(LocPressedVal==GPIO_HIGH){
					LocReturnKey = KEYPAD_Bottons[Row_Iterator][Col_Iterator];
				}
			 	/* IF the key still pressed this function will return the same data again
					so we need to make a delay 200 ms or insted of this we do as the following --> 
				 */
				GPIO_GetPinValue(KEYPAD_Port , Row_Pins[Row_Iterator] , &LocPressedVal);
				while(LocPressedVal == GPIO_HIGH){//Button still pressed
					GPIO_GetPinValue(KEYPAD_Port , Row_Pins[Row_Iterator] , &LocPressedVal);
				}
				return LocReturnKey ;
			}
		}
		GPIO_SetPinValue(KEYPAD_Port , Col_Pins[Col_Iterator] ,  GPIO_LOW );
	}

	return LocReturnKey ;
}

