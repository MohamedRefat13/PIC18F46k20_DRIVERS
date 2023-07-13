#include "../../MCAL/GPIO/GPIO.h"
#include "RELAY_Interface.h"

Std_ReturnType RELAY_Init(Relay_t * pRelay_Config)
{
    Std_ReturnType Ret_ErrorState = E_OK ; 
    if(pRelay_Config != NULL_ptr){

        Pin_Config_t RLY_Pin = { pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , GPIO_OUTPUT , pRelay_Config->RLY_State };
        Ret_ErrorState = GPIO_PinInitialize(&RLY_Pin);

    }else{
        Ret_ErrorState = E_NOT_OK ; 
    }
    return Ret_ErrorState ; 
}
Std_ReturnType RELAY_TurnOn(Relay_t * pRelay_Config)
{
    Std_ReturnType Ret_ErrorState = E_OK ; 
    if(pRelay_Config != NULL_ptr){
        
        Pin_Config_t RLY_Pin = { pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , GPIO_OUTPUT , pRelay_Config->RLY_State };
        Ret_ErrorState = GPIO_SetPinValue(&RLY_Pin , GPIO_HIGH );
        
    }else{
        Ret_ErrorState = E_NOT_OK ; 
    }
    return Ret_ErrorState ; 
}
Std_ReturnType RELAY_TurnOff(Relay_t * pRelay_Config)
{   
    Std_ReturnType Ret_ErrorState = E_OK ; 
    if(pRelay_Config != NULL_ptr){
        
        Pin_Config_t RLY_Pin = { pRelay_Config->RLY_PortNum , pRelay_Config->RLY_PinNum , GPIO_OUTPUT , pRelay_Config->RLY_State };
        Ret_ErrorState = GPIO_SetPinValue(&RLY_Pin , GPIO_LOW );

    }else{
        Ret_ErrorState = E_NOT_OK ; 
    }
    return Ret_ErrorState ; 
}