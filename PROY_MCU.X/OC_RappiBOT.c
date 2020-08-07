/* 
 * File:    OC_RappiBOT.c
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments:configura el modulo de comparacion de salida
 *          para genera salida PWM para el control motores
 * Revision history: v1.0 
 */
#include "OC_RappiBOT.h"
void OC_RappiBOT_Init(void){
    /*ASIGNACION DEL PIN*/
    RPOR4bits.RP8R = 0b10010;//RB0->SALIDA DE MODULO DE COMPARACION
    RPOR4bits.RP9R = 0b10010;//RB0->SALIDA DE MODULO DE COMPARACION
    RPOR5bits.RP10R = 0b10010;//RB0->SALIDA DE MODULO DE COMPARACION
    RPOR5bits.RP11R = 0b10010;//RB0->SALIDA DE MODULO DE COMPARACION
    RPOR7bits.RP14R = 0b10011;//RB0->SALIDA DE MODULO DE COMPARACION
    T2CON = 0;                  //se resetea la configuracion del timer2
    T2CONbits.TCKPS = 1;        //PSC->8
    PR2 = 3125;                 //2.5ms->periodo de PWM (400HZ)
    TMR2 = 0;   
    OC1CON = 0;                 //RESETEA TODO EL REGISTRO
    OC2CON = 0;                 //resetea todo el registro del modulo 2
    OC1R = 0;                   //Comparacion en 400ms
    OC2R = 0;
    OC1RS = 1;                 //Comparacion en 600ms
    OC2RS = 1000;
    OC1CONbits.OCM = 0b110;     //PMW
    T2CONbits.TON = 1;          //ACTIVA EL TIMER
}

