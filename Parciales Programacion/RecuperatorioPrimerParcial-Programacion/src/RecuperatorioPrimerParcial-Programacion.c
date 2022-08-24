/*
 ============================================================================
 Name        : RecuperatorioPrimerParcial-Programacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 51

int calcularDivisores(int numero);

void ordenarCadena(char* cadena);

void ordenarCadena(char* cadena){
	int i;
	int j;
	char aux;
	int len;

	len = strlen(cadena);

	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(cadena[i] > cadena[j])
			{
				aux = cadena[i];
				cadena[i] = cadena[j];
				cadena[j] = aux;
			}
			if(cadena[i]==' ')
			{
				cadena[i] = '*';
			}
		}
	}

}

int main(void) {
	//primer punto
	int numero = 8;
	int resultado;
	//segundo punto
	char cadena[TAM] = "la plaza";


	resultado = calcularDivisores(numero);
	printf("\ncant divisibles: %d", resultado);

	printf("\n%s", cadena);
	ordenarCadena(cadena);
	printf("\n%s", cadena);

	return 0;
}

int calcularDivisores(int numero){
	int contadorDivisibles;
	int i;

	contadorDivisibles = 0;

	for(i=1;i<=numero;i++)
	{
		if(numero % i == 0)
		{
			contadorDivisibles++;
		}
	}
	return contadorDivisibles;
}
