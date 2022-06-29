<<<<<<< HEAD
/*
 * user_entry.c
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "user_entry.h"
#include "IO.h"
#include "View.h"


static int userEntry_selectPassengerType(int* pTypeId);
static int userEntry_selectFlycode(char* flycode);
static int ll_findPassengerById(LinkedList* this, int id);

void userEntry_requestName(int* stage, char* name, int* flags){
	if(IO_getProperName(name, 51, 50, 2, "\n  Ingrese nombre: ", "\n  Nombre no válido. ", 3, " ")){
		flags[0] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de nombre agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editName(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	char name[51];
	char newName[51];

	if(IO_getProperName(newName, 51, 50, 2, "\n  Ingrese nombre: ", "\n  Nombre no válido. Reingrese nombre: ", 3, " ")){
		Passenger_getNombre(passenger, name);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de nombre de %s a %s? (S/N): ", name, newName);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setNombre(passenger, newName);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de nombre agotados. Modificación cancelada.");
	}
}


void userEntry_requestLastname(int* stage, char* lastName, int* flags){
	if(IO_getProperName(lastName, 51, 50, 2, "\n  Ingrese apellido: ", "\n  Apellido no válido. ", 3, " -")){
		flags[1] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de apellido agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editLastame(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	char lastname[51];
	char newLastname[51];

	if(IO_getProperName(newLastname, 51, 50, 2, "\n  Ingrese apellido: ", "\n  Apellido no válido. Reingrese apellido: ", 3, " ")){
		Passenger_getApellido(passenger, lastname);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de apellido de %s a %s? (S/N): ", lastname, newLastname);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setApellido(passenger, newLastname);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de apellido agotados. Modificación cancelada.");
	}
}


void userEntry_requestPrice(int* stage, float* price, int* flags){
	if(IO_getFloatingPoint(price, "\n  Ingrese el precio del vuelo: ", "  Error, ingrese un precio válido ($1 a $3000000.00). ", 1, 3000000, 3)){
		flags[2] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de precio agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editPrice(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	float price;
	float newPrice;

	if(IO_getFloatingPoint(&newPrice, "\n  Ingrese el precio del vuelo: ", "  Error, ingrese un precio válido ($1 a $3000000.00). ", 1, 3000000, 3)){
		Passenger_getPrecio(passenger, &price);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de precio de %.2f a %.2f? (S/N): ", price, newPrice);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setPrecio(passenger, newPrice);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de precio agotados. Modificación cancelada.");
	}
}

void userEntry_requestPType(int* stage, int* pTypeId, char* description, int* flags){
	if(userEntry_selectPassengerType(pTypeId)){
		view_loadDescription_passengerType(description, *pTypeId);
		flags[3] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de clase de pasajero agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editPType(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	int passengerType;
	int newPType;
	char oldTicket[16];
	char newTicket[16];

	if(userEntry_selectPassengerType(&newPType)){
		Passenger_getTipoPasajero(passenger, &passengerType);
		view_loadDescription_passengerType(oldTicket, passengerType);
		view_loadDescription_passengerType(newTicket, newPType);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de pasaje de %s a %s? (S/N): ", oldTicket, newTicket);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setTipoPasajero(passenger, newPType);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de clase de pasajero agotados.  Modificación cancelada.");
	}
}


void userEntry_requestFlycode(int* stage, char* flycode, int* flags){
	if(userEntry_selectFlycode(flycode)){
		flags[4] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de selección de vuelo agotados. El proceso de alta ha sido cancelado.");
	}
}


void userEntry_editFlycode(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	char flycode[12];
	char newFlycode[12];

	if(userEntry_selectFlycode(newFlycode)){
		Passenger_getCodigoVuelo(passenger, flycode);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de vuelo de %s a %s? (S/N): ", flycode, newFlycode);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setCodigoVuelo(passenger, newFlycode);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de selección de vuelo agotados. Modificación cancelada.");
	}
}



static int userEntry_selectPassengerType(int* passengerType){
	int outcome = 0;
	if(passengerType != NULL){
		view_SelectionMenu_passengerType();
		if(IO_getInteger(passengerType, "\n    Seleccione un tipo de pasaje: ", "\n  Opción inválida. ", 1, 3, 3)){
			outcome = 1;
		}
	}
	return outcome;
}


static int userEntry_selectFlycode(char* flycode){
	int outcome = 0;
	int choice;
	char options[8][12] = {"BA2491A","BR3456J","FR5678G","GU2345F","HY4567D","IB0800A","MM0987B","TU6789B"};
	if(flycode != NULL){
		view_SelectionMenu_flycode(12, options);
		if(IO_getInteger(&choice, "\n    Elija el vuelo: ", "\n  Opción inválida. ", 1, 8, 3)){
			outcome = 1;
			strcpy(flycode,options[choice-1]);
		}
	}
	return outcome;
}



int userEntry_requestPassengerId(LinkedList* pArrayListPassenger, int* index, int maxId){
	int outcome = 0;
	int attemps = 3;
	int id;
	char errorMsg[64];

	sprintf(errorMsg, "  Error, ingrese un id válido (1 a %4d). ", maxId);

	do{
		if(IO_getInteger(&id, "  Ingrese el número de ID del pasajero: ", "", 1, maxId, 1))
		{
			*index = ll_findPassengerById(pArrayListPassenger, id);
			if(*index > -1){
				outcome = 1;
				break;
			}else{
				printf("  El id que ud ingresó no corresponde a un pasajero activo.");
			}
		}
		else
		{
			printf("%s", errorMsg);
		}
		attemps--;
		if(attemps>0)
		{
			printf(" (Intentos restantes: %d)\n", attemps);
		}
	}while(attemps>0);
	return outcome;
}


static int ll_findPassengerById(LinkedList* this, int id)
{
    int returnAux = -1;
    int len;
    if(this != NULL){
    	len = ll_len(this);
    	for(int i=0; i<len; i++){
    		Passenger* buffer = (Passenger*) ll_get(this, i);
    		if(buffer->id == id){
    			returnAux = ll_indexOf(this, buffer);
    			break;
    		}
    	}
    }
    return returnAux;
}
=======
/*
 * user_entry.c
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "user_entry.h"
#include "IO.h"
#include "View.h"


static int userEntry_selectPassengerType(int* pTypeId);
static int userEntry_selectFlycode(char* flycode);
static int ll_findPassengerById(LinkedList* this, int id);

void userEntry_requestName(int* stage, char* name, int* flags){
	if(IO_getProperName(name, 51, 50, 2, "\n  Ingrese nombre: ", "\n  Nombre no válido. ", 3, " ")){
		flags[0] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de nombre agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editName(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	char name[51];
	char newName[51];

	if(IO_getProperName(newName, 51, 50, 2, "\n  Ingrese nombre: ", "\n  Nombre no válido. Reingrese nombre: ", 3, " ")){
		Passenger_getNombre(passenger, name);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de nombre de %s a %s? (S/N): ", name, newName);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setNombre(passenger, newName);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de nombre agotados. Modificación cancelada.");
	}
}


void userEntry_requestLastname(int* stage, char* lastName, int* flags){
	if(IO_getProperName(lastName, 51, 50, 2, "\n  Ingrese apellido: ", "\n  Apellido no válido. ", 3, " -")){
		flags[1] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de apellido agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editLastame(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	char lastname[51];
	char newLastname[51];

	if(IO_getProperName(newLastname, 51, 50, 2, "\n  Ingrese apellido: ", "\n  Apellido no válido. Reingrese apellido: ", 3, " ")){
		Passenger_getApellido(passenger, lastname);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de apellido de %s a %s? (S/N): ", lastname, newLastname);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setApellido(passenger, newLastname);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de apellido agotados. Modificación cancelada.");
	}
}


void userEntry_requestPrice(int* stage, float* price, int* flags){
	if(IO_getFloatingPoint(price, "\n  Ingrese el precio del vuelo: ", "  Error, ingrese un precio válido ($1 a $3000000.00). ", 1, 3000000, 3)){
		flags[2] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de precio agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editPrice(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	float price;
	float newPrice;

	if(IO_getFloatingPoint(&newPrice, "\n  Ingrese el precio del vuelo: ", "  Error, ingrese un precio válido ($1 a $3000000.00). ", 1, 3000000, 3)){
		Passenger_getPrecio(passenger, &price);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de precio de %.2f a %.2f? (S/N): ", price, newPrice);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setPrecio(passenger, newPrice);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de precio agotados. Modificación cancelada.");
	}
}

void userEntry_requestPType(int* stage, int* pTypeId, char* description, int* flags){
	if(userEntry_selectPassengerType(pTypeId)){
		view_loadDescription_passengerType(description, *pTypeId);
		flags[3] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de carga de clase de pasajero agotados. El proceso de alta ha sido cancelado.");
		*stage = 7;
	}
}

void userEntry_editPType(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	int passengerType;
	int newPType;
	char oldTicket[16];
	char newTicket[16];

	if(userEntry_selectPassengerType(&newPType)){
		Passenger_getTipoPasajero(passenger, &passengerType);
		view_loadDescription_passengerType(oldTicket, passengerType);
		view_loadDescription_passengerType(newTicket, newPType);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de pasaje de %s a %s? (S/N): ", oldTicket, newTicket);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setTipoPasajero(passenger, newPType);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de carga de clase de pasajero agotados.  Modificación cancelada.");
	}
}


void userEntry_requestFlycode(int* stage, char* flycode, int* flags){
	if(userEntry_selectFlycode(flycode)){
		flags[4] = 1;
		(*stage)++;
	}else{
		printf("\n  Intentos de selección de vuelo agotados. El proceso de alta ha sido cancelado.");
	}
}


void userEntry_editFlycode(Passenger* passenger, int* editFlag){
	char confirm;
	char confirmMsg[192];
	char flycode[12];
	char newFlycode[12];

	if(userEntry_selectFlycode(newFlycode)){
		Passenger_getCodigoVuelo(passenger, flycode);
		sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de vuelo de %s a %s? (S/N): ", flycode, newFlycode);
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			Passenger_setCodigoVuelo(passenger, newFlycode);
			*editFlag = 1;
		}else{
			printf("\n  Modificación cancelada.");
		}
	}else{
		printf("\n  Intentos de selección de vuelo agotados. Modificación cancelada.");
	}
}



static int userEntry_selectPassengerType(int* passengerType){
	int outcome = 0;
	if(passengerType != NULL){
		view_SelectionMenu_passengerType();
		if(IO_getInteger(passengerType, "\n    Seleccione un tipo de pasaje: ", "\n  Opción inválida. ", 1, 3, 3)){
			outcome = 1;
		}
	}
	return outcome;
}


static int userEntry_selectFlycode(char* flycode){
	int outcome = 0;
	int choice;
	char options[8][12] = {"BA2491A","BR3456J","FR5678G","GU2345F","HY4567D","IB0800A","MM0987B","TU6789B"};
	if(flycode != NULL){
		view_SelectionMenu_flycode(12, options);
		if(IO_getInteger(&choice, "\n    Elija el vuelo: ", "\n  Opción inválida. ", 1, 8, 3)){
			outcome = 1;
			strcpy(flycode,options[choice-1]);
		}
	}
	return outcome;
}



int userEntry_requestPassengerId(LinkedList* pArrayListPassenger, int* index, int maxId){
	int outcome = 0;
	int attemps = 3;
	int id;
	char errorMsg[64];

	sprintf(errorMsg, "  Error, ingrese un id válido (1 a %4d). ", maxId);

	do{
		if(IO_getInteger(&id, "  Ingrese el número de ID del pasajero: ", "", 1, maxId, 1))
		{
			*index = ll_findPassengerById(pArrayListPassenger, id);
			if(*index > -1){
				outcome = 1;
				break;
			}else{
				printf("  El id que ud ingresó no corresponde a un pasajero activo.");
			}
		}
		else
		{
			printf("%s", errorMsg);
		}
		attemps--;
		if(attemps>0)
		{
			printf(" (Intentos restantes: %d)\n", attemps);
		}
	}while(attemps>0);
	return outcome;
}


static int ll_findPassengerById(LinkedList* this, int id)
{
    int returnAux = -1;
    int len;
    if(this != NULL){
    	len = ll_len(this);
    	for(int i=0; i<len; i++){
    		Passenger* buffer = (Passenger*) ll_get(this, i);
    		if(buffer->id == id){
    			returnAux = ll_indexOf(this, buffer);
    			break;
    		}
    	}
    }
    return returnAux;
}
>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
