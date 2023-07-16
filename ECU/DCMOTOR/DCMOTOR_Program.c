#include "../../MCAL/GPIO/GPIO.h"
#include "DCMOTOR_Interface.h"

Std_ReturnType DC_MOTOR_INIT(DC_MOTOR_t *pMotor_Config)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        Pin_Config_t Motor_Pin1 = { pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_OUTPUT , GPIO_LOW};
        Pin_Config_t Motor_Pin2 = { pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_OUTPUT , GPIO_LOW};
        return_ErrorState = GPIO_PinInitialize(&Motor_Pin1);
        return_ErrorState = GPIO_PinInitialize(&Motor_Pin2);
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}
Std_ReturnType DC_MOTOR_ON_CW(DC_MOTOR_t *pMotor_Config)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        Pin_Config_t Motor_Pin1 = { pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_OUTPUT , GPIO_LOW};
        Pin_Config_t Motor_Pin2 = { pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_OUTPUT , GPIO_LOW};
        return_ErrorState = GPIO_SetPinValue(&Motor_Pin1 , GPIO_HIGH);
        return_ErrorState = GPIO_SetPinValue(&Motor_Pin2 , GPIO_LOW );
        
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}
Std_ReturnType DC_MOTOR_ON_CCW(DC_MOTOR_t *pMotor_Config)
{
    Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        Pin_Config_t Motor_Pin1 = { pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_OUTPUT , GPIO_LOW};
        Pin_Config_t Motor_Pin2 = { pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_OUTPUT , GPIO_LOW};
        return_ErrorState = GPIO_SetPinValue(&Motor_Pin1 , GPIO_LOW);
        return_ErrorState = GPIO_SetPinValue(&Motor_Pin2 , GPIO_HIGH );
        
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}
Std_ReturnType DC_MOTOR_OFF(DC_MOTOR_t *pMotor_Config)
{
       Std_ReturnType return_ErrorState = E_OK;
    if(pMotor_Config != NULL_ptr){
        Pin_Config_t Motor_Pin1 = { pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_OUTPUT , GPIO_LOW};
        Pin_Config_t Motor_Pin2 = { pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_OUTPUT , GPIO_LOW};
        return_ErrorState = GPIO_SetPinValue(&Motor_Pin1 , GPIO_LOW );
        return_ErrorState = GPIO_SetPinValue(&Motor_Pin1 , GPIO_LOW );
        
    }else{
        return_ErrorState = E_NOT_OK;
    }
    return return_ErrorState ; 
}