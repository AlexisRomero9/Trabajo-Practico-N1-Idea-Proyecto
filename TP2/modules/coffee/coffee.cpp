#include "coffee.h"
#include "arm_book_lib.h"
#include "modules/loadCell/loadCell.h"
#include "modules/temperatureSensor/temperatureSensor.h"


//====================[Declaración de constantes utilizadas]====================
#define BOILING_WATER_TEMPERATURE 100  //Temperatura de hervor del agua                                       
#define FULL_FILTER 25                 //Peso que debe tener el filtro para que se considere lleno
#define FINAL_PREPARATION_TIME 500     //Tiempo de preparación total que va a tener el proceso de preparado de la opción ingresada


typedef enum{
    MILK_POURING_TIME = 200,//Tiempo que se debe verter la leche en el café cortado
    CORTADO_WATER_POURING_TIME = 800,//Tiempo que se debe verter el agua en el café cortado (prueba, no es tiempo real)
    COFFEE_WATER_POURING_TIME = 1000 //Tiempo que se debe verter el agua en el café simple (prueba, no es tiempo real) 
}timesForPreparation;


static float coffeeWeight;             //Variable para determinar el peso actual del filtro de café
static float waterTemperature;         //Variable para determinar la temperatura actual del agua
static unsigned int preparationTime;   //Variable para determinar el tiempo transcurrido de preparación
static int coffeeWaterTime;
static int cortadoWaterTime;
static int cortadoMilkTime;

bool isCoffeeReady()
{
    return preparationTime == FINAL_PREPARATION_TIME;
}

void prepareCoffee()
{
    if (preparationTime <= coffeeWaterTime)
        preparationTime += 5;
}

void prepareCortado()
{
    if (preparationTime <= CORTADO_WATER_POURING_TIME){
        preparationTime += 5;
    }
    else if (preparationTime <= MILK_POURING_TIME){
        preparationTime += 5;
    }
}



void prepareOption(coffeeOption_t receivedOption)
{
    switch(receivedOption)
    {
        case COFFEE:
            prepareCoffee();
        case CORTADO:
            prepareCortado();
    }
}

bool isFilterReady()
{
    return isFilterFull(FULL_FILTER);
}
bool isWaterReady()
{
    return temperatureReached(BOILING_WATER_TEMPERATURE);
}

/*
    En este trabajo práctico no se implementarán estas funciones, ya que no cuento con los materiales
    adecuados para implementar el prototipo y considero que no es crucial para ver el funcionamiento
    del proyecto en el estado actual.
*/

void prepareWater()
{
    //Hervir el agua
}

void prepareFilter()
{
    //Verter el café
}



