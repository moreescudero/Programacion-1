/*
 * arrayPassenger.h
 *
 *  Created on: 4 may. 2022
 *      Author: moreescudero
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TAM 51
#define TAM_FC 10
#define ACTIVO 1
#define DEMORADO 2
#define INACTIVO 3

typedef struct{
	int id;
	int idEstado;//agregado
	char name[TAM];
	char lastName[TAM];
	float price;
	char flycode[TAM_FC];
	int typePassenger;
	int isEmpty;
}Passenger;



//INICIALIZAR

//	@fn		int initPassengers(Passenger* list, int len)
//	@brief	inicializa el array en isEmpty (TRUE = 1)
//	@param	Passenger* list
//	@param	int len
//	@return si esta todo ok devuelve un 0, si ocurrio un problema devuelve un -1
int initPassengers(Passenger* list, int len);

//ALTAS

//	@fn		int buscarEspacioLibre(Passenger* list, int len)
//	@brief	busca un espacio libre para dar alta a un pasajero
//	@param	Passenger* list
//	@param	int len
//	@return si no encontro lugar devuelve un -1, sino devuelve el indice
int buscarEspacioLibre(Passenger* list, int len);

//	@fn		int ingresarAltas(Passenger* list, int len)
//	@brief	carga un pasajero llamando a las funciones cargarPasajero y addPassenger
//	@param	Passenger* list
//	@param	int len
//	@return devuelve un -1 si ocurrio un error, un -2 si no se encontro lugar en addPassenger o un 0 si esta todo ok
int ingresarAltas(Passenger* list, int len);

//	@fn		int addPassenger(Passenger* list, int len, int idEstado,int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
//	@brief	llama a buscarEspacioLibre y asigna todos los parametros al index que devuelve buscarEspacioLibre y luego llama a mostrarUnPasajero
//	@param	Passenger* list
//	@param	int len
//	@param	int idEstado
//	@param	int id
//	@param	char name[]
//	@param	char lastName[]
//	@param	float price
//	@param	int typePassenger
//	@param	char flycode[]
//	@return retorna un -2 si no se encontro lugar en addPassenger o un 0 si esta todo ok
int addPassenger(Passenger* list, int len, int idEstado,int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

//	@fn		Passenger cargarUnPasajero(void)
//	@brief	pide todos los datos que necesiten ser ingresados por el usuario y llama a generarId
//	@param	-
//	@return devuelve un aux de la estructura
Passenger cargarUnPasajero(void);

//	@fn		void mostrarUnPasajero(Passenger list)
//	@brief	imprime todos los datos de un pasajero especifico
//	@param	Passenger list
//	@return -
void mostrarUnPasajero(Passenger list);

//MODIFICAR

//	@fn		int buscarId(void)
//	@brief	pide que el usuario ingrese el ID que necesita modificar o dar de baja
//	@param	-
//	@return retorna el id
int buscarId(void);

//	@fn		int findPassengerById(Passenger* list, int len, int id)
//	@brief	recorre el array de list buscando el id que coincida con el que ingresa el usuario
//	@param	Passenger* list
//	@param	int len
//	@param	int id
//	@return devuelve -1 si ocurrio un error o el id
int findPassengerById(Passenger* list, int len, int id);

//	@fn		int modificarPasajero(Passenger* list, int len)
//	@brief	llama a buscarId, a findPassengerById, si lo encuentra, llama a mostrarUnPasajero para que el usuario pueda ver
//			lo que puede modificar, muestra el menu modificar y segun la opcion que elija el usuario modifca el dato
//	@param	Passenger* list
//	@param	int len
//	@return devuelve un -1 si no se encuentra el id o 0 si esta todo ok
int modificarPasajero(Passenger* list, int len);

//BAJA

//	@fn		int removePassenger(Passenger* list, int len, int id)
//	@brief	da de baja un pasajero
//	@param	Passenger* list
//	@param	int len
//	@param	int id
//	@return retorna -1 si ocurrio un error, un 1 para salir del menu sin dar de baja y el 0 si se da de baja con exito
int removePassenger(Passenger* list, int len, int id);

//	@fn		int darBajaPasajero(Passenger* list, int len)
//	@brief	llama a buscarId y a removePassenger
//	@param	Passenger* list
//	@param	int len
//	@return retorna -1 si ocurrio un error,  un 1 para salir del menu sin dar de baja y el 0 si se da de baja con exito
int darBajaPasajero(Passenger* list, int len);

//INFORMAR

//	@fn		int calcularPromedio(Passenger* list, int length)
//	@brief	calcula el total, el promedio y los pasajeros que se pasaron del promedio
//	@param	Passenger* list
//	@param	int len
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int calcularPromedio(Passenger* list, int length);

//	@fn		int printPassengers(Passenger* list, int length, int byCodeOrByName)
//	@brief	imprime los pasajeros segun si fue ordenado por apellido o por codigo, en el ultimo caso solo muestra los que
//			tengan estado activo
//	@param	Passenger* list
//	@param	int len
//	@param	int byCodeOrByName
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int printPassengers(Passenger* list, int length, int byCodeOrByName);

//	@fn		int sortPassengersByName(Passenger* list, int len, int order, int byCodeOrByName)
//	@brief	ordena los pasajeros por apellido y, en caso de tener el mismo apellido los acomoda por tipo de pasajero
//	@param	Passenger* list
//	@param	int len
//	@param	int byCodeOrByName
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int sortPassengersByName(Passenger* list, int len, int order, int byCodeOrByName);

//	@fn		int sortPassengersByCode(Passenger* list, int len, int order, int byCodeOrByName)
//	@brief	ordena los pasajeros por codigo
//	@param	Passenger* list
//	@param	int len
//	@param	int byCodeOrByName
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int sortPassengersByCode(Passenger* list, int len, int order, int byCodeOrByName);

//	@fn		int informarListados(Passenger* list, int len)
//	@brief	muestra el menu de informar listado
//	@param	Passenger* list
//	@param	int len
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int informarListados(Passenger* list, int len);

//CARGA FORZADA

//	@fn		int cargaForzada(Passenger* list, int len)
//	@brief	hardcodea cinco pasajeros y llama a informarListados
//	@param	Passenger* list
//	@param	int len
//	@return retorna -1 si ocurrio un error o 0 si esta todo ok
int cargaForzada(Passenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
