/*
 * TP2_UI.c
 *
 *  Created on: May 7, 2022
 *      Author: GM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gtype.h"
#include "gral_ui.h"
#include "gral_io.h"

#define UP 1
#define DOWN 0

void pause(void){
	char c;
	fflush(stdin);
	printf("\n\n  ***** Presione enter para continuar. *****");
	scanf("%c", &c);
	fflush(stdin);
}


int printMainMenu(int harcodeAvail, int qPassengers){
	system("cls");
	int selection;
	char msjDisponible[16];
	char msjPasajeros[20];
	(harcodeAvail!=1) ? (strcpy(msjDisponible,"disponibles.")) : (strcpy(msjDisponible,"disponible. "));
	(qPassengers!=1) ? (strcpy(msjPasajeros,"pasajeros activos")) : (strcpy(msjPasajeros," pasajero activo "));
	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |--------------------------------------  *** MENÚ PRINCIPAL ***  --------------------------------------|\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |                                                                          < %4d %s >  |\n", qPassengers, msjPasajeros);
	printf(" |  1. ALTAS                  - Carga de pasajeros.                                                     |\n");
	printf(" |  2. MODIFICACIONES         - Modificación de pasajeros.                                              |\n");
	printf(" |  3. BAJAS                  - Anulación de pasajeros.                                                 |\n");
	printf(" |  4. INFORMES               - Acceso al submenú de informes.                                          |\n");
	printf(" |  5. CARGA FORZADA          - Carga forzada de pasajeros: %2d %s                             |\n", harcodeAvail, msjDisponible);
	printf(" |  6. CONSULTA DE VUELOS     - Consulta de vuelos cargados en el sistema.                              |\n");
	printf(" |  7. Salir                                                                                            |\n");
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n\n");
	fflush(stdin);
	getMenuSelection(&selection, "  Elija una opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.\n", 1, 7);
	return selection;
}


void printFlightsMenu(int* option){
	printf("\n  ¿Qué desea hacer?\n");
	printf("    1. Cambiar estado de vuelos.\n");
	printf("    2. Volver al menú principal.\n");
	if(!getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 2, 3)){
		*option = 2;
	}
}



int printReportsMenu(void){
	system("cls");
	int selection;
	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |-------------------------------------  *** SUBMENÚ INFORMES ***  -------------------------------------|\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  Mostrar:                                                                                            |\n");
	printf(" |          1. PASAJEROS. Orden 1: Apellido. Orden 2: Tipo de pasajero.                                 |\n");
	printf(" |          2. Total y promedio de precio pasajes y cantidad de pasajeros sobre el promedio.            |\n");
	printf(" |          3. PASAJEROS. Orden: Código de vuelo. Filtro: vuelos activos.                               |\n");
	printf(" |          4. REGRESAR AL MENÚ PRINCIPAL                                                               |\n");
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n\n");
	fflush(stdin);
	getMenuSelection(&selection, "  Elija una opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.\n", 1, 4);
	return selection;
}


void reportsInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int qPassengers){
	int selection;
	int filter;
	int order;
	int criteria;
	float total_price;
	float average_price;
	int above_average;
	do{
		system("cls");
		selection = printReportsMenu();
		switch(selection){
			case 1: //Sort and print passengers (lastname and then passenger_type.
					if(printLastnameTypeSortMenu(&criteria) && printSortOrderMenu(&order)){
						(criteria) ? sortPassengersLastnameAndType(array, size, order) : sortPassengersTypeAndLastname(array, size, order);
						printPassengers(array, size, flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size, filter);
						pause();
					}
					break;

			case 2: //Show total and average ticket price and passengers above average.
					calcAverageAndTotalPrice(array, size, &total_price, &average_price);
					calcAboveAverage(array, size, average_price, &above_average);
					printf("\n  El total de precio en pasajes es de $ %.2f.\n", total_price);
					printf("  El valor promedio de los pasajes es de $ %.2f.\n", average_price);
					printf("  La cantidad de pasajeros que superan el precio promedio es de %d.\n", above_average);
					pause();
					break;

			case 3: //Sort and print passengers by flycode filtering active flights.
					filter = 1; //filter 1 -> passenger.statusflight == active
					if(printSortOrderMenu(&order)){
						sortPassengersByCode(array, size, order);
						printPassengers(array, size, flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size, filter);
						pause();
					}
					break;

			case 4: //salir
					selection = 4;
					break;

		}
		filter=0;
	}while(selection != 4);
}


int calcAverageAndTotalPrice(Passenger* array, int size, float* total_price, float* average_price){
	int outcome = 0;
	float total = 0;
	float average;
	int counter = 0;

	if(array != NULL && size>0 && total_price != NULL && average_price != NULL){
		outcome = 1;
		for(int i=0; i<size;i++){
			if(!array[i].isEmpty){
				total += array[i].price;
				counter++;
			}
		}
		if(counter){
			average = total / counter;
			*average_price = average;
			*total_price = total;
		}
	}
	return outcome;
}

int calcAboveAverage(Passenger* array, int size, float average_price, int* count){
	int outcome = 0;
	int counter = 0;

	if(array != NULL && size>0 && average_price != 0 && count != NULL){
		outcome = 1;
		for(int i=0; i<size;i++){
			if(!array[i].isEmpty && array[i].price>average_price){
				counter++;
			}
		}
	}
	*count = counter;
	return outcome;
}


int printSortOrderMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  Elija un orden:\n");
		printf("    1. Ascendente\n");
		printf("    2. Descendente\n");
		printf("    3. Cancelar\n");
		if(!getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 3, 3) || *option == 3){
			outcome = 0;
		}else if(*option==2){
			*option = 0;
		}
	}
	return outcome;
}


int printLastnameTypeSortMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  ¿Cómo desea ordenar?\n");
		printf("    1. Primero por apellido, luego por tipo de pasajero.\n");
		printf("    2. Primero por tipo de pasajero, luego por apellido.\n");
		printf("    3. Cancelar\n");
		if(!getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 3, 3) || *option == 3){
			outcome = 0;
		}else if(*option==2){
			*option = 0;
		}
	}
	return outcome;
}
