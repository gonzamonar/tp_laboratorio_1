

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "View.h"
#include "parser.h"
#include "sorters.h"
#include "user_entry.h"
#include "IO.h"

#define SUCCESS 1
#define FAILURE 0

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;

	FILE* f = fopen(path, "r");
	if(f==NULL){
		printf("   No se pudo abrir el archivo.\n");
	}else{
		parser_PassengerFromText(f, pArrayListPassenger);
		outcome = SUCCESS;
		printf("\n  Carga exitosa.");
	}
	fclose(f);
    return outcome;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	FILE* f = fopen(path, "rb");
	if(f==NULL){
		printf("   No se pudo abrir el archivo.\n");
	}else{
		parser_PassengerFromBinary(f, pArrayListPassenger);
		outcome = SUCCESS;
		printf("\n  Carga exitosa.");
	}
	fclose(f);
    return outcome;
}


/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	int stage = 1;
	int flags[5] = {0,0,0,0,0}; //Flag: name,lastName,price,typePassenger,flycode
	int nextId = 0;
	char name[51]; 				//Stage 1
	char lastName[51]; 			//Stage 2
	float price; 				//Stage 3
	int passengerTypeId;		//Stage 4
	char flycode[12];			//Stage 5
	char confirm;				//Stage 6
	char ptypeDescription[16];

	controller_loadNextID("ID.bin", &nextId);

	do{
		fflush(stdin);
		view_printCreationMenu(flags, nextId, name, lastName, price, ptypeDescription, flycode);
		switch (stage){
			case 1:	//get name
					userEntry_requestName(&stage, name, flags);
					break;

			case 2:	//get surname
					userEntry_requestLastname(&stage, lastName, flags);
					break;

			case 3:	//get price
					userEntry_requestPrice(&stage, &price, flags);
					break;

			case 4:	//get typePassenger
					userEntry_requestPType(&stage, &passengerTypeId, ptypeDescription, flags);
					break;

			case 5:	//get flycode & statusFlight
					userEntry_requestFlycode(&stage, flycode, flags);
					break;

			case 6:	//get confirm & add passenger or cancel
					IO_getConfirm(&confirm, "\n  ¿Desea confirmar el alta en el sistema? (S/N): ", "  Error, ingrese una respuesta válida. ", 3);
					if(confirm == 'S')
					{
						Passenger* newPassenger = (Passenger*) Passenger_newParametros(nextId, name, lastName, price, passengerTypeId, flycode);
						if(newPassenger != NULL && ll_add(pArrayListPassenger, newPassenger)==0){
							printf("\n  Pasajero cargado correctamente.");
							nextId++;
							controller_saveNextID("ID.bin", &nextId);
							outcome = SUCCESS;
						}else{
							printf("\n  El alta ha sido cancelada.") ;
						}
					}
					else
					{
						printf("\n  El alta ha sido cancelada.");
					}
					stage++;
					break;
		}
	}while(stage != 7);
	view_pause();
    return outcome;
}


/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	int option;
	int passengerIndex;
	int maxId;
	char confirm;

	controller_loadNextID("ID.bin", &maxId);

	system("cls");
	controller_ListPassenger(pArrayListPassenger);								//print passengers
	if(userEntry_requestPassengerId(pArrayListPassenger, &passengerIndex, maxId)){    //request ID
		Passenger* chosenPassenger = (Passenger*) ll_get(pArrayListPassenger, passengerIndex);
		do{
			int editFlag = 0;
			fflush(stdin);
			view_printPassengerFile(*chosenPassenger);     //print passenger file
			view_printUpdateMenu(&option);			  //print update menu
			switch(option){
				case 1:	//edit name
						userEntry_editName(chosenPassenger, &editFlag);
						break;

				case 2:	//edit surname
						userEntry_editLastame(chosenPassenger, &editFlag);
						break;

				case 3:	//edit price
						userEntry_editPrice(chosenPassenger, &editFlag);
						break;

				case 4:	//edit passengerType
						userEntry_editPType(chosenPassenger, &editFlag);
						break;

				case 5:	//edit flycode
						userEntry_editFlycode(chosenPassenger, &editFlag);
						break;
			}
			//new edit or exit
			if(editFlag){
				system("cls");
				outcome = SUCCESS;
				view_printPassengerFile(*chosenPassenger);
				printf("\n  Modificación realizada exitosamente.");
				if(!IO_getConfirm(&confirm, "  ¿Desea realizar otra modificación? (S/N): ", "\n  Error, ingrese una respuesta válida. ", 3) || confirm == 'N'){
					option = 6;
				}
			}else{
				option = 6;
			}
		}while(option != 6);
	}else{
		printf("\n\n  Intentos de carga de id agotados. El proceso de modificación ha sido cancelado.");
	}
return outcome;
}


/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	int passengerIndex;
	int id;
	int maxId;
	char confirm;
	char confirmMsg[64];
	char errorMsg[64];

	controller_loadNextID("ID.bin", &maxId);
	sprintf(errorMsg, "  Error, ingrese un id válido (1000 a %4d). ", maxId);

	system("cls");
	controller_ListPassenger(pArrayListPassenger);												//print passengers
	if(userEntry_requestPassengerId(pArrayListPassenger, &passengerIndex, maxId))			//request ID && return index
	{
		Passenger* chosenPassenger = (Passenger*) ll_get(pArrayListPassenger, passengerIndex);  //get Passenger
		view_printPassengerFile(*chosenPassenger);     											//print passenger file
		Passenger_getId(chosenPassenger, &id);
		sprintf(confirmMsg, "\n  ¿Desea confirmar la baja del pasajero Nº %d? (S/N): ", id);
		printf("\n                            IMPORTANTE: ESTA ACCIÓN NO SE PUEDE DESHACER.\n");
		IO_getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);						//confirm && remove the passenger
		if(confirm=='S')
		{
			ll_remove(pArrayListPassenger, passengerIndex);
			outcome = SUCCESS;
		}
		else
		{
			printf("\n  Baja cancelada.");
		}
	}
	else
	{
		printf("\n\n  Intentos de carga de id agotados. El proceso de baja ha sido cancelado.");
	}
return outcome;
}



/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	if(pArrayListPassenger != NULL)
	{
		Passenger* passenger;
		view_passengerTable_header();
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			passenger = (Passenger*) ll_get(pArrayListPassenger, i);
			view_printPassengerRow(passenger);
		}
		view_passengerTable_footer();
		outcome = SUCCESS;
	}
    return outcome;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int order = 1;
	int criteria = 15;

	view_printSortOrderMenu(&order);
	if(order!=3){
		system("cls");
		view_printSortCriteriaMenu(&criteria);
		if(criteria != 15)
		{
			switch(criteria)
			{
				//CRITERIOS SIMPLES//
				case 1: //Ordenar por ID
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_ID, order);
						break;

				case 2: //Ordenar por Nombre
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_name, order);
						break;

				case 3: //Ordenar por Apellido
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_lastname, order);
						break;

				case 4: //Ordenar por Precio
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_price, order);
						break;

				case 5: //Ordenar por Código de Vuelo
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_flycode, order);
						break;

				case 6: //Ordenar por Tipo de Pasajero
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_passengerType, order);
						break;

				//CRITERIOS COMPUESTOS//
				case 7: //Ordenar por Apellido y Nombre
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_lastname_name, order);
						break;

				case 8: //Ordenar por Apellido y Precio
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_lastname_price, order);
						break;

				case 9: //Ordenar por Apellido y Tipo de Pasajero
						printf("\n  Ordenando...");
						ll_sort(pArrayListPassenger, sorter_lastname_passengerType, order);
						break;

				case 10: //Ordenar por Código de Vuelo y Apellido
					printf("\n  Ordenando...");
					ll_sort(pArrayListPassenger, sorter_flycode_lastname, order);
						break;

				case 11: //Ordenar por Código de Vuelo y Tipo de Pasajero
					printf("\n  Ordenando...");
					ll_sort(pArrayListPassenger, sorter_flycode_passengerType, order);
						break;

				case 12: //Ordenar por Código de Vuelo y Precio
					printf("\n  Ordenando...");
					ll_sort(pArrayListPassenger, sorter_flycode_price, order);
						break;

				case 13: //Ordenar por Tipo de Pasajero y Apellido
					printf("\n  Ordenando...");
					ll_sort(pArrayListPassenger, sorter_passengerType_lastname, order);
						break;

				case 14: //Ordenar por Tipo de Pasajero y Código de Vuelo
					printf("\n  Ordenando...");
					ll_sort(pArrayListPassenger, sorter_passengerType_flycode, order);
						break;
			}
		}
	}
	fflush(stdin);
    return SUCCESS;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	char passengerType[16];
	char flightStatus[16];

	FILE* f = fopen(path, "w");
	Passenger* buffer = NULL;

	if(f!=NULL)
	{
		int len = ll_len(pArrayListPassenger);
		fprintf(f, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(int i=0; i<len; i++)
		{
			buffer = (Passenger*) ll_get(pArrayListPassenger, i);
			view_loadDescription_passengerType(passengerType, buffer->tipoPasajero);
			view_loadDescription_flightStatus(flightStatus, buffer->estadoVuelo);
			fprintf(f, "%d,%s,%s,%.2f,%s,%s,%s\n", buffer->id,buffer->nombre,buffer->apellido,buffer->precio,buffer->codigoVuelo,passengerType,flightStatus);
		}
		outcome = SUCCESS;
		printf("\n  Guardado exitosamente.");
	}
	else
	{
		printf("   No se pudo acceder al archivo.\n");
	}
	fclose(f);
	view_pause();
    return outcome;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int outcome = FAILURE;
	FILE* f = fopen(path, "wb");
	Passenger* buffer = NULL;

	if(f!=NULL)
	{
		int len = ll_len(pArrayListPassenger);
		for(int i=0; i<len; i++)
		{
			buffer = (Passenger*) ll_get(pArrayListPassenger, i);
			fwrite(buffer, sizeof(Passenger), 1, f);
		}
		outcome = SUCCESS;
		printf("\n  Guardado exitosamente.");
	}
	else
	{
		printf("   No se pudo acceder al archivo.\n");
	}
	fclose(f);
	view_pause();
    return outcome;
}


int controller_loadNextID(char* path, int* pNextId)
{
	int outcome = FAILURE;
	FILE* f = fopen(path, "rb");
	if(f!=NULL)
	{
		fread(pNextId, sizeof(int), 1, f);
		outcome = SUCCESS;
	}
	fclose(f);
    return outcome;
}


int controller_saveNextID(char* path, int* pNextId)
{
	int outcome = FAILURE;
	FILE* f = fopen(path, "wb");
	if(f!=NULL)
	{
		fwrite(pNextId, sizeof(int), 1, f);
		outcome = SUCCESS;
	}
	fclose(f);
    return outcome;
}


int controller_exit(LinkedList* pArrayListPassenger, int* selection, int* saveCsvFlag, int* saveBinFlag){
	char confirmation;
	int outcome = FAILURE;
	system("cls");
	if(!*saveCsvFlag || !*saveBinFlag){
		printf("\n\n                            IMPORTANTE: TODA INFORMACIÓN NO GUARDADA SE PERDERÁ AL CERRAR.\n");
		printf("\n                                    Está intentado salir y hay cambios sin guardar.\n");
	}
	if(*saveCsvFlag == 0){
		IO_getConfirm(&confirmation, "\n  ¿Desea guardar los cambios en el archivo csv antes de salir? S/N: ", "  Opción inválida.", 3);
		if(confirmation == 'S'){
			controller_saveAsText("data.csv", pArrayListPassenger);
			*saveCsvFlag = 1;
		}
	}
	if(*saveBinFlag == 0){
		IO_getConfirm(&confirmation, "\n  ¿Desea guardar los cambios en el archivo binario antes de salir? S/N: ", "  Opción inválida.", 3);
		if(confirmation == 'S'){
			controller_saveAsBinary("data.bin", pArrayListPassenger);
			*saveBinFlag = 1;
		}
	}

	IO_getConfirm(&confirmation, "\n  ¿Confirma que desea salir? S/N: ", "  Opción inválida.", 1);
	if(confirmation == 'S'){
		*selection = 10;
		ll_deleteLinkedList(pArrayListPassenger);
		printf("\n  Ejecución concluida.");
		outcome = SUCCESS;
	}
	return outcome;
}
