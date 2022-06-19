/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "IO.h"
#include "Passenger.h"
#include "View.h"
#include "Controller.h"
#include "LL_Funciones.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
     10. Salir
*****************************************************/

int main()
{
	int qPassengers = 0;
	int selection;
	int loadFlag = 0;
	int saveBinFlag = 1;
	int saveCsvFlag = 1;
	char confirmation;

	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");
	chdir("..");

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* copiaSeguridad = ll_newLinkedList();

    if(listaPasajeros != NULL && copiaSeguridad != NULL){
		do{
			qPassengers = ll_len(listaPasajeros);
			switch(view_mainMenu(qPassengers))
			{
				case 1: //Cargar archivo data.csv
						if(!loadFlag){
							if(controller_loadFromText("data.csv", listaPasajeros)){
								loadFlag = 1;
							}
						}else{
							 printf("\n  El archivo ya fue cargado.");
						}
						view_pause();
						break;

				case 2: //Cargar archivo data.bin
						if(!loadFlag){
							if(controller_loadFromBinary("data.bin", listaPasajeros)){
								loadFlag = 1;
							}
						}else{
							 printf("\n  El archivo ya fue cargado.");
						}
						view_pause();
						break;

				case 3: //Alta de pasajero
						if(controller_addPassenger(listaPasajeros)){
							saveCsvFlag = 0;
							saveBinFlag = 0;
						}
						break;

				case 4: //Modificar pasajero
						if(qPassengers){
							if(controller_editPassenger(listaPasajeros)){
								saveCsvFlag = 0;
								saveBinFlag = 0;
							}
						}else{
							printf("\n  No hay pasajeros activos para modificar.");
						}
						view_pause();
						break;

				case 5: //Baja de pasajero
						(qPassengers) ? controller_removePassenger(listaPasajeros) : printf("\n  No hay pasajeros activos para eliminar.");
						view_pause();
						break;

				case 6: //Listar pasajeros
						(qPassengers) ? controller_ListPassenger(listaPasajeros) : printf("\n  No hay pasajeros activos para mostrar.");
						view_pause();
						break;

				case 7: //Ordenar pasajeros
						(qPassengers) ? controller_sortPassenger(listaPasajeros) : printf("\n  No hay pasajeros activos para ordenar."), view_pause() ;
						break;

				case 8: //Guardar data.csv
						if(loadFlag){
							if(controller_saveAsText("data.csv", listaPasajeros)){
								saveCsvFlag = 1;
							}
						}else{
							printf("\n                            ADVERTENCIA: ESTÁ A PUNTO DE SOBRE-ESCRIBIR UN ARCHIVO.\n");
							IO_getConfirm(&confirmation, "\n  Está intentando guardar sin haber cargado un archivo antes.\n  ¿Está seguro de que desea sobreescribir el archivo? S/N: ", "  Opción inválida.", 3);
							if(confirmation == 'S'){
								if(controller_saveAsText("data.csv", listaPasajeros)){
									saveCsvFlag = 1;
								}
							}
						}
						break;

				case 9: //Guardar data.bin
						if(loadFlag){
							if(controller_saveAsBinary("data.bin", listaPasajeros)){
								saveBinFlag = 1;
							}
						}else{
							printf("\n                            ADVERTENCIA: ESTÁ A PUNTO DE SOBRE-ESCRIBIR UN ARCHIVO.\n");
							IO_getConfirm(&confirmation, "\n  Está intentando guardar sin haber cargado un archivo antes.\n  ¿Está seguro de que desea sobreescribir el archivo? S/N: ", "  Opción inválida.", 3);
							if(confirmation == 'S'){
								if(controller_saveAsBinary("data.bin", listaPasajeros)){
									saveBinFlag = 1;
								}
							}
						}
						break;

				case 10: //testear linkedlist
						system("cls");
						controller_run_tests();
						view_pause();
						break;

				case 11: //menu de funciones de linkedlist
						llfunciones_menuPrincipal(listaPasajeros, copiaSeguridad);
						break;

				case 12: //salir
						controller_exit(listaPasajeros, copiaSeguridad, &selection, &saveCsvFlag, &saveBinFlag);
						view_pause();
						break;

				default:
						view_pause();
						break;
			}
		}while(selection != 12);
    }
    return 0;
}
