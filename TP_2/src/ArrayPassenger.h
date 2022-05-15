/*
 * ArrayPassenger.h
 *
 *  Created on: May 7, 2022
 *      Author: GM
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

	typedef struct{
		int id;
		char name[51];
		char lastname[51];
		float price;
		char flycode[10];
		int typePassenger;
		int statusFlight;
		int isEmpty;
	}Passenger;

#include "passenger_type.h"
#include "flights.h"
#include "flight_status.h"

#endif /* ARRAYPASSENGER_H_ */


/// @brief Indica que todas las posiciones del array están vacías, la función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int initPassengers(Passenger* array, int size);


/// @brief Realiza la carga forzada de la cantidad (quantity) de pasajeros indicada.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param quantity 	 -> cantidad de pasajeros para cargar
/// @param freeSpace	 -> cantidad de espacio libre en el array
/// @param pHarcodeAvail -> (referencia) puntero a cantidad de pasajeros disponibles para cargar
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
/// @param pNextId		 -> (referencia) puntero al próximo ID
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int harcodePassengers(Passenger* array, int size, int quantity, int freeSpace, int* pHarcodeAvail, int* qPassengers, int* pNextId);


/// @brief Imprime en formato de listado el array de pasajeros.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tamaño del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tamaño del array de estados de vuelo
/// @param filter		 -> filtro de impresión del array (0: ninguno, 1: flightstatus==active)
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int printPassengers(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int filter);


/// @brief Interfaz dinámica para el alta de un pasajero.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tamaño del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tamaño del array de estados de vuelo
/// @param pNextId		 -> (referencia) puntero al próximo ID
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
void creationInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int* pNextId, int* qPassengers);


/// @brief Agrega a un array de pasajeros existente los valores recibidos como parámetro en el primer índice libre.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param id			 -> id del pasajero
/// @param name			 -> nombre del pasajero
/// @param lastName		 -> apellido del pasajero
/// @param price		 -> precio de pasaje del pasajero
/// @param typePassenger -> tipo de pasajero
/// @param flycode		 -> código del vuelo
/// @param statusFlight  -> estado del vuelo
///
/// @return retorna -1 en caso de error, 0 en caso de éxito.
int addPassengers(Passenger* array, int size, int id, char* name, char* lastName, float price, int typePassenger, char* flycode, int statusFlight);


/// @brief Busca el primer índice libre del array.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param pIndex		 -> puntero al primer índice libre del array
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int getFreeSpace(Passenger* array, int size, int* pIndex);


/// @brief Interfaz dinámica para la modificación de un pasajero.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tamaño del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tamaño del array de estados de vuelo
/// @param pNextId		 -> (referencia) puntero al próximo ID
void updateInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int* pNextId);


/// @brief Función para solicitar el ingreso de un ID, validarlo y buscar el índice con intentos.
///
/// @param id			-> (referencia) devuelve el id del pasajero
/// @param index		-> (referencia) devuelve el index del pasajero
/// @param array		-> puntero al array de pasajeros
/// @param size			-> tamaño del array de pasajeros
/// @param lastId		-> Último ID cargado
/// @param requestMsg	-> Mensaje para requerir el ingreso
/// @param errorMsg		-> Mensaje a mostrar en caso de error
/// @param attemps		-> Cantidad de intentos
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int requestPassengerId(int* id, int* index, Passenger* array, int size, int lastId, char* requestMsg, char* errorMsg, int attemps);


/// @brief Busca un pasajero recibiendo como parámetro de búsqueda su id.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param id			 -> id para buscar coincidencia con un pasajero
///
/// @return retorna el index del pasajero en caso de coincidencia y -1 en caso de no haber coincidencia
int findPassengerById(Passenger* array, int size, int id);


/// @brief Interfaz dinámica para la baja de un pasajero.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param flights 		 -> puntero al array de vuelos
/// @param flights_size  -> tamaño del array de vuelos
/// @param ptypes		 -> puntero al array de tipos de pasajero
/// @param ptypes_size 	 -> tamaño del array de tipos de pasajero
/// @param fstatus 		 -> puntero al array de estados de vuelo
/// @param fstatus_size  -> tamaño del array de estados de vuelo
/// @param pNextId		 -> (referencia) puntero al próximo ID
/// @param qPassengers	 -> (referencia) puntero a cantidad de pasajeros cargados en sistema
void deleteInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int* pNextId, int* qPassengers);


/// @brief Elimina de manera lógica un pasajero a partir de su ID.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param id			 -> id del pasajero a eliminar
///
/// @return retorna -1 en caso de error, 0 en caso de éxito.
int removePassenger(Passenger* array, int size, int id);


/// @brief Ordena el array de pasajeros por código de vuelo según el orden indicado.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param order		 -> orden: 1 para ASC y 0 para DESC
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int sortPassengersByCode(Passenger* array, int size, int order);


/// @brief Ordena el array de pasajeros por tipo de pasajero (1ro) y apellido (2do) según el orden indicado.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param order		 -> orden: 1 para ASC y 0 para DESC
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int sortPassengersTypeAndLastname(Passenger* array, int size, int order);


/// @brief Ordena el array de pasajeros por apellido (1ro) y tipo de pasajero (2do) según el orden indicado.
///
/// @param array		 -> puntero al array de pasajeros
/// @param size			 -> tamaño del array de pasajeros
/// @param order		 -> orden: 1 para ASC y 0 para DESC
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int sortPassengersLastnameAndType(Passenger* array, int size, int order);



