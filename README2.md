## Informe de avance  del Trabajo Final de 86.65 Sistemas Embebidos
#### Alexis Romero Espinoza - Padrón: 103942

#### 2do Cuatrimestre 2024

# Cafetera automática

## Cumplimiento de los requerimientos

En la siguiente tabla se muestran los requerimientos del proyecto, indicando para cada uno el estado de situación, con verde se indica que el requerimiento ya se cumplió, con amarillo se indica que todavía no se cumplió pero que se podrá completar, y en rojo los requerimientos que aún no se cumplieron y se tiene dudas de que se podrán cumplir.




<table>
  <tr>
    <th>Grupo</th>
    <th>Req ID</th>
    <th>Descripción</th>

  </tr>
  <tr>
    <td rowspan="6">Firmware</td>
    <td style="text-align: center; background-color: #008f39;" >1.1</td> 
    <td style="text-align: center;background-color: #008f39;">Implementación de maquinas de estado</td>
    
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">1.2</td>
    <td style="text-align: center;background-color: #008f39;">Generación de señal para mover el servomotor</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #FFFF00;">1.3</td>
    <td style="text-align: center;background-color: #FFFF00;">Comunicación con módulo Wi-Fi mediante UART</td> 
  </tr>
  
  <tr>
    <td style="text-align: center;background-color: #008f39;">1.4</td>
    <td style="text-align: center;background-color: #008f39;">Procesamiento de datos de los sensores</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">1.5</td>
    <td style="text-align: center;background-color: #008f39;">Comunicación con display LCD mediante I2C</td>
    <tr>
    <td style="text-align: center;background-color: #008f39;">1.6</td>
    <td style="text-align: center;background-color: #008f39;">Configuración de Tickers para la temporización de los procesos de preparación</td> 
  </tr>
  </tr>
  <tr>
    <td rowspan="2">Alimentación</td>
    <td style="text-align: center;background-color: #008f39;">2.1</td> 
    <td style="text-align: center;background-color: #008f39;">Proveer 5 V a módulo de relés</td>
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">2.2</td>
    <td style="text-align: center;background-color: #008f39;">Proveer 5 V a display LCD</td> 
  </tr>
  <tr>
    <td rowspan="3">Sensores</td>
    <td style="text-align: center;background-color: #008f39;">3.1</td> 
    <td style="text-align: center;background-color: #008f39;">Medir el peso especificado de café para el filtro con celda de carga</td>
    
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">3.2</td>
    <td style="text-align: center;background-color: #008f39;">Medir la temperatura de hervor del agua</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">3.3</td>
    <td style="text-align: center;background-color: #008f39;">Detección de la taza mediante sensor de ultrasonido a una distancia de 2 cm</td> 
  </tr>
  <tr>
    <td rowspan="3">Módulo de relés</td>
    <td style="text-align: center;background-color: #008f39;">4.1</td> 
    <td style="text-align: center;background-color: #008f39;">Proveer corriente a bomba de agua</td>
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">4.2</td>
    <td style="text-align: center;background-color: #008f39;">Proveer corriente a servomotor de la boquilla de café</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">4.3</td>
    <td style="text-align: center;background-color: #008f39;">Proveer corriente a dos LEDs de prueba</td> 
  </tr>
  <tr>
    <td rowspan="4">Interfaz</td>
    <td style="text-align: center;background-color: #008f39;">5.1</td> 
    <td style="text-align: center;background-color: #008f39;">Contar con una pantalla LCD que indique el estado actual del proceso</td>
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">5.2</td>
    <td style="text-align: center;background-color: #008f39;">Mostrar las opciones disponibles</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #008f39;">5.2</td>
    <td style="text-align: center;background-color: #008f39;">Notificar en caso de ingresar una opción incorrecta</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #FFFF00;">5.3</td>
    <td style="text-align: center;background-color: #FFFF00;">Notificar que la taza no está en posición en caso de ingresar una opción</td> 
  </tr>
  <tr>
    <td rowspan="3">Aplicación</td>
    <td style="text-align: center;background-color: #FFFF00;">6.1</td> 
    <td style="text-align: center;background-color: #FFFF00;">Mostrar las opciónes de café</td>
  </tr>
  <tr>
    <td style="text-align: center;background-color: #FFFF00;">6.2</td>
    <td style="text-align: center;background-color: #FFFF00;">Elegir la opción de café</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #FFFF00;">6.3</td>
    <td style="text-align: center;background-color: #FFFF00;">Programar un horario para la preparación del café</td> 
  </tr>
  <tr>
    <td rowspan="3">Plazos</td>
    <td style="text-align: center;background-color: #008f39;">7.1</td> 
    <td style="text-align: center;background-color: #008f39;">30 de noviembre entrega del Informe de Avance del Trabajo Final </td>
  </tr>
  <tr>
    <td style="text-align: center;background-color: #FFFF00;">7.2</td>
    <td style="text-align: center;background-color: #FFFF00;">7 de diciembre entrega de un breve video mostrando el Trabajo Final en funcionamiento</td> 
  </tr>
  <tr>
    <td style="text-align: center;background-color: #FFFF00;">7.3</td>
    <td style="text-align: center;background-color: #FFFF00;">14 de diciembre entrega del Informe Final</td> 
  </tr>
</table>
