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

/*inclusion de librerias*/
#include "RappiBOT.h"

//inicializa los pines necesario para el proyecto
void GPIO_RappiBOT_Init(void){
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    TRISAbits.TRISA8 = 0;
    TRISAbits.TRISA9 = 0;
    TRISAbits.TRISA10 = 0;
    
}

void RappiBOT_Init(void){
    LCD_Init();
    ADC_RappiBOT_Init();
    OC_RappiBOT_Init();
    UART1_RappiBOT_Init(9600);
    GPIO_RappiBOT_Init();
}

void RappiBOT_FORWARD(void){
    LATAbits.LATA8 = 0;
    LATAbits.LATA9 = 0;
    OC2CONbits.OCM = 0;     //PMW
    LATB = 0b01100110;
}
void RappiBOT_BACKWARD(void){
    LATAbits.LATA8 = 0;
    LATAbits.LATA9 = 0;
    OC2CONbits.OCM = 0;     //PMW
    LATB = 0b10011001;
}
void RappiBOT_TURNLEFT(void){
    LATAbits.LATA8 = 0;
    LATAbits.LATA9 = 0;
    OC2CONbits.OCM = 0;     //PMW
    LATB = 0b01000100;
}
void RappiBOT_TURNRIGHT(void){
    LATAbits.LATA8 = 0;
    LATAbits.LATA9 = 0;
    OC2CONbits.OCM = 0;     //PMW
    LATB = 0b00100010;
}

void RappiBOT_GetTemp(void){
    uint16_t data;
    double temp;
    ADC_RappiBOT_Read(&data);
    temp = (double)data*500/1024;
    if(temp>=38){
        OC2CONbits.OCM = 0b110;     //PMW
        
        LATAbits.LATA8 = 0;
        LATAbits.LATA9 = 1;
        printf("ALERTA!->COVID A LA VISTA\r\n");
        printf("Temperatura de usuario->%.2f\r\n",temp);
        LCD_print("TEMP... ALTA");
        LCD_setCursor(1,0);
        LCD_print("Temp-> ");
        LCD_printFloat(temp);
    }
    else{
        OC2CONbits.OCM = 0;     //PMW
        LATAbits.LATA8 = 1;
        LATAbits.LATA9 = 0;
        printf("USUARIO NO TIENE FIEBRE\r\n");
        printf("Temperatura de usuario->%.2f\r\n",temp);
        LCD_print("TEMP... NORMAL");
        LCD_setCursor(1,0);
        LCD_print("Temp-> ");
        LCD_printFloat(temp);
    }
    delay_ms(50);
}