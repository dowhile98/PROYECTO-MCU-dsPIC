/* 
 * File:    OC_RappiBOT.h
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments:configura el modulo de comparacion de salida
 *          para genera salida PWM para el control motores
 * Revision history: v1.0 
 */
#ifndef __OC_RAPPI_BOT_H
#define __OC_RAPPI_BOT_H

#include "xc.h"
/**
 * @brief INCIALIZA EL OUTPUT COMPARE EN MODO PWM
 * @param : none
 * @return :none
 * @verbatim
 * confifura el output compare 1-2 en modo pwm
 */
void OC_RappiBOT_Init(void);
#endif /*__OC_RAPPI_BOT_H*/
