/*
 * funciones.c
 *
 *  Created on: 5 abr. 2022
 *      Author: morena
 */

#include <stdio.h>
#include <stdlib.h>
#include"calculos.h"
#include"validaciones.h"

int mostrarMenu(float kilometros, float latam, float aerolineas){
	int respuesta;


	if(kilometros==0&&latam==0&&aerolineas==0)
	{
		printf("Elija una opci%cn.\n",243);
		printf("1. Ingresar kil%cmetros: (km = x)\n", 243);
		printf("2. Ingresar precio de vuelos (Aerolineas = y, Latam = z)\n");
		printf("3. Calcular todos los costos.\n");
		printf("4. Informar resultados.\n");
		printf("5. Carga forzada de datos.\n");
		printf("6. Salir.");
	}
	else{
		if(kilometros==0)
		{
			printf("Elija una opci%cn.\n",243);
			printf("1. Ingresar kil%cmetros: (km = x)\n", 243);
			printf("2. Ingresar precio de vuelos (Aerolineas: $%.2f y Latam: $%.2f)\n", aerolineas, latam);
			printf("3. Calcular todos los costos.\n");
			printf("4. Informar resultados.\n");
			printf("5. Carga forzada de datos.\n");
			printf("6. Salir.");
		}
		else{
			if(latam==0&&aerolineas==0)
			{
				printf("Elija una opci%cn.\n",243);
				printf("1. Ingresar kil%cmetros: %.2f Km\n", 243, kilometros);
				printf("2. Ingresar precio de vuelos (Aerolineas = y, Latam = z)\n");
				printf("3. Calcular todos los costos.\n");
				printf("4. Informar resultados.\n");
				printf("5. Carga forzada de datos.\n");
				printf("6. Salir.");
			}
			else{
				printf("Elija una opci%cn.\n",243);
				printf("1. Ingresar kil%cmetros: %.2f Km\n", 243, kilometros);
				printf("2. Ingresar precio de vuelos (Aerolineas: $%.2f y Latam: $%.2f)\n", aerolineas, latam);
				printf("3. Calcular todos los costos.\n");
				printf("4. Informar resultados.\n");
				printf("5. Carga forzada de datos.\n");
				printf("6. Salir.");
			}
		}

	}

	scanf("%d", &respuesta);

	respuesta=validarMenu(respuesta);

	return respuesta;
}

float ingresarDato(char mensaje[], char mensajeError[]){
	float datoIngresado;

	printf("%s", mensaje);
	scanf("%f", &datoIngresado);

	datoIngresado=validarDato(datoIngresado, mensajeError);

	return datoIngresado;
}

int informarResultados(int flagCalcularCostos,float kilometros,float latam,float aerolineas,float costoDebitoLatam,float costoDebitoAero,float costoCreditoLatam,float costoCreditoAero,float bitcoinLatam,float bitcoinAero,float precioKmLatam,float precioKmAero,float diferencia){
	int retorno;

	if(flagCalcularCostos==1)
	{
		printf("Kil%cmetros ingresados: %.2f Km",243,kilometros);
		printf("\nLatam: $%.2f ", latam);
		printf("\na) Precio con tarjeta de d%cbito: $%.2f",233,costoDebitoLatam);
		printf("\nb) Precio con tarjeta de cr%cdito: $%.2f",233,costoCreditoLatam);
		printf("\nc) Precio pagando con bitcoin: %f BTC", bitcoinLatam);
		printf("\nd) Precio unitario: $%.2f", precioKmLatam);
		printf("\n\nAerolineas: $%.2f",aerolineas);
		printf("\na) Precio con tarjeta de d%cbito: $%.2f",233,costoDebitoAero);
		printf("\nb) Precio con tarjeta de cr%cdito: $%.2f",233,costoCreditoAero);
		printf("\nc) Precio pagando con bitcoin: %f BTC", bitcoinAero);
		printf("\nd) Precio unitario: $%.2f",precioKmAero);
		printf("\n\nLa diferencia de precio es: $%.2f", diferencia);

		printf("\n\nSi desea finalizar el programa presione 1, si desea ingresar nuevos datos presione cualquier tecla. ");
		scanf("%d",&retorno);
		switch(retorno)
		{
			case 1:
				retorno=6;
				printf("Finalizando el programa...");
			break;
			default:
				retorno=1;
			break;
		}
	}
	else{
		printf("ERROR, para informar resultados primero necesita calcular costos.\nPresione cualquier tecla para volver al menu principal");
		scanf("%d",&retorno);
		retorno=1;
	}

	return retorno;
}

int calcularCostos(int* flagCalcularCostos,int respuesta,float kilometros, float latam, float aerolineas,float* costoDebitoLatam,float* costoDebitoAero,float* costoCreditoLatam,float* costoCreditoAero,float* bitcoinLatam,float* bitcoinAero,float* precioKmLatam,float* precioKmAero,float* diferencia){
	int retorno;
	int devolver;

	devolver=validarCalcularCostos(kilometros,latam,aerolineas);

	if(devolver==1)
	{
		(*costoDebitoLatam)=calcularDebito(latam);
		(*costoDebitoAero)=calcularDebito(aerolineas);

		(*costoCreditoLatam)=calcularCredito(latam);
		(*costoCreditoAero)=calcularCredito(aerolineas);

		(*bitcoinLatam)=calcularBitcoin(latam);
		(*bitcoinAero)=calcularBitcoin(aerolineas);

		(*precioKmLatam)=calcularPrecioKm(kilometros, latam);
		(*precioKmAero)=calcularPrecioKm(kilometros, aerolineas);

		(*diferencia)=diferenciaAerolineas(latam, aerolineas);

		(*flagCalcularCostos)=1;

		if(respuesta==3)
		{
			printf("Se calcularon los costos exitosamente.\nPresione cualquier tecla para volver al menu principal");
			scanf("%d",&retorno);
		}
		else{
			retorno=1;
		}
	}
	else{
		printf("ERROR, para calcular los costos necesita ingresar m%cs datos.\nPresione cualquier tecla para volver al menu principal",225);
		scanf("%d",&retorno);
		retorno=1;
	}
	return retorno;
}

int cargaForzada(int respuesta){
	int retorno;
	int flagCalcularCostos;
	float kilometrosForzados;
	float latamForzados;
	float aerolineasForzados;
	float diferencia;
	float precioKmLatam;
	float precioKmAero;
	float bitcoinLatam;
	float bitcoinAero;
	float costoDebitoLatam;
	float costoDebitoAero;
	float costoCreditoLatam;
	float costoCreditoAero;


	kilometrosForzados=7090;
	latamForzados=159339;
	aerolineasForzados=162965;

	retorno=calcularCostos(&flagCalcularCostos,respuesta,kilometrosForzados,latamForzados,aerolineasForzados,&costoDebitoLatam,&costoDebitoAero,&costoCreditoLatam,&costoCreditoAero,&bitcoinLatam,&bitcoinAero,&precioKmLatam,&precioKmAero,&diferencia);

	retorno=informarResultados(flagCalcularCostos,kilometrosForzados,latamForzados,aerolineasForzados,costoDebitoLatam,costoDebitoAero,costoCreditoLatam,costoCreditoAero,bitcoinLatam,bitcoinAero,precioKmLatam,precioKmAero,diferencia);


	return retorno;
}
