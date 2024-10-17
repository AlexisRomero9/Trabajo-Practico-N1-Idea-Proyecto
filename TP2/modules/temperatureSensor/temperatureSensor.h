#ifndef __TEMPERATURE_SENSOR_H
#define __TEMPERATURE_SENSOR_H

#include "mbed.h"

#define MAX_TEMPERATURE 100 //Temperatura de hervor del agua
#define TEMPERATURE_SENSOR_PIN A0 //PF_12


//====================[Declaración de funciones privadas]====================
static float senseTemperature();
/*
    Devuelve el valor de la temperatura en °C.
*/

//====================[Declaración de funciones públicas]====================

bool temperatureReached(float temperature);
/*
    Función que determina si la temperatura actual es mayor o igual a la temperatura recibida por parámetro.
*/

#endif

