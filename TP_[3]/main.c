#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "funciones.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    int flag;
    int flagGuardadoTxt;
    int flagGuardadoBin;
    int respuesta;
    int huboError;

    flag = 0;
    flagGuardadoTxt = 0;
    flagGuardadoBin = 0;

    do{
    	option = getInt("\n\n-------Menu Principal-------\n\n1-Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2-Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3-Alta de pasajero\n4-Modificar datos de pasajero\n5-Baja de pasajero\n6-Listar pasajeros\n7-Ordenar pasajeros\n8-Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9-Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10-Salir\nIngrese su opcion: ", "\nERROR, por favor, ingrese una opcion valida: ", 1,10);
        switch(option)
        {
            case 1:
            	huboError = controller_loadFromText("data.csv",listaPasajeros, flag);
            	flag = 1;
                break;
            case 2:
            	huboError = controller_loadFromBinary("data.bin",listaPasajeros, flag);
            	flag = 1;
            	break;
            case 3:
            	huboError = controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	huboError = controller_editPassenger(listaPasajeros);
            	break;
            case 5:
            	huboError = controller_removePassenger(listaPasajeros);
            	break;
            case 6:
            	huboError = controller_listPassenger(listaPasajeros);
            	break;
            case 7:
            	huboError = controller_sortPassenger(listaPasajeros);
            	break;
            case 8:
            	huboError = controller_saveAsText("data.csv",listaPasajeros);
            	flagGuardadoTxt++;
            	break;
            case 9:
            	huboError = controller_saveAsBinary("data.bin",listaPasajeros);
            	flagGuardadoBin++;
            	break;
            default:
            	if(flagGuardadoTxt == 0 && flagGuardadoBin == 0)
            	{
            		respuesta = getInt("\nNo guardaste el archivo, si salis vas a perder los cambios, ¿Estas seguro que deseas salir?\n1-Si\t\t\t2-No\nIngrese su respuesta: ", "\nERROR, por favor, ingrese una respuesta valida: ", 0,3);
            		if(respuesta == 2)
            		{
            			option = 0;
            		}
            	}
            	else
            	{
            		if(flagGuardadoTxt == 0)
            		{
                		respuesta = getInt("\nNo guardaste el archivo de texto y va a quedar desactualizado al binario ¿Estas seguro que deseas salir?\n1-Si\t\t\t2-No\nIngrese su respuesta: ", "\nERROR, por favor, ingrese una respuesta valida: ", 0,3);
                		if(respuesta == 2)
                		{
                			option = 0;
                		}
            		}
            		else{
            			if(flagGuardadoBin == 0)
            			{
                    		respuesta = getInt("\nNo guardaste el archivo binario y va a quedar desactualizado al de texto ¿Estas seguro que deseas salir?\n1-Si\t\t\t2-No\nIngrese su respuesta: ", "\nERROR, por favor, ingrese una respuesta valida: ", 0,3);
                    		if(respuesta == 2)
                    		{
                    			option = 0;
                    		}
            			}
            			else{
            				printf("\n\nSaliendo del programa...");
            			}
            		}

            	}
            	break;
        }
    	if(huboError == 1)
    	{
    		printf("\nOcurrio un error");
    	}
    }while(option != 10);
    return 0;
}

