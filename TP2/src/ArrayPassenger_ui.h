/*
 * passengers_ui.h
 *
 *      Author: GM
 */

#ifndef PASSENGERS_UI_H_
#define PASSENGERS_UI_H_

#include "ArrayPassenger.h"
#include "passenger_type.h"
#include "flights.h"
#include "flight_status.h"

#endif /* PASSENGERS_UI_H_ */


/// @brief Función para gestionar la interfaz de hardcodeo de pasajeros.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param harcodeAvail -> cantidad disponible para hardcodear
/// @param pNextId 		-> puntero al próximo ID
/// @param qPassengers  -> puntero a la cantidad de pasajeros cargadas
void hardcodeInterface(Passenger* array, int size, int* harcodeAvail, int* pNextId, int* qPassengers);



/// @brief Función para calcular la cantidad de espacio libre en el array antes de una carga masiva (hardcode).
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
///
/// @return Devuelve la cantida de espacio libre.
int calcFreeSpace(Passenger* array, int size);


/// @brief Imprime un menú dinámico para el alta de un pasajero.
///
/// @param flag -> banderas de ingreso de datos (array tamaño 5)
/// @param id   -> próximo id a asignar al pasajero
/// @param name -> nombre ingresado por el usuario
/// @param lastName -> apellido ingresado por el usuario
/// @param price 	-> precio ingresado por el usuario
/// @param ptype_description -> descripción del tipo de pasajero
/// @param flycode -> código de vuelo ingresado por el usuario
void printCreationMenu(int* flag, int id, char* name, char* lastName, float price, char* ptype_description, char* flycode);


/// @brief Imprime un menú de selección de qué campo se quiere modificar del pasajero.
///
/// @param option -> puntero que devuelve por referencia la opción elegida.
void printUpdateMenu(int* option);


/// @brief Imprime una ficha de un pasajero.
///
/// @param passenger -> estructura de un pasajero
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tamaño del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tamaño del array de estados de vuelo
void printPassengerFile(Passenger passenger, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size);


/// @brief Busca en el array de vuelos la coincidencia con el código de vuelos ingresado y regresa el index.
///
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param flycode		 -> código de vuelo
///
/// @return retorna el index del vuelo con el que hay coincidencia y -1 en caso de no haber coincidencia
int getFlightIndex(sFlight* flights, int flight_size, char* flycode);

