#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funciones.h"

int Passenger_findById(LinkedList* this, int cantidad);

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int flag);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int flag);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_listPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


#endif /* CONTROLLER_H_ */
