/*
 ============================================================================
 Name        : PrimerParcial-Laboratorio.c
 Author      : Escudero, Morena Nazareth
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

#define LEN_GEN 3
#define LEN_TIPO 2
#define LEN_ART 13
#define LEN_TIPOALBUM 3
#define CANT 1000

int main(void){

	int respuesta;
	int huboError;
	int banderaAltas;

	eAlbum listaAlbum[CANT];
	eGenero listaGenero[LEN_GEN];
	eArtista listaArtistas[LEN_ART];
	eTipoArtista listaTipos[LEN_TIPO];
	eTipoAlbum listaTipoAlbum[LEN_TIPOALBUM];

	banderaAltas = 0;

	//INICIALIZO
	inicializarAlbum(listaAlbum, CANT);

	inicializarGenero(listaGenero, LEN_GEN);

	inicializarArtistas(listaArtistas, LEN_ART);

	inicializarTipoArtista(listaTipos, LEN_TIPO);

	inicializarTipoAlbum(listaTipoAlbum, LEN_TIPOALBUM);

	do
	{
		respuesta = mostrarMenu("\n\nMenu de opciones:\n1- ALTAS\n2- MODIFICAR\n3- BAJA\n4- INFORMAR\n5- LISTAR\n6- SALIR\nIngrese una opcion: ", "\nERROR, por favor, ingrese una opcion valida: ", 0,7);
		switch(respuesta)
		{
			case 1:
				huboError = ingresarAltas(listaAlbum, CANT, listaGenero, LEN_GEN, listaArtistas, LEN_ART, listaTipos, LEN_TIPO,listaTipoAlbum,LEN_TIPOALBUM);
				switch(huboError)
				{
					case -1:
						printf("\nNo hay espacio :(");
					break;
					default:
						banderaAltas = 1;
						printf("\nAlbum cargado!");
					break;
				}
			break;
			case 2:
				if(banderaAltas == 1)
				{
					huboError = modificarId(listaAlbum, CANT, listaGenero, LEN_GEN, listaArtistas, LEN_ART, listaTipos, LEN_TIPO,listaTipoAlbum,LEN_TIPOALBUM);
					if(huboError == -1)
					{
						printf("\nNo se ha encontrado el id para modificar");
					}
				}
				else{
					printf("\nNo hay albumes ingresados.");
				}
			break;
			case 3:
				if(banderaAltas == 1)
				{
					huboError = darBaja(listaAlbum, CANT);
					if(huboError == -1)
					{
						printf("\nNo se encontro album para dar de baja");
					}
				}
				else{
					printf("\nNo hay albumes ingresados.");
				}
			break;
			case 4:
				if(banderaAltas == 1)
				{
					huboError = informar(listaAlbum, CANT, listaGenero, LEN_GEN, listaTipoAlbum, LEN_TIPOALBUM);
					if(huboError == -1)
					{
						printf("\nOcurrio un error");
					}
				}
				else{
					printf("\nNo hay albumes ingresados.");
				}
			break;
			case 5:
				if(banderaAltas == 1)
				{
					huboError = listar(listaAlbum, CANT, listaGenero, LEN_GEN, listaArtistas, LEN_ART, listaTipos, LEN_TIPO,listaTipoAlbum,LEN_TIPOALBUM);
					if(huboError == -1)
					{
						printf("\nOcurrio un error");
					}
				}
			break;
			default:
				printf("\nSaliendo del programa...");
			break;
		}

	}while(respuesta != 6);

	return 0;
}

