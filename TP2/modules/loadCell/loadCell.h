#ifndef __LOAD_CELL_H
#define __LOAD_CELL_H

#include "mbed.h"
#include "HX711.h"


//====================[Declaración de funciones públicas]====================

void initLoadCell(void);
/*
    Inicializa el módulo HX711 y la celda de carga mediante la configuración del offset y la escala, valores
    que fueron determinados anteriormente con un peso de prueba.
*/


bool isFilterFull(int maxWeight);
/*
    Determina si el peso presente en la celda de carga es igual o mayor que el peso pasado por parámetro
*/

#endif