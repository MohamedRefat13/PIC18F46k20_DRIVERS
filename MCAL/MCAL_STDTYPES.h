/* 
 * File:   MCAL_STDTYPES.h
 * Author: Mohamed Refat
 *
 * Created on July 3, 2023, 3:17 PM
 */

#ifndef MCAL_STDTYPES_H
#define	MCAL_STDTYPES_H

/* Section : Includes*/
#include "Compiler.h"
#include "STD_LIB.h"


/* Section : Macro Delcarations */

#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define NULL_ptr ((void*)0)


/* Section : Data types Delcarations */
typedef unsigned long  int  uint32_t;
typedef unsigned short int  uint16_tt;
typedef signed   long  int  sint32_t;
typedef signed   short int  sint16_t;

typedef unsigned char       uint8_t;
typedef signed   char       sint8_t;

typedef float               f32_t;
typedef double              f64_t;
typedef long     double     f80_t;


typedef enum  
{
    E_NOT_OK,
    E_OK

}Std_ReturnType;


/* Section : Macro Functions Delcarations */


/* Section : Functions Delcarations */
#endif	/* MCAL_STDTYPES_H */

