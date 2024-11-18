#include "coffee.h"
#include "arm_book_lib.h"
#include "modules/loadCell/loadCell.h"
#include "modules/temperatureSensor/temperatureSensor.h"


//====================[Declaración de constantes utilizadas]====================
#define BOILING_WATER_TEMPERATURE 100  //Temperatura de hervor del agua en °C                                    
#define FULL_FILTER 25                 //Peso en gramos que debe tener el filtro para que se considere lleno
#define FINAL_PREPARATION_TIME 5000   //Tiempo de preparación total que va a tener el proceso de preparado de la opción ingresada

//Pines utilizados en placa NUCLEO F103RB
#define WATER_HEATER_PIN D7     
#define COFFEE_NOZZLE_PIN D6    
#define MILK_BOMB_PIN D5        
#define WATER_BOMB_PIN D4       
#define PWM_NOZZLE_PIN D9

//Configuración del servomotor MG90S utilizado
#define NOZZLE_PERIOD_MS 20
#define OPEN_NOZZLE_DUTY_CYCLE 0.10
#define CLOSE_NOZZLE_DUTY_CYCLE 0.03



static float coffeeWeight;             //Variable para determinar el peso actual del filtro de café
static float waterTemperature;         //Variable para determinar la temperatura actual del agua

static int timesForWaterPouring[] = {5000,4000};    //Tiempos para verter el agua segun la opción elegida
static int timesForMilkPouring[] = {0,1000};        //Tiempos para verter la leche segun la opción elegida

static int preparationTime;                         //Variable para determinar el tiempo transcurrido de preparación
static DigitalOut coffeeNozzle(COFFEE_NOZZLE_PIN);  //Pin utilizado para habilitar el relé de la boquilla de café (activa la alimentación del servomotor)
static DigitalOut waterBomb(WATER_BOMB_PIN);        //Pin utilizado para habilitar el relé de la bomba para verter el agua
static DigitalOut waterHeater(WATER_HEATER_PIN);    //Pin utilizado para habilitar el relé del calentador de agua
static DigitalOut milkBomb(MILK_BOMB_PIN);          //Pin utilizado par habilitar el relé de la bomba para verter la leche
static PwmOut nozzleSignal(PWM_NOZZLE_PIN);         //Salida del PWM del servomotor
static float dutyCycle;                             
static Ticker preparationTimer;                     
static bool preparationInProcess;
static int chosenOption;

void initPreparationModule()
{
    //El pin en HIGH mantiene desactivado el relé
    waterBomb.write(ON);
    waterHeater.write(ON);
    milkBomb.write(ON);
    coffeeNozzle.write(OFF);
    dutyCycle = CLOSE_NOZZLE_DUTY_CYCLE; //Posición inicial del servomotor
    nozzleSignal.period_ms(NOZZLE_PERIOD_MS);
    nozzleSignal.write(dutyCycle);
    preparationInProcess = false;
    preparationTime = 0;
}


static void turnOnWaterBomb(int time)
{
    preparationInProcess = true;
    waterBomb.write(OFF);
    preparationTimer.attach(&turnOffWaterBomb,std::chrono::milliseconds(time));        
}

static void turnOffWaterBomb()
{
    waterBomb.write(ON);
    preparationTimer.detach();
    preparationTime = timesForWaterPouring[chosenOption-1];
}

static void turnOnMilkBomb(int time)
{
    milkBomb.write(OFF);
    preparationTimer.attach(&turnOffMilkBomb,std::chrono::milliseconds(time));
}

static void turnOffMilkBomb()
{
    milkBomb.write(ON);
    preparationTimer.detach();
    preparationTime += timesForMilkPouring[chosenOption-1];
}


bool isCoffeeReady()
{
    if (preparationTime == FINAL_PREPARATION_TIME)
    {
        preparationInProcess = false;
        return true;
    }
    return false;
}

void prepareCoffee()
{
    if(!preparationInProcess)
    {
        turnOnWaterBomb(timesForWaterPouring[chosenOption-1]);        
    } 
}

void prepareCortado()
{
    if(!preparationInProcess)
    {
        turnOnWaterBomb(timesForWaterPouring[chosenOption-1]); 
    }
    else if (preparationTime == timesForWaterPouring[chosenOption-1])
    {
        turnOnMilkBomb(timesForMilkPouring[chosenOption-1]); 
    }
}



void prepareOption(coffeeOption_t receivedOption)
{
    chosenOption = receivedOption;
    switch(receivedOption)
    {
        case COFFEE:
            prepareCoffee();
            break;
        case CORTADO:
            prepareCortado();
            break;
    }
}

bool isFilterReady()
{
    if (isWeightEqualTo(FULL_FILTER))
    {
        nozzleSignal.write(CLOSE_NOZZLE_DUTY_CYCLE);
        return true;
    }
    return false;
}
bool isWaterReady()
{
    if(temperatureReached(BOILING_WATER_TEMPERATURE)==1)
    {
        waterHeater.write(ON);
        return true;
    }
    return false;
}


void prepareWater()
{
    waterHeater.write(OFF);
}

void prepareFilter()
{
    dutyCycle = OPEN_NOZZLE_DUTY_CYCLE;
    nozzleSignal.write(dutyCycle);
    
}



