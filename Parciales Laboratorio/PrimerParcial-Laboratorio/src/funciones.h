/*
 * funciones.h
 *
 *  Created on: 2 may. 2022
 *      Author: moreescudero
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//	@fn		int validarInt(int num, char error[], int min, int max)
//	@brief	valida que el numero ingresado por el usuario sea valido para lo necesitado
//	@param	num numero para validar
//	@param	error[] mensaje de error en caso de que el numero sea invalido
//	@param	min numero minimo
//	@param	max numero maximo
//	@return	retorna el numero que fue recibido como parametro validado
int validarInt(int num, char error[], int min, int max);

//	@fn		float validarFloat(float precio, char error[], int min)
//	@brief	valida que el precio que fue ingresado por el usuario sea mayor a 0
//	@param	precio flotante a validar
//	@param	error[] mensaje de error en caso de que el flotante sea invalido
//	@param	min numero minimo
//	@return	retorna el precio que fue recibido como parametro validado
float validarFloat(float precio, char error[], int min);

//	@fn		int validarChar(char texto[], int tam)
//	@brief	valida que el texto no se exceda de los caracteres permitidos
//	@param	texto[] cadena de caracteres que ingrese el usuario
//	@param	tam tamaño del vector texto[]
//	@return retorna 1 si esta ok y 0 si supera el maximo
int validarChar(char texto[], int tam);

//	@fn		int getInt(char texto[], char error[], int min, int max)
//	@brief	permite al usuario ingresar un entero
//	@param	texto[] indica al usuario el tipo de dato que se necesita ingresar
//	@param	error[] mensaje de error en caso de que el numero sea invalido enviado como parametro a validarInt
//	@param	min numero minimo enviado como parametro a validarInt
//	@param	max numero maximo enviado como parametro a validarInt
//	@return	retorna el entero ingresado
int getInt(char texto[], char error[], int min, int max);

//	@fn		void getChar(char texto[], int tam, char mensaje[])
//	@brief	permite al usuario ingresar un char
//	@param	texto[] guardara la cadena de caracteres que ingrese el usuario
//	@param	tam tamaño del vector texto[]
//	@param	mensaje[] mensaje que indica al usuario que tipo dde dato necesita ingresar
//	@return	-
void getChar(char texto[], int tam, char mensaje[]);

//	@fn		float getFloat(char texto[], char error[], int min)
//	@brief	permite al usuario ingresar un flotante
//	@param	texto[] mensaje que indica al usuario que tipo dde dato necesita ingresar
//	@param	error[] mensaje de error en caso de que el flotante sea invalido enviado como parametro a validarFloat
//	@param	min numero minimo enviado como parametro a validarFloat
//	@return	retorna el flotante ingresado
float getFloat(char texto[], char error[], int min);

//	@fn		int cantidadSXX(eAlbum listaAlbum[], int tam, int indicador)
//	@brief	cuenta e imprime (segun si sea llamada desde listar o informar) los albumes que hayan sido publicados antes
//			de 1/1/2000
//	@param	listaAlbum[] vector con los datos ingresados
//	@param	tam tamaño del vector
//	@param	indicador si la funcion es llamada desde informar vale 1 y solo contara y si es llamada desde listar vale 2 e imprime
//			los albumes
//	@return	retorna el contador en mayor a 0 si es que encontro algun album lanzado antes de 1/1/2000
int cantidadSXX(eAlbum listaAlbum[], int tam, int indicador);

//	@fn		void promediarPrecios(eAlbum listaAlbum[], int tam, int indicador)
//	@brief	calcula el total del importe, el promedio y la cantidad de albumes que superan el promedio. Segun el valor del indicador
//			va a printear el total, el promedio y la cantidad de albumes que superan el promedio, sino va a printear el id y el titulo
//			de los albumes que superan el promedio
//	@param	listaAlbum[] vector con los datos ingresados
//	@param	tam tamaño del vector
//	@param	indicador si la funcion es llamada desde informar vale 1 y printea el total de importes, el promedio y la cantidad que supera el promedio
//			y solo contara y si es llamada desde listar vale 2 e imprime
//			los albumes
//	@return	-
void promediarPrecios(eAlbum listaAlbum[], int tam, int indicador);

void cantidadAlbumesTipoAlbumGenero(eAlbum listaAlbum[],int tam, eGenero listaGenero[], int tamGenero,eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);

#endif /* FUNCIONES_H_ */
