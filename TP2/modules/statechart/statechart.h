#ifndef __STATECHART_H
#define __STATECHART_H

#include "mbed.h"

typedef enum{
    WAITING_FOR_CUP,
    READY_TO_PREPARE,
    POURING_COFFEE,
    BOILING_WATER,
    PREPARING_OPTION,
    READY,
    CANCELLED
}coffeeStates_t;

typedef enum{
    CONTINUE,
    CANCEL
}coffeeTransitions_t;

//====================[Declaración de funciones privadas]====================

static void cancelProcess();

//====================[Declaración de funciones públicas]====================

void initCoffeeMachine();
/*
    Inicializa la maquina de estados en un estado inicial y la configuración de los sensores a utilizar
*/

void coffeeMachineWorking();
/*
    Función que se encarga de determinar los estados de la maquina y qué función debe llamarse en cada uno
*/




#endif