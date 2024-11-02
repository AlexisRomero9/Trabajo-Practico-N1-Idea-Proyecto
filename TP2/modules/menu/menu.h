#ifndef MENU_H
#define MENU_H

#include "modules/coffee/coffee.h"
#define MENU_CONFIGURATION_AMOUNT 7//Se utiliza para saber cuantas configuraciones tengo

typedef enum{
    CORRECT,
    INCORRECT,
    EMPTY
}optionState_t;


typedef enum{
    NORMAL = 0,
    INCORRECT_OPTION,
    PREPARING_FILTER,
    PREPARING_WATER,
    PREPARING_COFFEE,
    COFFEE_READY,
    COFFEE_CANCELLED,
    STARTING
}menuConfiguration_t;

//====================[Declaración de funciones privadas]====================

static void refreshDisplay();
/*
    Función que borra todos los caracteres del display
*/

//====================[Declaración de funciones públicas]====================

void showMenu(menuConfiguration_t option,menuConfiguration_t previousOption);
/*
    Según la configuración recibida por parámetro, muestra el menú correspondiente
*/

optionState_t enterOption(coffeeOption_t *receivedOption);
/*
    Utilizando comunicación serial, se ingresa la opción de café a preparar
*/

#endif