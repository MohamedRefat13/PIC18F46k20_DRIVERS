#include "../../MCAL/GPIO/GPIO.h"
#include "RELAY_Interface.h"

Std_ReturnType RELAY_Init(RELAY_t * pRelay_Config)
{
    Std_ReturnType Ret_ErrorState = E_OK ; 
    if(pRelay_Config != NULL_ptr){
        Ret_ErrorState = GPIO_SetPinDirection(pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , GPIO_OUTPUT);
        Ret_ErrorState = GPIO_SetPinValue(pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , pRelay_Config->RLY_State);

    }else{
        Ret_ErrorState = E_NOT_OK ; 
    }
    return Ret_ErrorState ; 
}
Std_ReturnType RELAY_TurnOn(RELAY_t * pRelay_Config)
{
    Std_ReturnType Ret_ErrorState = E_OK ; 
    if(pRelay_Config != NULL_ptr){
        Ret_ErrorState = GPIO_SetPinValue(pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , GPIO_HIGH );
        
    }else{
        Ret_ErrorState = E_NOT_OK ; 
    }
    return Ret_ErrorState ; 
}
Std_ReturnType RELAY_TurnOff(RELAY_t * pRelay_Config)
{   
    Std_ReturnType Ret_ErrorState = E_OK ; 
    if(pRelay_Config != NULL_ptr){
        
        Ret_ErrorState = GPIO_SetPinValue(pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , GPIO_LOW );

    }else{
        Ret_ErrorState = E_NOT_OK ; 
    }
    return Ret_ErrorState ; 
}