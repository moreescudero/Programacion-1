/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"
#include "funciones.h"

#define CANT 2000

int main(void) {

	int huboError;
	int respuesta;

	Passenger listaPasajeros[CANT];

	huboError = initPassengers(listaPasajeros, CANT);

	if(huboError == 0)
	{
		do{
			respuesta = getInt("\n\nMenu principal\n1- ALTAS\n2- MODIFICAR\n3- BAJA\n4- INFORMAR\n5- CARGA FORZADA\n6- SALIR\nIngrese una opcion: ", "\nERROR, por favor ingrese una opcion valida del menu: ", 1, 6);

			switch(respuesta)
			{
				case 1:
					huboError = ingresarAltas(listaPasajeros, CANT);
					switch(huboError)
					{
						case -2:
							printf("\nNo se encontro lugar disponible para ingresar al pasajero\n");
						break;
						default:
							printf("\nSe ingreso al pasajero con exito!!\n");
						break;
					}
				break;
				case 2:
					huboError = modificarPasajero(listaPasajeros, CANT);
				break;
				case 3:
					huboError = darBajaPasajero(listaPasajeros, CANT);
				break;
				case 4:
					huboError = informarListados(listaPasajeros, CANT);
				break;
				case 5:
					huboError = cargaForzada(listaPasajeros, 5);
				break;
				default:
					printf("Saliendo del programa...");
				break;
			}
			if(huboError == -1)
			{
				printf("\nOcurrio un error\n");
			}

		}while(respuesta != 6);
	}
	else{
		printf("Ocurrio un error al inicializar los datos.");
	}

	return 0;
}
