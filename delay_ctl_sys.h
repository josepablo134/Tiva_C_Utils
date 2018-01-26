/*
 * delay_ctl_sys.h
 *
 *  Created on: 26/01/2018
 *      Author: josepablocb
 */

#ifndef _DELAY_CTL_SYS_H
#define _DELAY_CTL_SYS_H
    #define _CLK_FREC_  80000000
    #define delay(TIME)     {SysDelay((_CLK_FREC_/3000)*TIME);}
    #define delay_us(TIME)  {SysDelay((_CLK_FREC_/3000000)*TIME);}
    extern void SysDelay(uint32_t);
//    void delay_ms(uint32_t time);
//    void delay_us(uint32_t time);
#endif

