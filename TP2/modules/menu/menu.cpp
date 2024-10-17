#include "menu.h"
#include "modules/display/display.h"
#include "mbed.h"
#include "arm_book_lib.h"
#include "modules/coffee/coffee.h"
#include <string.h>

#define EMPTY_ROW_DISPLAY "                    "

UnbufferedSerial uartUsb(USBTX, USBRX, 9600); //Inicialización de la comunicacion serial

const char* listOfMenuStringsForRow1[MENU_CONFIGURATION_AMOUNT] = {"Ingrese una opcion:","Opción incorrecta, vuelve a intentar",EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY};
const char* listOfMenuStringsForRow2[MENU_CONFIGURATION_AMOUNT] = {"1-Cafe","Las opciones son:","Vertiendo cafe","Calentando el agua","Preparando tu cafe","Tu cafe esta listo","Cafe cancelado"};
const char* listOfMenuStringsForRow3[MENU_CONFIGURATION_AMOUNT] = {"2-Cortado","1-Cafe","Por favor espere","Por favor espere",EMPTY_ROW_DISPLAY,"Disfrute su cafe","Vuelve a presionar"};
const char* listOfMenuStringsForRow4[MENU_CONFIGURATION_AMOUNT] = {EMPTY_ROW_DISPLAY,"2: Cortado",EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY,EMPTY_ROW_DISPLAY,"el boton para salir"};

optionState_t enterOption(coffeeOption_t *receivedOption)
{
    char opcion[1];
    if(uartUsb.readable()){
        uartUsb.read(opcion,1);
        int optionNumber = opcion[0] - '0';
        if (optionNumber == COFFEE)
        { 
            *receivedOption = COFFEE;
            return CORRECT;
        }
        else if (optionNumber == CORTADO)
        {
            *receivedOption = CORTADO;
            return CORRECT;
        }
        else{
            return INCORRECT;
        }
    }
    return EMPTY;
}

void showMenu(menuConfiguration_t option, menuConfiguration_t previousOption)
{

    if (option != previousOption)
    {
        refreshDisplay();

        displayCharPositionWrite ( 0,0 );
        displayStringWrite(listOfMenuStringsForRow1[option]);
        
        displayCharPositionWrite ( 0,1 );
        displayStringWrite(listOfMenuStringsForRow2[option]);
        
        displayCharPositionWrite ( 0,2 );
        displayStringWrite(listOfMenuStringsForRow3[option]);

        displayCharPositionWrite ( 0,3 );
        displayStringWrite(listOfMenuStringsForRow4[option]);
    }
    
}


static void refreshDisplay()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite(EMPTY_ROW_DISPLAY);

    displayCharPositionWrite ( 0,1 );
    displayStringWrite(EMPTY_ROW_DISPLAY);
    
    displayCharPositionWrite ( 0,2 );
    displayStringWrite(EMPTY_ROW_DISPLAY);

    displayCharPositionWrite ( 0,3 );
    displayStringWrite(EMPTY_ROW_DISPLAY);
}
