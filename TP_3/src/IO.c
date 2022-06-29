/*
 * IO.c
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "my_ctype.h"


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

/// @brief Reversión de la función fgets eliminando el enter final del ingreso con longitud minima y maxima de cadena.
///
/// @param str -> cadena de destino del ingreso
/// @param size -> tamaño de la cadena de destino
/// @param maxlen -> longitud máxima aceptada
/// @param minlen -> longitud minima aceptada
///
/// @return Retorna 1 en caso de éxito de la validación y 0 en caso de falla.
static int myStrGets(char* str, int size, int maxlen, int minlen);


/// @brief Solicita el ingreso de una cadena al usuario y la valida.
///
/// @param dest -> cadena de destino
/// @param size -> tamaño de la cadena de destino
/// @param maxlen -> longitud máxima aceptada
/// @param minlen -> longitud minima aceptada
/// @param exceptions -> excepciones de validación (espacios, carácteres especiales, etc)
///
/// @return Retorna 1 en caso de éxito de la validación y 0 en caso de falla.
static int getStr(char* dest, int size, int maxlen, int minlen, char* exceptions);


/// @brief Valida que la cadena esté compuesta por letras.
///
/// @param str -> cadena a validar
/// @param exceptions -> excepciones de validación (espacios, guiones, etc)
///
/// @return Retorna 1 en caso de éxito de la validación y 0 en caso de falla.
static int validateAlphaStr(char* str, char* exceptions);


/// @brief Valida que la cadena posea al menos una vocal y una consonante.
///
/// @param str -> cadena a validar
///
/// @return Retorna 1 en caso de éxito de la validación y 0 en caso de falla.
static int checkVowelsAndConsonants(char* str);


static int myStrGets(char* str, int size, int maxlen, int minlen){
	int outcome = 0;
	if(str != NULL && size > 0 && fgets(str, size, stdin) == str){
		if(strlen(str)<=maxlen && strlen(str)>=minlen){
			fflush(stdin);
			if(str[strlen(str)-1] == '\n'){
				str[strlen(str)-1] = '\0';
			}
			outcome = 1;
		}
	}
	return outcome;
}

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

static int getStr(char* dest, int size, int maxlen, int minlen, char* exceptions){
	int outcome = 0;
	char buffer[size+4];
	if(dest != NULL){
		if(myStrGets(buffer, size, maxlen, minlen) && validateAlphaStr(buffer, exceptions) && checkVowelsAndConsonants(buffer)){
			strcpy(dest, buffer);
			outcome = 1;
		}
	}
	return outcome;
}


static int checkVowelsAndConsonants(char* str){
	int outcome = 0;
	int i = 0;
	int consonantFlag = 0;
	int vowelFlag = 0;

	if(str != NULL && strlen(str) > 0){
		while(str[i] != '\0'){
			if(!vowelFlag && strchr("aeiouAEIOU", str[i])){
				vowelFlag = 1;
			}

			if(!consonantFlag && strchr("bcdfghjklmnñpqrstvwxyzBCDFGHJKLMNÑPQRSTVWXYZ", str[i])){
				consonantFlag = 1;
			}

			if(vowelFlag && consonantFlag){
				outcome = 1;
				break;
			}
			i++;
		}
	}
	return outcome;
}

static int validateAlphaStr(char* str, char* exceptions){
	int outcome = 1;
	int i = 0;

	if(str != NULL && strlen(str) > 0){
		while(str[i] != '\0'){
			if(!isalpha(str[i]) && !(strchr(exceptions, str[i]))){
				outcome = 0;
				break;
			}
			i++;
		}
	}
	return outcome;
}




int IO_getInteger(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int outcome = 0;
	int number;
	if(mensaje != NULL && pResultado != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 1){
		do{
			reintentos--;
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
			if(reintentos>=1){
				printf("%s", mensajeError);
				printf("(Intentos restantes: %d)\n", reintentos);
			}
		}while(reintentos >= 1);
	}
	return outcome;
}




int IO_getConfirm(char* pResultado, char* mensaje, char* mensajeError, int reintentos){
	int outcome = 0;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 1){
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
				if(reintentos>=1){
					printf("%s", mensajeError);
					printf("(Intentos restantes: %d)\n", reintentos);
				}
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return outcome;
}



int IO_getFloatingPoint(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
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

			if(reintentos>=1){
				printf("%s", mensajeError);
				printf("(Intentos restantes: %d)\n", reintentos);
			}
			reintentos--;
		}while(reintentos >= 0);
	}
	return outcome;
}


int IO_getProperName(char* dest, int size, int maxlen, int minlen, char* mensaje, char* mensajeError, int reintentos, char* exceptions){
	int outcome = 0;
	char strBuffer[size+4];

	if(mensaje != NULL && dest != NULL && mensajeError != NULL && size >0 && maxlen>=minlen && reintentos >= 1){
		do{
			reintentos--;
			fflush(stdin);
			printf("%s", mensaje);
			if(getStr(strBuffer,size,maxlen,minlen,exceptions)){
					fflush(stdin);
					totitle(strBuffer);
					strcpy(dest, strBuffer);
					outcome = 1;
					break;
			}
			if(reintentos>=1){
				printf("%s", mensajeError);
				printf("(Intentos restantes: %d)\n", reintentos);
			}
		}while(reintentos >= 1);
	}
	return outcome;
}


int IO_getMenuSelection(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo){
	int outcome = 0;
	int number;
	if(mensaje != NULL && pResultado != NULL && mensajeError != NULL && minimo <= maximo){
		fflush(stdin);
		printf("%s", mensaje);
		if(getInt(&number)){
			if(number >= minimo && number <= maximo){
				*pResultado = number;
				outcome = 1;
				return outcome;
			}
		}
		fflush(stdin);
		printf("%s", mensajeError);
	}
	return outcome;
}
