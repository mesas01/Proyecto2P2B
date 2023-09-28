/**
  Archivo de encabezado: funciones.h

  Descripción:
    Este archivo es un archivo de encabezado que contiene las declaraciones de funciones y estructuras 
    que se utilizarán en el archivo funciones.c. Define la interfaz pública para las funciones y estructuras 
    relacionadas con el filtrado de señales.
*/

// Directiva de preprocesador para evitar la inclusión múltiple del archivo.
#ifndef FUNCIONES_H
#define FUNCIONES_H

// Inclusión de bibliotecas necesarias.
#include <stdint.h>

// Definición del orden del filtro FIR.
#define N 16

// Declaración de un array externo. Este array se define en otro archivo (probablemente funciones.c) 
// y se utiliza para almacenar las últimas entradas del filtro FIR.
extern volatile int x[N];

// Estructura para el filtro IIR de 4to orden.
typedef struct coef_iir_4_ord{
    float num[5];  // Coeficientes del numerador.
    float den[5];  // Coeficientes del denominador.
    float w[5];    // Vector de estados para el filtro IIR.
} coef_iir_4_ord;

// Prototipos de funciones.
long filtrarFIR1(int in);  // Función de filtro FIR.
void inicializar_iir_4_ord(float*num, float*den, float*w, coef_iir_4_ord* ir);  // Función para inicializar el filtro IIR de 4to orden.
float filtrarIIR(float in, coef_iir_4_ord* ir);  // Función de filtro IIR.

#endif // FUNCIONES_H
