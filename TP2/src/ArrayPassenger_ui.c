/*
 * passengers_ui.c
 *
 *      Author: GM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger_ui.h"
#include "gtype.h"
#include "gral_io.h"
#include "gral_ui.h"


void hardcodeInterface(Passenger* array, int size, int* harcodeAvail, int* pNextId, int* qPassengers){
	char harcodeMSG[128];
	char harcodeErrorMSG[128];
	int quantity;
	int freeSpace = calcFreeSpace(array, size);

	sprintf(harcodeMSG,"\n  ¿Cuántos pasajeros desea cargar por método forzado (máximo disponible: %d)?: ", *harcodeAvail);
	sprintf(harcodeErrorMSG,"  Los valores aceptados son de 1 a %d, ingrese una cantidad válida. ", *harcodeAvail);

	if(freeSpace){
		if(getInteger(&quantity, harcodeMSG, harcodeErrorMSG, 1, *harcodeAvail, 3) &&
		   harcodePassengers(array, size, quantity, freeSpace, harcodeAvail, qPassengers, pNextId))
		{
			(quantity>1) ? printf("\n  Pasajeros cargados correctamente.") : printf("\n  Pasajero cargado correctamente.");
		}
	}else{
		printf("\n  No se pueden cargar más pasajeros en el sistema.");
	}
}


int calcFreeSpace(Passenger* array, int size){
	int freeSpace = 0;
	if(array != NULL && size > 0){
		for(int i=0;i<size;i++){
			if(array[i].isEmpty){
				freeSpace++;
			}
		}
	}
	return freeSpace;
}


void printCreationMenu(int* flag, int id, char* name, char* lastName, float price, char* ptype_description, char* flycode){
	system("cls");
	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |-------------------------------------  *** SUBMENÚ DE ALTAS ***  -------------------------------------|\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  - ID: 	                 %-16d                                                       |\n", id);
	if(flag[0]){
		printf(" |  - NOMBRE:                    %-50s                     |\n", name);
	}else{
		printf(" |  - NOMBRE:                    %-20s                                                   |\n", "Sin Ingresar");
	}

	if(flag[1]){
		printf(" |  - APELLIDO:                  %-50s                     |\n", lastName);
	}else{
		printf(" |  - APELLIDO:                  %-20s                                                   |\n", "Sin Ingresar");
	}
	if(flag[2]){
		printf(" |  - PRECIO:                  $ %-14.2f                                                         |\n", price);
	}else{
		printf(" |  - PRECIO:                    %-20s                                                   |\n", "Sin Ingresar");
	}
	if(flag[3]){
		printf(" |  - TIPO DEL PASAJERO:         %-20s                                                   |\n", ptype_description);
	}else{
		printf(" |  - TIPO DEL PASAJERO:         %-20s                                                   |\n", "Sin Ingresar");
	}
	if(flag[4]){
		printf(" |  - CÓDIGO DE VUELO:           %-20s                                                   |\n", flycode);
	}else{
		printf(" |  - CÓDIGO DE VUELO:           %-20s                                                   |\n", "Sin Ingresar");
	}
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
}


void printUpdateMenu(int* option){
	printf("\n  ¿Qué campo desea modificar?\n");
	printf("    1. Nombre.\n");
	printf("    2. Apellido.\n");
	printf("    3. Precio de vuelo.\n");
	printf("    4. Clase de pasaje.\n");
	printf("    5. Vuelo.\n");
	printf("    6. Volver al menú principal.\n");
	if(!getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 6, 3)){
		printf("\n  El proceso de modificación ha sido cancelado.");
		*option = 6;
		pause();
	}
}


void printPassengerFile(Passenger passenger, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size){
	system("cls");
	char ptype_description[12];
	char fstatus_description[12];
	char route[68];
	int flight_index;

	loadPTypeDescription(ptypes, ptypes_size, ptype_description, passenger.typePassenger);
	loadFStatusDescription(fstatus, fstatus_size, fstatus_description, passenger.statusFlight);
	flight_index = getFlightIndex(flights, flights_size, passenger.flycode);
	sprintf(route,"%s - %s", flights[flight_index].origin, flights[flight_index].destination);

	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |---------------------------------  *** FICHA PASAJERO Nº %4d ***  -----------------------------------|\n", passenger.id);
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  - NOMBRE:                    %-50s                     |\n", passenger.name);
	printf(" |  - APELLIDO:                  %-50s                     |\n", passenger.lastname);
	printf(" |  - PRECIO:                  $ %-14.2f                                                         |\n", passenger.price);
	printf(" |  - TIPO DE PASAJE:            %-20s                                                   |\n", ptype_description);
	printf(" |  - CÓDIGO DE VUELO:           %-20s                                                   |\n", passenger.flycode);
	printf(" |  - AEROLÍNEA:                 %-32s                                       |\n", flights[flight_index].airline);
	printf(" |  - TRAYECTO:                  %-48s                       |\n", route);
	printf(" |  - ESTADO DE VUELO:           %-20s                                                   |\n", fstatus_description);
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
}


int getFlightIndex(sFlight* flights, int flight_size, char* flycode){
	int index = -1;
	if(flights != NULL && flight_size>0){
		for(int i=0; i<flight_size; i++){
			if(strcmp(flights[i].flycode, flycode)==0){
				index = i;
				break;
			}
		}
	}
	return index;
}

