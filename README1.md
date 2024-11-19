## Definición de Requisitos y Casos de Uso del Trabajo Final de 86.65 Sistemas Embebidos
#### Alexis Romero Espinoza - Padrón: 103942

#### 2do Cuatrimestre 2024

# Cafetera automática

## 1 - Marco del proyecto

Para la elección del proyecto se buscó desarrollar proyectos los cuales cuenten con una gran variedad de sensores y módulos comúnmente utilizados para aprender acerca de su funcionamiento y utilidades en productos que pueden ayudarnos en el dia a día.

## 2 - Selección del proyecto a implementar

 En principio se discutió la implementación de dos proyectos, la cafetera automática, y un sistema inteligente de iluminación de exteriores, analizando los siguientes aspectos:

- Tiempo de implementación: dado que fue un proyecto que se desarrolla durante la cursada, el tiempo de implementación es de 4 meses como máximo, por lo tanto se asignan puntajes altos a proyectos más cortos que puedan cubrir el tiempo estipulado.
- Disponibilidad del hardware: teniendo en cuenta que los módulos que se utilizan en cada proyecto son módulos relativamente comunes en el mercado, se asigna un puntaje mayor por la cantidad de módulos que necesita cada proyecto
- Utilidad del proyecto: se analiza la utilidad a nivel del aprendizaje obtenido durante el desarrollo del proyecto, el proyecto elegido debe contar en su mayoría con módulos vistos durante el curso.


<table>
  <tr>
    <th>Proyecto</th>
    <th>Peso </th>
    <th>Tiempo de implementación (Peso: 7)</th>
    <th>Disponibilidad del Hardware (Peso: 5)</th>
    <th>Utilidad del proyecto (Peso: 10)</th>
    <th> Suma de puntajes pesados </th>
  </tr>
  <tr>
    <td rowspan="2">Cafetera automática</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">8</td>
    <td style="text-align: center;" rowspan="2">176 </td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">56</td>
    <td style="text-align: center;">40</td>
    <td style="text-align: center;">80</td>
</tr>
<tr>
    <td rowspan="2">Sistema de iluminación de exteriores</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">6</td>
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">6</td>
    <td style="text-align: center;" rowspan="2"> 142 </td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">42</td>
    <td style="text-align: center;">40</td>
    <td style="text-align: center;">60</td>
    
</tr>
</table>

- Sistema de iluminación de exteriores: se le asignó un puntaje de 6 en tiempo de implementación dados los sensores y utilidades que este sistema tiene generalmente, el proyecto puede no ser tan extenso para cubrir el tiempo de cursada. En cuanto a disponibilidad del hardware, los módulos a utilizar son muy comunes y fáciles de conseguir, y por último la utilidad del proyecto se le asignó un puntaje de 6 dado que los módulos a utilizar no son tan variados como se buscaba con el proyecto desde un principio.

- Cafetera automática: en el tiempo de implementación se le asigno un valor de 8 ya que se busca que la cafetera cuenta con gran variedad de funcionalidades utilizando diferentes módulos, lo cual requerirá un tiempo mayor para el desarrollo y pruebas de cada módulo individual. Los módulos a utilizar son fáciles de obtener en el mercado, por eso se le asignó un valor alto a la disponiblidad de hardware, y por último en utilidad del proyecto se asignó un puntaje de 8 dado que cumple con el objetivo principal que se buscaba para el desarrollo del proyecto.

### 2.1 - Propósito del proyecto

El propósito del proyecto es diseñar una cafetera automática que ofrezca en principio la posibilidad de preparar dos opciones de café, las cuales podrán ser seleccionadas a través de una aplicación, permitiendo al usuario controlar la preparación de forma remota. Además, el sistema incluirá la funcionalidad de programar la preparación para una hora específica.

### 2.2 - Alcance del proyecto

El proyecto se desarrolló utilizando la placa NUCLEO-F103RB, donde se desarrollaron las funcionalidades de la cafetera, tales como la detección de la taza mediante un sensor de ultrasonido HC-SR04, una celda de carga para la medición de la cantidad de café molido necesario, un sensor de temperatura para determinar cuando el agua hierve, un servomotor que servirá para verter el café en el filtro, una bomba de agua para verter el agua, un display LCD donde se mostrará en que etapa de la preparación se encuentra, y por último un módulo Wi-Fi para conectar el sistema a un servidor local. 


## 3 - Elicitación de requisitos y casos de uso

### 3.1 - Diagrama de bloques

Una vez definidas las funcionalidades, se representa las conexiones en el siguiente diagrama de bloques

![diagrama_bloques_SE](https://github.com/user-attachments/assets/742baf4a-1311-42fa-b3b2-655f8afe5410)


### 3.2 Análisis de mercado

Se analizan tres opciones de cafeteras automáticas presentes en el mercado que cuentan con Wi-Fi incorporado.

| Característica | Princess 246060 | Instant Solo| Siemens TQ505R09|
|----------------|-----------------|---------|----------------------|
|Pantalla LED|Sí|Sí|Sí|
|Aplicación del celular|Sí|Sí|Sí|
|Opciones de café|1|1|9|
|Jarra de café|Si|No|No|
|Filtro extraible|Sí|Sí|Sí|
|Deposito de café|No|No|Sí|
|Depósito de agua|1,5|1,2|1,7|
|Depósito de leche|No|No|Sí|
|Mantiene caliente el café| Sí| Sí| Sí|
|Molinillo|No|No|Sí|
|Precio|74,63|66,49|539,19|

Nota: Los precios se muestran en euros dado que no todas las cafeteras están disponibles en el país


Los resultados del análisis muestran que los productos presentes en el mercado cuentan con características que incluimos en nuetro proyecto, como es una pantalla, y la aplicación celular, pero también se pueden destacar otras funcionalidades como el molinillo y que se mantenga el café caliente, que son caracteristicas muy útiles en este tipo de productos, las cuales no se implementarán debido al tiempo designado y el diseño de la mecánica que requerirían estas funcionalidades está fuera de los contenidos de la materia y complejizaría el proyecto.

### 3.3 Requerimientos

En la siguiente tabla se muestran los requerimientos del proyecto


<table>
  <tr>
    <th>Grupo</th>
    <th>Req ID</th>
    <th>Descripción</th>

  </tr>
  <tr>
    <td rowspan="6">Firmware</td>
    <td style="text-align: center;">1.1</td> 
    <td style="text-align: center;">Implementación de maquinas de estado</td>
    
  </tr>
  <tr>
    <td style="text-align: center;">1.2</td>
    <td style="text-align: center;">Generación de señal para mover el servomotor</td> 
  </tr>
  <tr>
    <td style="text-align: center;">1.3</td>
    <td style="text-align: center;">Comunicación con módulo Wi-Fi mediante UART</td> 
  </tr>
  
  <tr>
    <td style="text-align: center;">1.4</td>
    <td style="text-align: center;">Procesamiento de datos de los sensores</td> 
  </tr>
  <tr>
    <td style="text-align: center;">1.5</td>
    <td style="text-align: center;">Comunicación con display LCD mediante I2C</td>
    <tr>
    <td style="text-align: center;">1.6</td>
    <td style="text-align: center;">Configuración de Tickers para la temporización de los procesos de preparación</td> 
  </tr>
  </tr>
  <tr>
    <td rowspan="2">Alimentación</td>
    <td style="text-align: center;">2.1</td> 
    <td style="text-align: center;">Proveer 5 V a módulo de relés</td>
  </tr>
  <tr>
    <td style="text-align: center;">2.2</td>
    <td style="text-align: center;">Proveer 5 V a display LCD</td> 
  </tr>
  <tr>
    <td rowspan="3">Sensores</td>
    <td style="text-align: center;">3.1</td> 
    <td style="text-align: center;">Medir el peso especificado de café para el filtro con celda de carga</td>
    
  </tr>
  <tr>
    <td style="text-align: center;">3.2</td>
    <td style="text-align: center;">Medir la temperatura de hervor del agua</td> 
  </tr>
  <tr>
    <td style="text-align: center;">3.3</td>
    <td style="text-align: center;">Detección de la taza mediante sensor de ultrasonido a una distancia de 2 cm</td> 
  </tr>
  <tr>
    <td rowspan="3">Módulo de relés</td>
    <td style="text-align: center;">4.1</td> 
    <td style="text-align: center;">Proveer corriente a bomba de agua</td>
  </tr>
  <tr>
    <td style="text-align: center;">4.2</td>
    <td style="text-align: center;">Proveer corriente a servomotor de la boquilla de café</td> 
  </tr>
  <tr>
    <td style="text-align: center;">4.3</td>
    <td style="text-align: center;">Proveer corriente a dos LEDs de prueba</td> 
  </tr>
  <tr>
    <td rowspan="4">Interfaz</td>
    <td style="text-align: center;">5.1</td> 
    <td style="text-align: center;">Contar con una pantalla LCD que indique el estado actual del proceso</td>
  </tr>
  <tr>
    <td style="text-align: center;">5.2</td>
    <td style="text-align: center;">Mostrar las opciones disponibles</td> 
  </tr>
  <tr>
    <td style="text-align: center;">5.2</td>
    <td style="text-align: center;">Notificar en caso de ingresar una opción incorrecta</td> 
  </tr>
  <tr>
    <td style="text-align: center;">5.3</td>
    <td style="text-align: center;">Notificar que la taza no está en posición en caso de ingresar una opción</td> 
  </tr>
  <tr>
    <td rowspan="3">Aplicación</td>
    <td style="text-align: center;">6.1</td> 
    <td style="text-align: center;">Mostrar las opciónes de café</td>
  </tr>
  <tr>
    <td style="text-align: center;">6.2</td>
    <td style="text-align: center;">Elegir la opción de café</td> 
  </tr>
  <tr>
    <td style="text-align: center;">6.3</td>
    <td style="text-align: center;">Programar un horario para la preparación del café</td> 
  </tr>
  <tr>
    <td rowspan="3">Plazos</td>
    <td style="text-align: center;">7.1</td> 
    <td style="text-align: center;">30 de noviembre entrega del Informe de Avance del Trabajo Final </td>
  </tr>
  <tr>
    <td style="text-align: center;">7.2</td>
    <td style="text-align: center;">7 de diciembre entrega de un breve video mostrando el Trabajo Final en funcionamiento</td> 
  </tr>
  <tr>
    <td style="text-align: center;">7.3</td>
    <td style="text-align: center;">14 de diciembre entrega del Informe Final</td> 
  </tr>
</table>


### 3.3 Casos de uso

A continuación se muestran tres casos de uso, en ellos se puede observar la respuesta esperada del sistema ante ciertos eventos disparadores.

| Elemento del caso de uso | Definición |
| -------------------------|------------|
| Disparador |Se elige una opción de café|
|Precondición|Debe estar la taza en posición|
|Flujo básico|Se procede con la preparación del café|


| Elemento del caso de uso | Definición |
| -------------------------|------------|
| Disparador |Se presiona el botón de cancelar|
|Precondición|La preparación debe estar en proceso|
|Flujo básico|Se procede a detener la preparación y notificar por pantalla que se canceló el café|


| Elemento del caso de uso | Definición |
| -------------------------|------------|
| Disparador |Se retira la taza|
|Precondición|El café debe estar listo|
|Flujo básico|El sistema vuelve a mostrar por pantalla las opciones disponibles|
