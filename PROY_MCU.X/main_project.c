/ * 
 * Archivo: main_project.c
 * Autor: QUINO BRICEÑO JEFFRY
 * CARRILLO MARIN DIEGO
 * HERRERA AYALA ANDERSON
 * JARA MORALES STEFHANO
 * Comentarios: este proyecto tiene la finalidad de diseñar un prototipo de robot
 * cuadrupedo, de cuatro ruedas para que un futuro sea implementado
 * y usado en la entrega entrega.
 * Historial de revisiones: v1.0 
 * /

/*INCLUSION DE ARCHIVOS CABECERA*/
#include "config.h"
#include "RappiBOT.h"
/*DEFINICION DE MACROS*/

/*DEFINICION DE VARIABLES GLOBALES*/
uint8_t data = 0;
uint8_t state = 0;
int main(void) {
    RappiBOT_Init();                                        //inicializa los perifericos usados por el robot
    printf("BIENVENDO. TIENES PEDIDOS QUE ENTREGAR?\r\n");  //se muestra un mensaje por el puerto UART1
    //SE DESPLIEGA UN MENSAJE EN LA LCD 16x2
    LCD_clear();
    LCD_print("***HELLO,I AM***");
    LCD_setCursor(1,0);
    LCD_print("--->RappiBOT<---");
    delay_ms(1000);
    //BUCLE INFINITO
    while(1){
        if(state){                                          //SI YA SE RECIBIO UNA 'e' POR EL PUERTO SERIAL
            LCD_setCursor(0,0);
            LATAbits.LATA10 = 1;    
            if(data =='w'){                                 //SE MUEVE EL ROBOT HACIA DELANTE
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_FORWARD();
            }
            else if(data == 's'){                           //SE MUEVE EL ROBOT HACIA ATRAS
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_BACKWARD();
            }
            else if(data == 'd'){                           //SE MUEVE EL ROBOT A LA DERECHA
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_TURNRIGHT();
            }
            else if(data == 'a'){                          //SE MUEVE EL ROBOT A LA IZQUIERDA
                LCD_print("I'M WORKING    ");
                LCD_setCursor(1,0);
                LCD_print("                ");
                RappiBOT_TURNLEFT();
            }   
            else if(data == 't'){                           //SE LEE LA TEMPERATURA DEL LM35
                LATB = 0;
                RappiBOT_GetTemp();
                data = 0;
            }
            else if(data == 'x'){                           //DETIENE LOS MOTORES
                OC2CONbits.OCM = 0;     //PMW
                LATB = 0;
            }
            delay_ms(100);                                  //UNA ESPERA DE 100ms PARA QUE VUELVA A VERIFICAR EL ESTAOD DEL DATO RECIBIDO
        }
    }
    return 0;
}

/*rutina de servicio de la interrupcion*/
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void){
    IFS0bits.U1RXIF = 0;    //se borra el flag
    if(U1STAbits.URXDA){                                //SI YA RECIBIO UN BYTE
        data = U1RXREG;
        printf("se recibio->%c\r\n",data);              //ENVIA UN MENSAJE POR EL PUERTO UART CON EL DATO RECIBIDO
        
        if(data>47 && data<58){                         // SI ASCII RECIBIDO ES UN NUMERO DE 0-5
            data -=48;
            OC1RS = data*3123/9+1;                      //SE ASIGNA UN ANCHO DE PULSO AL PWM PARA LA VELOCIDAD DE MOTORES
        }
        else if(data == 'e'){                           //SI SE REBIBE UNA 'e' SE HABILITA EL FUNCIONAMIENTO DEL ROBOT
            state = 1;                                  //CABIA EL ESTADO DE VARIABLE STATE
            printf("listo para el cotrol\r\n");
            LCD_clear();
            LCD_print("RappiBOT is");
            LCD_setCursor(1,0);
            LCD_print("READY!!!!!!!");
            delay_ms(500);
        }
    }
    
}
