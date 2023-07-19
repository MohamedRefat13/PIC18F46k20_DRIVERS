

/* 
 * File:   Application.c
 * Author: Mohamed Refat
 *
 * Created on May 4, 2023, 2:02 AM
 */

#include "MCAL/GPIO/GPIO.h"
#include "ECU/LED/LED_Interface.h"
#include "ECU/SWITCH/SWITCH_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "ECU/KEYPAD/KEYPAD_Interface.h"
#include "ECU/DCMOTOR/DCMOTOR_Interface.h"
#include "ECU/RELAY/RELAY_Interface.h"
#include "ECU/SSD/SSD_Interface.h"
#define _XTAL_FREQ 8000000L 


void main()
{
    SSD_t s1 = {GPIO_PORTC , GPIO_PORTA , GPIO_PIN0 , SSD_CC};
    SSD_Init(&s1);

    while(1){
        for(uint8_t i=0 ; i<10 ; i++){
            SSD_WriteNum(&s1, i);
            __delay_ms(200);     
        }
    } 
  
}