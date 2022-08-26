/*
 * computadora.c
 *
 *  Created on: 28 jun. 2022
 *      Author: moreescudero
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "computadora.h"

#define TAM 200


eComputer* computerNew(void){
	return (eComputer*) malloc(sizeof(eComputer));
}
void computer_SetId(eComputer* this, int id)
{
	if(this != NULL)
	{
		this->id = id;
	}
}

void computer_SetDesc(eComputer* this, char* desc)
{
	if(this != NULL && desc != NULL)
	{
		strcpy(this->descripcion, desc);
	}
}

void computer_SetPrecio(eComputer* this, float precio)
{
	if(this != NULL)
	{
		this->precio = precio;
	}
}

void computer_SetIdTipo(eComputer* this, int idTipo)
{
	if(this != NULL)
	{
		this->idTipo = idTipo;
	}
}

void computer_getId(eComputer* this, int* id){
	if(this != NULL && id != NULL)
	{
		*id = this->id;
	}
}

void computer_getDesc(eComputer* this, char* desc){
	if(this != NULL && desc != NULL)
	{
		strcpy(desc, this->descripcion);
	}
}

void computer_getPrecio(eComputer* this, float* precio){
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
	}
}

void computer_getIdTipo(eComputer* this, int* idTipo){
	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
	}
}

eComputer* computerNewParametros(char* id, char* desc, char* precio, char* idTipo){
	eComputer* compu;

	compu = computerNew();

	if(compu != NULL)
	{
		computer_SetId(compu, atoi(id));
		computer_SetDesc(compu, desc);
		computer_SetPrecio(compu, atof(precio));
		computer_SetIdTipo(compu, atoi(idTipo));
	}

	return compu;
}

int validarInt(char* num, int min, int max){
	int huboError;
	int i;
	int aux;

	huboError = 0;

	aux = atoi(num);

	for(i=0; i<strlen(num);i++)
	{
		if(isdigit(num[i]) == 0 || (aux < min || aux > max))
		{
			huboError = -1; // se ingreso un digito o el numero es menor al minimo o mayor al maximo
			break;
		}
	}

	return huboError;
}

int getInt(char* mensaje, char* Error, int min, int max){
	char num[50];
	int opcion;
	int huboError;

	printf("%s", mensaje);
	fpurge(stdin);
	scanf("%[^\n]", num);

	huboError = validarInt(num, min, max);

	while(huboError == 1)
	{
		printf("%s", Error);
		fpurge(stdin);
		scanf("%[^\n]", num);
		huboError = validarInt(num, min, max);
	}

	opcion = atoi(num);

	return opcion;
}

int validarChar(char texto[], int tam){
	int ok;

	if(strlen(texto) > tam)
	{
		ok = 0;
	}
	else{
		ok = 1;
	}

	return ok;

}

void getChar(char texto[],int tam, char mensaje[]){
	int ok;

	printf("%s", mensaje);
	fpurge(stdin);
	scanf("%[^\n]", texto);

	ok = validarChar(texto, tam);

	if(ok == 0)
	{
		printf("\nERROR, por favor no se exceda en la cantidad de caracteres: ");
		fpurge(stdin);
		scanf("%[^\n]", texto);
	}

}

int computerOrdenarIdTipo(void* unTipo, void* otroTipo){
	int retorno;
	int primerId;
	int segundoId;
	retorno = -2;

	if(unTipo != NULL && otroTipo != NULL)
	{
		computer_getIdTipo(unTipo, &primerId);
		computer_getIdTipo(otroTipo, &segundoId);


		if(primerId > segundoId)
		{
			retorno = 1;//primer apellido mayor
		}
		else{
			if(primerId < segundoId)
			{
				retorno = -1;//segundo apellido mayor
			}
			else{
				retorno = 0;//iguales
			}
		}
	}

	return retorno;
}

void computerPrintOne(eComputer* this){
	int id;
	char desc[TAM];
	float precio;
	int idTipo;
	char idTipoStr[TAM];

	if(this != NULL)
	{
		computer_getId(this, &id);
		computer_getDesc(this, desc);
		computer_getPrecio(this, &precio);
		computer_getIdTipo(this, &idTipo);

		switch(idTipo)
		{
			case 1:
				strcpy(idTipoStr, "Desktop");
				break;
			default:
				strcpy(idTipoStr, "Laptop");
				break;
		}

		printf("%4d|%120s|$%10.2f|%s\n", id, desc, precio, idTipoStr);
	}
}

void computerDesktop(void* computadora){
	float precio;
	int idTipo;

	computer_getPrecio((eComputer*)computadora, &precio);
	computer_getIdTipo((eComputer*)computadora, &idTipo);

	if(idTipo == 1)
	{
		precio *= 1.1;
	}
	else{
		precio *= 1.2;
	}


	computer_SetPrecio((eComputer*)computadora, precio);

}
