/*
 * passenger_type.c
 *
 *  Created on: May 14, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger_type.h"

#include "gral_io.h"


int initPTypes(sPType* array, int size){
	int outcome = 0;
	if(array != NULL && size > 0){
		outcome = 1;
		for(int i=0; i<size; i++){
			array[i].isEmpty = 1;
		}
	}
	return outcome;
}


int harcodePTypes(sPType* array, int size){
	int outcome = 0;
	int id = 1;
	sPType typesList[4] =
			{{0, "Primera", 0},
			{0, "Business", 0},
			{0, "Premium", 0},
			{0, "Economy", 0}};

	if(array != NULL && size>0){
		outcome = 1;
		for(int i=0; i<4; i++, id++){
			typesList[i].id = id;
			array[i] = typesList[i];
		}
	}
	return outcome;
}


int loadPTypeDescription(sPType* array, int size, char* description, int id){
	int outcome = 0;
	if(description != NULL && id>=1 && array != NULL && size>0){
		for(int i=0; i<size; i++){
			if(array[i].id == id){
				outcome = 1;
				strcpy(description, array[i].description);
				break;
			}
		}
	}
	return outcome;
}


int selectPType(sPType* array, int size, int* id){
	int outcome = 0;
	int choice;
	int index[size];
	int max = 0;
	if(array != NULL && size > 0 && id != NULL){
		printf("\n\n    ------------------------------------  * TIPOS DISPONIBLES *  -------------------------------------\n");
		printf("    --------------------------------------------------------------------------------------------------\n");
		printf("    ¿En qué clase va a viajar?\n");
		for(int i=0; i<size; i++){
			if(!array[i].isEmpty){
				printf("       %d. %-25s\n", i+1, array[i].description);
				index[max] = i;
				max++;
			}
		}
		printf("    --------------------------------------------------------------------------------------------------\n");
		if(getInteger(&choice, "\n    Seleccione un tipo de pasaje: ", "\n  Opción inválida. ", 1, max, 3)){
			outcome = 1;
			*id = array[index[choice-1]].id;
		}
	}
	return outcome;
}

