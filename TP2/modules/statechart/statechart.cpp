#include "statechart.h"
#include "modules/menu/menu.h"
#include "modules/coffee/coffee.h"
#include "modules/loadCell/loadCell.h"
#include "modules/cupDetection/cupDetector.h"


volatile coffeeStates_t coffeeState;            //Determina el estado actual de la maquina de estados
static InterruptIn cancelButton(BUTTON1);       //Botón utilizado para cancelar la preparación


void initCoffeeMachine()
{
    coffeeState = WAITING_FOR_CUP;
    cancelButton.fall(&cancelProcess);
    initDetector(); 
    initLoadCell(); 
}

void coffeeMachineWorking()
{
    static coffeeOption_t chosenCoffeeOption;
    static menuConfiguration_t menuConfig; //Variable que se utiliza para determinar que menú debe mostrarse por el display
    static optionState_t option = EMPTY;
    
    switch(coffeeState)
    {
        case WAITING_FOR_CUP:
        {
            if (detectCup()){
                coffeeState = READY_TO_PREPARE;
            }
            menuConfig = STARTING;
            break;
        }
        case READY_TO_PREPARE:
        {
            showMenu(NORMAL,menuConfig);
            menuConfig = NORMAL;
            option = enterOption(&chosenCoffeeOption);
            switch(option)
            {
                case CORRECT:
                {
                    coffeeState = POURING_COFFEE;                    
                    prepareFilter();
                    break;
                }
                case INCORRECT:
                {
                    menuConfig = INCORRECT_OPTION;
                    break;
                }
                case EMPTY:
                    break;
            }
            break;
        }
        case POURING_COFFEE:
        {
            showMenu(PREPARING_FILTER,menuConfig);
            menuConfig = PREPARING_FILTER;
            if (isFilterReady()){
                coffeeState = BOILING_WATER;
                prepareWater();
            }
            break;
        }

        case BOILING_WATER:
        {
            showMenu(PREPARING_WATER,menuConfig);
            menuConfig = PREPARING_WATER;
            if (isWaterReady()){
                coffeeState = PREPARING_OPTION;
            }
            break;
        }
            
        case PREPARING_OPTION:
        {
            prepareOption(chosenCoffeeOption);
            showMenu(PREPARING_COFFEE,menuConfig);
            menuConfig = PREPARING_COFFEE;
            if (isCoffeeReady())
            {
                coffeeState = READY;
            }
            break;
        }
        case READY:
        {
            showMenu(COFFEE_READY,menuConfig);
            menuConfig = COFFEE_READY;
            if (!detectCup()){
                coffeeState = WAITING_FOR_CUP;
            }
            wait_us(7000000);
            break;
        }
        case CANCELLED:
        {
            showMenu(COFFEE_CANCELLED,PREPARING_COFFEE);
            wait_us(2000000); //Muestro un tiempo que el cafe fue cancelado, y espero a que se presione el botón nuevamente
            break;
        }
    }
}


static void cancelProcess()
{
    if (coffeeState != WAITING_FOR_CUP && coffeeState != READY)
    {
        coffeeState = CANCELLED;
    }
    else if (coffeeState == CANCELLED){
        coffeeState = WAITING_FOR_CUP; //Se presiona nuevamente el botón de cancelar para volver al estado inicial
    }
}