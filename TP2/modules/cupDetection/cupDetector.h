#ifndef __CUP_DETECTOR_H
#define __CUP_DETECTOR_H

#include "mbed.h"
#include "arm_book_lib.h"


#define CUP_DETECTOR_TRIGGER_PIN A1 //PC_1
#define CUP_DETECTOR_ECHO_PIN A2   //PC_0


//====================[Declaración de funciones privadas]====================
static void startEcho();
/*
    La función inicializa el timer cuando se detecta el flanco ascendente del pin Echo.
*/
static void endEcho();
/*
    Apaga el timer cuando detecta la interrupción del flanco descendente del pin Echo, y calcula el tiempo.
*/
static void sendTriggerPulse(void);
/*
    Se envia un pulso de 10us al pin de Trigger, y la respuesta será detectada por el pin Echo en caso de haber
    un objeto enfrente.
*/

//====================[Declaración de funciones públicas]====================

void initDetector(void);
/*
    Inicialización de los pines a utilizar y de las interrupciones del sensor
*/
bool detectCup(void);
/*
    Determina si hay un objeto en la posición de la taza
*/




#endif