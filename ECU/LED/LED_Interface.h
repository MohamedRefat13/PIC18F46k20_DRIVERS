/* 
 * File:   LED_Interface.h
 * Author: Mohamed Refat 
 *
 * Created on July 8, 2023, 6:16 AM
 */

#ifndef LED_INTERFACE_H
#define	LED_INTERFACE_H

#define LED_ACTIVE_HIGH 1 
#define LED_ACTIVE_LOW 0

typedef struct 
{
    uint8_t  PortNumber;  
    uint8_t  PinNumber ; 
    uint8_t  Active_Status ; 
}LED_t;

/**
 * @brief                    :This function used to  initiate led and sets the configration of it
 * 
 * @param *pLedConfigration  :*pLedConfigration is a  pointer to struct from type Led_t
 * 
 * @note                     :You mast call this function before you start using the Led
 * 
 * @return Std_ReturnType   This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Std_ReturnType LED_Init      (LED_t *pLedConfigration);

/**
 * @brief                     :This function used turn  the led on
 * 
 * @param *pLedConfigration   :*pLedConfigration is a  pointer to struct from type Led_t
 * 
 * @return Std_ReturnType     This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 *      
 */

Std_ReturnType LED_ON        (LED_t *pLedConfigration);

/**
 * @brief                     :This function used turn  the led off
 * 
 * @param *pLedConfigration   :*pLedConfigration is a  pointer to struct from type Led_t
 * 
 * @return Std_ReturnType     :This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Std_ReturnType LED_OFF       (LED_t *pLedConfigration);


/**
 * @brief                     :This function used toggle the Led Statuss
 * 
 * @param *pLedConfigration   :*pLedConfigration is a  pointer to struct from type Led_t
 * 
 * @return Std_ReturnType     :This function returns E_OK if it success (Parameter is correct)
 *                              and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Std_ReturnType LED_Toggle    (LED_t *pLedConfigration);



#endif	/* LED_INTERFACE_H */

