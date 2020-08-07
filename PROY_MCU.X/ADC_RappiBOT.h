/* 
 * File:    ADC_RappiBOT.h
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments: Configura la parametros del adc para el uso en el proyecto
 * Revision history: v1.0 
 */

#ifndef __ADC_RAPPIBOT_H
#define __ADC_RAPPIBOT_H

/*inclusion de librerias*/
#include "xc.h"

/**
 * @brief INCIALIZA EL ADC
 * @param : none
 * @return :none
 * @verbatim
 * AN0 -> entrada LM35
 */
void ADC_RappiBOT_Init(void);

/**
@brief LECTURA DEL LM35
@param data: puntero a la variable donde se almancenará el valor de buffer
@returns: none
@verbatim
 * esta funcion recibe como parametro un puntero, el puntero a punta
 * a la variable donde se desea almacenar el valor de buffer adc
@endverbatim
 */
void ADC_RappiBOT_Read(uint16_t * data);
#endif /*__ADC_RAPPIBOT_H*/