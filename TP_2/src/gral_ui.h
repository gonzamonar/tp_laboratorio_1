/*
 * TP2_UI.h
 *
 *  Created on: May 7, 2022
 *      Author: GM
 */

#ifndef TP2_UI_H_
#define TP2_UI_H_

#include "passenger_type.h"
#include "flights.h"
#include "flight_status.h"

#endif /* TP2_UI_H_ */


/// @brief Funci�n para pausar la ejecuci�n del programa hasta presionar la tecla 'Enter'.
///
void pause(void);


/// @brief Imprime el men� principal del programa y retorna la opci�n elegida.
///
/// @param pHarcodeAvail -> (referencia) puntero a cantidad de pasajeros disponibles para cargar
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
///
/// @return Retorna la opci�n seleccionada del menu.
int printMainMenu(int harcodeAvail, int qPassengers);


/// @brief Imprime un men� de selecci�n de interfaz de vuelos, requiere y retorna la opci�n elegida.
///
/// @param option -> (referencia) puntero al int para almacenar la opci�n elegida
void printFlightsMenu(int* option);


/// @brief Imprime el men� de informes y retorna la opci�n elegida.
///
/// @return Retorna la opci�n seleccionada en el menu.
int printReportsMenu(void);


/// @brief Interfaz din�mica de Informes.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tama�o del array de pasajeros
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tama�o del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tama�o del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tama�o del array de estados de vuelo
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
void reportsInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int qPassengers);


/// @brief Funci�n para calcular el precio promedio y total de pasajes.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tama�o del array de pasajeros
/// @param total_price	 -> (referencia) almacena el precio total calculado
/// @param average_price -> (referencia) almacena el precio promedio calculado
///
/// @return Retorna 1 en caso de �xito, 0 en caso de falla.
int calcAverageAndTotalPrice(Passenger* array, int size, float* total_price, float* average_price);


/// @brief Funci�n para calcular la cantidad de pasajeros sobre el precio promedio de pasajes.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tama�o del array de pasajeros
/// @param average_price -> precio promedio del array
/// @param count		 -> puntero al contador de pasajeros sobre el precio promedio
///
/// @return Retorna 1 en caso de �xito, 0 en caso de falla.
int calcAboveAverage(Passenger* array, int size, float average_price, int* count);


/// @brief Imprime un men� de selecci�n de orden, requiere y retorna la opci�n elegida.
///
/// @param option -> (referencia) puntero al int para almacenar la opci�n elegida
///
/// @return Retorna 1 en caso de ingreso v�lido, 0 en caso de falla u opci�n de salida.
int printSortOrderMenu(int* option);


/// @brief Imprime un men� de selecci�n ordenamiento, requiere y retorna la opci�n elegida.
///
/// @param option -> (referencia) puntero al int para almacenar la opci�n elegida
///
/// @return Retorna 1 en caso de ingreso v�lido, 0 en caso de falla u opci�n de salida.
int printLastnameTypeSortMenu(int* option);



