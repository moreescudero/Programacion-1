/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include "Passenger.h"


Passenger* Passenger_new(){

	return (Passenger*) malloc(sizeof(Passenger));;
}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precioStr, char* codigoStr, char* estadoStr){
	Passenger* pasajero;

	pasajero = Passenger_new();

	if(pasajero != NULL)
	{
		Passenger_setId(pasajero, atoi(idStr));
		Passenger_setNombre(pasajero, nombreStr);
		Passenger_setApellido(pasajero, apellidoStr);
		Passenger_setCodigoVuelo(pasajero, codigoStr);
		Passenger_setTipoPasajero(pasajero, tipoPasajeroStr);
		Passenger_setPrecio(pasajero, atof(precioStr));
		Passenger_setEstado(pasajero, estadoStr);
	}

	return pasajero;
}

Passenger* Passenger_parametros(int id, char* nombre, char* apellido, float precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo){
	Passenger* pasajero;

	pasajero = Passenger_new();

	if(id > 0 && nombre != NULL && apellido != NULL && codigoVuelo != NULL && precio > 0 && tipoPasajero != NULL && estadoVuelo != NULL)
	{
		Passenger_setId(pasajero, id);
		Passenger_setNombre(pasajero, nombre);
		Passenger_setApellido(pasajero, apellido);
		Passenger_setCodigoVuelo(pasajero, codigoVuelo);
		Passenger_setTipoPasajero(pasajero, tipoPasajero);
		Passenger_setPrecio(pasajero, precio);
		Passenger_setEstado(pasajero, estadoVuelo);
	}

	return pasajero;
}

void Passenger_delete(Passenger* this){
	if(this != NULL)
		free(this);
}

int Passenger_setId(Passenger* this,int id){
	int retorno;

	retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id){
	int retorno;

	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno;

	retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno;

	retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno;

	retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno;

	retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno;
	retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno;

	retorno = -1;


	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno;
	retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno;

	retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstado(Passenger* this,char* estado){
	int retorno;

	retorno = -1;

	if(this != NULL && estado != NULL)
	{
		strcpy(this->estadoVuelo, estado);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getEstado(Passenger* this,char* estado){
	int retorno;

	retorno = -1;

	if(this != NULL && estado != NULL)
	{
		strcpy(estado, this->estadoVuelo);
		retorno = 0;
	}

	return retorno;
}

void Passenger_printOne(Passenger* this){
	int id, contador;
	float precio;
	char nombre[TAM];
	char apellido[TAM];
	char codigoVuelo[TAMCOD];
	char tipoPasajero[TAM];
	char estado[TAM];

	contador = 0;

	contador += Passenger_getId(this, &id);
	contador += Passenger_getNombre(this, nombre);
	contador += Passenger_getApellido(this, apellido);
	contador += Passenger_getCodigoVuelo(this, codigoVuelo);
	contador += Passenger_getTipoPasajero(this, tipoPasajero);
	contador += Passenger_getPrecio(this, &precio);
	contador += Passenger_getEstado(this, estado);

	if(this != NULL && contador == 0)
	{
		printf("%4d|%15s|%15s|%10s|%15s|$%4.2f|%15s\n", id, nombre, apellido, codigoVuelo, tipoPasajero, precio, estado);
	}
	else{
		printf("\nOcurrio un error al imprimir un pasajero :(");
	}
}

int Passenger_compareByNombre(void* pasajero, void* otroPasajero){
	char primerNombre[TAM];
	char segundoNombre[TAM];
	int compara;
	int retorno;

	retorno = -2;

	if(pasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getNombre((Passenger*) pasajero, primerNombre);
		Passenger_getNombre((Passenger*) otroPasajero, segundoNombre);

		compara = strcmp(primerNombre, segundoNombre);
		if(compara > 0)
		{
			retorno = 1;//primer nombre mayor
		}
		else{
			if(compara < 0)
			{
				retorno = -1;//segundo nombre mayor
			}
			else{
				retorno = 0;//iguales
			}
		}
	}

	return retorno;
}

int Passenger_compareByApellido(void* pasajero, void* otroPasajero){
	char primerApellido[TAM];
	char segundoApellido[TAM];
	int compara;
	int retorno;

	retorno = -2;

	if(pasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getApellido((Passenger*) pasajero, primerApellido);
		Passenger_getApellido((Passenger*) otroPasajero, segundoApellido);

		compara = strcmp(primerApellido, segundoApellido);
		if(compara > 0)
		{
			retorno = 1;//primer apellido mayor
		}
		else{
			if(compara < 0)
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

int Passenger_compareByPrecio(void* pasajero, void* otroPasajero){
	float primerPrecio;
	float segundoPrecio;
	int retorno;

	retorno = -2;
	primerPrecio = 0;
	segundoPrecio = 0;

	if(pasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getPrecio((Passenger*) pasajero, &primerPrecio);
		Passenger_getPrecio((Passenger*) otroPasajero, &segundoPrecio);
		if(primerPrecio > segundoPrecio)
		{
			retorno = 1; //primer precio mayor
		}
		else{
			if(primerPrecio < segundoPrecio)
			{
				retorno = -1; //segundo precio mayor
			}
			else{
				retorno = 0;
			}
		}
	}

	return retorno;
}

int Passenger_compareByTipoPasajero(void* pasajero, void* otroPasajero){
	char primerTipoPasajero[TAM];
	char segundoTipoPasajero[TAM];
	int compara;
	int retorno;

	retorno = -1;

	if(pasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getTipoPasajero((Passenger*) pasajero, primerTipoPasajero);
		Passenger_getTipoPasajero((Passenger*) otroPasajero, segundoTipoPasajero);

		compara = strcmp(primerTipoPasajero, segundoTipoPasajero);
		if(compara > 0)
		{
			retorno = 1;//primer tipo pasajero mayor
		}
		else{
			if(compara < 0)
			{
				retorno = -1;//segundo tipo pasajero mayor
			}
			else{
				retorno = 0;//iguales
			}
		}

	}

	return retorno;
}

int Passenger_compareByEstado(void* pasajero, void* otroPasajero){
	char primerEstado[TAM];
	char segundoEstado[TAM];
	int compara;
	int retorno;

	retorno = -2;

	if(pasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getTipoPasajero((Passenger*) pasajero, primerEstado);
		Passenger_getTipoPasajero((Passenger*) otroPasajero, segundoEstado);

		compara = strcmp(primerEstado, segundoEstado);
		if(compara > 0)
		{
			retorno = 1;//primer estado mayor
		}
		else{
			if(compara < 0)
			{
				retorno = -1;//segundo estado mayor
			}
			else{
				retorno = 0;//iguales
			}
		}

	}

	return retorno;
}

int Passenger_compareById(void* pasajero, void* otroPasajero){
	int primerId;
	int segundoId;
	int retorno;

	retorno = -2;
	primerId = 0;
	segundoId = 0;

	if(pasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getId((Passenger*) pasajero, &primerId);
		Passenger_getId((Passenger*) otroPasajero, &segundoId);
		if(primerId > segundoId)
		{
			retorno = 1; //primerId mayor
		}
		else{
			if(primerId < segundoId)
			{
				retorno = -1; //segundoId mayor
			}
			else{
				retorno = 0; //ambos id iguales
			}
		}
	}

	return retorno;
}
