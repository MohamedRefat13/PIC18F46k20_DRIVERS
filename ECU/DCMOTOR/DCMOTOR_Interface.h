/* 
 * File:   DCMOTOR_Interface.h
 * Author: Mohamed Refat 
 *
 * Created on July 16, 2023, 5:11 PM
 */

#ifndef DCMOTOR_INTERFACE_H
#define	DCMOTOR_INTERFACE_H

typedef struct {
    uint8_t PortNumber ; 
    uint8_t Pin1Number ; 
    uint8_t Pin2Number ; 

}DC_MOTOR_t;

Std_ReturnType DC_MOTOR_INIT(DC_MOTOR_t *pMotor_Config);
Std_ReturnType DC_MOTOR_ON_CW(DC_MOTOR_t *pMotor_Config);
Std_ReturnType DC_MOTOR_ON_CCW(DC_MOTOR_t *pMotor_Config);
Std_ReturnType DC_MOTOR_OFF(DC_MOTOR_t *pMotor_Config);

#endif	/* DCMOTOR_INTERFACE_H */

