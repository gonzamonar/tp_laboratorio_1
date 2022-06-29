/*
 * sorters.c
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#include <string.h>
#include "Passenger.h"


int sorter_ID(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	int comparison = 0;
	if(a->id > b->id)
	{
		comparison = 1;
	}
	else if(a->id < b->id)
	{
		comparison = -1;
	}
	return comparison;
}

int sorter_name(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	return strcmp(a->nombre,b->nombre);
}

int sorter_lastname(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	return strcmp(a->apellido,b->apellido);
}

int sorter_price(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	int comparison = 0;
	if(a->precio > b->precio)
	{
		comparison = 1;
	}
	else if(a->precio < b->precio)
	{
		comparison = -1;
	}
	return comparison;
}


int sorter_passengerType(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	int comparison = 0;
	if(a->tipoPasajero > b->tipoPasajero)
	{
		comparison = 1;
	}
	else if(a->tipoPasajero < b->tipoPasajero)
	{
		comparison = -1;
	}
	return comparison;
}

int sorter_flycode(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	return strcmp(a->codigoVuelo,b->codigoVuelo);
}

int sorter_flightStatus(void* A, void* B)
{
	Passenger* a = (Passenger*) A;
	Passenger* b = (Passenger*) B;
	int comparison = 0;
	if(a->estadoVuelo > b->estadoVuelo)
	{
		comparison = 1;
	}
	else if(a->estadoVuelo < b->estadoVuelo)
	{
		comparison = -1;
	}
	return comparison;
}


int sorter_lastname_name(void* A, void* B)
{
	int comparison = sorter_lastname(A, B);
	if(comparison == 0){
		comparison = sorter_name(A, B);
	}
	return comparison;
}


int sorter_lastname_price(void* A, void* B)
{
	int comparison = sorter_lastname(A, B);
	if(comparison == 0){
		comparison = sorter_price(A, B);
	}
	return comparison;
}

int sorter_lastname_passengerType(void* A, void* B)
{
	int comparison = sorter_lastname(A, B);
	if(comparison == 0){
		comparison = sorter_passengerType(A, B);
	}
	return comparison;
}

int sorter_flycode_lastname(void* A, void* B)
{
	int comparison = sorter_flycode(A, B);
	if(comparison == 0){
		comparison = sorter_lastname(A, B);
	}
	return comparison;
}

int sorter_flycode_passengerType(void* A, void* B)
{
	int comparison = sorter_flycode(A, B);
	if(comparison == 0){
		comparison = sorter_passengerType(A, B);
	}
	return comparison;
}

int sorter_flycode_price(void* A, void* B)
{
	int comparison = sorter_flycode(A, B);
	if(comparison == 0){
		comparison = sorter_price(A, B);
	}
	return comparison;
}

int sorter_passengerType_lastname(void* A, void* B)
{
	int comparison = sorter_passengerType(A, B);
	if(comparison == 0){
		comparison = sorter_lastname(A, B);
	}
	return comparison;
}

int sorter_passengerType_flycode(void* A, void* B)
{
	int comparison = sorter_passengerType(A, B);
	if(comparison == 0){
		comparison = sorter_flycode(A, B);
	}
	return comparison;
}
