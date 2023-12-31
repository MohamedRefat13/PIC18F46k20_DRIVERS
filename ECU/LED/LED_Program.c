#include "../../MCAL/GPIO/GPIO.h"
#include "LED_Interface.h"
Std_ReturnType LED_Init(LED_t *pLedConfigration)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pLedConfigration != NULL_ptr){
        return_ErrorState = GPIO_SetPinDirection(pLedConfigration->PortNumber , pLedConfigration->PinNumber , GPIO_OUTPUT);
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
    
}

Std_ReturnType LED_ON(LED_t *pLedConfigration)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pLedConfigration != NULL_ptr){
        if(LED_ACTIVE_HIGH ==pLedConfigration->Active_Status)
        {
            return_ErrorState = GPIO_SetPinValue(pLedConfigration->PortNumber , pLedConfigration->PinNumber , GPIO_HIGH); 
        }else if(LED_ACTIVE_LOW ==pLedConfigration->Active_Status)
        {
            return_ErrorState = GPIO_SetPinValue(pLedConfigration->PortNumber , pLedConfigration->PinNumber , GPIO_LOW); 
        } 
       
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
    
} 
    

Std_ReturnType LED_OFF(LED_t *pLedConfigration)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pLedConfigration != NULL_ptr){
        if(LED_ACTIVE_HIGH ==pLedConfigration->Active_Status)
        {
           return_ErrorState = GPIO_SetPinValue(pLedConfigration->PortNumber , pLedConfigration->PinNumber , GPIO_LOW); 
        }else if(LED_ACTIVE_LOW ==pLedConfigration->Active_Status)
        {
           return_ErrorState = GPIO_SetPinValue(pLedConfigration->PortNumber , pLedConfigration->PinNumber , GPIO_HIGH); 
        }
       
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
    
}

Std_ReturnType LED_Toggle(LED_t *pLedConfigration)
{   Std_ReturnType return_ErrorState = E_OK;

    if(pLedConfigration != NULL_ptr){
        return_ErrorState = GPIO_TogglePinValue(pLedConfigration->PortNumber , pLedConfigration->PinNumber);
       
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
    
}