
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int retorna un 0 si salio OK, un -1 si los punteros son NULL o un -2 si hubo un error en el parseo o un -3 si unPasajero volvio NULL
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno;
	char id[6];
	char nombre[50];
	char apellido[50];
	char tipoPasajero[50];
	char precio[50];
	char codigoVuelo[10];
	char estadoVuelo[50];
	Passenger* unPasajero;
	int parseoCorrecto;

	retorno = -1;
	parseoCorrecto = 0;

	parseoCorrecto = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do{
			parseoCorrecto = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			if(parseoCorrecto == 7)
			{
				unPasajero = Passenger_newParametros(id, nombre, tipoPasajero, apellido, precio, codigoVuelo, estadoVuelo);

				if(unPasajero != NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
					retorno = 0; // se agrego exitosamente unPasajero
				}
				else{
					retorno = -3; // unPasajero volvio NULL
					break;
				}
			}
		}while(!feof(pFile));
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int	-1 si los punteros ingresan NULL
 * 				0 parseo ok
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno;
	Passenger* pasajero;

	retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			pasajero = Passenger_new();
			fread(pasajero, sizeof(Passenger), 1, pFile);
			if(pasajero != NULL)
			{
				ll_add(pArrayListPassenger, pasajero);
				retorno = 0;
			}
		}while(!feof(pFile));
	}

    return retorno;
}
