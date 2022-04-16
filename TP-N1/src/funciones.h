/*
 * funciones.h
 *
 *  Created on: 5 abr. 2022
 *      Author: morena
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn 	int mostrarMenu(float, float, float)
/// @brief 	Se muestran las opciones disponibles para avanzar con el programa y el usuario debe elegir una.
/// @param 	float kil�metros inicializado en 0 es donde se guardar�n los kil�metros que ingrese el usuario.
/// @param 	float latam inicializado en 0 guardar� el precio de la aerolinea latam.
/// @param 	float aerolineas inicializado en 0 guardar� el precio de la aerolinea aerolineas argentinas.
/// @return	Retorna la opci�n elegida al main para proceder con el programa.
int mostrarMenu(float, float, float);

/// @fn 	float ingresarDato(char[], char[])
/// @brief 	Funci�n donde el usuario ingresar� los precios del vuelo o el kilometraje seg�n el mensaje.
///			Se llama a la funcion de validacion para comprobar que sea un numero mayor a 0.
/// @param 	char mensaje lo recibe para indicar al usuario qu� debe ingresar.
///	@param	char mensajeError para enviar el dato como par�metro en la funci�n de validaci�n.
/// @return	Retorna el precio de la aerolinea al menu principal.
float ingresarDato(char[], char[]);

/// @fn 	int calcularCostos(int*,int,float,float,float,float*,float*,float*,float*,float*,float*,float*,float*,float*)
/// @brief 	Funcion en la que se llama a las funciones de c�lculo para obtener los costos finales del vuelo
///			ya sea si el usuario los ingres� o si decidi� realizar una carga forzada. Se llama a las funciones de validaci�n
///			para comprobar que los datos necesarios para el buen funcionamiento del programa est�n ingresados, sino se retorna al menu principal.
///			El usuario podr� dirigirse directamente a la opcion de informar resultados si es que eligi� la opci�n 3 en el menu principal o si eligi� la opci�n
///			4 o 5 primero se calcularan los datos y pasar� directamente a informar resultados sin consultar previamente.
///	@param	int* flagCalcularCostos carga un 1 como puntero para comprobar que los costos fueron calculados.
/// @param	int respuesta se recibe desde el main con la opci�n que el usuario ingres� en el menu principal, as� darle opciones personalizadas para
///			avanzar en el programa seg�n la acci�n que desea realizar.
/// @param	float kilometros puede recibirse tanto los ingresados por el usuario como el dato hardcodeado de la carga forzada.
/// @param	float latam puede recibirse tanto los ingresados por el usuario como el dato hardcodeado de la carga forzada.
/// @param	float aerolineas puede recibirse tanto los ingresados por el usuario como el dato hardcodeado de la carga forzada.
///	@param	float* costoDebitoLatam puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* costoDebitoAero puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* costoCreditoLatam puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* costoCreditoAero puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* bitcoinLatam puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* bitcoinAero puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* precioKmLatam puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* precioKmAero puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
///	@param	float* diferencia puntero utilizado para guardar un resultado y enviarlo luego a la funci�n informarResultados.
/// @return	Retorna al main 6 si el usuario desea finalizar el programa o 1 si desea volver al menu principal.

///float,float,float,float,float,float,float,float,float,float
int calcularCostos(int*,int, float, float, float,float*,float*,float*,float*,float*,float*,float*,float*,float*);

/// @fn		void informarResultados(int**,float,float,float,float**,float**,float**,float**,float**,float**,float**,float**,float**)
/// @brief	Funcion que informar� los resultados finales al usuario.
///	@param	int* flagCalcularCostos comprueba que los calculos hayan sido previamente calculados.
/// @param	float kilometros informa los kilometros totales.
/// @param	float latam informa el precio total eligiendo la aerolinea Latam.
/// @param	float aerolineas informa el precio total eligiendo la aerolinea Aerolineas Argentinas.
/// @param	float* costoDebitoLatam informa el precio con 10% de descuento con tarjeta de d�bito en la aerolinea Latam.
/// @param	float* costoDebitoAero informa el precio con 10% de descuento con tarjeta de d�bito en la aerolinea Aerolineas Argentinas.
/// @param	float* costoCreditoLatam informa el precio con 25% de inter�s con tarjeta de cr�dito en la aerolinea Latam.
/// @param	float* costoCreditoAero informa el precio con 25% de inter�s con tarjeta de cr�dito en la aerolinea Aerolineas Argentinas.
/// @param	float* bitcoinLatam informa la conversion del precio total en bitcoin en la aerolinea Latam.
/// @param  float* bitcoinAero informa la conversion del precio total en bitcoin en la aerolinea Aerolineas Argentinas.
/// @param	float* precioKmLatam	informa el precio por kil�metro con la aerolinea Latam.
/// @param	float* precioKmAero informa el precio por kil�metro con la aerolinea Aerolineas Argentinas.
/// @param  float* diferencia informa la diferencia de precios que hay entre Latam y Aerolineas Argentinas.
/// @return	Retorna un 6 a calcular costos o a carga forzada si desea finalizar o un 1 si desea volver al menu principal.
int informarResultados(int,float,float,float,float,float,float,float,float,float,float,float,float);
// int informarResultados(int*,float,float,float,float*,float*,float*,float*,float*,float*,float*,float*,float*);

/// @fn		int cargaForzada(int*,int,float*,float*,float*,float*,float*,float*,float*,float*,float*)
/// @brief	Funcion con los valores de los kil�metros y los precios de ambas aerolineas hardcodeados, son enviados a calcular costos y finalmente informan
///			los resultados.
/// @param	int respuesta ingresa a la funci�n para pasar el valor a la funci�n calcular costos.
/// @return	Retorna 6 en caso de finalizar el programa o un 1 para volver al menu principal.
int cargaForzada(int);


#endif /* FUNCIONES_H_ */
