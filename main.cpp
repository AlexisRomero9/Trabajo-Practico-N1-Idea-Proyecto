//====================[Librerias utilizadas]====================
#include "mbed.h"
#include "arm_book_lib.h"

//====================[Declaración de constantes utilizadas]====================
#define COFFEE_WATER_POURING_TIME 1000 //Tiempo que se debe verter el agua en el café simple (prueba, no es tiempo real)
#define CORTADO_WATER_POURING_TIME 800 //Tiempo que se debe verter el agua en el café cortado (prueba, no es tiempo real)
#define MILK_POURING_TIME 200 //Tiempo que se debe verter la leche en el café cortado
#define COFFEE '1'
#define CORTADO '2'
#define POTENTIOMETER_TEMP_READY 0.7 // El valor de la entrada analógica que debe alcanzar para considerar el agua hirviendo
                                     // el valor dado es aleatorio, fue dado como prueba, esto debe ser pasado a grados cuando
                                     //se utilice el sensor de temperatura.
#define POTENTIOMETER_COFFEE_READY 0.3 //El valor de entrada analógica que debe alcanzar la celda de carga para que el filtro 
                                       // esté lleno, el valor fue dado como prueba.
#define DELAY_TIMESTEP 50 //Tiempo que se agrega en cada iteración del preparado del café para evitar código bloqueante durante el delay


//====================[Declaración e inicialización de variables]====================
unsigned int coffeeState; //Estado del proceso de preparación
UnbufferedSerial uartUsb(USBTX, USBRX, 115200); //Inicialización de la comunicacion serial
DigitalIn cancelButton(D2); //Botón utilizado para cancelar la preparación
DigitalOut cancelledCoffee(LED1); //Led que se enciende cuando el café fue cancelado


//====================[Prototipos de funciones utilizadas]====================
void showMenu(char *receivedOption);
    /*
        Muestra el menú mediante comunicación serial, donde se mostrarán las opciones de café disponibles,
        mientras no se ingrese una opción correcta, se seguirá mostrando el menú
    */

void prepareIngredients();
    /*
        Se preparan los ingredientes necesarios para una posterior preparación del café elegido,
        se utilizan sensores (potenciometros) para medir la temperatura del agua, que debe hervir, y
        el peso del café al abrir la boquilla. Se muestra por el monitor serial el estado en que se
        encuentra, durante la ejecución de cada paso se chequea el estado del café, en caso de que sea
        cancelado.
    */


void prepareOption(char receivedOption);
    /*
        Se invoca a la función correspondiente a la opción ingresada
    */


void prepareCoffee();
    /*
        En la preparación del café simple, solo se debe verter el agua en el filtro, por lo cual se especifica
        un tiempo mediante una constante y delays que permitan chequear si no se cancelo la preparación.
    */
void prepareCortado();
    /*
        Se debe tener dos procesos, el primero vierte el agua en el filtro durante un tiempo determinado, una vez
        finalizado, se procede a verter leche en el café. Al estar diseñado para una misma taza, el tiempo del agua
        es menor al del café simple, teniendo en cuenta que se debe agregar leche. En está función también se tiene 
        en cuenta la posible cancelación de la preparación
    */

void checkCoffeeState();
    /*
        En caso de que el botón cancelButton esté en ON, se procede a cancelar el café y detener cualquier proceso
        en el que se encuentre.
    */


//====================[Estados que puede tomar la preparación del café]====================
typedef enum{
    READY_TO_PREPARE,
    PREPARING,
    CANCELED,
    READY
}coffeeStates;



int main()
{
    
    cancelButton.mode(PullDown);

    char receivedOption;

    coffeeState = READY_TO_PREPARE; //Se inicializa la cafetera lista para preparar el primer café

    while (true) {
        showMenu(&receivedOption);
        prepareIngredients();
        prepareOption(receivedOption);
    }
}


void showMenu(char *receivedOption)
{
    if (coffeeState == READY){
        uartUsb.write("El cafe está listo\n",2);
        delay(1500);
        coffeeState = READY_TO_PREPARE;
    }
    if (coffeeState == CANCELED ){
        while (cancelButton == ON){
            delay(100);
        }
    }
    if (coffeeState == READY_TO_PREPARE){
        cancelledCoffee = OFF;
        bool incorrectOption = true;
        *receivedOption = '\0';
        uartUsb.write( "Elija una opcion\r\n", 18 );
        uartUsb.write( "1-Cafe\r\n",8);
        uartUsb.write( "2-Cortado\r\n",11);
        uartUsb.write( "Ingrese el numero: \r\n",20);
        while(incorrectOption){
            uartUsb.read(receivedOption,1);
            uartUsb.write( "\n",1);
            if((*receivedOption) == COFFEE){
                incorrectOption = false;
                coffeeState = PREPARING;
            }
            else if((*receivedOption) == CORTADO){
                incorrectOption = false;
                coffeeState = PREPARING;
            }
            else{
                uartUsb.write("La opcion ingresada es incorrecta, vuelve a intentar\r\n",56);
                uartUsb.write( "Ingrese el numero: \r\n",20);
            }
        }
    }

}


void prepareIngredients()
{
    AnalogIn temperatureSensor(A0);
    AnalogIn loadCell(A1);
    float potentiometerLoadCell;
    float potentiometerTemperature = temperatureSensor.read();

    while (potentiometerTemperature < POTENTIOMETER_TEMP_READY && coffeeState == PREPARING)
    {
        delay(300);
        potentiometerTemperature = temperatureSensor.read();
        uartUsb.write("Calentando agua\n",14);
        checkCoffeeState();
    }

    potentiometerLoadCell = loadCell.read();

    while (potentiometerLoadCell < POTENTIOMETER_COFFEE_READY && coffeeState == PREPARING)
    {
        delay(300);
        potentiometerLoadCell = loadCell.read();
        uartUsb.write("Vertiendo café\n",14);
        checkCoffeeState();
    }

}

void prepareOption(char receivedOption)
{
    checkCoffeeState();
    if (receivedOption == COFFEE){
        prepareCoffee();
    }
    if (receivedOption == CORTADO){
        prepareCortado();
    }
}


void prepareCoffee()
{
    unsigned int delay_water = 0;
    
    while (coffeeState == PREPARING && delay_water < COFFEE_WATER_POURING_TIME){
        uartUsb.write("Vertiendo agua\n",14);
        delay_water += DELAY_TIMESTEP;
        delay(delay_water);
        checkCoffeeState();
    }
    coffeeState = READY;
}


void prepareCortado(){
    unsigned int delay_water = 0;
    unsigned int delay_milk = 0;
    checkCoffeeState();
    while(coffeeState == PREPARING){
        if (delay_water < CORTADO_WATER_POURING_TIME){
            uartUsb.write("Vertiendo agua\n",14);
            delay_water += DELAY_TIMESTEP;
            delay(delay_water);
            checkCoffeeState();
        }
        else if(delay_milk < MILK_POURING_TIME){
            uartUsb.write("Vertiendo leche\n",14);
            delay_milk += DELAY_TIMESTEP;
            delay(delay_milk);
            checkCoffeeState();
        }
        else{
            coffeeState = READY;
        }
        
    }
}


void checkCoffeeState()
{
    if (cancelButton == ON){
        coffeeState = CANCELED;
        cancelledCoffee = ON;
        uartUsb.write("El café fue cancelado\n",23);
    }
}