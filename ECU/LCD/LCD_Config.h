/* 
 * File:   LCD_Config.h
 * Author: Mohamed Refat 
 *
 * Created on July 18, 2023, 3:32 PM
 */

#ifndef LCD_CONFIG_H
#define	LCD_CONFIG_H

/**
 * Chose Mode [4bit or 8bit]
 * 
 * options:
 *          LCD_8Bit
 *          LCD_4Bit
 */
#define LCD_MODE  LCD_8Bit
/**
 * Chose Nibble [High , Low]
 * options : LCD_HIGH_NIBBLE
 *           LCD_LOW_NIBBLE
 * Not Valid in 8 bit Mode
 */
/* TO DO :
    Debug High Nibble it doent work
*/
#define LCD_4_BIT_DATA_PIN  LCD_LOW_NIBBLE

/*
    Chose Port Number for Control Pins:-
    CLCD_ControlPins_PortNum ::  GPIO_PORTA
                            GPIO_PORTB
                            GPIO_PORTC
                            GPIO_PORTD
 */
#define LCD_ControlPins_PortNum GPIO_PORTA
/* Control Pins From GPIO_PIN0 --> GPIO_PIN7 */
#define RS_PinNum GPIO_PIN0
#define RW_PinNum GPIO_PIN1
#define EN_PinNum GPIO_PIN2

/*
    Chose Port Number for Data Pins:-
    CLCD_DATA_PortNum ::  GPIO_PORTA
                            GPIO_PORTB
                            GPIO_PORTC
                            GPIO_PORTD
 */
#define LCD_DATA_PortNum GPIO_PORTC


#endif	/* LCD_CONFIG_H */

