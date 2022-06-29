/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "Flights.h"
#include "my_ctype.h"

#define SUCCESS 1
#define FAILURE 0

#define ATERRIZADO 1
#define DEMORADO 2
#define EN_HORARIO 3
#define EN_VUELO 4


static int Passenger_setEstadoVuelo(Passenger* this, char* flycode);


Passenger* Passenger_new(void){
	Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));
	if(newPassenger != NULL){
		newPassenger->id = 0;
		strcpy(newPassenger->nombre,"");
		strcpy(newPassenger->apellido, "");
		newPassenger->precio = 0;
		newPassenger->tipoPasajero = -1;
		strcpy(newPassenger->codigoVuelo, "");
	}
	return newPassenger;
}


Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo){
	Passenger* newPassenger = Passenger_new();

	if((Passenger_setId(newPassenger, id)
	   && Passenger_setNombre(newPassenger, nombre)
	   && Passenger_setApellido(newPassenger, apellido)
	   && Passenger_setCodigoVuelo(newPassenger, codigoVuelo)
	   && Passenger_setTipoPasajero(newPassenger, tipoPasajero)
	   && Passenger_setPrecio(newPassenger, precio))){
	}else{
		free(newPassenger);
		newPassenger = NULL;
	}
	return newPassenger;
}


void Passenger_delete(Passenger* this){
	free(this);
}


int Passenger_setId(Passenger* this, int id){
	int outcome = FAILURE;
	if(this != NULL){
		this->id = id;
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_getId(Passenger* this, int* id){
	int outcome = FAILURE;
	if(this != NULL){
		*id = this->id;
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_setNombre(Passenger* this, char* nombre){
	int outcome = FAILURE;
	if(this != NULL && nombre != NULL){
		totitle(nombre);
		strcpy(this->nombre, nombre);
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_getNombre(Passenger* this, char* nombre){
	int outcome = FAILURE;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_setApellido(Passenger* this, char* apellido){
	int outcome = FAILURE;
	if(this != NULL && apellido != NULL){
		totitle(apellido);
		strcpy(this->apellido, apellido);
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_getApellido(Passenger* this, char* apellido){
	int outcome = FAILURE;
	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_setPrecio(Passenger* this, float precio){
	int outcome = FAILURE;
	if(this != NULL && precio > 0){
		this->precio = precio;
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_getPrecio(Passenger* this, float* precio){
	int outcome = FAILURE;
	if(this != NULL && precio != NULL){
		*precio = this->precio;
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo){
	int outcome = FAILURE;
	if(this != NULL && codigoVuelo != NULL){
		Passenger_setEstadoVuelo(this, codigoVuelo);
		strcpy(this->codigoVuelo, codigoVuelo);
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo){
	int outcome = FAILURE;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero){
	int outcome = FAILURE;
	if(this != NULL){
		this->tipoPasajero = tipoPasajero;
		outcome = SUCCESS;
	}
	return outcome;
}


int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero){
	int outcome = FAILURE;
	if(this != NULL && tipoPasajero != NULL){
		*tipoPasajero = this->tipoPasajero;
		outcome = SUCCESS;
	}
	return outcome;
}


static int Passenger_setEstadoVuelo(Passenger* this, char* flycode){
	int outcome = FAILURE;
	Flight flightsList[8] =
			{{"BA2491A", ATERRIZADO},
			{"BR3456J", DEMORADO},
			{"FR5678G", EN_HORARIO},
			{"GU2345F", EN_VUELO},
			{"HY4567D", DEMORADO},
			{"IB0800A", ATERRIZADO},
			{"MM0987B", EN_HORARIO},
			{"TU6789B", ATERRIZADO}};

	if(this != NULL){
		for(int i=0; i<8; i++){
			if(strcmp(flightsList[i].flycode, flycode)==0){
				this->estadoVuelo = flightsList[i].flightStatus;
				outcome = SUCCESS;
			}
		}
	}
	return outcome;
}


int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo){
	int outcome = FAILURE;
	if(this != NULL && estadoVuelo != NULL){
		*estadoVuelo = this->estadoVuelo;
		outcome = SUCCESS;
	}
	return outcome;
}

