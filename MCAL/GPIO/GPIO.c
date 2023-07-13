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

Std_ReturnType GPIO_SetPinDirection(const Pin_Config_t *pConfig  )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(NULL_ptr == pConfig || pConfig->PinNum> GPIO_PIN7 || pConfig->PortNum > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        if(pConfig->PinDirection == GPIO_OUTPUT){
            CLR_BIT(*TRIS_Registers[pConfig->PortNum] , pConfig->PinNum);
        }else if(pConfig->PinDirection == GPIO_INPUT){
            SET_BIT(*TRIS_Registers[pConfig->PortNum] , pConfig->PinNum);
        }else{
            Return_ErrorState = E_NOT_OK ;
        }
    }
    return Return_ErrorState ; 
}

Std_ReturnType GPIO_GetPinDirection(const Pin_Config_t *pConfig , uint8_t *pDirection )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(NULL_ptr == pConfig || pConfig->PinNum> GPIO_PIN7 || pConfig->PortNum > GPIO_PORTE  ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        *pDirection = GET_BIT(*TRIS_Registers[pConfig->PortNum] , pConfig->PinNum);
    }
    return Return_ErrorState ; 
}


Std_ReturnType GPIO_SetPinValue(const Pin_Config_t *pConfig , uint8_t Copy_Logic)
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(NULL_ptr == pConfig || pConfig->PinNum> GPIO_PIN7 || pConfig->PortNum > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        if(Copy_Logic == GPIO_LOW){
            CLR_BIT(*LAT_Registers[pConfig->PortNum] , pConfig->PinNum);
        }else if(Copy_Logic == GPIO_HIGH){
            SET_BIT(*LAT_Registers[pConfig->PortNum] , pConfig->PinNum);
        }else{
            Return_ErrorState = E_NOT_OK ;
        }
    }
    return Return_ErrorState ; 
}

Std_ReturnType GPIO_GetPinValue(const Pin_Config_t *pConfig , uint8_t *pLogic )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(NULL_ptr == pConfig || pConfig->PinNum> GPIO_PIN7 || pConfig->PortNum > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        *pLogic = GET_BIT(*PORT_Registers[pConfig->PortNum] , pConfig->PinNum);
    }
    return Return_ErrorState ;    
}

Std_ReturnType GPIO_TogglePinValue (const Pin_Config_t *pConfig )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(NULL_ptr == pConfig || pConfig->PinNum> GPIO_PIN7 || pConfig->PortNum > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        TOGGLE_BIT(*LAT_Registers[pConfig->PortNum] , pConfig->PinNum);
    }
    return Return_ErrorState ;     
}

Std_ReturnType GPIO_PinInitialize(const Pin_Config_t *pConfig )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(NULL_ptr == pConfig || pConfig->PinNum> GPIO_PIN7 || pConfig->PortNum > GPIO_PORTE ){
        Return_ErrorState = E_NOT_OK ;
    }
    else{
        Return_ErrorState = GPIO_SetPinDirection(pConfig );
        Return_ErrorState = GPIO_SetPinValue(pConfig , pConfig->PinLogic);
    }
    return Return_ErrorState ;  
}


Std_ReturnType GPIO_SetPortDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Copy_Direction )
{
    Std_ReturnType Return_ErrorState = E_OK ; 
    if(Copy_PortNum>GPIO_PORTE || Copy_Direction != OUTPUT_PORT || Copy_Direction != INPUT_PORT ){
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
    if(Copy_PortNum > GPIO_PORTE || Copy_Logic != HIGH_PORT || Copy_Logic != LOW_PORT ){
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


