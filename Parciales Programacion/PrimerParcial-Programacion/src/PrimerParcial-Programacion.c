/*
 ============================================================================
 Name        : PrimerParcial-Programacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 15

float aplicarDescuento(float importe, float descuento);

void invertirCadena(char* texto,char textoInvertido[]);


void invertirCadena(char* cadena,char cadenaAlReves[]){
	int aux;
	int len;
	int i;

	len = strlen(cadena);
	aux = len - 1;

	for(i=0;i<len;i++)
	{
	    if(aux >= 0)
		{
		cadenaAlReves[aux] = cadena[i];
		aux--;
		}
	}

	printf("\nEl string al reves es: %s", cadenaAlReves);
}


int main(void) {

	float precio;
	float descuento;
	float total;
	char texto[LEN] = "bienvenido";
	char textoInvertido[LEN];

	precio = 200;
	descuento = 10;

	total = aplicarDescuento(precio,descuento);

	printf("El total es:  %.2f", total);

	printf("\n%s", texto);

	invertirCadena(texto, textoInvertido);

	return 0;
}


float aplicarDescuento(float importe, float descuento){
	float descontar;
	float total;

	descontar = importe * descuento / 100;
	total = importe - descontar;

	return total;
}
