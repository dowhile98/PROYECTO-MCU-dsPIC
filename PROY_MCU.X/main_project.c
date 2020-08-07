/*
 * File:   main_project.c
 * Author: Ronald Quino Bueno
 *
 * Created on 3 de agosto de 2020, 04:47 PM
 */

/*INCLUSION DE ARCHIVOS CABECERA*/
#include "config.h"
#include "RappiBOT.h"
/*DEFINICION DE MACROS*/

/*DEFINICION DE VARIABLES GLOBALES*/
uint8_t data = 0;
uint8_t state = 0;
int main(void) {
    RappiBOT_Init();
    printf("BIENVENDO. TIENES PEDIDOS QUE ENTREGAR?\r\n");
    LCD_clear();
    LCD_print("***HELLO,I AM***");
    LCD_setCursor(1,0);
    LCD_print("--->RappiBOT<---");
    delay_ms(1000);
    while(1){
        if(state){
            LCD_setCursor(0,0);
            LATAbits.LATA10 = 1;
            if(data =='w'){
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_FORWARD();
            }
            else if(data == 's'){
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_BACKWARD();
            }
            else if(data == 'd'){
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_TURNRIGHT();
            }
            else if(data == 'a'){
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_TURNLEFT();
            }
            else if(data == 't'){
                LATB = 0;
                RappiBOT_GetTemp();
                data = 0;
            }
            else if(data == 'x'){
                OC2CONbits.OCM = 0;     //PMW
                LATB = 0;
            }
            delay_ms(100);
        }
    }
    return 0;
}

/*rutina de servicio de la interrupcion*/
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void){
    IFS0bits.U1RXIF = 0;    //se borra el flag
    if(U1STAbits.URXDA){
        data = U1RXREG;
        printf("se recibio->%c\r\n",data);
        
        if(data>47 && data<58){
            data -=48;
            OC1RS = data*3123/9+1;
        }
        else if(data == 'e'){
            state = 1;
            printf("listo para el cotrol\r\n");
            LCD_clear();
            LCD_print("RappiBOT is");
            LCD_setCursor(1,0);
            LCD_print("READY!!!!!!!");
            delay_ms(500);
        }
    }
    
}