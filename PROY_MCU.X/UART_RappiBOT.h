/* 
 * File:    UART_RappiBOT.h
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments:configura y inicializa el uart1 y uart2
 *          UART1->HC-O5
 *          UART2->debugeo PC
 * Revision history: v1.0 
 */
#ifndef __UART_RAPPIBOT_H
#define __UART_RAPPIBOT_H

/*inclusion de archivos cabecera*/
#include "xc.h"
#include "reloj.h"

/*PROTOTIPO DE FUNCIONES*/
/*prototipo de funciones*/
/**
 @brief CONFIGURA LOS PARAMETROS DEL UART1
 *@param BaudRate:   velocidad en baudios
 @verbatim
 *  1 Stop bit
 *  No Parity, 8 data bits
 *  Auto-Baud Disabled
 */
void UART1_RappiBOT_Init(uint16_t BaudRate);

/**
 @brief ENVIO DE UN CARACTER POR UART1
 *@param ch: caracter a enviar
 @verbatim
 * funcion que envia un caracter por el uart1
 */
void UART1_PutChar(char ch);
#endif /*__UART_RAPPIBOT_H*/