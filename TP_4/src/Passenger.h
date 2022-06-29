<<<<<<< HEAD
<<<<<<< HEAD
/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[12];
	int tipoPasajero;
	int estadoVuelo;
}Passenger;


Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

#endif /* PASSENGER_H_ */


=======
/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[12];
	int tipoPasajero;
	int estadoVuelo;
}Passenger;


Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

#endif /* PASSENGER_H_ */


>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
=======
/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[12];
	int tipoPasajero;
	int estadoVuelo;
}Passenger;


Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

#endif /* PASSENGER_H_ */


>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
