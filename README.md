# Trabajo Prática N°2 - Idea Proyecto


**Título**: Cafetera automática

**Alumno**: Romero Espinoza Alexis

**Objetivo**: Desarrollar un sistema que me permite hacer un café de manera rápida y de calidad

## Descripción: 


La propuesta del primer proyecto es el diseño de una cafetera automática, que al iniciar mostrará un menú para la elección del café, y una vez elegido, las etapas de la preparación del café elegido se mostrarán por pantalla.
Durante el proceso de hacer el cafe, se cuenta con un sensor para pesar el café que se vierte sobre el filtro, un sensor de temperatura para el agua. Al terminar se encenderá un LED indicando que terminó de hacer el café.
 Por último en caso de querer cancelar el café, esta opción se implementará mediante un botón e iluminará otro LED, y al presionar nuevamente este boton se vuelve a empezar.

Al iniciar, se deberá ingresar por teclado la opción a elegir:
1- Café negro
2- Café cortado

En cada paso se indicará mediante un display LCD el estado del proceso:
- Calentando el agua
- Vertiendo café
- Preparando el café
- Café listo
- Café cancelado (en caso de presionar el botón de cancelar)

### Plataforma de desarrollo: NUCLEO-F429ZI

### Periféricos a utilizar:

- USER BUTTON: Al presionar se cancela el proceso.
- Sensor de temperatura LM35: Utilizado para sensar la temperatura del agua.
- Celda de carga + Amplificador ADC HX711: Utilizado para sensar el peso del café en el filtro.
- Sensor ultrasónico HC-SR04: Utilizado para sensar si la taza se encuentra en la posición para empezar el proceso.
- Display LCD: Utilizado para mostrar el menú y los estados del proceso de preparación del café.
- UART: Se ingresa la opción del café a preparar.


### Diagrama en bloques
  
![tp02-embebidos](https://github.com/user-attachments/assets/16a7e156-0a04-48e1-8d85-3d2eb6ef1db4)

### Desarrollo del código para TP1

Es un primer acercamiento al modelo final, donde se utilizaron solamente dos entradas analógicas, que se simularon con potenciómetros, que serán reemplazadas posteriormente con los sensores correspondientes. Para el desarrollo del menú, se implementó mediante comunicación serial, y el ingreso de las opciones mediante teclado. El código que implementa el menú es código bloqueante, ya que no sale de la función hasta que se ingrese una opción correcta. Una vez ingresada la opción correcta, se procede a preparar los ingredientes para la preparación del café elegido. Consta de dos pasos, el primero es hervir el agua, para ello se utiliza una de las entradas analógicas, simulando el futuro sensor de temperatura, que se encuentra sensando la temperatura hasta llegar a los 100°C, es decir hasta que hierva, mientras tanto, se chequea constantemente que la preparación no haya sido cancelada durante este proceso mediante un botón designado para esto. El valor que debe tomar la entrada analógica definido en el código no está definido para un sensor en especifico, solamente es un valor de prueba por el momento.
Luego de que termina de hervir el agua, procede a verter el café en el filtro, el cual contará con una celda de carga que sensará un peso determinado de café que debe tener el filtro. Una vez finalizada la preparación, se procede a verter el agua y/o leche, dependiendo de la opción elegida durante un tiempo determinado. Al finalizar el proceso, se comunica que el café está listo, y se vuelve a consultar por el ingreso de la opción de café.
Durante el código hay partes que son código bloqueante, las cuales serán implementadas con maquinas de estado, o de forma diferente para evitar este problema.

### Desarrollo del código para TP2

En esta segunda parte del trabajo, se utilizaron los sensores que fueron simulados en la entrega previa. Se utilizó un sensor de temperatura LM35, una celda de carga de 1kg con un amplificador ADC HX711, y se incorporó un display LCD y un sensor ultrasónico para la detección de la taza. 
El código original fue modularizado en distintas carpetas según su funcionalidad, y se diseño una maquina de estados del proceso de preparación de la maquina de café. Para el desarrollo de la misma, se utilizó la instrucción "switch" para determinar las funciones a realizar dependiendo del estado de la maquina.
Los valores utilizados para el sensado de temperatura y peso son los correspondientes a los valores que se utilizarían en una cafetera real, mientras que el tiempo de preparación es un valor muy corto para lo que llevaría hacer el café pero se definió de esa manera para no entorpecer las pruebas realizadas durante todo el desarrollo de este proyecto. Por otra parte, en el código hay funciones que no tienen funcionalidad, y que se implementarán en una próxima entrega, tales como prepareWater() y prepareFilter(), ya que estas funciones requieren una acción que en estos momentos no se puede realizar, y que se implementarán con la adición de un motor DC en el caso de la función del filtro, y la función del agua todavia no tengo claro como se implementará.
Otro detalle es el uso de comunicación serie para el ingreso de la opción, resulta algo incómodo, y en la próxima entrega se adicionará un teclado matricial para prescindir de una computadora, como fue este caso.

### Video demostración del TP2

https://drive.google.com/drive/folders/10vrW4IEvL2-kKUzHC8Ln_N-m4azOCo20?usp=drive_link

### Desarrollo del código para TP3

Para la tercera parte de este trabajo práctico se agregaron las funcionalidades para verter el cafe, el agua y la leche. Para verter el café molido, se simuló con un servomotor la apertura y cierre de la boquilla por la cual se vierte el café. Se configuró con una señal PWM para determinar el ángulo que debe moverse el servomotor en caso de abrir o cerrar la boquilla. En los casos de verter liquidos, se utilizarán unas mini bombas de agua de 5 V, de las cuales dispongo pero hubo problemas en las pruebas por lo cual no se utilizaron en el video de demostración para evitar cualquier incoveniente con la placa o los otros dispositivos utilizados. Se utilizó un módulo de relés que servirá para brindarle la corriente necesaria al servomotor, las bombas y el calentador de agua en caso de implementarlo en una futura entrega.
El tiempo que debe verter cada liquido se mide utilizando la clase Ticker, que permite ejecutar una función dada una vez que se cumpla determinado tiempo, esto nos evita utilizar delays bloqueantes y poder continuar con la ejecución del programa principal. Una vez cumplido el tiempo, se ejecuta la función, en este caso se apagan las bombas.

### Video demostración del TP3

Se encuentra en el mismo link que el video demostración del TP2

