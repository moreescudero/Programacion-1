/*
 * arrayPassenger.c
 *
 *  Created on: 4 may. 2022
 *      Author: moreescudero
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"
#include "funciones.h"


static int idAPasajeros = 100;
static int generarId();
static int generarId(){;
	idAPasajeros++;
	return idAPasajeros;
}



//INICIALIZAR

int initPassengers(Passenger* list, int len){
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len >= 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

//ALTAS

Passenger cargarUnPasajero(void){
	Passenger aux;

	aux.id = generarId();
	getChar(aux.name , sizeof(aux.name),"\nIngrese el nombre del pasajero: ", "\nERROR, por favor, no se exceda del maximo de caracteres", 0);
	getChar(aux.lastName ,sizeof(aux.lastName), "\nIngrese el apellido del pasajero: ","\nERROR, por favor, no se exceda del maximo de caracteres", 0);
	aux.typePassenger = getInt("\nTipo de pasajero:\nID\t\tTIPO\n1\t\tTURISTA\n2\t\tEJECUTIVO\n\nIngrese ID del tipo de pasajero: ","\nERROR, por favor, ingrese un ID valido", 1,2);
	aux.price = getFloat("\nIngrese precio del vuelo: ","\nERROR, por favor, ingrese un precio valido",0);
	getChar(aux.flycode, sizeof(aux.flycode), "\nIngrese el codigo de vuelo (flycode): ","\nERROR, por favor, no se exceda del maximo de caracteres", 1);
	aux.idEstado = getInt("\nIngrese el ID del estado de vuelo:\nID\t\tESTADO\n1\t\tACTIVO\n2\t\tDEMORADO\n3\t\tINACTIVO\n\nIngrese ID del estado de vuelo: ","\nERROR, por favor, ingrese un ID valido", 1,3);

	return aux;
}


int buscarEspacioLibre(Passenger* list, int len){
	int indice;
	int i;
	indice = -1;

	if(list != NULL && len >= 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

void mostrarUnPasajero(Passenger list){
	printf("\nNombre del pasajero:  %s\nApellido del pasajero:  %s\nTipo de pasajero:  %d\nEstado de vuelo: %d\nCodigo del vuelo:  %s\nPrecio:  $%.2f\nID pasajero:  %d", 	list.name,
																																											list.lastName,
																																											list.typePassenger,
																																											list.idEstado,
																																											list.flycode,
																																											list.price,
																																											list.id);
}

int addPassenger(Passenger* list, int len, int idEstado, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]){
	int index;
	int retorno;

	retorno= -2;

	index = buscarEspacioLibre(list, len);
	if(index >= 0 )
	{
		list[index].isEmpty = 0;
		list[index].id = id;
		list[index].price = price;
		list[index].idEstado = idEstado;
		list[index].typePassenger = typePassenger;
		strncpy(list[index].name, name, sizeof(list[index].name));
		strncpy(list[index].lastName, lastName, sizeof(list[index].lastName));
		strncpy(list[index].flycode, flycode, sizeof(list[index].flycode));

		mostrarUnPasajero(list[index]);

		retorno = 0;
	}
	return retorno;
}

int ingresarAltas(Passenger* list, int len){
	int retorno;

	Passenger aux;

	retorno = -1;

	if(list != NULL && len >= 0)
	{
		aux = cargarUnPasajero();

		retorno = addPassenger(list, len, aux.idEstado,aux.id, aux.name, aux.lastName, aux.price, aux.typePassenger, aux.flycode);
	}

	return retorno;
}

//MODIFICAR

int findPassengerById(Passenger* list, int len, int id){
	int i;
	int index;

	index = -1;

	if(list != NULL && len >= 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				index = i;
			}
		}
	}
	return index;
}


int buscarId(void){
	int auxId;

	printf("\nId a modificar: ");
	scanf("%d", &auxId);

	return auxId;
}

int modificarPasajero(Passenger* list, int len){
	int retorno;
	int respuesta;
	int auxId;
	int index;

	retorno = -1;

	auxId = buscarId();

	if(list != NULL && len >= 0)
	{
		index = findPassengerById(list, len, auxId);
		if(index >= 0)
		{
			do{
				mostrarUnPasajero(list[index]);
				respuesta = getInt("\n\nMenu modificar\n1- Nombre\n2- Apellido\n3- Precio\n4- Tipo de pasajero\n5- Codigo de vuelo\n6- Salir\nIngrese la opcion que desee modificar: ", "\nERROR, por favor ingrese una opcion valida del menu: ", 1,6);

				switch(respuesta)
				{
					case 1:
						getChar(list[index].name ,sizeof(list[index].name), "\nIngrese el nombre del pasajero: ", "\nERROR, por favor, no se exceda del maximo de caracteres", 0);
					break;
					case 2:
						getChar(list[index].lastName ,sizeof(list[index].lastName), "\nIngrese el apellido del pasajero: ","\nERROR, por favor, no se exceda del maximo de caracteres", 0);
					break;
					case 3:
						list[index].price = getFloat("\nIngrese precio del vuelo: ","\nERROR, por favor, ingrese un precio valido",0);
					break;
					case 4:
						list[index].typePassenger = getInt("\nTipo de pasajero:\nID\t\tTIPO\n1\t\tTURISTA\n2\t\tEJECUTIVO\nIngrese ID del tipo de pasajero: ","\nERROR, por favor, ingrese un ID valido", 1,2);
					break;
					case 5:
						getChar(list[index].flycode,sizeof(list[index].flycode), "\nIngrese el codigo de vuelo (flycode): ","\nERROR, por favor, no se exceda del maximo de caracteres", 1);
					break;
					default:
						printf("\nSaliendo del menu de modificaciones...");
					break;
				}
			}while(respuesta != 6);
			retorno = 0;
		}
		else{
			printf("\nNo se encontro el ID del pasajero ingresado");
		}
	}

	return retorno;
}

//BAJA

int removePassenger(Passenger* list, int len, int id){
	int retorno;
	char respuesta;
	int i;

	retorno = -1;

	if(list != NULL && len >= 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				mostrarUnPasajero(list[i]);
				printf("\n¿Seguro desea dar de baja este album? (s/n) ");
				fpurge(stdin);
				scanf("%c", &respuesta);

				switch(respuesta)
				{
					case 's':
						list[i].isEmpty = 1;
						retorno = 0;
					break;
					default:
						printf("Volviendo al menu principal...");
						retorno = 1;
					break;
				}
				break;

			}
		}
	}
	return retorno;
}

int darBajaPasajero(Passenger* list, int len){
	int retorno;
	int auxId;

	auxId = buscarId();

	retorno = -1;

	if(list != NULL && len >= 0)
	{
		retorno = removePassenger(list, len, auxId);
		if(retorno == 0)
		{
			printf("\nSe dio de baja exitosamente");
		}
		else{
			printf("\nNo se encontro el ID del pasajero ingresado");
		}
	}

	return retorno;
}

//INFORMAR

int printPassengers(Passenger* list, int length, int byCodeOrByName){
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && length >= 0)
	{
		for(i=0; i<length; i++)
		{
			if(list[i].isEmpty == 0 )
			{
				if(byCodeOrByName == 1 )
				{
					printf("\n\nNombre del pasajero:  %s\nApellido del pasajero:  %s\nTipo de pasajero:  %d\nEstado de vuelo: %d\nCodigo del vuelo:  %s\nPrecio:  $%.2f\nID pasajero:  %d", 	list[i].name,
																																																list[i].lastName,
																																																list[i].typePassenger,
																																																list[i].idEstado,
																																																list[i].flycode,
																																																list[i].price,
																																																list[i].id);
				}
				else{
					if(byCodeOrByName == 3 && list[i].typePassenger == 1)
					{
						printf("\n\nNombre del pasajero:  %s\nApellido del pasajero:  %s\nTipo de pasajero:  %d\nEstado de vuelo: %d\nCodigo del vuelo:  %s\nPrecio:  $%.2f\nID pasajero:  %d", 	list[i].name,
																																																	list[i].lastName,
																																																	list[i].typePassenger,
																																																	list[i].idEstado,
																																																	list[i].flycode,
																																																	list[i].price,
																																																	list[i].id);

					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order, int byCodeOrByName){
	int i;
	int j;
	int retorno;
	int lenLimite;

	Passenger aux;

	retorno = -1;
	lenLimite = len - 1;

	if(list != NULL && len >= 0)
	{
		printf("\nLos pasajeros listados por codigo de vuelo y estado de vuelo activo son:\n");
		for(i=0; i<lenLimite; i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty == 0 && list[i].idEstado == 1 )
				{
					if(order == -1)
					{
						if((strcmp(list[i].flycode, list[j].flycode) < 0))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
					else{
						if((strcmp(list[i].flycode, list[j].flycode) < 0))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			lenLimite--;
		}
		retorno = printPassengers(list, len, byCodeOrByName);
	}

	return retorno;
}

int sortPassengersByName(Passenger* list, int len, int order, int byCodeOrByName){
	int i;
	int j;
	int lenLimite;
	int retorno;

	retorno = -1;
	lenLimite = len - 1;

	Passenger aux;

	if(list != NULL && len >= 0)
	{
		for(i=0; i< lenLimite; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == 0 && list[j].isEmpty == 0 )
				{
					if(order == -1)
					{
						if(	((strcmp(list[i].lastName, list[j].lastName) < 0))||
							((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].typePassenger >list[j].typePassenger ))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;

						}
					}
					else{
						if(	((strcmp(list[i].lastName, list[j].lastName) > 0))||
							((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].typePassenger >list[j].typePassenger ))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			lenLimite--;
		}

		printf("\n\nEl listado de pasajeros por apellido en orden alfabetico es:\n");

		retorno = printPassengers(list, len, byCodeOrByName);

	}

	return retorno;
}

int calcularPromedio(Passenger* list, int length){
	int i;
	int retorno;
	int contador;
	float acumulador;
	int contadorMasCaros;
	float promedio;
	int auxPrecio;

	retorno = -1;
	contador = 0;
	acumulador = 0;
	contadorMasCaros = 0;

	if(list != NULL && length >= 0)
	{
		for(i=0; i<length; i++)
		{
			if(list[i].isEmpty == 0)
			{
				auxPrecio = list[i].price;
				acumulador += auxPrecio;
				contador++;
			}
		}

		promedio = acumulador / contador;

		for(i=0; i<length; i++)
		{
			if(list[i].isEmpty == 0 && list[i].price > promedio)
			{
				contadorMasCaros++;
			}
		}

		printf("\nEl total de los precios de los pasajes es: $%.2f\nPromedio de los pasajes: $%.2f", acumulador, promedio);

		if(contadorMasCaros > 0)
		{
			printf("\nHay %d pasajeros que superan el precio promedio", contadorMasCaros);
		}
		else{
			printf("\nNo hay pasajeros que superen el precio promedio");
		}
		retorno = 0;
	}

	return retorno;
}

int informarListados(Passenger* list, int len){
	int retorno;
	int respuesta;
	int ordenar;


	retorno = -1;

	if( list != NULL && len >= 0 )
	{
		do
		{
			respuesta = getInt("\n\nMenu informar\n1- Listado de los pasajeros por apelllido en orden alfabetico y tipo de pasajero\n2- Total y promedio de los precios de los pasajes y los pasajeros que superan el precio promedio\n3- Listado de pasajeros por codigo de vuelo y estados de vuelos 'ACTIVO'\n4- Salir\nIngrese su opcion: ", "\nERROR, por favor ingrese una opcion valida del menu: ",1,4);

			switch(respuesta)
			{
				case 1:
					ordenar = getInt("\nElija cómo ordenar la lista\n1- Ordenar de la 'A' a la 'Z'\n2- Ordenar de la 'Z a la 'A'\nIngrese su opcion: ", "\nERROR, por favor, ingrese una opcion valida: ",1,2);
					if(ordenar == 2)
					{
						ordenar = -1;
					}
					retorno = sortPassengersByName(list, len, ordenar, respuesta);
				break;
				case 2:
					retorno = calcularPromedio(list, len);
				break;
				case 3:
					ordenar = getInt("\nElija cómo ordenar la lista\n1- Ordenar de manera ascendente\n2- Ordenar de manera descendente\nIngrese su opcion: ", "\nERROR, por favor, ingrese una opcion valida: ",1,2);
					if(ordenar == 2)
					{
						ordenar = -1;
					}
					retorno = sortPassengersByCode(list, len, ordenar, respuesta);
				break;
				default:
					printf("\n\nSaliendo del menu informar...\n");
				break;
			}
		}while(respuesta != 4);


	}

	return retorno;
}

//CARGA FORZADA

int cargaForzada(Passenger* list, int len){
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len >= 0)
	{
		//INICIALIZO
		Passenger aux[] = 	{
								{101, 2, "Laura Ana", "Merello", 126000, "ME1506", 2, 0},
								{102, 1, "Astor", "Piazzolla", 149000, "AG2602", 1, 0},
								{103, 1, "Carlos", "Gardel", 130000, "ME1506", 2, 0},
								{104, 1, "Eduardo", "Visconti", 114000, "RE2512", 1, 0},
								{105, 2, "Hugo", "Del Carril", 168000, "MK3011", 2, 0}
							};

		for(i=0; i<len; i++)
		{
			list[i] = aux[i];
		}

		retorno = informarListados(list,len);

	}
	return retorno;
}
