/*
 * bibliotecaTP1.h
 *
 *	Created on: Apr 2, 2022
 *	Author: Gonzalo F. Montero Arguibay
 */

#ifndef FUNCTIONSTPV2_H_
#define FUNCTIONSTPV2_H_


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
int getInteger(int*, char*, char*, int, int, int);



/// @brief Funci�n para recibir una confirmaci�n binaria de tipo S/N.
///
/// @param pResultado 	(char*)	-> 	Devuelve el valor S o N ingresado por el usuario.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del caracter.
/// @param mensajeError (char*)	-> 	Mensaje en caso de error en el ingreso.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return retorna 1 en caso de �xito del ingreso, 0 en caso de falla.
int getConfirm(char*, char*, char*, int);



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
int getFloatingPoint(float*, char*, char*, float, float, int);



/// @brief Funci�n para aplicar un descuento a un nro real (FLOAT).
///
/// @param entrada	 (float)	->	N�mero ingresado sobre el que se aplica el descuento.
/// @param descuento (float)	->	Descuento expresado en nros reales (10% = 10 o 10.00).
/// @param salida	 (float*)	->	Puntero para almacenar el resultado de la operaci�n.
///
/// @return Retorna 1 en caso de �xito del c�lculo, 0 en caso de falla.
int float_calcDescuento(float, float, float*);



/// @brief Funci�n para aplicar un incremento a un nro real (FLOAT).
///
/// @param entrada		(float)	-> N�mero ingresado sobre el que se aplica el incremento.
/// @param incremento 	(float)	-> Incremento expresado en nros reales (10% = 10 o 10.00).
/// @param salida		(float*)-> Puntero para almacenar el resultado de la operaci�n.
///
/// @return Retorna 1 en caso de �xito del c�lculo, 0 en caso de falla.
int float_calcIncremento(float, float, float*);



/// @brief Funci�n para realizar una divisi�n simple entre dos FLOAT.
///
/// @param numerador 	(float)	-> Numerador de la operaci�n.
/// @param denominador 	(float)	-> Denominador de la operaci�n.
/// @param salida 		(float)	-> Puntero para almacenar el resultado de la operaci�n.
///
/// @return retorna 1 en caso de �xito del ingreso, 0 en caso de falla.
int float_divisionSimple(float, float, float*);



/// @brief Funci�n para calcular la diferencia (resta con orden indistinto y resultado de signo positivo) entre dos FLOAT.
///
/// @param inputA 	(float)	-> Primer valor para calcular diferencia.
/// @param inputB 	(float)	-> Segundo valor para calcular diferencia.
/// @param salida 	(float*)-> Puntero para almacenar el resultado de la resta en signo positivo.
///
/// @return retorna 1 en caso de �xito del ingreso, 0 en caso de falla.
int float_calcDiferencia(float, float, float*);



/// @brief Funci�n para calcular los costos de vuelos Aerol�neas y LATAM del TP1.
///
/// @param km 			(int)	-> Kilometraje (x).
/// @param precioAero 	(float)	-> Precio vuelo Aerol�neas (y).
/// @param precioLATAM 	(float)	-> Precio vuelo LATAM (z).
/// @param arrayOut 	(float)	-> ARRAY. Almacena los nueve costos calculados por la funci�n.
void calculoCostosTP1(int, float, float, float*);



/// @brief Funci�n para mostrar los costos de vuelos Aerol�neas y LATAM del TP1.
///
/// @param km 			(int)	-> Kilometraje (x).
/// @param precioAero 	(float)	-> Precio vuelo Aerol�neas (y).
/// @param precioLATAM 	(float)	-> Precio vuelo LATAM (z).
/// @param arrayCostos 	(float*)-> ARRAY. Provee los costos calculados con la funci�n calculoCostosTP1().
void printTP1(int, float, float, float*);



/// @brief Funci�n para detener la ejecuci�n del programa hasta presionar la tecla 'Enter'.
///
void stopAndGo(void);



/// @brief Imprime el Men� din�mico principal del TP1 (6 items) y limpia el texto en consola.
///
/// @param flag (int*)	-> ARRAY. Provee las banderas para regular el display de valores din�micos despu�s del primer ingreso.
/// @param x 	(int)	-> Valor din�mico de Kilometros a mostrar en el men�.
/// @param y 	(float)	-> Valor din�mico de Precio de Aerol�neas a mostrar en el men�.
/// @param z 	(float)	-> Valor din�mico de Precio de LATAM a mostrar en el men�.
///
/// @return Devuelve el valor del men� elegido por el usuario mediante la subfunci�n getInteger().
int printMenuTP1(int*, int, float, float);



/// @brief Imprime el Men� est�tico para el case 2 del TP1 (3 items).
///
/// @return Devuelve el valor del submen� elegido por el usuario mediante la subfunci�n getInteger().
int printSubmenu2TP1(void);



/// @brief Imprime el Men� est�tico para el case 4 del TP1 (3 items).
///
/// @return Devuelve el valor del submen� elegido por el usuario mediante la subfunci�n getInteger().
int printSubmenu4TP1(void);



#endif /* FUNCTIONSTPV2_H_ */
