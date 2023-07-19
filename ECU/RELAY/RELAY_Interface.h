/* 
 * File:   RELAY_Interface.h
 * Author: Mohamed Refat 
 *
 * Created on July 11, 2023, 8:26 PM
 */

#ifndef RELAY_INTERFACE_H
#define	RELAY_INTERFACE_H


#define RELAY_ON  GPIO_HIGH 
#define RELAY_OFF GPIO_LOW


/**
 * @brief  : RELAY_t is a data type to define basic configration of the relay
 *         : RLY_PortNum [GPIO_PORTA ---> GPIO_PORTE]
 *         : RLY_PinNum  [GPIO_PIN0  ---> GPIO_PIN7 ]
 *         : RLY_State   [RELAY_ON   ---- RELAY_OFF ]
 */
typedef struct 
{
    uint8_t RLY_PortNum ; 
    uint8_t RLY_PinNum  ;  
    uint8_t RLY_State  ; 
}RELAY_t;

/**
 * @brief                   : This function used to initialize relay 
 * 
 * @param pRelay_Config     : pointer to the relay configration which is a struct from type @RELAY_t 
 * @return Std_ReturnType   : This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Std_ReturnType RELAY_Init(RELAY_t * pRelay_Config);


/**
 * @brief                   : This function used to Turn On The Relay 
 *                                 --> ( Connenct the Common pin to Normally Open (NO) pin )
 * 
 * @param pRelay_Config     : pointer to the relay configration which is a struct from type @RELAY_t 
 * @return Std_ReturnType   : This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Std_ReturnType RELAY_TurnOn(RELAY_t * pRelay_Config);


/**
 * @brief                   : This function used to Turn On The Relay 
 *                                 --> ( Connenct the Common pin to Normally Close (NO) pin )
 * 
 * @param pRelay_Config     : pointer to the relay configration which is a struct from type @RELAY_t 
 * @return Std_ReturnType   : This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Std_ReturnType RELAY_TurnOff(RELAY_t * pRelay_Config);
#endif	/* RELAY_INTERFACE_H */

