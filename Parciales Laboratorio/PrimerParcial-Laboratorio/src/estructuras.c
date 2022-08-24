/*
 * estructuras.c
 *
 *  Created on: 30 abr. 2022
 *      Author: moreescudero
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "funciones.h"

static int idAlbumIncremental = 100;
static int generarId();
static int generarId(){;
	idAlbumIncremental++;
	return idAlbumIncremental;
}

int mostrarMenu(char menu[], char error[], int min, int max){
	int respuesta;

	printf("%s", menu);
	scanf("%d", &respuesta);

	respuesta = validarInt(respuesta, error, min, max);

	return respuesta;
}

/*INICIALIZAR*/

void inicializarTipoArtista(eTipoArtista listaTipos[], int tamTipo){
	int i;
	eTipoArtista lista[] = 	{
										{1,"Solista"},
										{2,"Banda"}
									};
	for(i=0; i<tamTipo;i++)
	{
		listaTipos[i]=lista[i];
	}
}

void inicializarArtistas(eArtista listaArtistas[], int tam){
	int i;
	eArtista lista[] = 	{
							{1,"Arctic Monkeys"},
							{2,"Red Hot Chilli Peppers"},
							{3,"Fleetwood Mac"},
							{4,"Lenny Kravitz"},
							{5,"Lana Del Rey"},
							{6,"Lorde"},
							{7,"The Marias"},
							{8,"Harry Styles"},
							{9,"Soda Stereo"},
							{10,"Sumo"},
							{11,"Los Twist"},
							{12,"Charly Garcia"},
							{13, "Los Fabulosos Cadillac"}
						};
	for(i=0;i<tam;i++)
	{
		listaArtistas[i] = lista[i];
	}
}

void inicializarGenero(eGenero listaGenero[], int tam){
	int i;
	eGenero lista[] = 	{
									{1,"ROCK"},
									{2,"POP"},
									{3,"ROCK ARGENTINO"}
								};
	for(i=0; i<tam; i++)
	{
		listaGenero[i]=lista[i];
	}

}

void inicializarTipoAlbum(eTipoAlbum listaTipoAlbum[], int tam){
	int i;

	eTipoAlbum lista[] = 	{
								{1,"VINILO"},
								{2,"CINTA"},
								{3,"CD"}
							};

	for(i=0; i<tam; i++)
	{
		listaTipoAlbum[i]=lista[i];
	}
}

void inicializarAlbum(eAlbum listaAlbum[], int tam){
	int i;

	if(listaAlbum != NULL && tam >= 0)
	{
		for(i=0;i<tam;i++)
		{
			listaAlbum[i].isEmpty = 1;
		}
	}
}

/*ALTA*/

int buscarEspacioLibre(eAlbum listaAlbum[], int tam){
	int indice;
	int i;
	indice = -1;

	if(listaAlbum != NULL && tam >= 0)
	{
		for(i=0; i<tam; i++)
		{
			if(listaAlbum[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}


void listadoArtistas(eArtista listaArtistas[], int tam){
	int i;

	printf("\nLos artistas son:\nID\t\tNOMBRES");

	for(i=0;i<tam;i++)
	{
		printf("\n%d\t\t%s", listaArtistas[i].idArtista, listaArtistas[i].nombreArtista);
	}
}


void listadoGenero(eGenero listaGenero[], int tam){
	int i;

	printf("\nLos generos son:\nID\t\tGENERO");

	for(i=0;i<tam;i++)
	{
		printf("\n%d\t\t%s", listaGenero[i].idGenero, listaGenero[i].descripcion);
	}
}

void listadoTiposArtistas(eTipoArtista listaTipos[], int tam){
	int i;

	printf("\nLos tipos de artistas musicales son:\nID\t\tTIPOS");

	for(i=0;i<tam;i++)
	{
		printf("\n%d\t\t%s", listaTipos[i].idTipoArtista, listaTipos[i].descripcion);
	}
}


void listadoTipoAlbumes(eTipoAlbum listaTipoAlbum[], int tam){
	int i;

	printf("\nLos tipos de albumes son:\nID\t\tTIPOS ALBUMES");

	for(i=0; i<tam; i++)
	{
		printf("\n%d\t\t%s",listaTipoAlbum[i].idTipoAlbum, listaTipoAlbum[i].descripcion);
	}
}

eAlbum cargarUnAlbum( eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	eAlbum unAlbum;

	listadoArtistas(listaArtistas, tamArtista);
	unAlbum.idArtista = getInt("\n\nIngrese el id del Artista: ", "\nERROR, por favor ingrese un numero valido: ",1,13);

	getChar(unAlbum.titulo,sizeof(unAlbum.titulo), "\nIngresar el titulo del album: ");

	listadoTiposArtistas(listaTipos, tamTipos);
	unAlbum.idTipoArtista = getInt("\n\nIngrese su opcion: ", "\nERROR, por favor ingrese un numero valido: ", 1,2);

	listadoTipoAlbumes(listaTipoAlbumes, tamTipoAlbumes);
	unAlbum.idTipoAlbum = getInt("\n\nIngrese su opcion: ","\nERROR, por favor ingrese un numero valido",1,3);

	listadoGenero(listaGenero, tamGenero);
	unAlbum.idGenero = getInt("\n\nIngrese su opcion: ", "\nERROR, por favor ingrese un numero valido: ",1,3);

	unAlbum.fecha.dia = getInt("\nIngrese fecha de lanzamiento del album: \nDia: ","\nERROR, por favor ingrese un numero valido: ",1,31);

	unAlbum.fecha.mes = getInt("\t\tMes: ","\nERROR, por favor ingrese un numero valido: ",1,12);

	unAlbum.fecha.anio = getInt("\t\t\t\tAnio: ","\nERROR, por favor ingrese un numero valido: ",1948,2022);

	unAlbum.precio = getFloat("\nIngrese importe del album: ","\nERROR, por favor ingrese un numero valido: ",1);

	return unAlbum;
}

void mostrarUnAlbum(eAlbum listaAlbum){
	printf("\n\nID ARTISTA|ID TIPO ARTISTA|ID GENERO|ID TIPO ALBUM|\tTITULO\t|Precio|FECHA PUBLICACION|ID ALBUM\n");
	printf("%8d %8d %12d %12d %14s $%10.2f %10d/%d/%d %10d\n\n",listaAlbum.idArtista,
																listaAlbum.idTipoArtista,
																listaAlbum.idGenero,
																listaAlbum.idTipoAlbum,
																listaAlbum.titulo,
																listaAlbum.precio,
																listaAlbum.fecha.dia,
																listaAlbum.fecha.mes,
																listaAlbum.fecha.anio,
																listaAlbum.idAlbum);
}

int ingresarAltas(eAlbum listaAlbum[], int tam, eGenero listadoGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	int retorno;
	int indice;

	eAlbum aux;

	retorno = -1;

	if(listaAlbum != NULL && tam >= 0)
	{
		indice = buscarEspacioLibre(listaAlbum, tam);
		if(indice >= 0)
		{
				// CARGA DATOS QUE NO SON GENERICOS.
			aux = cargarUnAlbum(listadoGenero, tamGenero, listaArtistas, tamArtista, listaTipos, tamTipos, listaTipoAlbumes, tamTipoAlbumes);
				// CARGA DATOS QUE SON GENERICOS.
			aux.idAlbum = generarId();
			aux.isEmpty = 0;

			listaAlbum[indice] = aux;
			mostrarUnAlbum(listaAlbum[indice]);
			retorno = 0;
		}

	}

	return retorno;
}

/*MODIFICACION*/

int buscarId(void){
	int auxId;

	printf("\nId a modificar: ");
	scanf("%d", &auxId);

	return auxId;
}

int modificarId(eAlbum listaAlbum[], int tam, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	int opcionModificar;
	int auxId;
	int retorno;
	int i;

	retorno= -1;

	auxId = buscarId();

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].idAlbum == auxId && listaAlbum[i].isEmpty == 0)
		{
			do
			{
				mostrarUnAlbum(listaAlbum[i]);

				opcionModificar = mostrarMenu("\n\nMenu modificar\n1- ID tipo de artista\n2- ID genero musical\n3- ID artista\n4- Tipo de album\n5- Titulo del album\n6- Precio\n7- Fecha de lanzamiento\n8- Salir\nIngrese una opcion: ","\nERROR, por favor, ingrese una opcion valida: ", 1,8);

				switch(opcionModificar)
				{
					case 1:
						listadoTiposArtistas(listaTipos, tamTipos);
						listaAlbum[i].idTipoArtista = getInt("\n\nIngrese su opcion: ", "\nERROR, por favor ingrese un numero valido: ", 1,2);
					break;
					case 2:
						listadoGenero(listaGenero, tamGenero);
						listaAlbum[i].idGenero = getInt("\n\nIngrese su opcion: ", "\nERROR, por favor ingrese un numero valido: ",1,3);
					break;
					case 3:
						listadoArtistas(listaArtistas, tamArtista);
						listaAlbum[i].idArtista = getInt("\n\nIngrese el id del Artista:  ", "\nERROR, por favor ingrese un numero valido: ",1,13);
					break;
					case 4:
						listadoTipoAlbumes(listaTipoAlbumes, tamTipoAlbumes);
						listaAlbum[i].idTipoAlbum = getInt("\n\nIngrese su opcion: ","\nERROR, por favor ingrese un numero valido",1,3);
					break;
					case 5:
						getChar(listaAlbum[i].titulo,sizeof(listaAlbum[i].titulo), "\nIngresar el titulo del album: ");
					break;
					case 6:
						listaAlbum[i].precio = getFloat("\nIngrese importe del album: ","\nERROR, por favor ingrese un numero valido: ",1);
					break;
					case 7:
						listaAlbum[i].fecha.dia = getInt("\nIngrese fecha de lanzamiento del album: \nDia: ","\nERROR, por favor ingrese un numero valido: ",1,31);
						listaAlbum[i].fecha.mes = getInt("\t\tMes: ","\nERROR, por favor ingrese un numero valido: ",1,12);
						listaAlbum[i].fecha.anio = getInt("\t\t\t\tAnio: ","\nERROR, por favor ingrese un numero valido: ",1948,2022);
					break;
					default:
						printf("\nSaliendo del menu de modificaciones...");
					break;
					if(opcionModificar <= 6 && opcionModificar >=1)
					{
						printf("\nSe realizo la modifcacion con exito!! ");
					}
				}
			}while(opcionModificar != 8);

			retorno = 0;
			break;
		}
	}

	return retorno;
}

/*BAJA*/

int darBaja(eAlbum listaAlbum[], int tam){
	int retorno;
	char respuesta;
	int auxId;
	int i;

	retorno = -1;

	auxId = buscarId();

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].idAlbum == auxId && listaAlbum[i].isEmpty == 0)
		{
			mostrarUnAlbum(listaAlbum[i]);
			printf("\n¿Seguro desea dar de baja este album? (s/n) ");
			fpurge(stdin);
			scanf("%c", &respuesta);

			switch(respuesta)
			{
				case 's':
					listaAlbum[i].isEmpty = -1;
					printf("\nSe ha dado de baja un album!!");
				break;
				default:
					printf("Volviendo al menu principal...");
				break;
			}

			break;
		}
	}

	return retorno;
}

/*INFORMAR*/



int informar(eAlbum listaAlbum[],int tam, eGenero listaGenero[], int tamGenero,eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	int retorno;
	int respuesta;
	int cantidadSigloXX;
	int indicador;

	retorno = -1;
	indicador = 1;

	if(listaAlbum != NULL && tam >= 0)
	{
		do{
			respuesta = mostrarMenu("\n\nMenu informar\n1- Total y promedio de los importes\n2- Cantidad de albumes anteriores al 1/1/2000\n3- Cantidad de albumes de un tipo de album determinado y de un genero determinado\n4- Salir\nIngrese una opcion: ","\nERROR, por favor, ingrese una opcion valida: ",1,4);

			switch(respuesta)
			{
				case 1:
					promediarPrecios(listaAlbum, tam, indicador);
					break;
				case 2:
					cantidadSigloXX = cantidadSXX(listaAlbum, tam, indicador);
					if(cantidadSigloXX > 0)
					{
						printf("\nLa cantidad de albumes cuya fecha de publicacion es menor a a 1/1/2000 es: %d", cantidadSigloXX);
					}
					break;
				case 3:
					cantidadAlbumesTipoAlbumGenero(listaAlbum, tam, listaGenero,tamGenero,listaTipoAlbumes,tamTipoAlbumes);
					break;
				default:
					printf("Saliendo del menu de informes...");
					break;
			}

		}while(respuesta != 4);
		retorno = 0;
	}

	return retorno;
}

/*LISTAR*/



void listadoAlbumes(eAlbum listaAlbum[], int tam){
	int i;

	printf("\nLos albumes son:\nID\t\tALBUMES");

	for(i=0;i<tam;i++)
	{
		if(listaAlbum[i].isEmpty == 0)
		{
			mostrarUnAlbum(listaAlbum[i]);
		}
	}
}

void listadoAlbumArtista(eAlbum listaAlbum[], int tamAlbum, eArtista listaArtistas[], int tamArtista){
	int i;
	int j;

	printf("\nLos albumes de cada artista son:\nARTISTA\t\t\t\tALBUMES");

	for(i=0;i<tamAlbum;i++)
	{
		for(j=0;j<tamArtista;j++)
		{
			if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].idArtista == listaArtistas[j].idArtista)
			{
				mostrarUnAlbum(listaAlbum[i]);
			}
		}
	}
}

int buscarAnio(eAlbum listaAlbum[], int tam, int indicador){
	int anio;
	int retorno;
	int i;
	retorno = -1;

	anio = getInt("\nIngrese el anio que desea buscar: ","\nERROR, por favor, ingrese un anio valido: ", 1948,2022);

	if(indicador == 2)
	{
		printf("\nLos album que salieron en el anio %d son: ", anio);

		for(i=0;i<tam;i++)
		{
			if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].fecha.anio == anio)
			{
				mostrarUnAlbum(listaAlbum[i]);
			}
			else{
				printf("\nNo se encontraron albumes que hayan sido lanzados en %d", anio);
			}
		}
		retorno = 1;
	}
	else{
		retorno = anio;
	}
	return retorno;
}

void mostrarAlbumesMasCaros(eAlbum listaAlbum[], int tam){
	int i;
	int tamLimite;
	int flagSwap;

	tamLimite = tam - 1;

	float auxiliar;

	auxiliar = 0;

	if(listaAlbum != NULL && tam >= 0)
	{
		printf("\nEl o los albumes mas caros son: \nPRECIOS\t\tALBUM");

			flagSwap = 0;
			for(i = 0; i < tamLimite; i++)
			{
				if((listaAlbum[i].isEmpty == 0 && listaAlbum[i].precio < listaAlbum[i+1].precio) || flagSwap == 0)
				{
					flagSwap = 1;
					auxiliar = listaAlbum[i].precio;
				}
			tamLimite--;

			}

		for(i = 0; i < tam; i++)
		{
			if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].precio == auxiliar)
			{
				mostrarUnAlbum(listaAlbum[i]);
			}
		}
	}

}

void listadoImporteTitulo(eAlbum listaAlbum[], int tam){
	int i;
	int j;
	int tamLimite;
	int flagSwap;

	flagSwap = 0;

	tamLimite = tam - 1;
	eAlbum aux;

	if(listaAlbum != NULL && tam >= 0)
	{
		printf("\nListado por mayor precio y por titulo:\n\n");

			for(i=0; i< tamLimite; i++)
			{
				for(j=i+1; j<tam; j++)
				{

					if(	((listaAlbum[i].isEmpty == 0 && listaAlbum[i].precio < listaAlbum[j].precio )|| flagSwap == 0 )||
						(listaAlbum[i].precio == listaAlbum[j].precio && (strncmp(listaAlbum[i].titulo, listaAlbum[j].titulo, sizeof(listaAlbum[i].titulo)) < 0)))
					{

						flagSwap = 1;
						aux = listaAlbum[i];
						listaAlbum[i] = listaAlbum[j];
						listaAlbum[j] = aux;
					}
				}
				tamLimite--;
			}

		for(i=0; i<tam;i++)
		{
			if(listaAlbum[i].isEmpty == 0 )
			{
				mostrarUnAlbum(listaAlbum[i]);
			}
		}

	}
}

void listadoAlbumesNoSonVinilo(eAlbum listaAlbum[], int tamAlbum, eTipoAlbum listaTipoAlbum[], int tamTipo){
	int i;
	int j;

	printf("\nLos albumes que no son de vinilo son:\nTIPO\t\tALBUM");

	for(i=0; i<tamAlbum; i++)
	{
		for(j=0; j<tamTipo; j++)
		{
			if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].idTipoAlbum == listaTipoAlbum[j].idTipoAlbum && listaTipoAlbum[j].idTipoAlbum != 1)
			{
				mostrarUnAlbum(listaAlbum[i]);
			}
		}
	}
}

void listadoAlbumesViniloSegunArtista(eAlbum listaAlbum[], int tamAlbum, eTipoAlbum listaTipoAlbum[], int tamTipo, eArtista listaArtistas[], int tamArtista){
	int i;
	int j;
	int aux;
	int hayVinilo;

	hayVinilo = 0;

	listadoArtistas(listaArtistas, tamArtista);

	aux = getInt("\nIngrese el ID del artista para mostrar sus vinilos: ", "\nERROR, por favor ingrese un numero valido: ",1,13);

	for(i=0; i<tamAlbum; i++)
	{
		for(j=0; j<tamTipo; j++)
		{
			if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].idArtista == aux && listaTipoAlbum[j].idTipoAlbum == 1 && listaAlbum[i].idTipoAlbum == listaTipoAlbum[j].idTipoAlbum )
			{
				mostrarUnAlbum(listaAlbum[i]);
				hayVinilo++;
			}
		}
	}
	if(hayVinilo == 0)
	{
		printf("\nEl artista que buscas no tiene albumes en vinilo");
	}

}

void listadoAlbumesSolistaDeUnAnio(eAlbum listaAlbum[], int tamAlbum, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	int indicador;
	int anio;
	int hayAlbumesSolista;
	int i;
	int j;
	int k;
	int p;
	int l;

	indicador = 1;
	hayAlbumesSolista = 0;

	anio = buscarAnio(listaAlbum, tamAlbum, indicador);

	for(i=0;i<tamAlbum;i++) //album
	{
		if(listaAlbum[i].isEmpty == 0 && listaAlbum[i].idTipoArtista == 1 && listaAlbum[i].fecha.anio == anio)
		{
			for(j=0;j<tamGenero;j++) //genero
			{
				for(k=0;k<tamArtista;k++) //artista
				{
					for(p=0;p<tamTipoAlbumes;p++) //tipoAlbumes
					{
						for(l=0;l<tamTipos;l++)
						{
							if(	listaAlbum[i].idArtista == listaArtistas[k].idArtista &&

									listaAlbum[i].idGenero == listaGenero[j].idGenero &&
								listaAlbum[i].idTipoAlbum == listaTipoAlbumes[p].idTipoAlbum &&
								listaAlbum[i].idTipoArtista == listaTipos[l].idTipoArtista)
							{
								hayAlbumesSolista++;
								printf("\nID  | TITULO | FECHA PUBLICACION | IMPORTE | GENERO | TIPO ARTISTA | ARTISTA | TIPO ALBUM");
								printf("\n%4d %8s %4d/%d/%d $%14.2f %8s %8s %8s %8s", 	listaAlbum[i].idAlbum,
																						listaAlbum[i].titulo,
																						listaAlbum[i].fecha.dia,
																						listaAlbum[i].fecha.mes,
																						listaAlbum[i].fecha.anio,
																						listaAlbum[i].precio,
																						listaGenero[j].descripcion,
																						listaTipos[l].descripcion,
																						listaArtistas[k].nombreArtista,
																						listaTipoAlbumes[p].descripcion);
							}
						}
					}
				}
			}
		}
	}
	if(hayAlbumesSolista == 0)
	{
		printf("\nEl anio que buscas no tiene albumes de artistas solistas");
	}

}



int listar(eAlbum listaAlbum[], int tamAlbum, eGenero listaGenero[], int tamGenero, eArtista listaArtistas[], int tamArtista, eTipoArtista listaTipos[], int tamTipos, eTipoAlbum listaTipoAlbumes[], int tamTipoAlbumes){
	int respuesta;
	int retorno;
	int indicador;

	retorno = -1;
	indicador = 2;


	if(listaAlbum != NULL && tamAlbum >= 0 && listaGenero != NULL && tamGenero >= 0 && listaArtistas != NULL &&  tamArtista >= 0&& listaTipos != NULL && tamTipos >= 0)
	{
		do
		{
			respuesta = mostrarMenu("\n\nMenu listar\n1-  Todos los generos\n2-  Todos los tipos de artistas musicales\n3-  Todos los artistas\n4-  Todos los tipos de albumes\n5-  Todos los albumes\n6-  Importe descendente\n7-  Albumes cuya fecha de publicacion sea anterior a 01/01/2000\n8-  Albumes que superan el promedio de importes\n9-  Todos los albumes de cada artista\n10-  Todos los albumes de un año especifico\n11-  El album o los albumes mas caros\n12-  Todos los albumes que no sean de vinilo\n13-  Todos los albumes de vinilo que correspondan a un artista determinado\n14-  Todos los albumes de solistas de un año determinado\n15-  Salir\nIngrese una opcion: ", "\nERROR, por favor ingrese un numero valido: ", 1, 15);

			switch(respuesta)
			{
				case 1:
					listadoGenero(listaGenero, tamGenero);
				break;
				case 2:
					listadoTiposArtistas(listaTipos, tamTipos);
				break;
				case 3:
					listadoArtistas(listaArtistas, tamArtista);
				break;
				case 4:
					listadoTipoAlbumes(listaTipoAlbumes, tamTipoAlbumes);
				break;
				case 5:
					listadoAlbumes(listaAlbum, tamAlbum);
				break;
				case 6:
					listadoImporteTitulo(listaAlbum, tamAlbum);
				break;
				case 7:
					printf("\nLos albumes que fueron publicados antes del 01/01/2000 son:\nID\t\tALBUMES");
					retorno = cantidadSXX(listaAlbum, tamAlbum, indicador);
				break;
				case 8:
					printf("\nLos albumes que superan el promedio de importes son:\nID\t\tALBUMES");
					promediarPrecios(listaAlbum, tamAlbum, indicador);
				break;
				case 9:
					listadoAlbumArtista(listaAlbum, tamAlbum, listaArtistas, tamArtista);
				break;
				case 10:
					buscarAnio(listaAlbum, tamAlbum, indicador);
				break;
				case 11:
					mostrarAlbumesMasCaros(listaAlbum, tamAlbum);
				break;
				case 12:
					listadoAlbumesNoSonVinilo(listaAlbum, tamAlbum,listaTipoAlbumes, tamTipoAlbumes);
				break;
				case 13:
					listadoAlbumesViniloSegunArtista(listaAlbum, tamAlbum,listaTipoAlbumes, tamTipoAlbumes, listaArtistas, tamArtista);
				break;
				case 14:
					listadoAlbumesSolistaDeUnAnio(listaAlbum, tamAlbum, listaGenero, tamGenero, listaArtistas, tamArtista, listaTipos, tamTipos, listaTipoAlbumes, tamTipoAlbumes);
					break;
				default:
					printf("Saliendo del menu listar...");
				break;
			}

		}while(respuesta != 15);
		retorno = 0;
	}

	return retorno;
}
