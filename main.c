/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

// Inclusión de bibliotecas y archivos de encabezado necesarios.
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include "funciones.h"

//----------------------------------------------------------------------------------------------------
// Declaración de variables globales para almacenar los valores del ADC con y sin DC
uint16_t signal_DC_1 = 0;       // Señal con componente DC.
int16_t signal_No_DC_1 = 0;    // Señal sin componente DC (offset removido).
long salidaFIR, salidaIIR;     // Salidas de los filtros FIR e IIR.

// Variables para el DAC.
uint16_t DAC_SPI = 0;          // Valor para el DAC.
uint8_t DAC_SPI_High = 0;      // Byte alto para SPI del DAC.
uint8_t DAC_SPI_Low = 0;       // Byte bajo para SPI del DAC.
//----------------------------------------------------------------------------------------------------

//Coeficientes para el IIR a 63Hz de corte
//const float num1[5] = {0.0105, 0.0419, 0.0629, 0.0419, 0.0105};
//const float den2[5] = {1.0000, -1.9524, 1.7152, -0.7133, 0.1182};

const float num1[5] = {3.0996e-05, 1.2398e-04, 1.8597e-04, 1.2398e-04, 3.0996e-05};

const float  den2[5] ={1, -3.5906, 4.8534, -2.9259, 0.6636};

////Coeficientes para el IIR a 31Hz de corte
//const float num1[5] = {0.0009, 0.0036, 0.0054, 0.0036, 0.0009};
//const float den2[5] ={1.0000, -2.9850, 3.4392, -1.7983, 0.3586};

//----------------------------------------------------------------------------------------------------
float w[5]; // Vector de estados para el filtro IIR.
coef_iir_4_ord ir; // Estructura para coeficientes y estados del filtro IIR.
char char_hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // Array para conversiones a hexadecimal.
//----------------------------------------------------------------------------------------------------
void leerDelADC(){
    // Función para leer valores del ADC.
    signal_DC_1 = ADCC_GetSingleConversion(channel_ANA0);//señal de entrada
    signal_No_DC_1 = signal_DC_1 - 0b0000011111111111; // Offset de 1v señal que se filtra
}
//----------------------------------------------------------------------------------------------------

// Función para enviar datos al DAC a través de SPI.
void sendToDAC(uint16_t value, uint8_t channel) {
    // Configura el bit del canal y el bit SHDN dependiendo del canal seleccionado.
    if (channel) {
        value |= 0b1011000000000000; // Canal B con SHDN activado.
    } else {
        value |= 0b0011000000000000; // Canal A con SHDN activado.
    }

    SPI_SetLow();//LOW para iniciar la transmisión SPI.
    DAC_SetLow();//LOW para actualizar la salida del DAC

    // Envía el valor al DAC a través de SPI (Interfaz Periférica Serial).
    SPI1_ExchangeByte((value >> 8) & 0xFF); // Envía byte más significativo.
    SPI1_ExchangeByte(value & 0xFF);       // Envía byte menos significativo.

    // Sube CS y LDAC para finalizar la transmisión al DAC.
    SPI_SetHigh();//LOW para iniciar la transmisión SPI.
    DAC_SetHigh();//LOW para actualizar la salida del DAC
}

void sendToUART(uint16_t senal_entrada, uint16_t senal_filtrada){
// Función para enviar datos a UART en formato hexadecimal.
    
UART1_Write(char_hexa[(senal_entrada & 0xf000)>>12]);
UART1_Write(char_hexa[(senal_entrada & 0x0f00)>>8]);
UART1_Write(char_hexa[(senal_entrada & 0x00f0)>>4]);
UART1_Write(char_hexa[(senal_entrada & 0x000f)]);
UART1_Write(',');
UART1_Write(char_hexa[(senal_filtrada & 0xf000)>>12]);
UART1_Write(char_hexa[(senal_filtrada & 0x0f00)>>8]);
UART1_Write(char_hexa[(senal_filtrada & 0x00f0)>>4]);
UART1_Write(char_hexa[(senal_filtrada & 0x000f)]);
//UART1_Write('\n');
// //---------------------------SEÑAL DE ENTRADA-------------------------------------------------------------------------   
//    uint8_t mostrarBajo = (signal_DC_1 & 0x00FF);
//    uint8_t mostrarAlto = (signal_DC_1 >> 8);
// //------------------------------SALIDA SEÑAL FILTRADA----------------------------------------------------------------------
//    uint8_t mostrarBajo_1 = (salidaFIR & 0x00FF);
//    uint8_t mostrarAlto_1 = (salidaFIR >> 8);
// //-------------------------------------ENVIOS ---------------------------------------------------------------  
//    UART1_Write(char_hexa[mostrarAlto >> 4]);
//    UART1_Write(char_hexa[mostrarAlto & 0x00F]);
//    UART1_Write(char_hexa[mostrarBajo >> 4]);
//    UART1_Write(char_hexa[mostrarBajo & 0x00F]);  
// //----------------------------------------------------------------------------------------------------   
//    UART1_Write(',');
//    
//    UART1_Write(char_hexa[mostrarAlto_1 >> 4]);
//    UART1_Write(char_hexa[mostrarAlto_1 & 0x00F]);
//    
//    UART1_Write(char_hexa[mostrarBajo_1 >> 4]);
//    UART1_Write(char_hexa[mostrarBajo_1 & 0x00F]);  
//    
//    UART1_Write('\n');
}    


void main(void) {
    // Initialize the device
    // Función principal del programa.
    SYSTEM_Initialize();       // Inicialización del sistema.
    SPI1_Open(SPI1_DEFAULT);   // Apertura de la comunicación SPI.
    inicializar_iir_4_ord(num1, den2, w, &ir); // Inicialización del filtro IIR.
    UART1_Initialize();        // Inicialización de UART.
    
    while (1) {
        leerDelADC(); // Lectura del ADC.
        //LED_0_SetHigh();
        //salidaFIR = (long)(filtrarFIR1(signal_No_DC_1) + 0x0800); // Filtrado FIR.
        //LED_0_SetLow();
        
        //LED_1_SetHigh();
        salidaIIR = (long)(filtrarIIR(signal_No_DC_1, &ir) + 0x0800); // Filtrado IIR.
        //LED_1_SetLow();
        sendToDAC((uint16_t) signal_DC_1, 0);// Envío de señal original al DAC.
        //sendToDAC((uint16_t)salidaFIR, 1);  // Envío de señal filtrada al DAC.
        sendToDAC((uint16_t)salidaIIR, 1);  // Envío de señal filtrada al DAC.
        
        sendToUART((int16_t) signal_DC_1, (int16_t) salidaFIR); // Envío de datos a UART.
        //sendToUART((int16_t) signal_DC_1, (int16_t) salidaIIR); // Envío de datos a UART.
    } 
}
/**
 End of File
*/


