/*
 * validaciones.c
 *
 *  Created on: 9 abr. 2022
 *      Author: morena
 */
#include <stdio.h>
#include <stdlib.h>

int validarMenu(int respuesta){

	while(respuesta>=7||respuesta<=0)
	{
		printf("ERROR, por favor, ingrese una opci%cn v%clida: ",243,225);
		scanf("%d",&respuesta);
	}

	return respuesta;
}

float validarDato(float dato, char mensaje[]){

	while(dato<=0)
	{
		fflush(stdin);
		printf("%s", mensaje);
		scanf("%f", &dato);
	}

	return dato;
}

int validarCalcularCostos(float kilometros, float latam, float aerolineas){
	int retorno;

	if(kilometros!=0&&latam!=0&&aerolineas!=0)
	{
		retorno=1;
	}
	else{
		retorno=0;
	}

	return retorno;
}
