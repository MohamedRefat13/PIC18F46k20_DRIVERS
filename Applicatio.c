

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
#include "ECU/DCMOTOR/DCMOTOR_Interface.h"
#include "Application.h"
#include <xc.h>
#define _XTAL_FREQ 8000000L 



Std_ReturnType Error_State = E_OK ; 
int main()
{
     DC_MOTOR_t Motor1 = { GPIO_PORTA , GPIO_PIN0 ,GPIO_PIN1 };
     Error_State = DC_MOTOR_INIT(&Motor1);
     while(1){
          Error_State = E_OK;
          Error_State = DC_MOTOR_ON_CW(&Motor1);
          __delay_ms(1000);
          Error_State = DC_MOTOR_OFF(&Motor1);
          __delay_ms(1000);
       
          Error_State = DC_MOTOR_ON_CCW(&Motor1);
          __delay_ms(1000);

     }
     return (EXIT_SUCCESS);
}