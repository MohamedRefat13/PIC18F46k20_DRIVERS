/* 
 * File:   LCD_Private.h
 * Author: Mohamed Refat 
 *
 * Created on July 18, 2023, 3:31 PM
 */

#ifndef LCD_PRIVATE_H
#define	LCD_PRIVATE_H

/* LCD Commands Macros */

#define LCD_CLEAR_SCREEN               0X01
#define LCD_RETURN_HOME                0x02

#define LCD_FUNCTION_SET_8_BIT         0x38
#define LCD_FUNCTION_SET_4_BIT         0x28

#define LCD_DISPLAY_ON_CURSOR_ON       0x0E
#define LCD_DISPLAY_ON_CURSOR_OFF      0x0C
#define LCD_DISPLAY_OFF_CURSOR_OFF     0x09 

#define LCD_BLINK_ON                   0x0F
#define LCD_BLINK_OFF                  0x0E

#define LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define LCD_ENTRY_MODE_INC_SHIFT_ON    0x07


#define LCD_SHIFT_LEFT                 0x18
#define LCD_SHIFT_RIGHT                0x1C

#define LCD_CGRAM_START                0x40
#define LCD_DDRAM_START                0x80

#define LCD_8Bit        8
#define LCD_4Bit        4

#define LCD_HIGH_NIBBLE 0xF
#define LCD_LOW_NIBBLE  0x0

static void LCD_SendFallingEndgPulse(void);
static void LCD_SendData(uint8_t Data);
static void LCD_SendCommand(uint8_t Command);

#endif	/* LCD_PRIVATE_H */

