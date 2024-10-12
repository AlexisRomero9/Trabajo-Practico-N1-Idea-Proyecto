//====================[Librerias utilizadas]====================
#include "mbed.h"
#include "arm_book_lib.h"
#include "modules/display/display.h"
#include "modules/statechart/statechart.h"
#include "modules/menu/menu.h"
#include "modules/cupDetection/cupDetector.h"


//====================[Declaración e inicialización de variables]====================

int main()
{
    initCoffeeMachine();
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER); 

    while (true) {
        coffeeMachineWorking();
    }
}

