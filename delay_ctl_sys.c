/*
 * delay_ctl_sys.c
 *
 *  Created on: 26/01/2018
 *      Author: josepablocb
 */
#include "delay_ctl_sys.h"
//_CLK_FREC_    80000000
__asm("    .sect \".text:SysDelay\"\n"
      "    .clink\n"
      "    .thumbfunc SysDelay\n"
      "    .thumb\n"
      "    .global SysDelay\n"
      "SysDelay:\n"
      "    subs r0, #1\n"
      "    bne.n SysDelay\n"
      "    bx lr\n");
