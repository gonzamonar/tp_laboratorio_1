<<<<<<< HEAD
/*
 * View.c
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "View.h"
#include "Passenger.h"
#include "IO.h"
#include "my_ctype.h"


void view_pause(void){
	char c;
	fflush(stdin);
	printf("\n\n  ***** Presione enter para continuar. *****");
	scanf("%c", &c);
	fflush(stdin);
}


int view_mainMenu(int qPassengers){
	system("cls");
	int selection = 0;
	char msjPasajeros[20];
	(qPassengers!=1) ? (strcpy(msjPasajeros,"pasajeros activos")) : (strcpy(msjPasajeros," pasajero activo "));
	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |--------------------------------------  *** MENÚ PRINCIPAL ***  --------------------------------------|\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |                                                                          < %4d %s >  |\n", qPassengers, msjPasajeros);
	printf(" |  1. CARGAR DATOS DE PASAJEROS (MODO TEXTO)                                                           |\n");
	printf(" |  2. CARGAR DATOS DE PASAJEROS (MODO BINARIO)                                                         |\n");
	printf(" |  3. ALTA DE PASAJERO                                                                                 |\n");
	printf(" |  4. MODIFICAR PASAJERO                                                                               |\n");
	printf(" |  5. BAJA DE PASAJERO                                                                                 |\n");
	printf(" |  6. LISTAR DE PASAJERO                                                                               |\n");
	printf(" |  7. ORDENAR PASAJEROS                                                                                |\n");
	printf(" |  8. GUARGAR DATOS DE PASAJEROS (MODO TEXTO)                                                          |\n");
	printf(" |  9. GUARGAR DATOS DE PASAJEROS (MODO BINARIO)                                                        |\n");
	printf(" |  10. SALIR                                                                                           |\n");
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n\n");
	fflush(stdin);
	IO_getMenuSelection(&selection, "  Elija una opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.\n", 1, 10);
	return selection;
}


void view_passengerTable_header(){
		system("cls");
		printf("\n\n");
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
		printf(" |-------------------------------------  *** LISTADO DE PASAJEROS ***  -------------------------------------|\n");
		printf(" |----------------------------------------------------------------------------------------------------------|\n");
		printf(" |%5s | %20s | %20s | %12s |%10s|%14s|%12s| \n", "", "", "", "", "Código  ", "Clase de  ", "Estado   ");
		printf(" |%5s | %20s | %20s | %12s |%10s|%14s|%12s| \n", "ID ", "Nombre       ", "Apellido      ", "Precio   ", "de Vuelo ", " Pasaje   ", "de Vuelo  ");
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
}


void view_passengerTable_footer(){
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
}


void view_printPassengerRow(Passenger* passenger){
	Passenger buffer;
	char fStatus_description[16];
	char pType_description[16];

	Passenger_getId(passenger, &buffer.id);
	Passenger_getNombre(passenger, buffer.nombre);
	Passenger_getApellido(passenger, buffer.apellido);
	Passenger_getPrecio(passenger, &buffer.precio);
	Passenger_getCodigoVuelo(passenger, buffer.codigoVuelo);
	Passenger_getEstadoVuelo(passenger, &buffer.estadoVuelo);
	Passenger_getTipoPasajero(passenger, &buffer.tipoPasajero);

	view_loadDescription_flightStatus(fStatus_description, buffer.estadoVuelo);
	view_loadDescription_passengerType(pType_description, buffer.tipoPasajero);

	printf(" |%5d | %-20s | %-20s | %10.2f   |%8s  |%14s|%12s| \n", buffer.id, buffer.nombre, buffer.apellido, buffer.precio, buffer.codigoVuelo, pType_description, fStatus_description);
}


void view_loadDescription_passengerType(char* description, int passengerType){
	char class[16];
	if(description != NULL && passengerType > 0 && passengerType < 4){
		switch(passengerType){
			case 1:
				strcpy(class, "FirstClass");
				break;
			case 2:
				strcpy(class, "ExecutiveClass");
				break;
			case 3:
				strcpy(class, "EconomyClass");
				break;
		}
	}
	strcpy(description, class);
}

void view_SelectionMenu_passengerType(void){
	printf("\n\n    ------------------------------------  * TIPOS DISPONIBLES *  -------------------------------------\n");
	printf("    --------------------------------------------------------------------------------------------------\n");
	printf("    ¿En qué clase va a viajar?\n");
	printf("    1. FirstClass\n");
	printf("    2. ExecutiveClass\n");
	printf("    3. EconomyClass\n");
	printf("    --------------------------------------------------------------------------------------------------\n");
}

void view_SelectionMenu_flycode(int col, char options[][col]){
	printf("\n\n    ------------------------------------  * VUELOS DISPONIBLES *  ------------------------------------\n");
	printf("    --------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<8; i++){
		printf("       %d. Vuelo %10s\n", i+1, options[i]);
	}
	printf("    --------------------------------------------------------------------------------------------------\n\n");
}

void view_loadDescription_flightStatus(char* description, int flightStatus){
	char status[16];
	if(description != NULL && flightStatus > 0 && flightStatus < 5){
		switch(flightStatus){
			case 1:
				strcpy(status, "Aterrizado");
				break;
			case 2:
				strcpy(status, "Demorado");
				break;
			case 3:
				strcpy(status, "En Horario");
				break;
			case 4:
				strcpy(status, "En Vuelo");
				break;
		}
	}
	strcpy(description, status);
}



void view_printCreationMenu(int* flag, int id, char* name, char* lastName, float price, char* ptype_description, char* flycode){
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


void view_printPassengerFile(Passenger passenger){
	system("cls");
	Passenger buffer;
	char fStatus_description[16];
	char pType_description[16];

	Passenger_getId(&passenger, &buffer.id);
	Passenger_getNombre(&passenger, buffer.nombre);
	Passenger_getApellido(&passenger, buffer.apellido);
	Passenger_getPrecio(&passenger, &buffer.precio);
	Passenger_getCodigoVuelo(&passenger, buffer.codigoVuelo);
	Passenger_getEstadoVuelo(&passenger, &buffer.estadoVuelo);
	Passenger_getTipoPasajero(&passenger, &buffer.tipoPasajero);

	view_loadDescription_flightStatus(fStatus_description, buffer.estadoVuelo);
	view_loadDescription_passengerType(pType_description, buffer.tipoPasajero);

	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |---------------------------------  *** FICHA PASAJERO Nº %4d ***  -----------------------------------|\n", buffer.id);
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  - NOMBRE:                    %-50s                     |\n", buffer.nombre);
	printf(" |  - APELLIDO:                  %-50s                     |\n", buffer.apellido);
	printf(" |  - PRECIO:                  $ %-14.2f                                                         |\n", buffer.precio);
	printf(" |  - TIPO DE PASAJE:            %-20s                                                   |\n", pType_description);
	printf(" |  - CÓDIGO DE VUELO:           %-20s                                                   |\n", buffer.codigoVuelo);
	printf(" |  - ESTADO DE VUELO:           %-20s                                                   |\n", fStatus_description);
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
}


void view_printUpdateMenu(int* option){
	printf("\n  ¿Qué campo desea modificar?\n");
	printf("    1. Nombre.\n");
	printf("    2. Apellido.\n");
	printf("    3. Precio de vuelo.\n");
	printf("    4. Clase de pasaje.\n");
	printf("    5. Vuelo.\n");
	printf("    6. Volver al menú principal.\n");
	if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 6, 3)){
		printf("\n  El proceso de modificación ha sido cancelado.");
		*option = 6;
		view_pause();
	}
}



int view_printSortOrderMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  Elija un orden:\n");
		printf("    1. Ascendente\n");
		printf("    2. Descendente\n");
		printf("    3. Cancelar\n");
		if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 3, 3) || *option == 3){
			outcome = 0;
		}else if(*option==2){
			*option = 0;
		}
	}
	return outcome;
}


int view_printSortCriteriaMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  ¿Cómo desea ordenar?\n");
		printf("    *CRITERIOS SIMPLES*\n");
		printf("     1. Por ID.\n");
		printf("     2. Por Nombre.\n");
		printf("     3. Por Apellido\n");
		printf("     4. Por Precio.\n");
		printf("     5. Por Código de Vuelo.\n");
		printf("     6. Por Tipo de Pasajero\n");
		printf("    *CRITERIOS COMPUESTOS*\n");
		printf("     7. Por Apellido y luego por Nombre.\n");
		printf("     8. Por Apellido y luego por Precio.\n");
		printf("     9. Por Apellido y luego por Tipo de Pasajero\n");
		printf("    10. Por Código de Vuelo y luego por Apellido.\n");
		printf("    11. Por Código de Vuelo y luego por Tipo de Pasajero.\n");
		printf("    12. Por Código de Vuelo y luego por Precio\n");
		printf("    13. Por Tipo de Pasajero y luego por Apellido\n");
		printf("    14. Por Tipo de Pasajero y luego por Código de Vuelo\n");
		printf("    *SALIDA*\n");
		printf("    15. Volver al Menú Principal\n");
		if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 15, 3) || *option == 15){
			outcome = 0;
		}
	}
	return outcome;
}
=======
/*
 * View.c
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "View.h"
#include "Passenger.h"
#include "IO.h"
#include "my_ctype.h"


void view_pause(void){
	char c;
	fflush(stdin);
	printf("\n\n  ***** Presione enter para continuar. *****");
	scanf("%c", &c);
	fflush(stdin);
}


int view_mainMenu(int qPassengers){
	system("cls");
	int selection = 0;
	char msjPasajeros[20];
	(qPassengers!=1) ? (strcpy(msjPasajeros,"pasajeros activos")) : (strcpy(msjPasajeros," pasajero activo "));
	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |--------------------------------------  *** MENÚ PRINCIPAL ***  --------------------------------------|\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |                                                                          < %4d %s >  |\n", qPassengers, msjPasajeros);
	printf(" |  1. CARGAR DATOS DE PASAJEROS (MODO TEXTO)                                                           |\n");
	printf(" |  2. CARGAR DATOS DE PASAJEROS (MODO BINARIO)                                                         |\n");
	printf(" |  3. ALTA DE PASAJERO                                                                                 |\n");
	printf(" |  4. MODIFICAR PASAJERO                                                                               |\n");
	printf(" |  5. BAJA DE PASAJERO                                                                                 |\n");
	printf(" |  6. LISTAR DE PASAJERO                                                                               |\n");
	printf(" |  7. ORDENAR PASAJEROS                                                                                |\n");
	printf(" |  8. GUARGAR DATOS DE PASAJEROS (MODO TEXTO)                                                          |\n");
	printf(" |  9. GUARGAR DATOS DE PASAJEROS (MODO BINARIO)                                                        |\n");
	printf(" |  10. SALIR                                                                                           |\n");
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n\n");
	fflush(stdin);
	IO_getMenuSelection(&selection, "  Elija una opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.\n", 1, 10);
	return selection;
}


void view_passengerTable_header(){
		system("cls");
		printf("\n\n");
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
		printf(" |-------------------------------------  *** LISTADO DE PASAJEROS ***  -------------------------------------|\n");
		printf(" |----------------------------------------------------------------------------------------------------------|\n");
		printf(" |%5s | %20s | %20s | %12s |%10s|%14s|%12s| \n", "", "", "", "", "Código  ", "Clase de  ", "Estado   ");
		printf(" |%5s | %20s | %20s | %12s |%10s|%14s|%12s| \n", "ID ", "Nombre       ", "Apellido      ", "Precio   ", "de Vuelo ", " Pasaje   ", "de Vuelo  ");
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
}


void view_passengerTable_footer(){
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
}


void view_printPassengerRow(Passenger* passenger){
	Passenger buffer;
	char fStatus_description[16];
	char pType_description[16];

	Passenger_getId(passenger, &buffer.id);
	Passenger_getNombre(passenger, buffer.nombre);
	Passenger_getApellido(passenger, buffer.apellido);
	Passenger_getPrecio(passenger, &buffer.precio);
	Passenger_getCodigoVuelo(passenger, buffer.codigoVuelo);
	Passenger_getEstadoVuelo(passenger, &buffer.estadoVuelo);
	Passenger_getTipoPasajero(passenger, &buffer.tipoPasajero);

	view_loadDescription_flightStatus(fStatus_description, buffer.estadoVuelo);
	view_loadDescription_passengerType(pType_description, buffer.tipoPasajero);

	printf(" |%5d | %-20s | %-20s | %10.2f   |%8s  |%14s|%12s| \n", buffer.id, buffer.nombre, buffer.apellido, buffer.precio, buffer.codigoVuelo, pType_description, fStatus_description);
}


void view_loadDescription_passengerType(char* description, int passengerType){
	char class[16];
	if(description != NULL && passengerType > 0 && passengerType < 4){
		switch(passengerType){
			case 1:
				strcpy(class, "FirstClass");
				break;
			case 2:
				strcpy(class, "ExecutiveClass");
				break;
			case 3:
				strcpy(class, "EconomyClass");
				break;
		}
	}
	strcpy(description, class);
}

void view_SelectionMenu_passengerType(void){
	printf("\n\n    ------------------------------------  * TIPOS DISPONIBLES *  -------------------------------------\n");
	printf("    --------------------------------------------------------------------------------------------------\n");
	printf("    ¿En qué clase va a viajar?\n");
	printf("    1. FirstClass\n");
	printf("    2. ExecutiveClass\n");
	printf("    3. EconomyClass\n");
	printf("    --------------------------------------------------------------------------------------------------\n");
}

void view_SelectionMenu_flycode(int col, char options[][col]){
	printf("\n\n    ------------------------------------  * VUELOS DISPONIBLES *  ------------------------------------\n");
	printf("    --------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<8; i++){
		printf("       %d. Vuelo %10s\n", i+1, options[i]);
	}
	printf("    --------------------------------------------------------------------------------------------------\n\n");
}

void view_loadDescription_flightStatus(char* description, int flightStatus){
	char status[16];
	if(description != NULL && flightStatus > 0 && flightStatus < 5){
		switch(flightStatus){
			case 1:
				strcpy(status, "Aterrizado");
				break;
			case 2:
				strcpy(status, "Demorado");
				break;
			case 3:
				strcpy(status, "En Horario");
				break;
			case 4:
				strcpy(status, "En Vuelo");
				break;
		}
	}
	strcpy(description, status);
}



void view_printCreationMenu(int* flag, int id, char* name, char* lastName, float price, char* ptype_description, char* flycode){
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


void view_printPassengerFile(Passenger passenger){
	system("cls");
	Passenger buffer;
	char fStatus_description[16];
	char pType_description[16];

	Passenger_getId(&passenger, &buffer.id);
	Passenger_getNombre(&passenger, buffer.nombre);
	Passenger_getApellido(&passenger, buffer.apellido);
	Passenger_getPrecio(&passenger, &buffer.precio);
	Passenger_getCodigoVuelo(&passenger, buffer.codigoVuelo);
	Passenger_getEstadoVuelo(&passenger, &buffer.estadoVuelo);
	Passenger_getTipoPasajero(&passenger, &buffer.tipoPasajero);

	view_loadDescription_flightStatus(fStatus_description, buffer.estadoVuelo);
	view_loadDescription_passengerType(pType_description, buffer.tipoPasajero);

	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |---------------------------------  *** FICHA PASAJERO Nº %4d ***  -----------------------------------|\n", buffer.id);
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  - NOMBRE:                    %-50s                     |\n", buffer.nombre);
	printf(" |  - APELLIDO:                  %-50s                     |\n", buffer.apellido);
	printf(" |  - PRECIO:                  $ %-14.2f                                                         |\n", buffer.precio);
	printf(" |  - TIPO DE PASAJE:            %-20s                                                   |\n", pType_description);
	printf(" |  - CÓDIGO DE VUELO:           %-20s                                                   |\n", buffer.codigoVuelo);
	printf(" |  - ESTADO DE VUELO:           %-20s                                                   |\n", fStatus_description);
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
}


void view_printUpdateMenu(int* option){
	printf("\n  ¿Qué campo desea modificar?\n");
	printf("    1. Nombre.\n");
	printf("    2. Apellido.\n");
	printf("    3. Precio de vuelo.\n");
	printf("    4. Clase de pasaje.\n");
	printf("    5. Vuelo.\n");
	printf("    6. Volver al menú principal.\n");
	if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 6, 3)){
		printf("\n  El proceso de modificación ha sido cancelado.");
		*option = 6;
		view_pause();
	}
}



int view_printSortOrderMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  Elija un orden:\n");
		printf("    1. Ascendente\n");
		printf("    2. Descendente\n");
		printf("    3. Cancelar\n");
		if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 3, 3) || *option == 3){
			outcome = 0;
		}else if(*option==2){
			*option = 0;
		}
	}
	return outcome;
}


int view_printSortCriteriaMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  ¿Cómo desea ordenar?\n");
		printf("    *CRITERIOS SIMPLES*\n");
		printf("     1. Por ID.\n");
		printf("     2. Por Nombre.\n");
		printf("     3. Por Apellido\n");
		printf("     4. Por Precio.\n");
		printf("     5. Por Código de Vuelo.\n");
		printf("     6. Por Tipo de Pasajero\n");
		printf("    *CRITERIOS COMPUESTOS*\n");
		printf("     7. Por Apellido y luego por Nombre.\n");
		printf("     8. Por Apellido y luego por Precio.\n");
		printf("     9. Por Apellido y luego por Tipo de Pasajero\n");
		printf("    10. Por Código de Vuelo y luego por Apellido.\n");
		printf("    11. Por Código de Vuelo y luego por Tipo de Pasajero.\n");
		printf("    12. Por Código de Vuelo y luego por Precio\n");
		printf("    13. Por Tipo de Pasajero y luego por Apellido\n");
		printf("    14. Por Tipo de Pasajero y luego por Código de Vuelo\n");
		printf("    *SALIDA*\n");
		printf("    15. Volver al Menú Principal\n");
		if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 15, 3) || *option == 15){
			outcome = 0;
		}
	}
	return outcome;
}
>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
