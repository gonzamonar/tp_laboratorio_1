/*
 * flights.c
 *
 *  Created on: May 9, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "flights.h"
#include "ArrayPassenger_ui.h"
#include "passenger_type.h"
#include "gtype.h"
#include "gral_io.h"
#include "gral_ui.h"

//FLIGHT STATUS
#define ACTIVE 1
#define BOARDING 2
#define DEPARTED 3
#define DELAYED 4
#define CANCELLED 5


int initFlights(sFlight* array, int size){
	int outcome = 0;
	if(array != NULL && size > 0){
		outcome = 1;
		for(int i=0; i<size; i++){
			array[i].isEmpty = 1;
		}
	}
	return outcome;
}


int harcodeFlights(sFlight* array, int size){
	int outcome = 0;
	sFlight flightsList[10] =
			{{"AR1696", "Aerolíneas Argentinas", "Buenos Aires", "Madrid", ACTIVE, 0},
			{"AF084", "AirFrance", "Paris", "Roma", ACTIVE, 0},
			{"LA530", "LATAM", "Santiago de Chile", "Buenos Aires", ACTIVE, 0},
			{"AA2350", "American Airlines", "Dallas", "México DF", ACTIVE, 0},
			{"TK077", "Turkish Airlines", "Miami", "Istanbul", ACTIVE, 0},
			{"LX139", "Swiss Air", "Zurich", "Hong Kong", DELAYED, 0}};

	if(array != NULL && size>0){
		outcome = 1;
		for(int i=0; i<6; i++){
			array[i] = flightsList[i];
		}
	}
	return outcome;
}


int printFlights(sFlight* array, int size, sFStatus* fstatus, int size_fstatus){
	int outcome = 0;
	char fstatus_description[12];
	system("cls");
	if(array != NULL && size>0){
		outcome = 1;
		printf("\n\n");
		printf(" +------------------------------------------------------------------------------------------------------+\n");
		printf(" |-------------------------------------  *** LISTADO DE VUELOS ***  ------------------------------------|\n");
		printf(" |------------------------------------------------------------------------------------------------------|\n");
		printf(" | %10s | %25s | %20s | %21s | %12s | \n", "Código  ", "", "", "", "Estado   ");
		printf(" | %10s | %25s | %20s | %21s | %12s | \n", "de Vuelo ", "Aerolínea        ", "Origen       ", "Destino       ", "de Vuelo  ");
		printf(" +------------------------------------------------------------------------------------------------------+\n");
		for(int i=0;i<size;i++){
			if(!array[i].isEmpty){
				loadFStatusDescription(fstatus, size_fstatus, fstatus_description, array[i].statusFlight);
				printf(" |   %-8s | %-25s | %-20s | %-21s |  %-12s| \n",
						array[i].flycode, array[i].airline, array[i].origin, array[i].destination, fstatus_description);
			}
		}
		printf(" +------------------------------------------------------------------------------------------------------+\n");
	}
	return outcome;
}


int selectFlight(sFlight* array, int size, int* index){
	int outcome = 0;
	int choice;
	int options[size];
	int max = 0;
	if(array != NULL && size > 0 && index != NULL){
		printf("\n\n    ------------------------------------  * VUELOS DISPONIBLES *  ------------------------------------\n");
		printf("    --------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<size; i++){
			if(!array[i].isEmpty){
				printf("       %d. %8s  |  %-25s   |   %s - %s\n", i+1, array[i].flycode, array[i].airline, array[i].origin, array[i].destination);
				options[max] = i;
				max++;
			}
		}
		printf("    --------------------------------------------------------------------------------------------------\n\n");
		if(getInteger(&choice, "\n    Elija el vuelo: ", "\n  Opción inválida. ", 1, max, 3)){
			outcome = 1;
			*index = options[choice-1];
		}
	}
	return outcome;
}


void flightsInterface(sFlight* array, int size, sFStatus* fstatus, int size_fstatus, Passenger* passengers, int size_passengers){
	int option;
	int index;
	int newFStatusId;
	char confirm;
	char confirmMsg[128];
	char oldFStatus[12];
	char newFStatus[12];

	do{
		system("cls");
		printFlights(array, size, fstatus, size_fstatus); //show flights
		printFlightsMenu(&option); //show menu
		switch(option){
			case 1:	//edit FStatus
				if(selectFlight(array, size, &index)){ //choose a flight to edit
					printFlightFile(array[index], fstatus, size_fstatus);  //print flight file
					if(selectFStatus(fstatus, size_fstatus, &newFStatusId)) //select new flight status
					{
						loadFStatusDescription(fstatus, size_fstatus, oldFStatus, array[index].statusFlight);  //load old fstatus description
						loadFStatusDescription(fstatus, size_fstatus, newFStatus, newFStatusId); 			  //load new fstatus description
						sprintf(confirmMsg, "\n    ¿Desea confirmar el cambio de estado de vuelo de <<%s>> a <<%s>>? (S/N): ", oldFStatus, newFStatus); //msg confirm
						getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
						if(confirm=='S'){
							array[index].statusFlight = newFStatusId;
							updatePassengersSFlight(passengers, size_passengers, array[index].flycode, newFStatusId);
						}else{
							printf("\n  Modificación de estado de vuelo cancelada.");
							pause();
						}
					}
				}else{
					printf("\n  Intentos agotados, modificación cancelada.");
					pause();
				}
				break;
		}
	}while(option != 2);
}


void printFlightFile(sFlight flight, sFStatus* fstatus, int size_fstatus){
	system("cls");
	printf("\n\n");
	char fstatus_description[12];
	loadFStatusDescription(fstatus, size_fstatus, fstatus_description, flight.statusFlight);
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |--------------------------------  *** FICHA DE VUELO Nº %-7s ***  ---------------------------------|\n", flight.flycode);
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  - AEROLÍNEA:                 %-20s                                                   |\n", flight.airline);
	printf(" |  - ORIGEN:                    %-20s                                                   |\n", flight.origin);
	printf(" |  - DESTINO:                   %-20s                                                   |\n", flight.destination);
	printf(" |  - ESTADO DEL VUELO:          %-20s                                                   |\n", fstatus_description);
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
}


int updatePassengersSFlight(Passenger* array, int size, char* flycode, int newFStatus){
	int outcome = 0;
		if(array != NULL && size>0 && flycode!=NULL && newFStatus>0){
			for(int i=0;i<size;i++){
				if(strcmp(array[i].flycode, flycode)==0){
					array[i].statusFlight = newFStatus;
				}
			}
		}
	return outcome;
}


