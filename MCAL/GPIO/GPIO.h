/* 
 * File:   GPIO.h
 * Author: Mohamed Refat
 *
 * Created on May 4, 2023, 3:03 AM
 */

#ifndef GPIO_H
#define	GPIO_H

/* Section : Includes*/
#include "../proc/pic18f4620.h" 
#include "../MCAL_STDTYPES.h"
#include "../Device_Config.h"

/* Section : Macro Delcarations */
#define BIT_MASK  (uint8_t)0X01
#define PORT_MASK (uint8_t)0XFF

#define OUTPUT_PORT (uint8_t)0X00
#define INPUT_PORT  (uint8_t)0XFF

#define HIGH_PORT   (uint8_t)0XFF
#define LOW_PORT    (uint8_t)0X00


/* Section : Macro Functions Delcarations */

#define HWREG8(_x) ( *( (volatile uint8_t *)(_x) ) ) 


#define SET_BIT(REG , BIT_NUM)     REG |=  (BIT_MASK<<BIT_NUM)
#define CLR_BIT(REG , BIT_NUM)     REG &= ~(BIT_MASK<<BIT_NUM)
#define TOGGLE_BIT(REG , BIT_NUM)  REG ^=  (BIT_MASK<<BIT_NUM)
#define GET_BIT(REG , BIT_NUM)        ( (REG>>BIT_NUM) & BIT_MASK )

/* Section : Data types Delcarations */
typedef enum
{
    GPIO_PORTA=0,    
    GPIO_PORTB ,
    GPIO_PORTC ,
    GPIO_PORTD ,  
    GPIO_PORTE

} GPIO_PORT_NUM;

typedef enum
{
    GPIO_PIN0=0,    
    GPIO_PIN1 ,
    GPIO_PIN2 ,  
    GPIO_PIN3 ,
    GPIO_PIN4 ,
    GPIO_PIN5 ,  
    GPIO_PIN6 ,
    GPIO_PIN7

} GPIO_PIN_NUM;

typedef enum
{
    GPIO_OUTPUT,
    GPIO_INPUT

} PIN_DIRRECTION;

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH

}LogicState;



/* Section : Functions Delcarations */

Std_ReturnType GPIO_SetPinDirection(GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t Direction   );
Std_ReturnType GPIO_GetPinDirection(GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t *pDirection );
Std_ReturnType GPIO_SetPinValue    (GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t Copy_Logic  );
Std_ReturnType GPIO_GetPinValue    (GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber , uint8_t *pLogic     );
Std_ReturnType GPIO_TogglePinValue (GPIO_PORT_NUM PortNumber , GPIO_PIN_NUM PinNumber);
//Std_ReturnType GPIO_PinInitialize  (const Pin_Config_t *pConfig                       );


Std_ReturnType GPIO_SetPortDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Copy_Direction );
Std_ReturnType GPIO_GetPortDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t *pDirection    );
Std_ReturnType GPIO_SetPortValue    (const GPIO_PORT_NUM Copy_PortNum , uint8_t Copy_Logic     );
Std_ReturnType GPIO_GetPortValue    (const GPIO_PORT_NUM Copy_PortNum , uint8_t *pLogic        );
Std_ReturnType GPIO_TogglePortValue (const GPIO_PORT_NUM Copy_PortNum                          );



Std_ReturnType GPIO_SetLowNibbleValue(const GPIO_PORT_NUM Copy_PortNum , uint8_t Value);
Std_ReturnType GPIO_SetHighNibbleValue(const GPIO_PORT_NUM Copy_PortNum , uint8_t Value);
Std_ReturnType GPIO_SetLowNibbleDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Direction);
Std_ReturnType GPIO_SetHighNibbleDirection(const GPIO_PORT_NUM Copy_PortNum , uint8_t Direction);


#endif	/* GPIO_H */
 
