
/* 
 * File:   RappiBOT.h
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments: este proyecto tiene la  finalidad de diseñar un prototipo de robot
 *           cuadrupedo, de cuatro ruedas para que a futuro sea implementado
 *           y usado en la entrega delivery.
 * Revision history: v1.0 
 */
#ifndef __RAPPIBOT_H
#define __RAPPIBOT_H

/****************************************************************************
 *                      inclusion de librerias                              *
 ***************************************************************************/
#include <stdio.h>
#include "reloj.h"
#include "ADC_RappiBOT.h"
#include "OC_RappiBOT.h"
#include "UART_RappiBOT.h"
#include "xlcd.h"
#include <libpic30.h>
/****************************************************************************
 *                      DEFINCION DE MACROS                                 *
 ***************************************************************************/

/****************************************************************************
 *                  DEFINICION DE PROTOTIPO DE FUNCIONES                    *
 ***************************************************************************/
/**
 * @brief INCIALIZA TODOS LOS PERIFERICOS
 * @param : none
 * @return :none
 * @verbatim
 * LCD_Init();
 * ADC_RappiBOT_Init();
 * OC_RappiBOT_Init();
 * UART1_RappiBOT_Init(9600);
 * GPIO_RappiBOT_Init();
 */
void RappiBOT_Init(void);
/**
 * @brief CONTROLA EL GIRO HACIA DELANTE
 * @param : none
 * @return :none
 * @verbatim
 */
void RappiBOT_FORWARD(void);
/**
 * @brief CONTROLA EL GIRO HACIA ATRAS
 * @param : none
 * @return :none
 * @verbatim
 */
void RappiBOT_BACKWARD(void);

/**
 * @brief CONTROLA EL GIRO HACIA LA IZQUIERDA
 * @param : none
 * @return :none
 * @verbatim
 */
void RappiBOT_TURNLEFT(void);
/**
 * @brief CONTROLA EL GIRO HACIA LA DERECHA
 * @param : none
 * @return :none
 * @verbatim
 */
void RappiBOT_TURNRIGHT(void);

/**
 * @brief mide la temperatura
 * @param : none
 * @return :none
 * @verbatim
 */
void RappiBOT_GetTemp(void);



#endif /*__RAPPIBOT_H*/

