/*
 * flight_status.c
 *
 *  Created on: May 14, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "flight_status.h"

#include "gral_io.h"


int initFStatus(sFStatus* array, int size){
	int outcome = 0;
	if(array != NULL && size > 0){
		outcome = 1;
		for(int i=0; i<size; i++){
			array[i].isEmpty = 1;
		}
	}
	return outcome;
}



int harcodeFStatus(sFStatus* array, int size){
	int outcome = 0;
	int id = 1;
	sFStatus statusList[5] =
			{{0, "Activo", 0},
			{0, "Abordando", 0},
			{0, "En Vuelo", 0},
			{0, "Demorado", 0},
			{0, "Cancelado", 0}};

	if(array != NULL && size>0){
		outcome = 1;
		for(int i=0; i<5; i++, id++){
			statusList[i].id = id;
			array[i] = statusList[i];
		}
	}
	return outcome;
}


int loadFStatusDescription(sFStatus* array, int size, char* description, int id){
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


int selectFStatus(sFStatus* array, int size, int* id){
	int outcome = 0;
	int choice;
	int index[size];
	int max = 0;
	if(array != NULL && size > 0 && id != NULL){
		printf("\n\n    -------------------------------------  * ESTADO DE VUELO *  --------------------------------------\n");
		printf("    --------------------------------------------------------------------------------------------------\n");
		printf("    El vuelo se encuentra:\n");
		for(int i=0; i<size; i++){
			if(!array[i].isEmpty){
				printf("       %d. %-25s\n", i+1, array[i].description);
				index[max] = i;
				max++;
			}
		}
		printf("    --------------------------------------------------------------------------------------------------\n");
		if(getInteger(&choice, "\n    Seleccione un estado de vuelo: ", "\n  Opción inválida. ", 1, max, 3)){
			outcome = 1;
			*id = array[index[choice-1]].id;
		}
	}
	return outcome;
}
