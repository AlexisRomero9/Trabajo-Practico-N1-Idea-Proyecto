#include "loadCell.h"

/*Se utiliza un módulo de un ADC de 24 bit de resolución que permite obtener una mejor medición del peso
en la celda de carga
Especificaciones técnicas:
Rango de tensión de entrada: 2.6 ~ 5.5V
Corriente consumida en uso normal: < 1.5mA
*/

#define HX711_DT_PIN D12   //DT es el pin de Data y se conecta a una entrada digital de la placa
#define HX711_SCK_PIN D11  //SCK es el pin de Clock y habilita la lectura del pin de Data
//Para F103RB utilizo D11 en vez de D13

HX711 loadCellModule(HX711_DT_PIN,HX711_SCK_PIN);

void initLoadCell(void)
{
    loadCellModule.setOffset(8318471); //Será el peso de la base y el filtro
    loadCellModule.setScale(2022.380952);
}


bool isFilterFull(int maxWeight)
{
    return (loadCellModule.getGram() >= maxWeight);
}

