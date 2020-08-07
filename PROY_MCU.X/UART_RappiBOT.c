/* 
 * File:    UART_RappiBOT.C
 * Author:  QUINO BRICEÑO JEFFRY
 *          CARRILLO MARIN DIEGO
 *          HERRERA AYALA ANDERSON
 *          JARA MORALES STEFHANO
 * Comments:configura y inicializa el uart1 y uart2
 *          UART1->HC-O5
 *          UART2->debugeo PC
 * Revision history: v1.0 
 */

/*inclusion de encabezados*/
#include "UART_RappiBOT.h"

/*DEFINICION DE FUNCIONES*/
void UART1_RappiBOT_Init(uint16_t BaudRate){
    RPOR6bits.RP12R = 3;   //RB12->tx
    RPINR18bits.U1RXR = 13;//RB13->RX
    U1MODE = 0;             //LIMPIO TODA LA CONFIGURACION
    U1STA = 0;              //LIMPIO TODA LA CONFIGURACION
    U1BRG = BRGVAL(BaudRate);//SE ESTABLECE LA VELOCIDAD DE TRANSMISION
    
    IPC2bits.U1RXIP = 1;    //prioridad uno
    IFS0bits.U1RXIF = 0;    //se borra el flag
    IEC0bits.U1RXIE = 1;    //activas la interrupcion
    U1MODEbits.PDSEL = 0;   //TRANSMISION SIN PARIDAD
    U1MODEbits.STSEL = 0;   //BIT DE PARADA = 1
    U1MODEbits.UARTEN = 1;  //SE HABILITA EL MODULO UART1
    U1STAbits.UTXEN = 1;    //SE HABILITA LA TRANSMISION DE DATOS
    
}

void UART1_PutChar(char ch){
    while (U1STAbits.UTXBF == 1);
    U1TXREG = ch;
}

/*****************************************************************************
 *      ESTA FUNCION SIRVE PARA EL USO DE LA FUNCION PRINTF                  *
 ****************************************************************************/
int    write(int handle, void *buffer, unsigned int len)
{
  int i;
   switch (handle)
  {
      case 0:        // handle 0 corresponds to stdout
      case 1:        // handle 1 corresponds to stdin
      case 2:        // handle 2 corresponds to stderr
      default:
          for (i=0; i<len; i++)
              
              UART1_PutChar(*(char*)buffer++);
  }
  return(len);
}