#include "cupDetector.h"

//Se utiliza el sensor ultrasonico HC-SR04, las especificaciones técnicas son:

/*
Tensión: 5V
Corriente: 15mA
Frecuencia: 40kHz
Rango Max: 4m
Rango Min: 2cm
Precisión: 3mm
*/

// Umbral de distancia para detectar la taza (en cm)
#define DETECTION_THRESHOLD 5.0f //El detector estará a 5cm de la taza

#define SOUND_SPEED 0.0343f // cm/us (velocidad del sonido en aire), para calcular la distancia del objeto al sensor

DigitalOut triggerPin(CUP_DETECTOR_TRIGGER_PIN);
InterruptIn echoPin(CUP_DETECTOR_ECHO_PIN); //Se configura el echoPin como una Interrupción
Timer timer; // Timer para medir el tiempo del eco


volatile float echoStartTime = 0.0f;
volatile float echoEndTime = 0.0f;
volatile bool echoReceived = false;

void startEcho()
{
    timer.reset(); // Reinicia el timer cuando el echo empieza
    timer.start();
}

void endEcho()
{
    timer.stop(); // Detiene el timer cuando el echo termina
    echoEndTime = timer.elapsed_time().count(); // Tiempo en microsegundos
    echoReceived = true;
}

void initDetector(void)
{
    triggerPin.write(OFF); // Asegura que el trigger esté apagado inicialmente
    echoPin.mode(PullDown); // Activa un pull-down para el pin de echo
    
    // Configuración de las interrupciones
    echoPin.rise(&startEcho); // Interrupción cuando el eco empieza (HIGH)
    echoPin.fall(&endEcho);   // Interrupción cuando el eco termina (LOW)
}

void sendTriggerPulse(void)
{
    // Enviar pulso de 10 us al trigger
    triggerPin.write(ON);
    wait_us(10); // Pulso de 10 microsegundos
    triggerPin.write(OFF);
}

bool detectCup(void)
{
    
    sendTriggerPulse();
    
    if (echoReceived) {
        echoReceived = false; // Reiniciar la flag de eco recibido
        
        
        // Calcular la distancia en centímetros
        float distance = (echoEndTime * SOUND_SPEED) / 2.0f;
        
        // Comparar con el umbral para detectar la taza
        if (distance < DETECTION_THRESHOLD) {
            return true; // Se detectó la taza
        }
    } 
    return false; // No se ha detectado la taza
}