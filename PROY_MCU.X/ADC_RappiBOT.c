/* 
 * File:    ADC_RappiBOT.C
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments: Configura la parametros del adc para el uso en el proyecto
 * Revision history: v1.0 
 */

#include "ADC_RappiBOT.h"
#include "RappiBOT.h"
void ADC_RappiBOT_Init(void){
    AD1PCFGL = 0xFFFF;      //inicialmente se desactiva todas los pines adc
    /*0. Se selecciona 10-bit o 12-bit*/
    AD1CON1bits.AD12B = 0;  //se selecciona 12 bit
    /*1. Seleccione los pines del puerto como entradas analógicas (AD1PCFGH <15: 0> o AD1PCFGL <15: 0>).*/
    AD1PCFGLbits.PCFG0 = 0; //AN0
    TRISAbits.TRISA0 = 1;   //entrada analogica
    /*2. Seleccione la fuente de referencia de voltaje para que coincida con el rango 
     * esperado en las entradas analógicas (AD1CON2 <15:13>).*/
    AD1CON2bits.VCFG = 0;   //AVDD-AVss 
    /*3. Seleccione el reloj de conversión analógico para que coincida con la 
     * velocidad de datos deseada con el reloj del procesador (AD1CON3 <7: 0>).*/
    AD1CON3bits.ADCS = 1;   //2 · TCY = TAD
    /*4. Determine cuántos canales de muestreo y retención se utilizarán 
     * (AD1CON2 <9: 8> y AD1PCFGH <15: 0> o AD1PCFGL <15: 0>).*/
    AD1CON2bits.CHPS = 0;   
    /*5. Seleccione la muestra apropiada/secuencia de conversión (AD1CON1 <7: 5> y AD1CON3 <12: 8>).*/
    AD1CON1bits.SSRC = 0;   //000 = cuando se pone el bit samp = 0 inicia la conversion
    AD1CON1bits.ASAM = 0;   //inicia el muestreo cuando samp = 1
    /*6. Seleccione la forma en que se presentan los resultados de conversión 
     * en el búfer (AD1CON1 <9: 8>).*/
    AD1CON1bits.FORM = 0;   //enteros
    /*7. SELECCIÓN DE ENTRADA ANALÓGICA PARA CONVERSIÓN*/
    AD1CHS0bits.CH0SA = 0;  // Channel 0 positive input is AN0
    AD1CHS0bits.CH0NA = 0;  //0 = Channel 0 negative input is VREF
    /*8. Encienda el módulo ADC (AD1CON1 <15>).*/
    AD1CON1bits.ADON = 1;
    /*9. Configure la interrupción de ADC (si es necesario):
        a) Borrar el bit AD1IF.
        b) Seleccione la prioridad de interrupción de ADC.*/
}

void ADC_RappiBOT_Read(uint16_t * data){
    AD1CON1bits.SAMP = 1;   //inicia el muestreo
    delay_ms(0.9);
    AD1CON1bits.SAMP = 0;   //inicia la conversion
    while(!AD1CON1bits.DONE);//se espera hasta que se termine la conversion
    AD1CON1bits.DONE = 0;    //se limpia el flag
    *data = ADC1BUF0;
}