/*
 * bibliotecaTP1.c
 *
 *	Created on: Apr 2, 2022
 *	Author: Gonzalo F. Montero Arguibay
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wchar.h>
#include <conio.h>
#include <string.h>

#include "bibliotecaTP1.h"

/// @brief Reversión de la función fgets eliminando el enter final del ingreso.
///
/// @param str (char*)	-> Puntero a STRING donde se almacena la cadena ingresada.
/// @param len (int)	-> INT que indica la longitud de la cadena.
///
/// @return Retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
static int myGets(char*, int);

/// @brief Solicita el ingreso de un número al usuario y valida que sea INT.
///
/// @param pResultado (int*)-> Puntero a INT donde se almacena el ingreso.
///
/// @return Retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
static int getInt(int*);

/// @brief Valida que todos los valores dentro de una cadena sean números enteros.
///
/// @param str (char*)-> STRING a validar por la función.
///
/// @return Retorna 1 en caso de éxito de la validación y 0 en caso de falla.
static int validateInteger(char* str);

/// @brief Solicita el ingreso de un número al usuario y valida que sea FLOAT.
///
/// @param pResultado (float*)-> Puntero a FLOAT donde se almacena el ingreso.
///
/// @return Retorna 1 en caso de éxito del ingreso, 0 en caso de falla.
static int getFloat(float*);

/// @brief Valida que todos los valores dentro de una cadena sean números reales (con decimales).
///
/// @param str (char*)-> STRING a validar por la función.
///
/// @return Retorna 1 en caso de éxito de la validación y 0 en caso de falla.
static int validateFloat(char*);



static int myGets(char* str, int len){
	int outcome = 0;
	if(str != NULL && len > 0 && fgets(str, len, stdin) == str){
		fflush(stdin);
		if(str[strlen(str)-1] == '\n'){
			str[strlen(str)-1] = '\0';
		}
		outcome = 1;
	}
	return outcome;
}

static int getInt(int* pResultado){
	int outcome = 0;
	char buffer[64];
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) && validateInteger(buffer)){
			*pResultado = atoi(buffer);
			outcome = 1;
		}
	}
	return outcome;
}

static int validateInteger(char* str){
	int outcome = 1;
	int i = 0;
	if(str != NULL && strlen(str) > 0){
		while(str[i] != '\0'){
			if(str[i] < '0' || str[i] > '9'){
				outcome = 0;
				break;
			}
			i++;
		}
	}
	return outcome;
}

static int getFloat(float* pResultado){
	int outcome = 0;
	char buffer[64];
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) && validateFloat(buffer)){
			*pResultado = atof(buffer);
			outcome = 1;
		}
	}
	return outcome;
}

static int validateFloat(char* str){
	int outcome = 1;
	int i = 0;
	if(str != NULL && strlen(str) > 0){
		while(str[i] != '\0'){
			if((str[i] < '0' || str[i] > '9') && str[i] != '.'){
				outcome = 0;
				break;
			}
			i++;
		}
	}
	return outcome;
}



int getInteger(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int outcome = 0;
	int number;
	if(mensaje != NULL && pResultado != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			fflush(stdin);
			printf("%s", mensaje);
			if(getInt(&number)){
				if(number >= minimo && number <= maximo){
					*pResultado = number;
					outcome = 1;
					break;
				}
			}
			fflush(stdin);
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return outcome;
}



int getConfirm(char* pResultado, char* mensaje, char* mensajeError, int reintentos){
	int outcome = 0;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			fflush(stdin);
			printf("%s", mensaje);
			scanf("%c", &buffer);
			buffer = toupper(buffer);
			if(buffer == 'S' || buffer == 'N'){
				*pResultado = buffer;
				outcome = 1;
				break;
			}else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return outcome;
}



int getFloatingPoint(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	int outcome = 0;
	float number;
	if(mensaje != NULL && pResultado != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			fflush(stdin);
			printf("%s", mensaje);
			if(getFloat(&number)){
				if(number >= minimo && number <= maximo){
					*pResultado = number;
					outcome = 1;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return outcome;
}



int float_calcDescuento(float entrada, float descuento, float* salida){
	float outcome = 0;
	if(salida != NULL && descuento >= 0){
		outcome = 1;
		*salida = entrada * (1-(descuento*0.01));
	}
	return outcome;
}



int float_calcIncremento(float entrada, float incremento, float* salida){
	float outcome = 0;
	if(salida != NULL && incremento >= 0){
		outcome = 1;
		*salida = entrada * (1+(incremento*0.01));
	}
	return outcome;
}



int float_divisionSimple(float numerador, float denominador, float* salida){
	float outcome = 0;
	if(salida != NULL && denominador != 0){
		outcome = 1;
		*salida = numerador / denominador;
	}
	return outcome;
}



int float_calcDiferencia(float inputA, float inputB, float* salida){
	float outcome = 0;
	if(salida != NULL){
		outcome = 1;
		*salida = inputA - inputB;
		if (*salida < 0){
			*salida = *salida * -1;
		}
	}
	return outcome;
}



void calculoCostosTP1(int km, float precioAero, float precioLATAM, float* arrayOut){
	float_calcDescuento(precioAero, 10, &arrayOut[0]);
	float_calcIncremento(precioAero, 25, &arrayOut[1]);
	float_divisionSimple(precioAero, 4606954.55, &arrayOut[2]);
	float_divisionSimple(precioAero, km, &arrayOut[3]);
	float_calcDescuento(precioLATAM, 10, &arrayOut[4]);
	float_calcIncremento(precioLATAM, 25, &arrayOut[5]);
	float_divisionSimple(precioLATAM, 4606954.55, &arrayOut[6]);
	float_divisionSimple(precioLATAM, km, &arrayOut[7]);
	float_calcDiferencia(precioAero, precioLATAM, &arrayOut[8]);
}



void printTP1(int km, float precioAero, float precioLATAM, float* arrayCostos){
	printf("\nKMs Ingresados: %d km\n\n", km);
	printf("Precio Aerolíneas: $ %.2f\n", precioAero);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", arrayCostos[0]);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", arrayCostos[1]);
	printf("c) Precio pagando con bitcoin: %.4f BTC\n", arrayCostos[2]);
	printf("d) Precio unitario: $ %.2f por km\n\n", arrayCostos[3]);
	printf("Precio LATAM: $ %.2f\n", precioLATAM);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", arrayCostos[4]);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", arrayCostos[5]);
	printf("c) Precio pagando con bitcoin : %.4f BTC\n", arrayCostos[6]);
	printf("d) Precio unitario: $ %.2f por km\n\n", arrayCostos[7]);
	printf("La diferencia de precio es: $ %.2f\n", arrayCostos[8]);
}



void stopAndGo(void){
	char c;
	fflush(stdin);
	printf("\n\n***** Presione enter para continuar. *****");
	scanf("%c", &c);
	fflush(stdin);
}



int printMenuTP1(int* flag, int x, float y, float z){
	int selection = 7;
	system("cls");
	printf("\n----------------------------------------------\n");
	printf("-------------------- MENU --------------------\n\n");
	if (flag[0]){
		printf("  1. Ingresar Kilómetros: Sin Ingresar.\n");
	}else{
		printf("  1. Ingresar Kilómetros: %dkm.\n", x);
	}
	if (flag[1]){
		printf("  2. Ingresar Precio de Vuelos:\n");
		printf("     - Precio vuelo Aerolíneas: Sin Ingresar."
				"\n");
		printf("     - Precio vuelo Latam: Sin Ingresar.\n");
	}else{
		printf("  2. Ingresar Precio de Vuelos:\n");
		printf("     - Precio vuelo Aerolíneas: $%.2f.\n", y);
		printf("     - Precio vuelo Latam: $%.2f.\n", z);
	}
	printf("  3. Calcular todos los costos.\n");
	printf("  4. Informar resultados.\n");
	printf("  5. Carga forzada de datos.\n");
	printf("  6. Salir.\n\n");
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n\n");
	fflush(stdin);
	getInteger(&selection, "Elija una opción: ", "Opción de menú incorrecta, inténtelo nuevamente.\n", 1, 6, 0);
	return selection;
}



int printSubmenu2TP1(void){
	int rta = 4;
	printf("\nDesea editar:\n");
	printf("       1. Costos de Aerolíneas.\n");
	printf("       2. Costos de LATAM.\n");
	printf("       3. Ambos.\n\n");
	fflush(stdin);
	getInteger(&rta, "Elija su respuesta y presione enter: ", "Opción de menú incorrecta, elija 1, 2 o 3.\n", 1, 3, 0);
	return rta;
}



int printSubmenu4TP1(void){
	int rta = 4;
	printf("\nSe realizaron modificaciones en los valores de kilometraje y/o precio\ny los nuevos costos aún no fueron calculados.\n");
	printf("\nDesea:\n");
	printf("       1. Mostrar los costos calculados previamente a realizar las modificaciones.\n");
	printf("       2. Calcular los nuevos costos y mostrarlos.\n");
	printf("       3. Regresar al menú.\n\n");
	fflush(stdin);
	getInteger(&rta, "Elija su respuesta y presione enter: ", "Opción de menú incorrecta, elija 1, 2 o 3.\n", 1, 3, 0);
	return rta;
}
