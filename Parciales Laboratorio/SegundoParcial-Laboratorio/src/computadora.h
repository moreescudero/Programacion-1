/*
 * computadora.h
 *
 *  Created on: 28 jun. 2022
 *      Author: moreescudero
 */

#ifndef SRC_COMPUTADORA_H_
#define SRC_COMPUTADORA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 200


typedef struct{
	int id;
	char descripcion[TAM];
	float precio;
	int idTipo;
}eComputer;

eComputer* computerNew(void);

eComputer* computerNewParametros(char* id, char* desc, char* precio, char* idTipo);

void computer_SetIdTipo(eComputer* , int );

void computer_SetPrecio(eComputer* , float );

void computer_SetDesc(eComputer* , char* );

void computer_SetId(eComputer* , int );

void computer_getIdTipo(eComputer* , int* );

void computer_getPrecio(eComputer* , float* );

void computer_getDesc(eComputer* , char* );

void computer_getId(eComputer* , int* );

int validarInt(char* num, int min, int max);

int getInt(char* mensaje, char* Error, int min, int max);

int validarChar(char texto[], int tam);

void getChar(char texto[],int tam, char mensaje[]);

int computerOrdenarIdTipo(void* unTipo, void* otroTipo);

void computerPrintOne(eComputer*);

void computerLaptop(void* computadora);

void computerDesktop(void* computadora);

#endif /* SRC_COMPUTADORA_H_ */
