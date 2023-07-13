

/* 
 * File:   Application.c
 * Author: Mohamed Refat
 *
 * Created on May 4, 2023, 2:02 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include "MCAL/GPIO/GPIO.h"
#include "ECU/LED/LED_Interface.h"
#include "ECU/RELAY/RELAY_Interface.h"
#include "Application.h"
#include <xc.h>
#define _XTAL_FREQ 8000000L 



int main()
{
    Relay_t Relay_1 = { GPIO_PORTD , GPIO_PIN0 , RELAY_OFF};
    Relay_t Relay_2 = { GPIO_PORTD , GPIO_PIN1 , RELAY_OFF};
    RELAY_Init(&Relay_1);
    RELAY_Init(&Relay_2);
   while(1){
        RELAY_TurnOn(&Relay_1);
        RELAY_TurnOff(&Relay_2);
        __delay_ms(1000);
        RELAY_TurnOff(&Relay_1);
        RELAY_TurnOn(&Relay_2);
        __delay_ms(1000);
       
   }
   return (EXIT_SUCCESS);
}