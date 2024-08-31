Título: Cafetera automática

Alumno: Romero Espinoza Alexis

Objetivo: Desarrollar un sistema que me permite hacer un café de manera rápida y de calidad

Descripción: 


La propuesta del primer proyecto es el diseño de una cafetera automática, que contará con varios sensores para determinar en el momento que se apoya la taza sobre la misma,
y en ese instante comenzará a funcionar el programa, mostrando un menú para la elección del café, y una vez elegido, se mostrará por pantalla en que instancia del proceso se encuentra.
Durante el proceso de hacer el cafe, se cuenta con unsensor para pesar el café que se vierte sobre el filtro, un sensor de temperatura para el agua,
y otro sensor para medir la cantidad de agua que se vierte a la taza. Por otra parte, contará con tres sensores para determinar si
se está quedandos sin agua, sin cafe o sin leche. Al terminar se encenderá un LED indicando que terminó de hacer el café.
 Por último en caso de querer cancelar el café, esta opción se implementará mediante un botón e iluminará otro LED, y al presionar nuevamente este boton se vuelve a empezar


En cada paso se indicará mediante el puerto serie el estado del proceso:
-Calentando el agua
-Vertiendo café
-Vertiendo agua
-Vertiendo leche (en caso de cortado o con leche)
-Café listo

Plataforma de desarrollo: NUCLEO-F429ZI

Periféricos a utilizar:

USER BUTTONS(3): Al presionar se elegirá que café preparar, entre café negro, café cortado o café con leche
USER BUTTON: Al presionar se cancela el proceso
ANALOG IN 1: Se utiliza para leer el peso al apoyar una taza
ANALOG IN 2: Se utiliza para leer el peso del recipiente que contiene el cafe a utilizar
ANALOG IN 3: Se utiliza para leer el peso de la cantidad de cafe en el filtro
ANALOG IN 4: Se utiliza para leer el peso de la cantidad de agua en el recipiente
ANALOG IN 5: Se utiliza para leer el peso de la cantidad de leche en el recipiente
ANALOG IN 6: Se utiliza para leer la temperatura del agua
UART: Se utiliza para enviar información de estado del sistema a la PC
LED1: Se utiliza para indicar que el café está listo
LED2: Se utiliza para indicar que el sistema cancelo el proceso anterior
