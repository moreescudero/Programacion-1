/*
 * funciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: moreescudero
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int validarChar(char texto[], int tam, int necesitaAlfaNumerica){
	int huboError;
	int supera;
	int i;

	if(strlen(texto) > tam)
	{
		supera = 1;
		huboError = supera;
	}
	else{
		supera = 0;
		for(i=0;i<tam;i++)
		{
			if((necesitaAlfaNumerica == 1 && (isdigit(texto[i]) == 1 || isalpha(texto[i]) == 1))||
				(necesitaAlfaNumerica == 0 && isalpha(texto[i]) == 1) )
			{
				texto[i] = toupper(texto[i]);
				huboError = 0;
			}
			else{
				huboError = 1;
				break;
			}
		}
	}

	return huboError;

}

int validarInt(char* num, int min, int max){
	int huboError;
	int i;
	int aux;

	huboError = 0;

	aux = atoi(num);

	for(i=0; i<strlen(num);i++)
	{
		if(isdigit(num[i]) == 0 || (aux < min && aux > max))
		{
			huboError = 1;
			break;
		}
	}

	return huboError;
}

int validarFloat(char* precio, int min){
	int flagPunto;
	int i;
	int huboError;
	float aux;

	flagPunto = 0;
	huboError = 0;

	aux = atof(precio);

	for(i=0;i<strlen(precio);i++)
	{

		if(flagPunto == 0 && precio[i] == '.')
		{
			flagPunto = 1;
		}
		else{
			if(isdigit(precio[i]) == 0 || aux <= min)
			{
				huboError = 1;
				break;
			}
		}
	}

	return huboError;
}

void getChar(char* texto,int tam, char mensaje[], char mensajeError[], int necesitaAlfaNumerica){
	int huboError;

	printf("%s", mensaje);
	fpurge(stdin);
	scanf("%[^\n]", texto);

	huboError = validarChar(texto, tam, necesitaAlfaNumerica);

	while(huboError == 1)
	{
		printf("%s", mensaje);
		fpurge(stdin);
		scanf("%[^\n]", texto);
		huboError = validarChar(texto, tam, necesitaAlfaNumerica);
	}

}


int getInt(char mensaje[], char mensajeError[], int min, int max){
	char num[51];
	int numInt;
	int huboError;

	printf("%s", mensaje);
	fpurge(stdin);
	scanf("%[^\n]", num);

	huboError = validarInt(num, min, max);

	while(huboError == 1)
	{
		printf("%s", mensajeError);
		fpurge(stdin);
		scanf("%[^\n]", num);
		huboError = validarInt(num, min, max);
	}

	numInt = atoi(num);

	return numInt;
}

float getFloat(char mensaje[], char mensajeError[], int min){
	char precio[51];
	float precioFloat;
	int huboError;

	printf("%s", mensaje);
	fpurge(stdin);
	scanf("%[^\n]", precio);

	huboError = validarFloat(precio, min);

	while(huboError == 1)
	{
		printf("%s", mensajeError);
		fpurge(stdin);
		scanf("%[^\n]", precio);
		huboError = validarFloat(precio, min);
	}

	precioFloat = atof(precio);

	return precioFloat;
}


