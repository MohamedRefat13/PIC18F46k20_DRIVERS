/*
 * SWITCH_Program.c
 *
 *  Created on: Mar 1, 2023
 *      Author: Mohamed Refat
 */

#include"../../MCAL/GPIO/GPIO.h"
#include"SWITCH_Interface.h"
#define _XTAL_FREQ 8000000L 

Std_ReturnType SWITCH_Init(SWITCH_t *Switch_Config )
{
    Std_ReturnType return_ErrorState = E_OK ;   
    return_ErrorState  = GPIO_SetPinDirection(Switch_Config->SW_PortNum , Switch_Config->SW_PinNum , GPIO_INPUT );
    return return_ErrorState;
}

Std_ReturnType SWITCH_GetPressed(SWITCH_t *Switch_Config , SWITCH_STATE_t *pPressedValue)
{
    Std_ReturnType return_ErrorState = E_OK ; 
    
    uint8_t loc_PinVal = GPIO_HIGH;
    return_ErrorState  = GPIO_GetPinValue(Switch_Config->SW_PortNum , Switch_Config->SW_PinNum , &loc_PinVal);

    if(Switch_Config->SW_State == SW_PULL_UP)
    {
        if(loc_PinVal == GPIO_HIGH)
        {
            *pPressedValue = SW_NOT_PRESSED ; 

        }else if (loc_PinVal == GPIO_LOW)
        {
            __delay_ms(30);
        	return_ErrorState  = GPIO_GetPinValue(Switch_Config->SW_PortNum , Switch_Config->SW_PinNum , &loc_PinVal);
        	if (loc_PinVal == GPIO_LOW)
        	{
        		*pPressedValue = SW_PRESSED ;
        	}

        }
    }
    else if(Switch_Config->SW_State == SW_PULL_DOWN)
    {

        if(loc_PinVal == GPIO_HIGH)
        {
            *pPressedValue = SW_PRESSED ; 

        }else if (loc_PinVal == GPIO_LOW)
        {
            *pPressedValue = SW_NOT_PRESSED ; 
        }
    }
    return return_ErrorState ; 
}


