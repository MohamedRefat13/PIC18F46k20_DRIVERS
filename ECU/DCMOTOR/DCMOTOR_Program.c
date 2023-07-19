#include "../../MCAL/GPIO/GPIO.h"
#include "DCMOTOR_Interface.h"

Std_ReturnType DC_MOTOR_INIT(DC_MOTOR_t *pMotor_Config)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        return_ErrorState = GPIO_SetPinDirection(pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_OUTPUT);
        return_ErrorState = GPIO_SetPinDirection(pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_OUTPUT);
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}
Std_ReturnType DC_MOTOR_ON_CW(DC_MOTOR_t *pMotor_Config)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        return_ErrorState = GPIO_SetPinValue(pMotor_Config->PortNumber , pMotor_Config->Pin1Number ,  GPIO_HIGH);
        return_ErrorState = GPIO_SetPinValue(pMotor_Config->PortNumber , pMotor_Config->Pin2Number ,  GPIO_LOW );
        
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}
Std_ReturnType DC_MOTOR_ON_CCW(DC_MOTOR_t *pMotor_Config)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        return_ErrorState = GPIO_SetPinValue(pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_LOW);
        return_ErrorState = GPIO_SetPinValue(pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_HIGH );
        
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}
Std_ReturnType DC_MOTOR_OFF(DC_MOTOR_t *pMotor_Config)
{
       Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        return_ErrorState = GPIO_SetPinValue(pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_LOW );
        return_ErrorState = GPIO_SetPinValue(pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_LOW );
        
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}