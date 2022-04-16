/*Alumna: Morena Escudero  Division: 1°F  Trabajo Práctico: 1 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);

	int respuesta;
	float latamIngresados, aerolineasIngresados, kilometrosIngresados;
	float diferencia;
	float precioKmLatam;
	float precioKmAero;
	float bitcoinLatam;
	float bitcoinAero;
	float costoDebitoLatam;
	float costoDebitoAero;
	float costoCreditoLatam;
	float costoCreditoAero;
	int flagCalcularCostos;

	kilometrosIngresados=0;
	latamIngresados=0;
	aerolineasIngresados=0;

	do{
		respuesta = mostrarMenu(kilometrosIngresados, latamIngresados, aerolineasIngresados);
		switch(respuesta)
		{
			case 1:
				kilometrosIngresados=ingresarDato("Ingresar kilometraje: ","ERROR, por favor ingrese un numero mayor a 0 para el kilometraje: ");
			break;
			case 2:
				latamIngresados=ingresarDato("Ingrese precio de Latam: ","ERROR, por favor ingrese un numero mayor a 0 para el precio del vuelo con Latam: ");
				aerolineasIngresados=ingresarDato("Ingrese precio de Aerolineas: ", "ERROR, por favor ingrese un numero mayor a 0 para el precio del vuelo con Aerolineas Argentinas: ");
			break;
			case 3:
				respuesta=calcularCostos(&flagCalcularCostos,respuesta,kilometrosIngresados,latamIngresados,aerolineasIngresados,&costoDebitoLatam,&costoDebitoAero,&costoCreditoLatam,&costoCreditoAero,&bitcoinLatam,&bitcoinAero,&precioKmLatam,&precioKmAero,&diferencia);
			break;
			case 4:
				respuesta=informarResultados(flagCalcularCostos, kilometrosIngresados,latamIngresados,aerolineasIngresados,costoDebitoLatam,costoDebitoAero,costoCreditoLatam,costoCreditoAero,bitcoinLatam,bitcoinAero,precioKmLatam,precioKmAero,diferencia);
			break;
			case 5:
				respuesta=cargaForzada(respuesta);
			break;
			case 6:
				printf("Finalizando el programa...");
			break;
		}
	}while(respuesta!=6);


	return 0;
}
