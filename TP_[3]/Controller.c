
#include "Controller.h"


#define TAM 50
#define TAMCOD 10


static int idPasajeros;
static int flagId = 0;
static int generarId();
static int generarId(){;
	FILE* pArchivo;
	char id[TAMCOD];

	if(flagId== 0)
	{
		pArchivo = fopen("id.txt", "r");
		flagId = 1;
		fscanf(pArchivo, "%s", id);
		idPasajeros = atoi(id);
		fclose(pArchivo);
	}
	idPasajeros++;

	return idPasajeros;
}

static void guardarId();
static void guardarId(){;
	FILE* pArchivo;

	pArchivo = fopen("id.txt", "w");
	if(pArchivo != NULL)
	{
		fprintf(pArchivo, "%d", idPasajeros);
		fclose(pArchivo);
	}
}

/** \brief el usuario ingresa un id para buscar en la lista de linkedlist
 *
 * \param this LinkedList*
 * \param int cantidad
 * \return int el id ingresado
 *
 */
int Passenger_findById(LinkedList* this, int cantidad){
	int id;
	id = 0;


	if(this != NULL && cantidad > 0)
	{
		id = getInt("\n\nIngrese el ID del Pasajero: ", "\nERROR, por favor, ingrese un id valido", 0, cantidad);
	}

	return id;
	/*int id;
	int idAux;
	int i;
	Passenger* pasajero;

	id=0;
	if(this != NULL && cantidad > 0)
	{
		id = getInt("\n\nIngrese el ID del Pasajero: ", "\nERROR, por favor, ingrese un id valido", 0, cantidad);
		for(i=0;i<cantidad;i++)
		{
			Passenger_getId(pasajero, &idAux);
		}
	}

	return pasajero;*/

}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param int flag para saber si ya se cargo anteriormente el binario o el texto
 * \return int	-1 en caso de que pArrayListPassenger sea un puntero a NULL
 *				0 si salio todo ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int flag){
	int retorno;
	FILE* pArchivo;

	retorno = -1;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		if(flag == 0)
		{
			pArchivo = fopen(path, "r");

			if(pArchivo != NULL)
			{
				retorno = parser_PassengerFromText(pArchivo, pArrayListPassenger);
				fclose(pArchivo);
				if(retorno == 0)
				{
					printf("\nLos datos del archivo se cargaron con exito");
				}
			}
			else{
				retorno = -2; // error abriendo el archivo
			}
		}
		else{
			printf("\nLos datos ya han sido cargados.");
		}
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param int flag para saber si ya se cargo anteriormente el binario o el texto
 * \return int	-1 en caso de que pArrayListPassenger sea un puntero a NULL
 *				0 si salio todo ok
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int flag){
	int retorno;
	FILE* pArchivo;

	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL )
	{
		if(flag == 0 )
		{
			pArchivo = fopen(path, "rb");
			if(pArchivo != NULL)
			{
				retorno = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			}
		}
		else{
			printf("\nLos datos ya han sido cargados.");
		}
	}


    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int	-1 en caso de que pArrayListPassenger sea un puntero a NULL
 *				0 si salio todo ok
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){
	int retorno;
	Passenger* unPasajero;
	int id;
	float precio;
	char nombre[TAM], apellido [TAM], codigoVuelo[TAMCOD], tipoPasajero[TAM], estadoVuelo[TAM];
	int tPasajero, eVuelo;
	int i;

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		id = generarId();
		getChar(nombre, TAM, "\nIngrese el nombre del pasajero: ","\nERROR, por favor, ingrese un nombre valido: ", 0);
		for(i=0;i<TAM;i++)
		{
			nombre[i] = tolower(nombre[i]);
		}
		nombre[0] = toupper(nombre[0]);
		getChar(apellido, TAM, "\nIngrese el apellido del pasajero: ","\nERROR, por favor, ingrese un apellido valido: ", 0);
		for(i=0;i<TAM;i++)
		{
			apellido[i] = tolower(apellido[i]);
		}
		apellido[0] = toupper(apellido[0]);
		precio = getFloat("\nIngrese precio del vuelo: ", "\nERROR, por favor, ingrese un precio valido: ", 0);
		tPasajero = getInt("\nIngrese el tipo de pasajero:\n1-ExecutiveClass\t|\t2-FirstClass\t|\t3-EconomyClass\nOpcion: ", "\nERROR, por favor, ingrese un tipo de pasajero valido: ", 0, 4);
		eVuelo = getInt("\nIngrese el estado del vuelo del pasajero:\n1-EnVuelo\t|\t2-Aterrizado\t|\t3-EnHorario\nOpcion: ", "\nERROR, por favor, ingrese un estado de vuelo valido: ", 0, 4);
		getChar(codigoVuelo, TAMCOD, "\nIngrese codigo de vuelo del pasajero: ", "\nERROR, por favor, ingrese un codigo de vuelo valido: ", 1);
		for(i=0;i<TAMCOD;i++)
		{
			codigoVuelo[i] = toupper(codigoVuelo[i]);
		}

		switch(tPasajero)
		{
			case 1:
				strcpy(tipoPasajero,"ExecutiveClass");
				break;
			case 2:
				strcpy(tipoPasajero, "FirstClass");
				break;
			default:
				strcpy(tipoPasajero, "EconomyClass");
				break;
		}

		switch(eVuelo)
		{
			case 1:
				strcpy(estadoVuelo, "EnVuelo");
				break;
			case 2:
				strcpy(estadoVuelo, "Aterrizado");
				break;
			default:
				strcpy(estadoVuelo, "EnHorario");
				break;
		}


		unPasajero = Passenger_parametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
		if(unPasajero != NULL)
		{
			ll_add(pArrayListPassenger, unPasajero);
			retorno = 0;
		}
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int	-1 en caso de que pArrayListPassenger sea un puntero a NULL o si la lista todavia no fue cargada.
 *				0 si salio todo ok
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno;
	int error;
	int id;
	int opcion;
	char nombre[TAM], apellido[TAM], codigoVuelo[TAMCOD], tipoPasajero[TAM], estadoVuelo[TAM];
	float precio;
	int isEmpty;
	int i;
	int cantidad;
	int idAux;

	Passenger* pasajero = Passenger_new();

	isEmpty = ll_isEmpty(pArrayListPassenger);
	cantidad = ll_len(pArrayListPassenger);
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		if(isEmpty == 0)
		{
			error = controller_listPassenger(pArrayListPassenger);
			if(error == 0)
			{
				id = Passenger_findById(pArrayListPassenger, cantidad);
				for(i=0;i<cantidad; i++)
				{
					pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
					Passenger_getId(pasajero,&idAux);
					if(id == idAux)
					{
						break;
					}
				}
				if(pasajero != NULL)
				{
					printf("ID\t|\tNombre\t|\tApellido\t|\tCodigo Vuelo\t|  Precio  |\tEstado de Vuelo\n");
					Passenger_printOne(pasajero);
					retorno = 1; //es el retorno que quedara en caso de que el usuario salga de menu modificacion sin modificar nada
					do
					{
						opcion = getInt("\n\n-------Menu Modificacion-------\n\nDesea modificar:\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero\n5-Codigo de vuelo\n6-Estado de vuelo\n7-Salir del menu modificacion", "\nERROR, por favor, ingrese una opcion valida: ", 0, 8);
						switch(opcion)
						{
							case 1:
								getChar(nombre, TAM, "\nIngrese el nombre del pasajero: ","\nERROR, por favor, ingrese un nombre valido: ", 0);
								retorno = Passenger_setNombre(pasajero, nombre);
								break;
							case 2:
								getChar(apellido, TAM, "\nIngrese el apellido del pasajero: ","\nERROR, por favor, ingrese un apellido valido: ", 0);
								retorno = Passenger_setApellido(pasajero, apellido);
								break;
							case 3:
								precio = getFloat("\nIngrese precio del vuelo: ", "\nERROR, por favor, ingrese un precio valido: ", 0);
								retorno = Passenger_setPrecio(pasajero, precio);
								break;
							case 4:
								getChar(tipoPasajero, TAM, "\nIngrese el tipo de pasajero:\nExecutiveClass\t|\tFirstClass\t|\tEconomyClass\nOpcion: ", "\nERROR, por favor, ingrese un tipo de pasajero valido: ", 0);
								retorno = Passenger_setTipoPasajero(pasajero, tipoPasajero);
								break;
							case 5:
								getChar(codigoVuelo, TAMCOD, "\nIngrese codigo de vuelo del pasajero: ", "\nERROR, por favor, ingrese un codigo de vuelo valido: ", 1);
								retorno = Passenger_setCodigoVuelo(pasajero, codigoVuelo);
								break;
							case 6:
								getChar(estadoVuelo, TAM, "\nIngrese el estado del vuelo del pasajero:\n1 - EnVuelo\t\t2 - Aterrizado\t\t3 - EnHorario\nOpcion: ", "\nERROR, por favor, ingrese un estado de vuelo valido: ", 0);
								retorno = Passenger_setEstado(pasajero, estadoVuelo);
								break;
							default:
								printf("\nSaliendo del menu modificacion...");
						}
					}while(opcion != 7);
					if(retorno == 0)
					{
						retorno = ll_set(pArrayListPassenger, id, pasajero);
					}

				}
			}
		}
		else{
			printf("\nPara modificar primero tienes que cargar la lista.");
		}
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int	-1 en caso de que pArrayListPassenger sea un puntero a NULL o si la lista todavia no fue cargada.
 *				0 si salio todo ok
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){
	int retorno;
	int error;
	int id;
	int respuesta;
	Passenger* pasajero;
	int isEmpty;
	int cantidad;
	int i;
	int idAux;

	isEmpty = ll_isEmpty(pArrayListPassenger);
	cantidad = ll_len(pArrayListPassenger);
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		if(isEmpty == 0)
		{
			error = controller_listPassenger(pArrayListPassenger);
			if(error == 0)
			{
				id = Passenger_findById(pArrayListPassenger, cantidad);
				for(i=0;i<cantidad; i++)
				{
					pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
					Passenger_getId(pasajero,&idAux);
					if(id == idAux)
					{
						break;
					}
				}
				if(pasajero != NULL)
				{
					printf("ID\t|\tNombre\t|\tApellido\t|\tCodigo Vuelo\t|  Precio  |\tEstado de Vuelo\n");
					Passenger_printOne(pasajero);
					respuesta = getInt("\n¿Seguro que desea eliminar este pasajero?\n1-Si\t\t\t2-No\nIngrese su respuesta: ", "\nERROR, por favor, ingrese una respuesta valida: ", 0,3);
					if(respuesta == 1)
					{
						Passenger_delete(pasajero);
						error = ll_remove(pArrayListPassenger, i);
						printf("%d", error);
					}
					else{
						printf("\nSaliendo de baja de pasajero");
					}
					retorno = 0;
				}

			}
		}
		else{
			printf("\nPara dar de baja un pasajero primero tienes que cargar la lista.");
		}
	}


    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int	-1 en caso de que pArrayListPassenger sea un puntero a NULL o si la lista todavia no fue cargada.
 *				0 si salio todo ok
 */
int controller_listPassenger(LinkedList* pArrayListPassenger){
	int retorno;
	Passenger* pasajero;
	int cantidad;
	int i;
	//int isEmpty;

	retorno = -1;
	cantidad = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
		if(cantidad > 0)
		{
			printf("%4s|%15s|%15s|%10s|%15s|%4s|%15s\n","ID","Nombre","Apellido","Codigo Vuelo","Tipo Pasajero","Precio","Estado de Vuelo\n");
			for(i=0;i<cantidad;i++)
			{
				pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				Passenger_printOne(pasajero);
			}
			retorno = 0;
		}
		else{
			printf("\nPara listar primero tienes que cargar la lista.");
		}
	}

    return retorno;
}

/** \brief Ordena pasajeros, llama a ll_sort pasandole el puntero a funcion segun la opcion que elija el usuario en el submenu
 *
 * \param pArrayListPassenger LinkedList*
 * \return int retorna 	-1 en caso de que pArrayListPassenger sea un puntero NULL o si la lista todavia no fue cargada.
 * 						0 en caso de que haya salido OK el ordenamiento
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger){
	int retorno;
	int opcion;
	int orden;
	int isEmpty;

	isEmpty = ll_isEmpty(pArrayListPassenger);

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		if(isEmpty == 0)
		{
			do{
				opcion = getInt("\n\n-------Menu Ordenar-------\n\nDesea ordenar el archivo por:\n1-Apellido\n2-Nombre\n3-Id\n4-Precio\n5-Tipo Pasajero\n6-Estado\n7-Salir del menu ordenar\nIngrese su opcion: ", "\nERROR, por favor, ingrese una opcion valida: ", 0, 8);
				if(opcion != 7)
				{
					orden = getInt("\nDesea que sea de manera:\n1-Ascendente \n0-Descendente \nIngrese su opcion: ", "\nERROR, por favor, ingrese una opcion valida: ", -1, 2);
				}
				retorno = 1;

				switch(opcion)
				{
					case 1:
						retorno = ll_sort(pArrayListPassenger, Passenger_compareByApellido, orden);
						break;
					case 2:
						retorno = ll_sort(pArrayListPassenger, Passenger_compareByNombre, orden);
						break;
					case 3:
						retorno = ll_sort(pArrayListPassenger, Passenger_compareById, orden);
						break;
					case 4:
						retorno = ll_sort(pArrayListPassenger, Passenger_compareByPrecio, orden);
						break;
					case 5:
						retorno = ll_sort(pArrayListPassenger, Passenger_compareByTipoPasajero, orden);
						break;
					case 6:
						retorno = ll_sort(pArrayListPassenger, Passenger_compareByEstado, orden);
						break;
					default:
						printf("\nVolviendo al menu principal...");
						break;
				}
				if(retorno == 0)
				{
					retorno = controller_listPassenger(pArrayListPassenger);
				}
			}while(opcion != 7);
		}
		else{
			printf("\nPara ordenar primero tienes que cargar la lista");
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int retorna 	-1 si los punteros recibidos como parametros apuntan a NULL o en caso de no haber cargado la lista.
 * 						0 si se guardo exitosamente
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){
	int retorno;
	FILE* pArchivo;
	int cantidad;
	int i;
	Passenger* pasajero;
	int id;
	char nombre[TAM], apellido [TAM], codigoVuelo[TAMCOD], tipoPasajero[TAM], estadoVuelo[TAM];
	float precio;
	int isEmpty;

	isEmpty = ll_isEmpty(pArrayListPassenger);

	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(isEmpty == 0)
		{
			pArchivo = fopen(path, "w");
			cantidad = ll_len(pArrayListPassenger);
			if(pArchivo != NULL && cantidad > 0)
			{
				fprintf(pArchivo, "ID,Name,LastName,Price,Flycode,TypePassenger,StatusFlight");
				for(i=0; i<cantidad;i++)
				{
					pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
					Passenger_getId(pasajero, &id);
					Passenger_getNombre(pasajero, nombre);
					Passenger_getApellido(pasajero, apellido);
					Passenger_getPrecio(pasajero, &precio);
					Passenger_getCodigoVuelo(pasajero, codigoVuelo);
					Passenger_getTipoPasajero(pasajero, tipoPasajero);
					Passenger_getEstado(pasajero, estadoVuelo);

					fprintf(pArchivo, "%d,%s,%s,%.2f,%s,%s,%s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
				}
				fclose(pArchivo);
				guardarId();
				retorno = 0;
			}
		}
		else{
			printf("\nPara guardar primero tienes que cargar la lista.");
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int	-1 si los punteros recibidos como parametros apuntan a NULL o en caso de no haber cargado la lista.
 * 				0 si guardo ok
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno;
	int isEmpty;
	int cantidad;
	FILE* pArchivo;
	Passenger* pasajero;
	int i;

	isEmpty = ll_isEmpty(pArrayListPassenger);

	cantidad = ll_len(pArrayListPassenger);

	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(isEmpty == 0)
		{
			pArchivo = fopen(path, "wb");
			if(pArchivo != NULL)
			{
				for(i=0;i<cantidad;i++)
				{
					pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
					if(pasajero != NULL)
						fwrite(pasajero, sizeof(Passenger), 1, pArchivo);
				}
				guardarId();
				retorno = 0;
			}
		}
		else{
			printf("\nPara guardar primero tienes que cargar la lista.");
		}
	}

    return retorno;
}



