# Trabajo Prática N1 - Idea Proyecto


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

En cada paso se indicará mediante el puerto serie el estado del proceso:
- Calentando el agua
- Vertiendo café
- Vertiendo agua
- Vertiendo leche (en caso de cortado)
- Café listo

### Plataforma de desarrollo: NUCLEO-F429ZI

### Periféricos a utilizar:

- USER BUTTON: Al presionar se cancela el proceso
- ANALOG IN 1: Se utiliza para leer el peso de la cantidad de cafe en el filtro
- ANALOG IN 2: Se utiliza para leer la temperatura del agua
- UART: Se utiliza para enviar información de estado del sistema a la PC
- LED1: Se utiliza para indicar que el café está listo
- LED2: Se utiliza para indicar que el sistema cancelo el proceso anterior


### Diagrama en bloques
  ![tp01-embebidos drawio](https://github.com/user-attachments/assets/736681c7-afa1-4870-8eff-f4d4d85f3bfb)


