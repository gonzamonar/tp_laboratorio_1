<<<<<<< HEAD
/*
 * View.h
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */

#ifndef VIEW_H_
#define VIEW_H_


#include "Passenger.h"

#endif /* VIEW_H_ */

/// @brief Función para pausar la ejecución del programa hasta presionar la tecla 'Enter'.
///
void view_pause(void);


/// @brief Imprime el menú principal del programa y retorna la opción elegida.
///
/// @param qPassengers	 -> valor entero de cantidad de pasajeros cargados en sistema
///
/// @return Retorna la opción seleccionada del menu.
int view_mainMenu(int qPassengers);



void view_passengerTable_header();
void view_passengerTable_footer();
void view_printPassengerRow(Passenger* passenger);
void view_SelectionMenu_passengerType(void);
void view_SelectionMenu_flycode(int col, char options[][col]);
void view_loadDescription_passengerType(char* description, int passengerType);
void view_loadDescription_flightStatus(char* description, int flightStatus);

void view_printPassengerFile(Passenger passenger);
void view_printCreationMenu(int* flag, int id, char* name, char* lastName, float price, char* ptype_description, char* flycode);
void view_printUpdateMenu(int* option);
int view_printSortOrderMenu(int* option);
int view_printSortCriteriaMenu(int* option);
=======
/*
 * View.h
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */

#ifndef VIEW_H_
#define VIEW_H_


#include "Passenger.h"

#endif /* VIEW_H_ */

/// @brief Función para pausar la ejecución del programa hasta presionar la tecla 'Enter'.
///
void view_pause(void);


/// @brief Imprime el menú principal del programa y retorna la opción elegida.
///
/// @param qPassengers	 -> valor entero de cantidad de pasajeros cargados en sistema
///
/// @return Retorna la opción seleccionada del menu.
int view_mainMenu(int qPassengers);



void view_passengerTable_header();
void view_passengerTable_footer();
void view_printPassengerRow(Passenger* passenger);
void view_SelectionMenu_passengerType(void);
void view_SelectionMenu_flycode(int col, char options[][col]);
void view_loadDescription_passengerType(char* description, int passengerType);
void view_loadDescription_flightStatus(char* description, int flightStatus);

void view_printPassengerFile(Passenger passenger);
void view_printCreationMenu(int* flag, int id, char* name, char* lastName, float price, char* ptype_description, char* flycode);
void view_printUpdateMenu(int* option);
int view_printSortOrderMenu(int* option);
int view_printSortCriteriaMenu(int* option);
>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
