/*
 * passenger_type.h
 *
 *  Created on: May 14, 2022
 *      Author: GM
 */

#ifndef PASSENGER_TYPE_H_
#define PASSENGER_TYPE_H_

	typedef struct{
		int id;		//starts in 1
		char description[12];
		int isEmpty;
	}sPType;

#endif /* PASSENGER_TYPE_H_ */



/// @brief Función para inicializar Tipos de Pasajero.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tamaño del array de tipo de pasajero
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int initPTypes(sPType* array, int size);


/// @brief Función para hardcodear Tipos de Pasajero.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tamaño del array de tipo de pasajero
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int harcodePTypes(sPType* array, int size);


/// @brief Función para cargar la Descripción de un Tipo de Pasajero a partir de un ID.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tamaño del array de tipo de pasajero
/// @param description  -> puntero a la cadena donde se va a cargar la descripción
/// @param id			-> id para comparar y cargar la descripción
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int loadPTypeDescription(sPType* array, int size, char* description, int id);


/// @brief Función para seleccionar Tipo de Pasajero.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tamaño del array de tipo de pasajero
/// @param id		-> (referencia) devuelve el id del tipo de pasajero elegido
///
/// @return retorna 0 en caso de error, 1 en caso de éxito.
int selectPType(sPType* array, int size, int* id);

