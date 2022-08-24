/*
 * funciones.c
 *
 *  Created on: 2 may. 2022
 *      Author: moreescudero
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estructuras.h"


float validarFloat(float precio, char error[], int min){
	while(precio <= min)
		{
			printf("%s",error);
			scanf("%f", &precio);
		}

	return precio;
}

int validarInt(int num, char error[], int min, int max){
	while( num > max || num < min)
		{
			printf("%s",error);
			scanf("%d", &num);
		}
	return num;
}

int validarChar(char texto[], int tam){
	int ok;

	if(strlen(texto) > tam)
	{
		ok = 0;
	}
	else{
		ok = 1;
	}

	return ok;

}

int getInt(char texto[], char error[], int min, int max){
	int id;

	printf("%s", texto);
	scanf("%d", &id);

	id = validarInt(id ,error , min, max);

	return id;
}

float getFloat(char texto[], char error[], int min){
	float precio;

	printf("%s", texto);
	scanf("%f", &precio);

	precio = validarFloat(precio, error, min);

	return precio;
}


void getChar(char texto[],int tam, char mensaje[]){
	int ok;

	printf("%s", mensaje);
	fpurge(stdin);
	scanf("%[^\n]", texto);

	ok = validarChar(texto, tam);

	if(ok == 0)
	{
		printf("\nERROR, por favor no se exceda en la cantidad de caracteres: ");
		fpurge(stdin);
		scanf("%[^\n]", texto);
	}

}

int cantidadSXX(eAlbum listaAlbum[], int tam, int indicador){
	int contador;
	int i;

	contador = 0;

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].fecha.anio <= 1999)
		{
			if(indicador == 1)
			{
				contador++;
			}
			else{
				if(contador > 0)
				{
					printf("\n%d\t\t%s", listaAlbum[i].idAlbum, listaAlbum[i].titulo);
				}
			}
		}
	}
	if(contador == 0)
	{
		printf("\nNo se encontraron albumes publicados antes del 01/01/2000");
	}
	return contador;
}

void cantidadAlbumesTipoAlbumGenero(eAlbum listaAlbum[],int tam, eGenero listaGenero[], int tamGenero,eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	int respuestaTipo;
	int respuestaGenero;
	int contadorTipoAlbumes;
	int contadorGenero;
	int i;

	contadorTipoAlbumes = 0;
	contadorGenero = 0;

	listadoTipoAlbumes(listaTipoAlbumes, tamTipoAlbumes);
	respuestaTipo = getInt("\nIngrese el ID del tipo de Album del que desea saber la cantidad: ","\nERROR, ingrese un ID de tipo de album valido: ",1,3);

	for(i = 0; i<tam;i++)
	{
		if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].idTipoAlbum == respuestaTipo)
		{
			contadorTipoAlbumes++;
		}
	}

	listadoGenero(listaGenero, tamGenero);
	respuestaGenero = getInt("\nIngrese el ID del genero del que desea saber la cantidad: ","\nERROR, ingrese un ID de un genero valido: ",1,3);
	for(i = 0; i<tam;i++)
	{
		if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].idTipoAlbum == respuestaGenero)
		{
			contadorGenero++;
		}
	}

	printf("\nLa cantidad de albumes que hay del tipo de album ingresado es: %d",respuestaTipo);
	printf("\nLa cantidad de albumes que hay del genero ingresado es: %d",respuestaGenero);

}

void promediarPrecios(eAlbum listaAlbum[], int tam, int indicador){
	int contadorMasCaros;
	float acumulador;
	float auxPrecio;
	float promedio;
	int contador;
	int i;

	contadorMasCaros = 0;
	acumulador = 0;
	contador = 0;

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].isEmpty == 0)
		{
			auxPrecio = listaAlbum[i].precio;
			acumulador += auxPrecio;
			contador ++;
		}
	}

	promedio = acumulador / contador;

	for(i=0;i<tam;i++)
	{
		if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].precio > promedio)
		{
			if(indicador == 1)
			{
				contadorMasCaros++;
			}
			else{
				printf("\n%d\t\t%s", listaAlbum[i].idAlbum, listaAlbum[i].titulo);
			}
		}
	}
	if(indicador == 1)
	{
		printf("\nEl total de importes es: $%.2f", acumulador);
		printf("\nEl promedio es: $%.2f", promedio);
		printf("\nHay %d albumes que superan el promedio.",contadorMasCaros);
	}

}
