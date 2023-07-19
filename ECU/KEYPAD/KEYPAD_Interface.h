/* 
 * File:   KEYPAD_Interface.h
 * Author: Mohamed Refat 
 *
 * Created on July 17, 2023, 6:15 PM
 */

#ifndef KEYPAD_INTERFACE_H
#define	KEYPAD_INTERFACE_H

#define KEYPAD_NOTPRESSED 0XFF

#define KEYPAD_R1   0
#define KEYPAD_R2   1
#define KEYPAD_R3   2
#define KEYPAD_R4   3

#define KEYPAD_C1  0
#define KEYPAD_C2  1
#define KEYPAD_C3  2
#define KEYPAD_C4  3


void KEYPAD_Init(void);
uint8_t KEYPAD_GetPressedKey(void);


#endif	/* KEYPAD_INTERFACE_H */
