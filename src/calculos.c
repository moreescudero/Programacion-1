/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: morena
 */
#include <stdio.h>
#include <stdlib.h>

float calcularPrecioKm(float kilometros, float precioVuelo){
	float resultado;

	resultado=precioVuelo/kilometros;

	return resultado;
}

float calcularBitcoin(float precioVuelo){
	float resultado;
	float precioUnBitcoin;

	precioUnBitcoin=4918527.09;

	resultado= precioVuelo/precioUnBitcoin;

	return resultado;
}



float diferenciaAerolineas(float latam, float aerolineas){
	float resultado;

	resultado=0;

	if(latam>aerolineas)
	{
		resultado= latam-aerolineas;
	}
	else{
		if(aerolineas>latam)
		{
			resultado=aerolineas-latam;
		}
	}
	return resultado;
}

float calcularCredito(float precioVuelo){
	float interes;
	float resultado;

	interes=1.25;

	resultado=precioVuelo*interes;

	return resultado;
}

float calcularDebito(float precioVuelo){
	float resultado;
	float descuento;

	descuento=0.9;

	resultado=precioVuelo*descuento;

	return resultado;
}
