/*
 * flights.h
 *
 *  Created on: May 9, 2022
 *      Author: GM
 */


#ifndef FLIGHTS_H_
#define FLIGHTS_H_

	typedef struct{
		char flycode[10];
		char airline[32];
		char origin[32];
		char destination[32];
		int statusFlight;
		int isEmpty;
	}sFlight;

#include "flight_status.h"
#include "ArrayPassenger.h"

#endif /* FLIGHTS_H_ */


/// @brief Funci�n para inicializar Vuelos
///
/// @param array 		 		-> puntero al array de vuelos
/// @param size 				-> tama�o del array de vuelos
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int initFlights(sFlight* array, int size);


/// @brief Funci�n para hardcodear Vuelos.
///
/// @param array 		 		-> puntero al array de vuelos
/// @param size 				-> tama�o del array de vuelos
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int harcodeFlights(sFlight* array, int size);


/// @brief Funci�n para imprimir el contenido del array de vuelos.
///
/// @param array 		 		-> puntero al array de vuelos
/// @param size 				-> tama�o del array de vuelos
/// @param fstatus 				-> puntero al array de estados de vuelo
/// @param fstatus_size 		-> tama�o del array de estados de vuelo
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int printFlights(sFlight* array, int size, sFStatus* fstatus, int size_fstatus);


/// @brief Funci�n para seleccionar un Vuelo.
///
/// @param array 		-> puntero al array de vuelos
/// @param size 		-> tama�o del array de vuelos
/// @param index		-> (referencia) devuelve el index del vuelo elegido
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int selectFlight(sFlight* array, int size, int* index);


/// @brief Interfaz din�mica para la modificaci�n de estados de vuelo.
///
/// @param array 		 		-> puntero al array de vuelos
/// @param size 				-> tama�o del array de vuelos
/// @param fstatus 				-> puntero al array de estados de vuelo
/// @param fstatus_size 		-> tama�o del array de estados de vuelo
/// @param passengers		 	-> puntero al array de pasajeros
/// @param size_passengers		-> tama�o del array de pasajeros
void flightsInterface(sFlight* array, int size, sFStatus* fstatus, int size_fstatus, Passenger* passengers, int size_passengers);


/// @brief Imprime la ficha con todos los datos de un vuelo.
///
/// @param flight			-> estructura de un vuelo
/// @param fstatus 			-> puntero al array de estados de vuelo
/// @param fstatus_size 	-> tama�o del array de estados de vuelo
void printFlightFile(sFlight flight, sFStatus* fstatus, int size_fstatus);


/// @brief Actualiza (luego de un cambio de estado de vuelo) el campo "estado de vuelo"
///		    en el array de pasajeros de acuerdo a la coincidencia con el c�digo de vuelo.
///
/// @param array 		 	-> puntero al array de pasajeros
/// @param size 			-> tama�o del array de pasajeros
/// @param flycode			-> c�digo de vuelo
/// @param newFStatus		-> nuevo estado para asignar
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int updatePassengersSFlight(Passenger* array, int size, char* flycode, int newFStatus);
