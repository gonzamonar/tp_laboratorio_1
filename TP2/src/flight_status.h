/*
 * fligth_status.h
 *
 *  Created on: May 14, 2022
 *      Author: GM
 */

#ifndef FLIGHT_STATUS_H_
#define FLIGHT_STATUS_H_

	typedef struct{
		int id;		//starts in 500
		char description[12];
		int isEmpty;
	}sFStatus;

#endif /* FLIGHT_STATUS_H_ */



/// @brief Función para inicializar Estados de Vuelo.
///
/// @param array 	-> puntero al array de estado de vuelo
/// @param size  	-> tamaño del array de estado de vuelo
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int initFStatus(sFStatus* array, int size);


/// @brief Función para hardcodear Estados de Vuelo.
///
/// @param array 	-> puntero al array de estado de vuelo
/// @param size  	-> tamaño del array de estado de vuelo
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int harcodeFStatus(sFStatus* array, int size);


/// @brief Función para cargar la Descripción de un Estado de vuelo a partir de un ID.
///
/// @param array 		-> puntero al array de estado de vuelo
/// @param size  		-> tamaño del array de estado de vuelo
/// @param description  -> puntero a la cadena donde se va a cargar la descripción
/// @param id			-> id para comparar y cargar la descripción
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int loadFStatusDescription(sFStatus* array, int size, char* description, int id);


/// @brief Función para seleccionar Estado de Vuelo.
///
/// @param array 	-> puntero al array de estado de vuelo
/// @param size  	-> tamaño del array de estado de vuelo
/// @param id		-> (referencia) devuelve el id del flightstatus elegido
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int selectFStatus(sFStatus* array, int size, int* id);
