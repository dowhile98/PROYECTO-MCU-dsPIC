#ifndef __RELOJ_H
#define __RELOJ_H

#include <xc.h>
#define FCY             (10000000UL)      //unsigned long
#define delay_ms(x)     __delay32((FCY/1000)*x)
#define BRGVAL(BAUDRATE)    ((FCY/BAUDRATE)/16)-1

#endif/*__RELOJ_H*/