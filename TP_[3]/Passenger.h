/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "funciones.h"

#define TAM 50
#define TAMCOD 10

typedef struct
{
	int id;
	char nombre[TAM];
	char apellido[TAM];
	float precio;
	char tipoPasajero[TAM];
	char codigoVuelo[TAMCOD];
	char estadoVuelo[TAM];

}Passenger;

/** \brief Nuevo Pasajero
 *
 * \return Passenger* en memoria
 */
Passenger* Passenger_new();

/** \brief Setea todos los parametros para parsearlos en el archivo y llama a Passenger_new
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* tipoPasajeroStr
 * \param char* apellidoStr
 * \param char* precioStr
 * \param char* codigoStr
 * \param char* estadoStr
 * \return Passenger* devuelve el pasajero
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precioStr, char* codigoStr, char* estadoStr);

/** \brief Setea todos los parametros que ingrese el usuario en Controller_addPassenger y llama a Passenger_new
 *
 * \param int idS
 * \param char* nombre
 * \param char* tipoPasajero
 * \param char* apellido
 * \param float precio
 * \param char* codigoVuelo
 * \param char* estadoVuelo
 * \return Passenger* devuelve el pasajero
 */
Passenger* Passenger_parametros(int id, char* nombre, char* apellido, float precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo);

/** \brief Borra un pasajero de memoria
 *
 * \param Passenger* this

 */
void Passenger_delete(Passenger* this);

/** \brief Setea el id
 *
 * \param Passenger* this
 * \param int id
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setId(Passenger* this,int id);
/** \brief Devuelve el id de la lista
 *
 * \param Passenger* this
 * \param int* id
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getId(Passenger* this,int* id);

/** \brief Setea el nombre
 *
 * \param Passenger* this
 * \param char* nombre
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/** \brief Devuelve el nombre de la lista
 *
 * \param Passenger* this
 * \param char* nombre
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/** \brief Setea el apellido
 *
 * \param Passenger* this
 * \param char* apellido
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/** \brief Devuelve el apellido en lista
 *
 * \param Passenger* this
 * \param char* apellido
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/** \brief Setea el codigo
 *
 * \param Passenger* this
 * \param char* codigoVuelo
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/** \brief Devuelve el codigo de vuelo en lista
 *
 * \param Passenger* this
 * \param char* codigoVuelo
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/** \brief Setea el tipo Pasajero
 *
 * \param Passenger* this
 * \param char* tipoPasajero
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
/** \brief Devuelve el tipo Pasajero en lista
 *
 * \param Passenger* this
 * \param char* tipoPasajero
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/** \brief Setea el precio
 *
 * \param Passenger* this
 * \param float precio
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setPrecio(Passenger* this,float precio);
/** \brief Devuelve el precio en lista
 *
 * \param Passenger* this
 * \param float* precio
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/** \brief Setea el estado de vuelo
 *
 * \param Passenger* this
 * \param char* estado
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_setEstado(Passenger* this,char* estado);

/** \brief Devuelve el estado de vuelo
 *
 * \param Passenger* this
 * \param char* estado
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int Passenger_getEstado(Passenger* this,char* estado);


/** \brief Imprime un pasajero
 *
 * \param Passenger* this
 *
 */

void Passenger_printOne(Passenger* this);
/** \brief Compara por nombre para ll_sort
 *
 * \param void* pasajero
 * \param void* otroPasajero
 *
 * \return int 	-1 primerNombre menor
 * 				1 primerNombre mayor
 * 				0 si es igual
 */
int Passenger_compareByNombre(void* pasajero, void* otroPasajero);
/** \brief Compara por apellido para ll_sort
 *
 * \param void* pasajero
 * \param void* otroPasajero
 *
 * \return int 	-1 primerApellido menor
 * 				1 primerApellido mayor
 * 				0 si es igual
 */
int Passenger_compareByApellido(void* pasajero, void* otroPasajero);
/** \brief Compara por id para ll_sort
 *
 * \param void* pasajero
 * \param void* otroPasajero
 *
 * \return int 	-1 primerId menor
 * 				1 primerId mayor
 * 				0 si es igual
 */
int Passenger_compareById(void* pasajero, void* otroPasajero);
/** \brief Compara por precio para ll_sort
 *
  * \param void* pasajero
 * \param void* otroPasajero
 *
 * \return int 	-1 primerPrecio menor
 * 				1 primerPrecio mayor
 * 				0 si es igual
 */
int Passenger_compareByPrecio(void* pasajero, void* otroPasajero);
/** \brief Compara por tipo pasajero para ll_sort
 *
 * \param void* pasajero
 * \param void* otroPasajero
 *
 * \return int 	-1 primerTipoPasajero menor
 * 				1 primerTipoPasajero mayor
 * 				0 si es igual
 */
int Passenger_compareByTipoPasajero(void* pasajero, void* otroPasajero);
/** \brief Compara por estado vuelo para ll_sort
 *
 * \param void* pasajero
 * \param void* otroPasajero
 *
 * \return int 	-1 primerEstado menor
 * 				1 primerEstado mayor
 * 				0 si es igual
 */
int Passenger_compareByEstado(void* pasajero, void* otroPasajero);


#endif /* PASSENGER_H_ */
