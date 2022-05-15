/*
 * funciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: moreescudero
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


//	@fn		int validarInt(char* num, int min, int max)
//	@brief	valida que se ingrese un int entre el min y el max permitido y que no se ingrese un char
//	@param	char* num
//	@param	int min
//	@param	int max
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int validarInt(char* num, int min, int max);

//	@fn		int validarChar(char texto[], int tam, int necesitaAlfaNumerica)
//	@brief	valida que se ingrese un char que no exceda el tamaño y que no rompa con signos
//	@param	char texto[]
//	@param	int tam
//	@param	int necesitaAlfaNumerica
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int validarChar(char texto[], int tam, int necesitaAlfaNumerica);

//	@fn		int validarFloat(char* precio, int min)
//	@brief	valida que se ingrese un float mayor al min y que no se ingrese un char
//	@param	char* precio
//	@param	int min
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int validarFloat(char* precio, int min);

//	@fn		void getChar(char* texto,int tam, char mensaje[], char mensajeError[], int necesitaAlfaNumerica)
//	@brief	permite al usuario ingresar un char
//	@param	char* texto
//	@param	int tam
//	@param	char mensaje[]
//	@param	char mensajeError[]
//	@param	int necesitaAlfaNumerica
//	@return retorna la cadena de texto
void getChar(char* texto,int tam, char mensaje[], char mensajeError[], int necesitaAlfaNumerica);

//	@fn		int getInt(char mensaje[], char mensajeError[], int min, int max)
//	@brief	permite al usuario ingresar un int
//	@param	char mensaje[]
//	@param	char mensajeError[]
//	@param	int min
//	@param	int max
//	@return retorna un int
int getInt(char mensaje[], char mensajeError[], int min, int max);

//	@fn		float getFloat(char mensaje[], char mensajeError[], int min)
//	@brief	permite al usuario ingresar un float
//	@param	char mensaje[]
//	@param	char mensajeError[]
//	@param	int min
//	@return retorna un float
float getFloat(char mensaje[], char mensajeError[], int min);

#endif /* FUNCIONES_H_ */
