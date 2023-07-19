/* 
 * File:   GPIO.c
 * Author: Mohamed Refat
 *
 * Created on May 4, 2023, 2:02 AM
 */

#include "GPIO.h"

volatile uint8_t *TRIS_Registers[] = {&TRISA , &TRISB , &TRISC , &TRISD , &TRISE};
volatile uint8_t *LAT_Registers[] = {&LATA , &LATB , &LATC , &LATD , &LATE};
volatile uint8_t *PORT_Registers[] = {&PORTA , &PORTB , &PORTC , &PORTD , &PORTE};


Std_ReturnType GPIO_SetPinDirection(GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t Direction   )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if( PinNumber> GPIO_PIN7 || PortNumber > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        if(Direction == GPIO_OUTPUT){
            CLR_BIT(*TRIS_Registers[PortNumber] , PinNumber);
        }else if(Direction== GPIO_INPUT){
            SET_BIT(*TRIS_Registers[PortNumber] , PinNumber);
        }else{
            Return_ErrorState = E_NOT_OK ;
        }
    }
    return Return_ErrorState ; 
}

Std_ReturnType GPIO_GetPinDirection(GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t *pDirection )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if( PinNumber> GPIO_PIN7 || PortNumber > GPIO_PORTE  ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        *pDirection = GET_BIT(*TRIS_Registers[PortNumber] , PinNumber);
    }
    return Return_ErrorState ; 
}


Std_ReturnType GPIO_SetPinValue(GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t Copy_Logic  )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if( PinNumber> GPIO_PIN7 || PortNumber > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        if(Copy_Logic == GPIO_LOW){
            CLR_BIT(*LAT_Registers[PortNumber] , PinNumber);
        }else if(Copy_Logic == GPIO_HIGH){
            SET_BIT(*LAT_Registers[PortNumber] , PinNumber);
        }else{
            Return_ErrorState = E_NOT_OK ;
        }
    }
    return Return_ErrorState ; 
}

Std_ReturnType GPIO_GetPinValue (GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t *pLogic     )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if( PinNumber> GPIO_PIN7 || PortNumber > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        *pLogic = GET_BIT(*PORT_Registers[PortNumber] , PinNumber);
    }
    return Return_ErrorState ;    
}   

Std_ReturnType GPIO_TogglePinValue(GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber)
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if( PinNumber> GPIO_PIN7 || PinNumber > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        TOGGLE_BIT(*LAT_Registers[PortNumber] , PinNumber);
    }
    return Return_ErrorState ;     
}

/* Std_ReturnType GPIO_PinInitialize(const Pin_Config_t *pConfig )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if( PinNumber> GPIO_PIN7 || PinNumber > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        Return_ErrorState = GPIO_SetPinDirection(pConfig );
        Return_ErrorState = GPIO_SetPinValue(pConfig , PinLogic);
    }
    return Return_ErrorState ;  
}
 */

Std_ReturnType GPIO_SetPortDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Copy_Direction )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(Copy_PortNum>GPIO_PORTE  ){
        Return_ErrorState = E_NOT_OK ;
    }else{
        *TRIS_Registers[Copy_PortNum] = Copy_Direction ; 
    }
    return Return_ErrorState ; 
}

Std_ReturnType GPIO_GetPortDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t *pDirection )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(Copy_PortNum>GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }else{
        *pDirection = *TRIS_Registers[Copy_PortNum]  ; 
    }
    return Return_ErrorState ; 
}

Std_ReturnType GPIO_SetPortValue(const GPIO_PORT_NUM Copy_PortNum , uint8_t Copy_Logic )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(Copy_PortNum > GPIO_PORTE){
        Return_ErrorState = E_NOT_OK ;
    }else{
        *LAT_Registers[Copy_PortNum] = Copy_Logic ; 
    }
    return Return_ErrorState ; 
}
Std_ReturnType GPIO_GetPortValue (const GPIO_PORT_NUM Copy_PortNum , uint8_t *pLogic )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(Copy_PortNum > GPIO_PORTE  ){
        Return_ErrorState = E_NOT_OK ;
    }else{
        *pLogic = *PORT_Registers[Copy_PortNum] ; 
    }
    return Return_ErrorState ; 
}
Std_ReturnType GPIO_TogglePortValue(const GPIO_PORT_NUM Copy_PortNum )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(Copy_PortNum > GPIO_PORTE  ){
        Return_ErrorState = E_NOT_OK ;
    }else{
        *LAT_Registers[Copy_PortNum]  ^= PORT_MASK; 
    }
    return Return_ErrorState ;
}










Std_ReturnType GPIO_SetLowNibbleValue(const GPIO_PORT_NUM Copy_PortNum , uint8_t Value)
{
	Std_ReturnType LocReturnError = E_OK ;
    if(Copy_PortNum >= GPIO_PORTA && Copy_PortNum<=GPIO_PORTD){
        /* This line to make sure that the high nibble in port value will not change */
	    Value &= 0X0F;
        (*LAT_Registers[Copy_PortNum] ) &= 0XF0 ;
        (*LAT_Registers[Copy_PortNum] ) |= Value ;
    }else{
        LocReturnError = E_NOT_OK ;  
    }
	return LocReturnError ;
}

Std_ReturnType GPIO_SetHighNibbleValue(const GPIO_PORT_NUM Copy_PortNum , uint8_t Value)
{
	Std_ReturnType LocReturnError = E_OK ;
    if(Copy_PortNum >= GPIO_PORTA && Copy_PortNum<=GPIO_PORTD){
        /* This line to make sure that the high nibble in port value will not change */
	    Value &= 0XF0;
        (*LAT_Registers[Copy_PortNum] ) &= 0X0F ;
        (*LAT_Registers[Copy_PortNum] ) |= Value ;
    }else{
        LocReturnError = E_NOT_OK ;  
    }
	return LocReturnError ;
}



Std_ReturnType GPIO_SetLowNibbleDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Direction)
{
	Std_ReturnType LocReturnError = E_OK ;
    if(Copy_PortNum >= GPIO_PORTA && Copy_PortNum<=GPIO_PORTD){
        /* This line to make sure that the high nibble in port value will not change */
	    Direction &= 0X0F;
        (*TRIS_Registers[Copy_PortNum] ) &= 0XF0 ;
        (*TRIS_Registers[Copy_PortNum] ) |= Direction ;
    }else{
        LocReturnError = E_NOT_OK ;  
    }
	return LocReturnError ;
}
Std_ReturnType GPIO_SetHighNibbleDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Direction)
{
	Std_ReturnType LocReturnError = E_OK ;
    if(Copy_PortNum >= GPIO_PORTA && Copy_PortNum<=GPIO_PORTD){
        /* This line to make sure that the high nibble in port value will not change */
	    Direction &= 0XF0;
        (*TRIS_Registers[Copy_PortNum] ) &= 0X0F ;
        (*TRIS_Registers[Copy_PortNum] ) |= Direction ; 
    }else{
        LocReturnError = E_NOT_OK ;  
    }
	return LocReturnError ;
}
