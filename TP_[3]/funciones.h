/*
 * funciones.h
 *
 *  Created on: 2 jun. 2022
 *      Author: moreescudero
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Valida entero
 *
 * \param char* num
 * \param int min
 * \param int max
 * \return int 	-1 se ingreso un digito o el numero es menor al minimo o mayor al maximo
 * 				0 si esta todo ok
 */
int validarInt(char* num, int min, int max);

/** \brief Ingresar entero, llama a validarInt
 *
 * \param char* mensaje
 * \param char* error
 * \param int min
 * \param int max
 * \return int el numero ingresado validado
 *
 */
int getInt(char* mensaje, char* Error, int min, int max);

/** \brief Valida float
 *
 * \param char* precio
 * \param int min
 * \return int	-1 se ingreso un digito o el precio es menor o igual a 0
 * 				0 si esta todo ok
 */
int validarFloat(char* precio, int min);

/** \brief Ingresa float, llama a validarFloat
 *
 * \param char mensaje[]
 * \param char mensajeError[]
 * \param int min
 * \return int el precio ingresado
 *
 */
float getFloat(char mensaje[], char mensajeError[], int min);

/** \brief Valida char
 *
 * \param char texto[]
 * \param int tam
 * \param int necesitaAlfaNumerica
 * \return int	-1 se excede
 * 				-2 isdigit false o si es alfanumerica isdigit o isalpha false
 *				0 si esta todo ok
 */
int validarChar(char texto[], int tam, int necesitaAlfaNumerica);

/** \brief Ingresa char
 *
 * \param char* texto
 * \param int tam
 * \param char mensaje[]
 * \param char mensajeError[]
 * \param int necesitaAlfaNumerica
 *
 */
void getChar(char* texto,int tam, char mensaje[], char mensajeError[], int necesitaAlfaNumerica);


#endif /* FUNCIONES_H_ */
