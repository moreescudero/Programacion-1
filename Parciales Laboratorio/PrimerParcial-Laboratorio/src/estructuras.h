/*
 * estructuras.h
 *
 *  Created on: 30 abr. 2022
 *      Author: moreescudero
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#define TAM 51

typedef struct
{
	int idGenero;
	char descripcion[TAM];
}eGenero;

typedef struct
{
	int idTipoAlbum;
	char descripcion[TAM];
}eTipoAlbum;

typedef struct
{
	int idTipoArtista;
	char descripcion[TAM];
}eTipoArtista;

typedef struct
{
	int idArtista;
	char nombreArtista[TAM];
}eArtista;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFechaPublicacion;

typedef struct
{
	int idTipoArtista;
	int idGenero;
	int idArtista;
	int idTipoAlbum;
	int idAlbum;
	char titulo[TAM];
	float precio;
	int isEmpty;
	eFechaPublicacion fecha;
}eAlbum;

//MENU

//	@fn		int mostrarMenu(char[], char[], int, int)
//	@brief	funcion reutilizable para poder mostrar un menu de opciones llama a validarInt para que valide que la respuesta sea correcta
//	@param	char menu[] contiene el menu de opciones completo para printearlo al usuario
//	@param	char error[] contien el mensaje de error que se pasara como parametro a la funcion de validarInt en caso de que
//			el usuario elija una opcion invalida
//	@param	int min el numero minimo de opcion permitida para ingresar
//	@param	int max el numero maximo de opcion permitida para ingresar
//	@return	retorna la respuesta elegida por el usuario
int mostrarMenu(char menu[], char error[], int min, int max);

//INICIALIZAR ESTRUCTURAS

//	@fn		void inicializarTipoArtista(eTipoArtista listaTipos[], int tam)
//	@brief	hardcodea los tipos de artista, inicializandolos
//	@param	listaTipos[] vector que inicializara la estructura de eTipoArista
//	@param	tam tamaño del array listaTipos[]
//	@return	-
void inicializarTipoArtista(eTipoArtista listaTipos[], int tam);

//	@fn		void inicializarGenero(eGenero listaGenero[], int tam)
//	@brief	hardcodea los generos musicales, inicializandolos
//	@param	listaGenero[] vector que inicializara la estructura de eGenero
//	@param	tam tamaño del array listaGenero[]
//	@return	-
void inicializarGenero(eGenero listaGenero[], int tam);

//	@fn		void inicializarArtistas(eArtista listaArtistas[], int tam)
//	@brief	hardcodea los artistas, inicializandolos
//	@param	listaArtistas[] vector que inicializara la estructura de eArtista
//	@param	tam tamaño del array listaArtistas[]
//	@return	-
void inicializarArtistas(eArtista listaArtistas[], int tam);

//	@fn		void inicializarAlbum(eAlbum listaAlbum[])
//	@brief	inicializa la estructura eAlbum indicando que todos los lugares de isEmpty son TRUE (1)
//	@param	listaAlbum[] vector que inicializara la estructura de eAlbum
//	@param	tam tamaño del array listaAlbum[]
//	@return	-
void inicializarAlbum(eAlbum listaAlbum[], int tam);

//	@fn		void inicializarTipoAlbum(eTipoAlbum, int tam)
//	@brief	hardcodea los tipos de album, inicializandolos
//	@param	listaTipoAlbum[] vector que inicializara la estructura de eTipoAlbum
//	@param	tam tamaño del array listaTipoAlbum[]
//	@return	-
void inicializarTipoAlbum(eTipoAlbum listaTipoAlbum[], int tam);

//ALTAS

//	@fn		int buscarEspacioLibre(eAlbum listaAlbum[], int tam)
//	@brief	busca un espacio en el vector
//	@param	listaAlbum[] recorrera el vector buscando un espacio libre (isEmpty == 1)
//	@param	tam tamaño del array listaAlbum[]
//	@return	retorna -1 en caso de no encontrar espacio y retorna el indice si se encontro un espacio
int buscarEspacioLibre(eAlbum listaAlbum[], int tam);

//	@fn		int ingresarAltas(eAlbum listaAlbum[], int tam))
//	@brief	llama a buscarEspacioLibre en el array, de encontrarlo llama a la funcion cargarAlbum y a generarId, indica
//			que ese espacio esta ocupado por el album y tambien llama a mostrarAlbum para que el usuario pueda ver
//			el resultado final de los datos cargados y sepa si hay algo que desee modificar
//	@param	listaAlbum[] guardara el album cargado en la estructura de eAlbum segun el indice proporcionado
//	@param	tam tamaño del array listaAlbum[], lo pasara como parametro a buscarEspacioLibre
//	@return	retorna -1 en caso de no encontrar espacio y retorna 0 si se ingreso el alta correctamente
int ingresarAltas(eAlbum listaAlbum[], int tam, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);

//	@fn		eAlbum cargarUnAlbum(void)
//	@brief	llama a getInt, getFloat y getChar hasta completar los datos que necesiten ser cargados por el cliente.
//	@param	-
//	@return	retorna la estructura de eAlbum para ser cargada en IngresarAltas
eAlbum cargarUnAlbum( eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);

//	@fn		void mostrarUnAlbum(eAlbum listaAlbum)
//	@brief	printea todos los datos ingresados por el usuario y ademas printea el ID que se le fue generado al album
//			en caso de que desea realizar una baja o modificacion.
//	@param	listaAlbum[] imprimira el album cargado en la estructura de eAlbum
//	@return	-
void mostrarUnAlbum(eAlbum listaAlbum);

//MODIFICAR

//	@fn		int buscarId(void)
//	@brief	buscar el Id para modificar el album o darlo de baja
//	@param	-
//	@return	retorna el id a modificar
int buscarId(void);

//	@fn		int modificarId(eAlbum listaAlbum[], int tam)
//	@brief	llama a buscarId y en caso de haber encontrado el ID llama a mostrarMenu para que el usuario elija el dato que
//			desee modificar
//	@param	listaAlbum[] actualizado con el nuevo dato modificado
//	@param	tam tamaño del array listaAlbum[], lo recorre en busca del ID
//	@return	retorna -1 en caso de no encontrar el id o 0 en caso de haberlo encontrado
int modificarId(eAlbum listaAlbum[], int tam, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);

//BAJA

//	@fn		int darBaja(eAlbum listaAlbum[], int tam)
//	@brief	llama a buscarId, en caso de encontrarlo llama a mostrarUnAlbum y pregunta si desea darlo de baja, en caso de que
//			la respuesta sea 's' reemplaza isEmpty = 0 por isEmpty = -1 en caso de necesitar recuperarlo en un futuro
//	@param	listaAlbum[] da de baja los datos cargados
//	@param	tam tamaño del array listaAlbum[], lo recorre en busca del ID
//	@return	retorna -1 en caso de no encontrar el id o 0 en caso de haberlo encontrado
int darBaja(eAlbum listaAlbum[], int tam);

//INFORMAR

//	@fn		int informar(eAlbum listaAlbum[], int tam)
//	@brief	llama a mostrarMenu y en funcion de la respuesta proporcionada por el usuario llama a promediarPrecios o a cantidadSXX
//	@param	listaAlbum[] lo pasa como parametro a las funciones promediarPrecios y cantidadSXX
//	@param 	tam lo pasa como parametro a las funciones promediarPrecios y cantidadSXX
//	@return	retorna -1 en caso de que listaAlbum sea NULL o 0 si esta OK
int informar(eAlbum listaAlbum[],int tam, eGenero listaGenero[], int tamGenero,eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);

//LISTAR

//	@fn		int listar(eAlbum listaAlbum[], int tamAlbum, eGenero listadoGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos)
//	@brief	llama a mostrarMenu y en funcion de la respuesta proporcionada por el usuario llama a las 10 funciones de listado
//	@param	recibe todos los arrays de todas las entidades (excepto eFecha) con sus respectivos tamaños para enviarlas como parametros a
//			las funciones que llama
//	@return	retorna -1 en caso de que listaAlbum sea NULL o 0 si esta OK
int listar(eAlbum listaAlbum[], int tamAlbum, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);

//	@fn		void listadoGenero(eGenero listaGenero[], int tam)
//	@brief	printea todos los generos hardcodeados
//	@param	listaGenero[] vector que contiene los datos hardcodeados
//	@param	tam tamaño del vector
//	@return	-
void listadoGenero(eGenero listaGenero[], int tam);

//	@fn		void listadoTiposArtistas(eTipoArtista listaTipos[], int tam)
//	@brief	printea todos los tipos de artistas hardcodeados
//	@param	listaTipos[] vector que contiene los datos hardcodeados
//	@param	tam tamaño del vector
//	@return	-
void listadoTiposArtistas(eTipoArtista listaTipos[], int tam);

//	@fn		void listadoArtistas(eArtista listaArtistas[], int tam)
//	@brief	printea todos los artistas hardcodeados
//	@param	listaGenero[] vector que contiene los datos hardcodeados
//	@param	tam tamaño del vector
//	@return	-
void listadoArtistas(eArtista listaArtistas[], int tam);

//	@fn		void listadoTipoAlbumes(eTipoAlbum listaTipoAlbum[], int tam)
//	@brief	printea todos los artistas hardcodeados
//	@param	listaTipoAlbum[] vector que contiene los datos hardcodeados
//	@param	tam tamaño del vector
//	@return	-
void listadoTipoAlbumes(eTipoAlbum listaTipoAlbum[], int tam);

//	@fn		void listadoAlbumes(eAlbum listaAlbum[], int tam)
//	@brief	printea todos los albumes ingresados por el usuario
//	@param	listaAlbum[] vector que contiene los datos ingresados
//	@param	tam tamaño del vector
//	@return	-
void listadoAlbumes(eAlbum listaAlbum[], int tam);

//	@fn		void listadoAlbumArtista(eAlbum listaAlbum[], int tamAlbum, eArtista listaArtistas[], int tamArtista)
//	@brief	printea todos los artistas y los albumes que posean
//	@param	recibe como parametro los vectores de las entidades eAlbum y eArtista con sus respectivos tamaños para poder
//			recorrerlos y asi printearlo segun el matcheo del id del artista en cada vector.
//	@return	-
void listadoAlbumArtista(eAlbum listaAlbum[], int tamAlbum, eArtista listaArtistas[], int tamArtista);

//	@fn		int buscarAnio(eAlbum listaAlbum[], int tam)
//	@brief	llama a la funcion getInt para que el usuario ingrese el año que desea buscar y luego recorre el vector en busca
//			de matchear el año cargado en listaAlbum[] y el ingresado, de no encontrarlo se informa
//	@param	listaAlbum[] vector que contiene los datos ingresados
//	@param	tam tamaño del vector
//	@param	indicador
//	@return	1 si ok, el anio si el indicador es 2
int buscarAnio(eAlbum listaAlbum[], int tam, int indicador);

//	@fn		void mostrarAlbumesMasCaros(eAlbum listaAlbum[], int tam)
//	@brief	busca en el vector el precio maximo ingresado y lo guarda en una variable auxiliar, luego los compara con los
//			datos ingresados para mostrar al usuario el album mas caro o en caso de haber mas de uno, tambien los mostrara.
//	@param	listaAlbum[] vector que contiene los datos ingresados
//	@param	tam tamaño del vector
//	@return	-
void mostrarAlbumesMasCaros(eAlbum listaAlbum[], int tam);

//	@fn		void listadoImporteTitulo(eAlbum listaAlbum[], int tam)
//	@brief	ordena el importe de manera descendente y el titulo de manera ascendente en caso de que el importe sea el en mas de un album.
//	@param	listaAlbum[] vector que contiene los datos ingresados
//	@param	tam tamaño del vector
//	@return	-
void listadoImporteTitulo(eAlbum listaAlbum[], int tam);

//	@fn		void listadoAlbumesNoSonVinilo(eAlbum listaAlbum[], int tamAlbum, eTipoAlbum listaTipoAlbum[], int tamTipo)
//	@brief	imprime al usuario los albumes que hayan sido ingresados que no sean de tipo vinilo
//	@param	recibe como parametro los vectores de las entidades eAlbum y eTipoAlbum y sus respectivos tamaños para poder
//			recorrerlos y asi imprimir segun el matcheo del id del tipo de album mientras sea distinto de vinilo
//	@return	-
void listadoAlbumesNoSonVinilo(eAlbum listaAlbum[], int tamAlbum, eTipoAlbum listaTipoAlbum[], int tamTipo);

//	@fn		void listadoAlbumesViniloSegunArtista(eAlbum listaAlbum[], int tamAlbum, eTipoAlbum listaTipoAlbum[], int tamTipo, eArtista listaArtistas[], int tamArtista)
//	@brief	llama a la funcion listadoArtistas para que el usuario ingrese el ID del artista del cual desea comprobar si tiene vinilos llamando a getInt
//			y de ese artista tener un album de vinilo lo printeara o sino le indicara que el artista no tiene albumes de vinilo
//	@param	recibe como parametro los vectores de las entidades eAlbum y eTipoAlbum con sus respectivos tamaños para poder recorrerlos y asi imprimir el matcheo
//			del id tipo de album mientras este sea igual a vinilo. Ademas eArtista es recibido para enviarlo coomo parametro a listadoArtistas
//	@return	-
void listadoAlbumesViniloSegunArtista(eAlbum listaAlbum[], int tamAlbum, eTipoAlbum listaTipoAlbum[], int tamTipo, eArtista listaArtistas[], int tamArtista);

void listadoAlbumesSolistaDeUnAnio(eAlbum listaAlbum[], int tamAlbum, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes);


#endif /* ESTRUCTURAS_H_ */
