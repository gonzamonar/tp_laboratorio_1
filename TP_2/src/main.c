/*
 ==========================================================================================================================
 Name        : TP2_v2.c
 Autor       : Gonzalo Fabi�n Montero Arguibay
 Asignatura  : UTN-FRA - Programaci�n I
 Description : TP2 - Programaci�n I - Div G.

 Observaciones: - El campo name y lastName (char*) no soportan ingresos (salvo hardcoded) con acentos, di�resis (����� �)
				  o similares, para resolverlo habr�a que usar la librer�a <wchar.h>, reemplazar la funci�n fgets por fgetws
				  y utilizar el tipo wchar_t en lugar de char, pero se respet� el tipo de dato asignado por consigna.
 ==========================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "ArrayPassenger.h"
#include "ArrayPassenger_ui.h"
#include "flights.h"
#include "flight_status.h"
#include "gral_io.h"
#include "gral_ui.h"
#include "gtype.h"
#include "passenger_type.h"

#define SIZE_PASSENGERS 2000
#define SIZE_FLIGHTS 6
#define SIZE_PTYPES 4
#define SIZE_FSTATUS 5

int main(void) {
	Passenger passengers[SIZE_PASSENGERS];
	sFlight flights[SIZE_FLIGHTS];
	sPType ptypes[SIZE_PTYPES];
	sFStatus fstatus[SIZE_FSTATUS];

	int pNextId = 1000;
	int qPassengers = 0;
	int harcodeAvail = 20;
	int selection;

	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");

	initPassengers(passengers, SIZE_PASSENGERS);
	initFlights(flights, SIZE_FLIGHTS);
	initPTypes(ptypes, SIZE_PTYPES);
	initFStatus(fstatus, SIZE_FSTATUS);

	harcodeFlights(flights, SIZE_FLIGHTS);
	harcodePTypes(ptypes, SIZE_PTYPES);
	harcodeFStatus(fstatus, SIZE_FSTATUS);

	do{
		switch (printMainMenu(harcodeAvail, qPassengers)){
			case 1: //altas
					(qPassengers!=SIZE_PASSENGERS) ? creationInterface(passengers, SIZE_PASSENGERS, flights, SIZE_FLIGHTS, ptypes, SIZE_PTYPES, fstatus, SIZE_FSTATUS, &pNextId, &qPassengers) : printf("\n  No se pueden cargar m�s pasajeros en el sistema.");
					pause();
					break;

			case 2: //modificaciones
					(qPassengers) ? updateInterface(passengers, SIZE_PASSENGERS, flights, SIZE_FLIGHTS, ptypes, SIZE_PTYPES, fstatus, SIZE_FSTATUS, &pNextId) : printf("\n  No hay pasajeros activos para modificar.");
					pause();
					break;

			case 3: //bajas
					(qPassengers) ? deleteInterface(passengers, SIZE_PASSENGERS, flights, SIZE_FLIGHTS, ptypes, SIZE_PTYPES, fstatus, SIZE_FSTATUS, &pNextId, &qPassengers) : printf("\n  No hay pasajeros activos para eliminar.");
					pause();
					break;

			case 4: //informes
					(qPassengers) ? reportsInterface(passengers, SIZE_PASSENGERS, flights, SIZE_FLIGHTS, ptypes, SIZE_PTYPES, fstatus, SIZE_FSTATUS, qPassengers) : printf("\n  No hay pasajeros activos para mostrar o informar.");
					break;

			case 5: //hardcode
					(harcodeAvail) ? hardcodeInterface(passengers, SIZE_PASSENGERS, &harcodeAvail, &pNextId, &qPassengers) : printf("\n  Ya fue cargado el m�ximo de pasajeros disponibles para carga forzada.\n");
					pause();
					break;

			case 6: //vuelos
					flightsInterface(flights, SIZE_FLIGHTS, fstatus, SIZE_FSTATUS, passengers, SIZE_PASSENGERS);
					break;

			case 7: //salir
					selection = 7;
					printf("\n  Ejecuci�n concluida.");
					pause();
					break;

			default:
					pause();
					break;
		}
	}while(selection != 7);
}
