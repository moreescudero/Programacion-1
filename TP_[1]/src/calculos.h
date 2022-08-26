/*
 * calculos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: morena
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


/// @fn		float calcularDebito(float)
/// @brief	Calcula el 10% de descuento sobre el total del precio del vuelo.
/// @param	float precioVuelo ingresa el precio para aplicarle el descuento.
/// @return	Retorna el resultado a calcular costos.
float calcularDebito(float);

/// @fn		float calcularCredito(float)
/// @brief	Calcula el 25% de interés sobre el total del precio del vuelo.
/// @param	float precioVuelo ingresa el precio para aplicarle el interés.
/// @return	Retorna el resultado a calcular costos.
float calcularCredito(float);

/// @fn		float calcularBitcoin(float)
/// @brief	Calcula el precio del vuelo en bitcoin.
/// @param	float precioVuelo ingresa el precio para calcular precio en bitcoin.
/// @return	Retorna el resultado a calcular costos.
float calcularBitcoin(float);

/// @fn		float calcularPrecioKm(float, float)
/// @brief	Calcula el valor por cada kilómetro.
/// @param	float kilometros ingresa los kilómetros para calcular.
///	@param	float precioVuelo ingresa el precio del vuelo para calcular.
/// @return	Retorna el resultado a calcular costos.
float calcularPrecioKm(float, float);

/// @fn		float diferenciaAerolineas(float, float)
/// @brief	Calcula la diferencia de precios entre las aerolineas Latam y Aerolineas Argentinas.
///	@param	float latam ingresa el precio de Latam.
/// @param	float aerolineas ingresa el precio de Aerolineas Argentinas.
/// @return	Retorna el resultado a calcular costos.
float diferenciaAerolineas(float, float);

#endif /* CALCULOS_H_ */
