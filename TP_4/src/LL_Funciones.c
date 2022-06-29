/*
 * LL_Funciones.c
 *
 *  Created on: Jun 18, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include "LL_Funciones.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "View.h"
#include "parser.h"
#include "sorters.h"
#include "user_entry.h"
#include "IO.h"



void llfunciones_menuPrincipal(LinkedList* pArrayListPassenger, LinkedList* pBackupList)
{
	int selection = 0;
	int empty;
	int contained;
	LinkedList* contained_list;
	LinkedList* buffer = NULL;

	do{
		system("cls");
		empty = ll_isEmpty(pBackupList);
		switch(view_linkedlistMenu())
		{
			case 1: //Crear / actualizar copia de seguridad
					buffer = ll_clone(pArrayListPassenger);
					if(buffer != NULL){
						printf("\n  Copia de seguridad creada exitosamente.");
						int len = ll_len(buffer);
						ll_clear(pBackupList);
						for(int i=0; i<len;i++){
							ll_add(pBackupList, ll_get(buffer, i));
						}
						ll_deleteLinkedList(buffer);
						view_pause();
					}
					break;

			case 2: //Recortar copia de seguridad
					(empty) ? printf("\n  La copia de seguridad está vacía.") : llfunciones_recortarLinkedlist(pBackupList);
					view_pause();
					break;

			case 3: //Listar copia de seguridad
					(empty) ? printf("\n  La copia de seguridad está vacía.") : controller_ListPassenger(pBackupList) ;
					view_pause();
					break;

			case 4: //Limpiar copia de seguridad
					if(!ll_clear(pBackupList)){
						printf("\n  Copia de seguridad vaciada exitosamente.");
						view_pause();
					}
					break;

			case 5: //Remover elemento (pop)
					(empty) ? printf("\n  La copia de seguridad está vacía.") : llfunciones_popPassenger(pBackupList) ;
					view_pause();
					break;

			case 6: //Copiar (push) o sobre-escribir un elemento (set)
					contained_list = llfunciones_ListNotContainedPassengers(pArrayListPassenger, pBackupList);
					if(ll_isEmpty(contained_list) == 1){
						printf("\n  No hay pasajeros disponibles para recuperar desde la copia de seguridad.");
					}else{
						llfunciones_backupPassenger(pArrayListPassenger, contained_list);
					}
					view_pause();
					break;

			case 7: //Verificar que la copia está contenida en el listado principal (containsall)
					contained = ll_containsAll(pArrayListPassenger, pBackupList);
					if(!contained){
						printf("\n  Hay elementos de la copia de seguridad que no están en la lista principal.");
					}else if(contained == 1){
						printf("\n  Todos los elementos de la copia de seguridad están en la lista principal.");
					}
					view_pause();
					break;

			case 8: //Verificar si la lista está vacía (isempty)
					if(empty){
						printf("\n  La copia de seguridad está vacía.");
					}else{
						int len = ll_len(pBackupList);
						printf("\n  La copia de seguridad no está vacía, tiene cargados %d elementos.", len);
					}
					view_pause();
					break;

			case 9: //Volver al Menú principal
					selection = 9;
					break;
		}
	}while(selection != 9);
	fflush(stdin);
}




int llfunciones_recortarLinkedlist(LinkedList* pBackupList)
{
	int outcome = -1;
	int index1;
	int index2;
	int maxId;
	LinkedList* buffer = NULL;

	controller_loadNextID("ID.bin", &maxId);

	system("cls");
	controller_ListPassenger(pBackupList);												//print passengers
	printf("   Ingrese dos números de ID para hacer el recorte de la copia.\n");
	if(userEntry_requestPassengerId(pBackupList, &index1, maxId) && userEntry_requestPassengerId(pBackupList, &index2, maxId))
	{
		if(index1 < index2){
			buffer = ll_subList(pBackupList, index1, index2);
		}else{
			buffer = ll_subList(pBackupList, index2, index1);
		}
		printf("\n   Recorte efectuado exitosamente");
		ll_clear(pBackupList);
		int len = ll_len(buffer);
		for(int i=0; i<len;i++){
			ll_push(pBackupList, i, ll_get(buffer, i));
		}
	}
	else
	{
		printf("\n\n  Intentos de carga de id agotados. El proceso ha sido cancelado.");
	}
return outcome;
}


int llfunciones_popPassenger(LinkedList* pBackupList)
{
	int outcome = -1;
	int index;
	int maxId;

	controller_loadNextID("ID.bin", &maxId);

	system("cls");
	controller_ListPassenger(pBackupList);												//print passengers
	if(userEntry_requestPassengerId(pBackupList, &index, maxId))
	{
		ll_pop(pBackupList, index);
	}
	else
	{
		printf("\n\n  Intentos de carga de id agotados. El proceso ha sido cancelado.");
	}
return outcome;
}



LinkedList* llfunciones_ListNotContainedPassengers(LinkedList* pArrayListPassenger, LinkedList* pBackupList)
{
	LinkedList* uncontained = ll_newLinkedList();
	if(pArrayListPassenger != NULL && pBackupList != NULL && uncontained != NULL)
	{
		Passenger* passenger;
		view_passengerTable_header();
		int len = ll_len(pBackupList);
		for(int i=0; i<len; i++)
		{
			passenger = (Passenger*) ll_get(pBackupList, i);
			if(!ll_contains(pArrayListPassenger, passenger)){
				view_printPassengerRow(passenger);
				ll_add(uncontained, passenger);
			}
		}
		view_passengerTable_footer();
	}
    return uncontained;
}


int llfunciones_backupPassenger(LinkedList* pArrayListPassenger, LinkedList* uncontained)
{
	int outcome = -1;
	int index;
	int maxId;
	int choice;
	Passenger* chosen_Passenger;

	controller_loadNextID("ID.bin", &maxId);
	if(userEntry_requestPassengerId(uncontained, &index, maxId))
	{
		chosen_Passenger = (Passenger*) ll_get(uncontained, index);
		view_SelectionMenu_Backup();
		if(IO_getInteger(&choice, "\n    Seleccione una opción: ", "\n  Opción inválida. ", 1, 2, 3)){
			controller_ListPassenger(pArrayListPassenger);
			if(choice == 1){
				printf("\n\n  ¿En la posición de qué pasajero desea copiarlo? ");
			}else{
				printf("\n\n  ¿Qué pasajero desea sobre-escribir? ");
			}
			userEntry_requestPassengerId(pArrayListPassenger, &index, maxId);
			if(choice == 1){
				ll_push(pArrayListPassenger, index, chosen_Passenger);
			}else{
				ll_set(pArrayListPassenger, index, chosen_Passenger);
			}
		}
	}
	else
	{
		printf("\n\n  Intentos de carga de id agotados. El proceso ha sido cancelado.");
	}
return outcome;
}

