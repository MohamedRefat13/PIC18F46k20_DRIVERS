/*
 * SSD_Program->c
 *
 *  Created on: Feb 15, 2023
 *      Author: Mohamed Refat
 */
#include "../..//MCAL/GPIO/GPIO.h"
#include"SSD_Private.h"
#include"SSD_Interface.h"

uint8_t SSD_u8Numbers[] = SSD_NUM ;
void SSD_Init(SSD_t *SSD_Config )
{
    GPIO_SetPortDirection ( SSD_Config->PortNum , GPIO_OUTPUT );
    GPIO_SetPinDirection(SSD_Config->CommonPin_PortNum , SSD_Config->CommonPin_Num , GPIO_OUTPUT);
  
}

void SSD_Enable(SSD_t *SSD_Config )
{

    if( SSD_Config->SSD_Mode == SSD_CC )
    {
        GPIO_SetPinValue(SSD_Config->CommonPin_PortNum , SSD_Config->CommonPin_Num , GPIO_LOW);
    }else if( SSD_Config->SSD_Mode == SSD_CA )
    {
        GPIO_SetPinValue(SSD_Config->CommonPin_PortNum , SSD_Config->CommonPin_Num , GPIO_HIGH);
    }  
}
void SSD_Disable(SSD_t *SSD_Config )
{
    if( SSD_Config->SSD_Mode == SSD_CC )
    {
        GPIO_SetPinValue(SSD_Config->CommonPin_PortNum , SSD_Config->CommonPin_Num , GPIO_HIGH);
    }else if( SSD_Config->SSD_Mode == SSD_CA )
    {
        GPIO_SetPinValue(SSD_Config->CommonPin_PortNum , SSD_Config->CommonPin_Num , GPIO_HIGH);
    }  
}

void SSD_WriteNum(SSD_t *SSD_config , uint8_t Number)
{
    if( SSD_config->SSD_Mode == SSD_CC )
    {
        GPIO_SetPortValue(SSD_config->PortNum , SSD_u8Numbers[Number] );
    }else if( SSD_config->SSD_Mode == SSD_CA )
    {
        GPIO_SetPortValue(SSD_config->PortNum , ~SSD_u8Numbers[Number] );
    }    
}

void SSD_WriteShape(SSD_t *SSD_config , uint8_t ShapeVal )
{
	 GPIO_SetPortValue(SSD_config->PortNum , ShapeVal );
}

