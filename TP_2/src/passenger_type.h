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



/// @brief Funci�n para inicializar Tipos de Pasajero.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tama�o del array de tipo de pasajero
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int initPTypes(sPType* array, int size);


/// @brief Funci�n para hardcodear Tipos de Pasajero.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tama�o del array de tipo de pasajero
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int harcodePTypes(sPType* array, int size);


/// @brief Funci�n para cargar la Descripci�n de un Tipo de Pasajero a partir de un ID.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tama�o del array de tipo de pasajero
/// @param description  -> puntero a la cadena donde se va a cargar la descripci�n
/// @param id			-> id para comparar y cargar la descripci�n
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int loadPTypeDescription(sPType* array, int size, char* description, int id);


/// @brief Funci�n para seleccionar Tipo de Pasajero.
///
/// @param array 	-> puntero al array de tipo de pasajero
/// @param size  	-> tama�o del array de tipo de pasajero
/// @param id		-> (referencia) devuelve el id del tipo de pasajero elegido
///
/// @return retorna 0 en caso de error, 1 en caso de �xito.
int selectPType(sPType* array, int size, int* id);

