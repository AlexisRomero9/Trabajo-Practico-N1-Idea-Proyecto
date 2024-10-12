#include "temperatureSensor.h"

/*
El sensor de temperatura a utilizar es el LM35, que necesita una tensión de alimentación de 5V, y la tensión de
salida Vout es 1mV/°C.
*/

static AnalogIn temperatureSensorPin(TEMPERATURE_SENSOR_PIN);


static float senseTemperature()
{
    float temperatureVoltage;
    temperatureVoltage = temperatureSensorPin.read();
    return temperatureVoltage*3.3/(0.01);
}

bool temperatureReached(float temperature)
{
    return (senseTemperature() >= 100);
}