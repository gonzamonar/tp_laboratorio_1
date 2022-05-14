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


/// @brief Función para pausar la ejecución del programa hasta presionar la tecla 'Enter'.
///
void pause(void);


/// @brief Imprime el menú principal del programa y retorna la opción elegida.
///
/// @param pHarcodeAvail -> (referencia) puntero a cantidad de pasajeros disponibles para cargar
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
///
/// @return Retorna la opción seleccionada del menu.
int printMainMenu(int harcodeAvail, int qPassengers);


/// @brief Imprime un menú de selección de interfaz de vuelos, requiere y retorna la opción elegida.
///
/// @param option -> (referencia) puntero al int para almacenar la opción elegida
void printFlightsMenu(int* option);


/// @brief Imprime el menú de informes y retorna la opción elegida.
///
/// @return Retorna la opción seleccionada en el menu.
int printReportsMenu(void);


/// @brief Interfaz dinámica de Informes.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tamaño del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tamaño del array de estados de vuelo
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
void reportsInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int qPassengers);


/// @brief Función para calcular el precio promedio y total de pasajes.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param total_price	 -> (referencia) almacena el precio total calculado
/// @param average_price -> (referencia) almacena el precio promedio calculado
///
/// @return Retorna 1 en caso de éxito, 0 en caso de falla.
int calcAverageAndTotalPrice(Passenger* array, int size, float* total_price, float* average_price);


/// @brief Función para calcular la cantidad de pasajeros sobre el precio promedio de pasajes.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param average_price -> precio promedio del array
/// @param count		 -> puntero al contador de pasajeros sobre el precio promedio
///
/// @return Retorna 1 en caso de éxito, 0 en caso de falla.
int calcAboveAverage(Passenger* array, int size, float average_price, int* count);


/// @brief Imprime un menú de selección de orden, requiere y retorna la opción elegida.
///
/// @param option -> (referencia) puntero al int para almacenar la opción elegida
///
/// @return Retorna 1 en caso de ingreso válido, 0 en caso de falla u opción de salida.
int printSortOrderMenu(int* option);


/// @brief Imprime un menú de selección ordenamiento, requiere y retorna la opción elegida.
///
/// @param option -> (referencia) puntero al int para almacenar la opción elegida
///
/// @return Retorna 1 en caso de ingreso válido, 0 en caso de falla u opción de salida.
int printLastnameTypeSortMenu(int* option);



