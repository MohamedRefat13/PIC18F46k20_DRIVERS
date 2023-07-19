/* 
 * File:   KEYPAD_Config.h
 * Author: Mohamed Refat 
 *
 * Created on July 17, 2023, 6:20 PM
 */

#ifndef KEYPAD_CONFIG_H
#define	KEYPAD_CONFIG_H

/* Options:
 * 			GPIO_PORTA
 * 			GPIO_PORTB
 * 			GPIO_PORTC
 * 			GPIO_PORTD
 * */

#define KEYPAD_Port GPIO_PORTD

#define KEYPAD_R1_PIN GPIO_PIN0
#define KEYPAD_R2_PIN GPIO_PIN1
#define KEYPAD_R3_PIN GPIO_PIN2
#define KEYPAD_R4_PIN GPIO_PIN3

#define KEYPAD_C1_PIN GPIO_PIN4
#define KEYPAD_C2_PIN GPIO_PIN5
#define KEYPAD_C3_PIN GPIO_PIN6
#define KEYPAD_C4_PIN GPIO_PIN7

uint8_t KEYPAD_Bottons[4][4] = 
{
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'C','0','=','+'}
		
};

#endif	/* KEYPAD_CONFIG_H */

