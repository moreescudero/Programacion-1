/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "computadora.h"

#define TAM 200
#define ORDENASC 1

int main(void)
{
	FILE* pArchivo;
	LinkedList* this;
	eComputer* compu;
	int respuesta;
	int parseoOk;
	int cantidad;
	int salioOk;
	int i, idInt;
	float precioFloat;
	char ruta[TAM];
	char id[TAM];
	char descripcion[TAM];
	char precio[TAM];
	int idTipo;
	char idTipoChar[TAM];

	do{
		respuesta = getInt("\n\nMENU PRINCIPAL\n1-Cargar Archivo\n2-Ordenar por IdTipo\n3-Imprimir los datos de las computadoras\n4-Mapeo\n5-Guardar archivo\n6-Salir\nIngrese una opcion: ", "ERROR, ingrese una opcion valida",1,6);
		switch(respuesta){
			case 1:
				this = ll_newLinkedList();
				getChar(ruta, TAM, "Ingrese el nombre del archivo que desea cargar: ");
				pArchivo = fopen(ruta, "r");
				salioOk = -2;
				if(pArchivo != NULL && this != NULL)
				{
					fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, precio ,idTipoChar); //id, descripcion, precio, tipo
					do{
						parseoOk = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, precio ,idTipoChar);

						if(parseoOk == 4)
						{
							compu = computerNewParametros(id, descripcion,precio, idTipoChar);
							if(compu != NULL)
							{
								salioOk = ll_add(this, compu);
							}
						}
					}while(!feof(pArchivo));
				}
				if(pArchivo == NULL)
				{
					printf("\nEl archivo no carga");
				}
				fclose(pArchivo);
				if(salioOk == 0)
				{
					printf("\nSe cargo ok");
				}
				break;
			case 2:
				salioOk = ll_sort(this, computerOrdenarIdTipo, ORDENASC);
				if(salioOk == 0)
				{
					printf("\nSe ordeno ok");
				}
				break;
			case 3:
				cantidad = ll_len(this);
				if(cantidad > 0)
				{
					printf("%4s|%120s|%4s|%10s\n","ID","Descripcion","Precio","Tipo\n");
					for(i=0;i<cantidad;i++)
					{
						compu = (eComputer*) ll_get(this, i);
						computerPrintOne(compu);
					}
				}
				break;
			case 4:
				ll_map(this, computerDesktop);
				break;
			case 5:
				pArchivo = fopen("mapeado.csv","w");
				cantidad = ll_len(this);
				if(cantidad > 0 && pArchivo != NULL)
				{
					fprintf(pArchivo, "ID,Descripcion,Precio,IdTipo");
					for(i=0;i<cantidad;i++)
					{
						compu = (eComputer*) ll_get(this, i);
						computer_getId(compu, &idInt);
						computer_getDesc(compu, descripcion);
						computer_getPrecio(compu, &precioFloat);
						computer_getIdTipo(compu, &idTipo);

						fprintf(pArchivo, "%d,%s,%f,%d\n", idInt, descripcion, precioFloat,idTipo);
					}
					fclose(pArchivo);
				}
				break;
			default:
				printf("\nSaliendo del programa");
				break;
		}


	}while(respuesta != 6);


    return 0;
}

