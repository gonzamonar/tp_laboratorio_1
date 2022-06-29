/*
 * IO.h
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */

#ifndef TP2_IO_H_
#define TP2_IO_H_

#endif /* TP2_IO_H_ */


/// @brief Funci�n para obtener un nro entero (INT) ingresado por el usuario.
///
/// @param pResultado 	(int*)	-> 	Puntero donde va a almacenarse el resultado del ingreso.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del dato.
/// @param mensajeError (char*)	-> 	Mensaje en caso de error en el ingreso.
/// @param minimo  		(int)	-> 	Valor m�nimo del n�mero a ingresar.
/// @param maximo 		(int)	-> 	Valor m�ximo del n�mero a ingresar.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return Retorna 1 en caso de �xito del ingreso, 0 en caso de falla.
int IO_getInteger(int*, char*, char*, int, int, int);



/// @brief Funci�n para recibir una confirmaci�n binaria de tipo S/N.
///
/// @param pResultado 	(char*)	-> 	Devuelve el valor S o N ingresado por el usuario.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del caracter.
/// @param mensajeError (char*)	-> 	Mensaje en caso de error en el ingreso.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return retorna 1 en caso de �xito del ingreso, 0 en caso de falla.
int IO_getConfirm(char*, char*, char*, int);



/// @brief Funci�n para obtener un nro real con decimales (FLOAT) ingresado por el usuario.
///
/// @param pResultado 	(float*)-> 	Puntero donde va a almacenarse el resultado del ingreso.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del dato.
/// @param mensajeError (char)*	->	Mensaje en caso de error en el ingreso.
/// @param minimo 		(float)	->	Valor m�nimo del n�mero a ingresar.
/// @param maximo 		(float)	-> 	Valor m�ximo del n�mero a ingresar.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return Retorna 1 en caso de �xito del ingreso, 0 en caso de falla
int IO_getFloatingPoint(float*, char*, char*, float, float, int);



/// @brief Funci�n para obtener una cadena (string) con formato de nombre propio ingresado por el usuario.
///
/// @param dest 	(char*) -> cadena de destino donde se va a copiar lo ingresado por el usuario
/// @param size		(int) -> tama�o de la cadena de destino
/// @param maxlen	(int) -> tama�o m�ximo aceptado para el ingreso de la cadena
/// @param minlen	(int) -> tama�o m�nimo aceptado para el ingreso de la cadena
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del dato.
/// @param mensajeError (char*)	->	Mensaje en caso de error en el ingreso.
/// @param reintentos (int) -> cantidad de reintentos
/// @param exceptions (char*) -> cadena donde se contienen las excepciones de car�cteres especiales para validar (ejemplo: espacios, guiones, etc).
///
/// @return Retorna 1 en caso de �xito del ingreso, 0 en caso de falla
int IO_getProperName(char* dest, int size, int maxlen, int minlen, char* mensaje, char* mensajeError, int reintentos, char* exceptions);



/// @brief Funci�n para el ingreso de un n�mero de men� sin cancelaci�n por cantidad de intentos fallidos.
///
/// @param pResultado 	(int*)-> 	Puntero donde va a almacenarse el resultado del ingreso.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del dato.
/// @param mensajeError (char)*	->	Mensaje en caso de error en el ingreso.
/// @param minimo  		(int)	-> 	Valor m�nimo del n�mero a ingresar.
/// @param maximo 		(int)	-> 	Valor m�ximo del n�mero a ingresar.
///
/// @return Retorna 1 en caso de �xito del ingreso, 0 en caso de falla
int IO_getMenuSelection(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);


