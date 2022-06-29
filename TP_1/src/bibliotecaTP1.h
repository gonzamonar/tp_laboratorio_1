/*
 * bibliotecaTP1.h
 *
 *	Created on: Apr 2, 2022
 *	Author: Gonzalo F. Montero Arguibay
 */

#ifndef FUNCTIONSTPV2_H_
#define FUNCTIONSTPV2_H_


/// @brief Función para obtener un nro entero (INT) ingresado por el usuario.
///
/// @param pResultado 	(int*)	-> 	Puntero donde va a almacenarse el resultado del ingreso.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del dato.
/// @param mensajeError (char*)	-> 	Mensaje en caso de error en el ingreso.
/// @param minimo  		(int)	-> 	Valor mínimo del número a ingresar.
/// @param maximo 		(int)	-> 	Valor máximo del número a ingresar.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return Retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
int getInteger(int*, char*, char*, int, int, int);



/// @brief Función para recibir una confirmación binaria de tipo S/N.
///
/// @param pResultado 	(char*)	-> 	Devuelve el valor S o N ingresado por el usuario.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del caracter.
/// @param mensajeError (char*)	-> 	Mensaje en caso de error en el ingreso.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
int getConfirm(char*, char*, char*, int);



/// @brief Función para obtener un nro real con decimales (FLOAT) ingresado por el usuario.
///
/// @param pResultado 	(float*)-> 	Puntero donde va a almacenarse el resultado del ingreso.
/// @param mensaje 		(char*)	-> 	Mensaje para solicitar el ingreso del dato.
/// @param mensajeError (char)*	->	Mensaje en caso de error en el ingreso.
/// @param minimo 		(float)	->	Valor mínimo del número a ingresar.
/// @param maximo 		(float)	-> 	Valor máximo del número a ingresar.
/// @param reintentos 	(int)	-> 	Cantidad de reintentos otorgados al usuario.
///
/// @return Retorna 1 en caso de éxito del ingreso, 0 en caso de falla
int getFloatingPoint(float*, char*, char*, float, float, int);



/// @brief Función para aplicar un descuento a un nro real (FLOAT).
///
/// @param entrada	 (float)	->	Número ingresado sobre el que se aplica el descuento.
/// @param descuento (float)	->	Descuento expresado en nros reales (10% = 10 o 10.00).
/// @param salida	 (float*)	->	Puntero para almacenar el resultado de la operación.
///
/// @return Retorna 1 en caso de éxito del cálculo, 0 en caso de falla.
int float_calcDescuento(float, float, float*);



/// @brief Función para aplicar un incremento a un nro real (FLOAT).
///
/// @param entrada		(float)	-> Número ingresado sobre el que se aplica el incremento.
/// @param incremento 	(float)	-> Incremento expresado en nros reales (10% = 10 o 10.00).
/// @param salida		(float*)-> Puntero para almacenar el resultado de la operación.
///
/// @return Retorna 1 en caso de éxito del cálculo, 0 en caso de falla.
int float_calcIncremento(float, float, float*);



/// @brief Función para realizar una división simple entre dos FLOAT.
///
/// @param numerador 	(float)	-> Numerador de la operación.
/// @param denominador 	(float)	-> Denominador de la operación.
/// @param salida 		(float)	-> Puntero para almacenar el resultado de la operación.
///
/// @return retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
int float_divisionSimple(float, float, float*);



/// @brief Función para calcular la diferencia (resta con orden indistinto y resultado de signo positivo) entre dos FLOAT.
///
/// @param inputA 	(float)	-> Primer valor para calcular diferencia.
/// @param inputB 	(float)	-> Segundo valor para calcular diferencia.
/// @param salida 	(float*)-> Puntero para almacenar el resultado de la resta en signo positivo.
///
/// @return retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
int float_calcDiferencia(float, float, float*);



/// @brief Función para calcular los costos de vuelos Aerolíneas y LATAM del TP1.
///
/// @param km 			(int)	-> Kilometraje (x).
/// @param precioAero 	(float)	-> Precio vuelo Aerolíneas (y).
/// @param precioLATAM 	(float)	-> Precio vuelo LATAM (z).
/// @param arrayOut 	(float)	-> ARRAY. Almacena los nueve costos calculados por la función.
void calculoCostosTP1(int, float, float, float*);



/// @brief Función para mostrar los costos de vuelos Aerolíneas y LATAM del TP1.
///
/// @param km 			(int)	-> Kilometraje (x).
/// @param precioAero 	(float)	-> Precio vuelo Aerolíneas (y).
/// @param precioLATAM 	(float)	-> Precio vuelo LATAM (z).
/// @param arrayCostos 	(float*)-> ARRAY. Provee los costos calculados con la función calculoCostosTP1().
void printTP1(int, float, float, float*);



/// @brief Función para detener la ejecución del programa hasta presionar la tecla 'Enter'.
///
void stopAndGo(void);



/// @brief Imprime el Menú dinámico principal del TP1 (6 items) y limpia el texto en consola.
///
/// @param flag (int*)	-> ARRAY. Provee las banderas para regular el display de valores dinámicos después del primer ingreso.
/// @param x 	(int)	-> Valor dinámico de Kilometros a mostrar en el menú.
/// @param y 	(float)	-> Valor dinámico de Precio de Aerolíneas a mostrar en el menú.
/// @param z 	(float)	-> Valor dinámico de Precio de LATAM a mostrar en el menú.
///
/// @return Devuelve el valor del menú elegido por el usuario mediante la subfunción getInteger().
int printMenuTP1(int*, int, float, float);



/// @brief Imprime el Menú estático para el case 2 del TP1 (3 items).
///
/// @return Devuelve el valor del submenú elegido por el usuario mediante la subfunción getInteger().
int printSubmenu2TP1(void);



/// @brief Imprime el Menú estático para el case 4 del TP1 (3 items).
///
/// @return Devuelve el valor del submenú elegido por el usuario mediante la subfunción getInteger().
int printSubmenu4TP1(void);



#endif /* FUNCTIONSTPV2_H_ */
