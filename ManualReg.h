#ifndef MANUALREG_H_
#define MANUALREG_H_


//SysCtl Base
#include "inc/hw_sysctl.h"
//Direcciones base
#include "inc/hw_memmap.h"
//Offset pwm
#include "inc/hw_pwm.h"
//Offset gpio
#include "inc/hw_gpio.h"
//Offset qei
#include "inc/hw_qei.h"

//
// Macros para manipulacion de registros
//
#define WR8(x)         (*((volatile uint8_t *)(x)))
#define WR16(x)        (*((volatile uint16_t *)(x)))
#define WR32(x)        (*((volatile uint32_t *)(x)))
#define WR(x)          (WR16(x))
#define WR8_L(x)       (*((volatile uint8_t *)((uint8_t *)&x)))
#define WR8_H(x)       (*((volatile uint8_t *)(((uint8_t *)&x)+1)))
#define WR16_L(x)      (*((volatile uint16_t *)((uint16_t *)&x)))
#define WR16_H(x)      (*((volatile uint16_t *)(((uint16_t *)&x)+1)))


//
// Mascara de Bits de un registro de hasta 32 bits
//
#define R0          0x00000001
#define R1          0x00000002
#define R2          0x00000004
#define R3          0x00000008
#define R4          0x00000010
#define R5          0x00000020
#define R6          0x00000040
#define R7          0x00000080
#define R8          0x00000100
#define R9          0x00000200
#define R10         0x00000400
#define R11         0x00000800
#define R12         0x00001000
#define R13         0x00002000
#define R14         0x00004000
#define R15         0x00008000
#define R16         0x00010000
#define R17         0x00020000
#define R18         0x00040000
#define R19         0x00080000
#define R20         0x00100000
#define R21         0x00200000
#define R22         0x00400000
#define R23         0x00800000
#define R24         0x01000000
#define R25         0x02000000
#define R26         0x04000000
#define R27         0x08000000
#define R28         0x10000000
#define R29         0x20000000
#define R30         0x40000000
#define R31         0x80000000


#endif
