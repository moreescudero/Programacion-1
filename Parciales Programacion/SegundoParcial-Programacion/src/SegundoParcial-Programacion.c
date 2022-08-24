/*
 ============================================================================
 Name        : SegundoParcial-Programacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ajustarArray(char* palabra,char* palabraSinVocales);

void guardarBin(char* palabra);

void leerBin();

void ajustarArray(char* palabra,char* palabraSinVocales){
	int i;
	int j = 0;
	int len;

	len = strlen(palabra);

	for(i=0;i<len;i++)
	{
		if(palabra[i] != 'a' && palabra[i] != 'e' && palabra[i] !='i' && palabra[i] != 'o' && palabra[i] != 'u')
		{
			palabraSinVocales[j] = palabra[i];
			j++;
		}
	}
	palabraSinVocales[j] = '\0';

	free(palabra);

	strcpy(palabra, palabraSinVocales);

	printf("%s", palabra);

}

void guardarBin(char* palabra){
	FILE* pArchivo;
	pArchivo = fopen("array.bin", "wb");
	if(pArchivo != NULL)
	{
		fwrite(palabra, sizeof(palabra), 1, pArchivo);
	}
	fclose(pArchivo);
}

void leerBin(){
	FILE* pArchivo;
	char pAux[50];
	pArchivo = fopen("array.bin", "rb");

	if(pArchivo != NULL)
	{
		fread(pAux, sizeof(pAux), 1, pArchivo);
		printf("\n%s", pAux);
	}
	fclose(pArchivo);
}

int main(void) {

	char* palabra;
	char* palabraSinVocales;

	palabra = (char*) malloc(sizeof(palabra));
	palabraSinVocales = (char*) malloc(sizeof(palabraSinVocales));

	if(palabra!= NULL && palabraSinVocales != NULL)
	{
		strcpy(palabra, "perro");
		ajustarArray(palabra, palabraSinVocales);
	}

	guardarBin(palabra);

	leerBin();

	//segundo punto
	/*
	 * La memoria dinamica es utilizada para guardar variables dinamicas, o sea, creadas en
	 * tiempo de ejecucion. Estas son guardadas en el segmento  de Heap.
	 *
	 *
	 * */


	return 0;
}
