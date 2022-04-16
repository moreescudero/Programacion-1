/*
 * validaciones.h
 *
 *  Created on: 9 abr. 2022
 *      Author: morena
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


/// @fn		int validarMenu(int)
/// @brief	Valida que se respeten la cantidad de opciones disponibles para el usuario. No se podrán ingresar menos de 1 ni más de 6.
/// @param	int respuesta la respuesta elegida por el usuario.
/// @return	Retorna al menu principal la respuesta validada.
int validarMenu(int);

/// @fn		int validarDatos(float,char[])
/// @brief	Valida que los datos ingresados por el usuario no sean 0 ni numeros negativos.
/// @param	float dato es la cantidad de kilómetros o el precio de las aerolineas ingresados por el usuario.
/// @param	char mensaje es el mensaje que se mostrará según el dato que se esté validando.
/// @return	Retorna el dato validados.
float validarDato(float, char[]);

/// @fn		int validarCalcularCostos(float,float,float)
/// @brief	Valida que los valores de Kilómetros y los precios de ambas aerolineas sean distintos de 0 para poder calcular los costos.
/// @param	float kilometros kilómetros ingresados o hardcodeados.
/// @param	float latam precio de Latam ingresado o hardcodeado.
/// @param	float aerolineas precio de Aerolineas Argentinas ingresado o hardcodeado.
/// @return	Retorna 0 si al menos uno de los parámetros es igual a 0, y retorna 1 si todos los parámetros son distintos de 0.
int validarCalcularCostos(float,float,float);

#endif /* VALIDACIONES_H_ */
