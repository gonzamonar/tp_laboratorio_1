

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"
#include "parser.h"

#define SUCCESS 1
#define FAILURE 0

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	Passenger buffer;
	int outcome = FAILURE;
	int r;
	char typePassenger[12];
	char statusFlight[12];
	char id[20];
	char precio[20];
	char readHeader[512];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		outcome = SUCCESS;
		fscanf(pFile, "%s\n", readHeader);
		do{
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, buffer.nombre, buffer.apellido, precio, buffer.codigoVuelo, typePassenger, statusFlight);
			buffer.id = atoi(id);
			buffer.precio = atof(precio);
			if(r==7)
			{
				parser_getPassengerType(&(buffer.tipoPasajero), typePassenger);
				Passenger* passengerAux = Passenger_newParametros(buffer.id, buffer.nombre, buffer.apellido, buffer.precio, buffer.tipoPasajero, buffer.codigoVuelo);
				ll_add(pArrayListPassenger, (void*) passengerAux);
			}
			else
			{
				outcome = FAILURE;
				break;
			}
		}while(!feof(pFile));
	}
    return outcome;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger buffer;
	int outcome = FAILURE;
	int r;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		outcome = SUCCESS;
		do{
			r = fread(&buffer, sizeof(Passenger), 1, pFile);
			if(r == 1)
			{
				Passenger* passengerAux = Passenger_newParametros(buffer.id, buffer.nombre, buffer.apellido, buffer.precio, buffer.tipoPasajero, buffer.codigoVuelo);
				ll_add(pArrayListPassenger, (void*) passengerAux);
			}
		}while(!feof(pFile));
	}
    return outcome;
}


void parser_getPassengerType(int* passengerType, char* description)
{
	if(description != NULL && passengerType != NULL)
	{
		if(strcmp(description, "FirstClass")==0){
			*passengerType = 1;
		}else if(strcmp(description, "ExecutiveClass")==0){
			*passengerType = 2;
		}else if(strcmp(description, "EconomyClass")==0){
			*passengerType = 3;
		}
	}
}

