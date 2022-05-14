/*
 * ArrayPassenger.c
 *
 *  Created on: May 7, 2022
 *      Author: GM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "ArrayPassenger_ui.h"
#include "gtype.h"
#include "gral_io.h"
#include "gral_ui.h"


//passenger type definitions
#define PRIMERA 1
#define BUSINESS 2
#define PREMIUM 3
#define ECONOMY 4
//flight status definitions
#define ACTIVE 1
#define BOARDING 2
#define DEPARTED 3
#define DELAYED 4
#define CANCELLED 5


int initPassengers(Passenger* array, int size){
	int outcome = 0;
	if(array != NULL && size > 0){
		outcome = 1;
		for(int i=0; i<size; i++){
			array[i].isEmpty = 1;
		}
	}
	return outcome;
}


int harcodePassengers(Passenger* array, int size, int quantity, int freeSpace, int* pHarcodeAvail, int* qPassengers, int* pNextId){
	int outcome = 0;
	int index;
	char msgPassengers[12];
	char msgSpace[12];
	Passenger flightlist[20] =
			{{0, "Julio", "César", 4900.00, "TK077", ECONOMY, ACTIVE, 0},
			 {0, "Audrey", "Hepburn", 3300.00, "AF084", PRIMERA, ACTIVE, 0},
			 {0, "Napoleon", "Bonaparte", 9700.75, "AF084", ECONOMY, ACTIVE, 0},
			 {0, "Marilyn", "Monroe", 6540.00, "LA530", PREMIUM, ACTIVE, 0},
			 {0, "Gioachino", "Rossini", 7700.00, "AA2350", ECONOMY, ACTIVE, 0},
			 {0, "Samantha", "Schweblin", 3540.10, "LX139", PRIMERA, DELAYED, 0},
			 {0, "Frida", "Kahlo", 670.80, "AR1696", PREMIUM, ACTIVE, 0},
			 {0, "Lionel", "Messi", 1010.10, "LA530", PRIMERA, ACTIVE, 0},
			 {0, "Ana", "Mendieta", 2500.25, "AF084", BUSINESS, ACTIVE, 0},
			 {0, "Fernando", "Alonso", 9800.50, "AR1696", PREMIUM, ACTIVE, 0},
			 {0, "Julia", "Ducournau", 500.50, "AR1696", PRIMERA, ACTIVE, 0},
			 {0, "Antonio", "Vivaldi", 7890.90, "TK077", BUSINESS, ACTIVE, 0},
			 {0, "Rodrigo", "De La Serna", 2806.00, "TK077", BUSINESS, ACTIVE, 0},
			 {0, "Juana", "Azurduy", 3500.75, "LA530", BUSINESS, ACTIVE, 0},
			 {0, "Sergio", "Agüero", 4560.00, "LX139", PREMIUM, DELAYED, 0},
			 {0, "Natalia", "Lafourcade", 1000.00, "AA2350", PREMIUM, ACTIVE, 0},
			 {0, "José", "De San Martín", 3000.00, "AR1696", PRIMERA, ACTIVE, 0},
			 {0, "Piet", "Mondrian", 5000.00, "LX139", BUSINESS, DELAYED, 0},
			 {0, "Mirtha", "Legrand", 1750.50, "AF084", ECONOMY, ACTIVE, 0},
			 {0, "Diego", "Rivera", 2000.00, "AA2350", ECONOMY, ACTIVE, 0}};

	if(array != NULL && pNextId != NULL && freeSpace > 0 && quantity <= freeSpace){
		outcome = 1;
		for(int i = (20-*pHarcodeAvail); quantity>0; i++, quantity--){
			getFreeSpace(array, size, &index);
			array[index] = flightlist[i];
			array[index].id = *pNextId;
			*pHarcodeAvail -= 1;
			*pNextId += 1;
			*qPassengers += 1;
		}
	}else{
		(quantity!=1) ? strcpy(msgPassengers, "pasajeros") : strcpy(msgPassengers, "pasajero");
		(freeSpace!=1) ? strcpy(msgSpace, "espacios") : strcpy(msgSpace, "espacio");
			printf("\n                            ** Espacio insuficiente en el sistema. **");
			printf("\n  Usted está solicitando el alta de %d %s y el sistema dispone de %d %s de carga libres.\n", quantity, msgPassengers, freeSpace, msgSpace);
	}
	return outcome;
}


int printPassengers(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int filter){
	int outcome = 0;
	char fstatus_description[12];
	char ptype_description[12];
	char shortenName[21];
	if(array != NULL && size>0 && flights != NULL && flights_size>0 && ptypes != NULL && ptypes_size>0 && fstatus != NULL && fstatus_size>0){
		outcome = 1;
		system("cls");
		printf("\n\n");
		printf(" +------------------------------------------------------------------------------------------------------+\n");
		printf(" |-----------------------------------  *** LISTADO DE PASAJEROS ***  -----------------------------------|\n");
		printf(" |------------------------------------------------------------------------------------------------------|\n");
		printf(" |%5s | %18s | %20s | %12s |%10s|%12s|%12s| \n", "", "", "", "", "Código  ", "Clase de  ", "Estado   ");
		printf(" |%5s | %18s | %20s | %12s |%10s|%12s|%12s| \n", "ID ", "Nombre       ", "Apellido      ", "Precio   ", "de Vuelo ", " Pasaje   ", "de Vuelo  ");
		printf(" +------------------------------------------------------------------------------------------------------+\n");
		for(int i=0;i<size;i++){
			if(!array[i].isEmpty && ((filter==0) || (filter==1 && array[i].statusFlight==1))){
				loadPTypeDescription(ptypes, ptypes_size, ptype_description, array[i].typePassenger);
				loadFStatusDescription(fstatus, fstatus_size, fstatus_description, array[i].statusFlight);
				printf(" |%5d | ", array[i].id);
				if(strlen(array[i].name)<=18){
					printf("%-18s", array[i].name);
				}else{
					shortenstr(shortenName, 21, array[i].name, 18);
					printf("%-18s", shortenName);
				}
				if(strlen(array[i].lastname)<=20){
					printf(" | %-20s | ", array[i].lastname);
				}else{
					shortenstr(shortenName, 21, array[i].lastname, 20);
					printf(" | %-20s | ", shortenName);
				}
				printf("%10.2f   |%8s  |%12s|%12s| \n", array[i].price, array[i].flycode, ptype_description, fstatus_description);
			}
		}
		printf(" +------------------------------------------------------------------------------------------------------+\n");
	}
	return outcome;
}


void creationInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int* pNextId, int* qPassengers){
	int stage = 1;
	int flags[5] = {0,0,0,0,0}; //Flag: name,lastName,price,typePassenger,flycode
	char name[51]; 				//Stage 1
	char lastName[51]; 			//Stage 2
	float price; 				//Stage 3
	int typePassengerId;		//Stage 4
	char ptypeDescription[12]; 	//
	char flycode[12];			//Stage 5
	int flightIndex;			//
	int statusFlightId; 		//
	char confirm;				//Stage 6

	do{
		fflush(stdin);
		printCreationMenu(flags, *pNextId, name, lastName, price, ptypeDescription, flycode);
		switch (stage){
			case 1:	//get name
					if(getProperName(name, 51, 50, 2, "\n  Ingrese nombre: ", "\n  Nombre no válido. ", 3, " ")){
						flags[0] = 1;
						stage++;
					}else{
						printf("\n  Intentos de carga de nombre agotados. El proceso de alta ha sido cancelado.");
						stage = 7;
					}
					break;

			case 2:	//get surname
					if(getProperName(lastName, 51, 50, 2, "\n  Ingrese apellido: ", "\n  Apellido no válido. ", 3, " -")){
						flags[1] = 1;
						stage++;
					}else{
						printf("\n  Intentos de carga de apellido agotados. El proceso de alta ha sido cancelado.");
						stage = 7;
					}
					break;

			case 3:	//get price
					if(getFloatingPoint(&price, "\n  Ingrese el precio del vuelo: ", "  Error, ingrese un precio válido ($1 a $3000000.00). ", 1, 3000000, 3)){
						flags[2] = 1;
						stage++;
					}else{
						printf("\n  Intentos de carga de precio agotados. El proceso de alta ha sido cancelado.");
						stage = 7;
					}
					break;

			case 4:	//get typePassenger
					if(selectPType(ptypes, ptypes_size, &typePassengerId)){
						loadPTypeDescription(ptypes, ptypes_size, ptypeDescription, typePassengerId);
						flags[3] = 1;
						stage++;
					}else{
						printf("\n  Intentos de carga de clase de pasajero agotados. El proceso de alta ha sido cancelado.");
						stage = 7;
					}
					break;

			case 5:	//get flycode & statusFlight
					if(selectFlight(flights, flights_size, &flightIndex)){
						strcpy(flycode, flights[flightIndex].flycode);
						statusFlightId = flights[flightIndex].statusFlight;
						flags[4] = 1;
						stage++;
					}else{
						printf("\n  Intentos de selección de vuelo agotados. El proceso de alta ha sido cancelado.");
						stage = 7;
					}
					break;

			case 6:	//get confirm & add passenger or cancel
					getConfirm(&confirm, "\n  ¿Desea confirmar el alta en el sistema? (S/N): ", "  Error, ingrese una respuesta válida. ", 3);
					if(confirm == 'S'){
						addPassengers(array, size, *pNextId, name, lastName, price, typePassengerId, flycode, statusFlightId);
						*pNextId += 1;
						*qPassengers += 1;
						printf("\n  Pasajero cargado correctamente.");
					}else{
						printf("\n  El alta ha sido cancelada.");
					}
					stage++;
					break;
		}
	}while(stage != 7);
}


int addPassengers(Passenger* array, int size, int id, char* name, char* lastName, float price, int typePassenger, char* flycode, int statusFlight){
    int outcome = -1;
    int index;
    Passenger buffer;
    if(array != NULL && size>0){
    	if(getFreeSpace(array, size, &index)){
    		outcome = 0;
    		buffer.id = id;
    		strcpy(buffer.name, name);
			strcpy(buffer.lastname, lastName);
			buffer.price = price;
			buffer.typePassenger = typePassenger;
			strcpy(buffer.flycode, flycode);
			buffer.statusFlight = statusFlight;
			buffer.isEmpty = 0;

			array[index] = buffer;
    	}else{
			printf("\n  Espacio insuficiente en el sistema para realizar una nueva alta.");
    	}
    }
    return outcome;
}


int getFreeSpace(Passenger* array, int size, int* pIndex){
	int outcome = 0;
	if(array != NULL && size > 0 && pIndex != NULL){
		for(int i=0;i<size;i++){
			if(array[i].isEmpty){
				outcome = 1;
				*pIndex = i;
				break;
			}
		}
	}
	return outcome;
}


void updateInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int* pNextId){
	int id;
	int index;
	int option;
	int lastId = *pNextId-1;

	char name[51];			//edit 1
	char lastName[51];		//edit 2
	float price;			//edit 3
	int typePassengerId;	//edit 4
	char flycode[10];		//edit 5
	int flightIndex;		//edit 5
	char confirm;
	char confirmMsg[192];
	char errorMsg[64];
	char requestMsg[] = {"\n  Ingrese el ID del pasajero que desea modificar: "};

	sprintf(errorMsg, "  Error, ingrese un id válido (1000 a %4d). ", lastId);

	system("cls");
	printPassengers(array, size, flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size, 0);  //print passengers
	if(requestPassengerId(&id, &index, array, size, lastId, requestMsg, errorMsg, 3)){							  //request ID
		do{
			int editFlag = 0;
			fflush(stdin);
			printPassengerFile(array[index], flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size);	//print passenger file
			printUpdateMenu(&option);									//print update menu
			switch(option){
				case 1:	//edit name
						if(getProperName(name, 51, 50, 2, "\n  Ingrese nombre: ", "\n  Nombre no válido. Reingrese nombre: ", 3, " ")){
							sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de nombre de %s a %s? (S/N): ", array[index].name, name);
							getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
							if(confirm=='S'){
								strcpy(array[index].name, name);
								editFlag = 1;
							}else{
								printf("\n  Modificación cancelada.");
							}
						}else{
							printf("\n  Intentos de carga de nombre agotados. Modificación cancelada.");
						}
						break;

				case 2:	//edit surname
						if(getProperName(lastName, 51, 50, 2, "\n  Ingrese apellido: ", "\n  Apellido no válido. Reingrese apellido: ", 3, " -")){
							sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de apellido de %s a %s? (S/N): ", array[index].lastname, lastName);
							getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
							if(confirm=='S'){
								strcpy(array[index].lastname, lastName);
								editFlag = 1;
							}else{
								printf("\n  Modificación cancelada.");
							}
						}else{
							printf("\n  Intentos de carga de apellido agotados. Modificación cancelada.");
						}
						break;

				case 3:	//edit price
						if(getFloatingPoint(&price, "\n  Ingrese el precio del vuelo: ", "  Error, ingrese un precio válido ($1 a $3000000.00). ", 1, 3000000, 3)){
							sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de precio de %.2f a %.2f? (S/N): ", array[index].price, price);
							getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
							if(confirm=='S'){
								array[index].price = price;
								editFlag = 1;
							}else{
								printf("\n  Modificación cancelada.");
							}
						}else{
							printf("\n  Intentos de carga de precio agotados. Modificación cancelada.");
						}
						break;

				case 4:	//edit typePassenger
						if(selectPType(ptypes, ptypes_size, &typePassengerId)){
							char newPType[12], oldPType[12];
							loadPTypeDescription(ptypes, ptypes_size, newPType, typePassengerId);
							loadPTypeDescription(ptypes, ptypes_size, oldPType, array[index].typePassenger);
							sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de pasaje de %s a %s? (S/N): ", oldPType, newPType);
							getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
							if(confirm=='S'){
								array[index].typePassenger = typePassengerId;
								editFlag = 1;
							}else{
								printf("\n  Modificación cancelada.");
							}
						}else{
							printf("\n  Intentos de carga de clase de pasajero agotados.  Modificación cancelada.");
						}
						break;

				case 5:	//edit flycode
						if(selectFlight(flights, flights_size, &flightIndex)){
							strcpy(flycode, flights[flightIndex].flycode);
							sprintf(confirmMsg, "\n  ¿Desea confirmar el cambio de vuelo de %s a %s? (S/N): ", array[index].flycode, flycode);
							getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
							if(confirm=='S'){
								strcpy(array[index].flycode, flycode);
								array[index].statusFlight = flights[flightIndex].statusFlight;
								editFlag = 1;
							}else{
								printf("\n  Modificación cancelada.");
							}
						}else{
							printf("\n  Intentos de selección de vuelo agotados. Modificación cancelada.");
						}
						break;
			}
			//new edit or exit
			if(editFlag){
				system("cls");
				printPassengerFile(array[index], flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size);
				printf("\n  Modificación realizada exitosamente.");
				if(!getConfirm(&confirm, "  ¿Desea realizar otra modificación? (S/N): ", "\n  Error, ingrese una respuesta válida. ", 3) || confirm == 'N'){
					option = 6;
				}
			}else{
				option = 6;
			}
		}while(option != 6);
	}else{
		printf("\n\n  Intentos de carga de id agotados. El proceso de modificación ha sido cancelado.");
	}
}


int requestPassengerId(int* id, int* index, Passenger* array, int size, int lastId, char* requestMsg, char* errorMsg, int attemps){
	int outcome = 0;

	do{
		if(getInteger(id, requestMsg, "", 1000, lastId, 1)){
			*index = findPassengerById(array, size, *id);
			if(*index > -1){
				outcome = 1;
				break;
			}else{
				printf("  El id que ud ingresó no corresponde a un pasajero activo.");
			}
		}else{
			printf("%s", errorMsg);
		}
		attemps--;
		if(attemps>0){
			printf(" (Intentos restantes: %d)\n", attemps);
		}
	}while(attemps>0);
	return outcome;
}


int findPassengerById(Passenger* array, int size, int id){
	int index = -1;
	if(array != NULL && size > 0){
		for(int i=0; i<size; i++){
			if(array[i].id == id && !array[i].isEmpty){
				index = i;
				break;
			}
		}
	}
	return index;
}


void deleteInterface(Passenger* array, int size, sFlight* flights, int flights_size, sPType* ptypes, int ptypes_size, sFStatus* fstatus, int fstatus_size, int* pNextId, int* qPassengers){
	int id;
	int index;
	int lastId = *pNextId-1;

	char errorMsg[64];
	char requestMsg[] = {"\n  Ingrese el ID del pasajero que desea modificar: "};

	sprintf(errorMsg, "  Error, ingrese un id válido (1000 a %4d). ", lastId);

	system("cls");
	printPassengers(array, size, flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size, 0);	//print passengers
	if(requestPassengerId(&id, &index, array, size, lastId, requestMsg, errorMsg, 3)){					//request ID
		printPassengerFile(array[index], flights, flights_size, ptypes, ptypes_size, fstatus, fstatus_size);	//print passenger file
		if(removePassenger(array, size, id)){  //confirm && remove the passenger
			*qPassengers -= 1;
		}

	}else{
		printf("\n\n  Intentos de carga de id agotados. El proceso de baja ha sido cancelado.");
	}
}


int removePassenger(Passenger* array, int size, int id){
	char confirmMsg[64];
	char confirm;
	int outcome = -1;

	if(array != NULL && size > 0){
		sprintf(confirmMsg, "\n  ¿Desea confirmar la baja del pasajero Nº %d? (S/N): ", id);
		printf("\n                            IMPORTANTE: ESTA ACCIÓN NO SE PUEDE DESHACER.\n");
		getConfirm(&confirm, confirmMsg, "  Respuesta inválida. ", 3);
		if(confirm=='S'){
			for(int i=0;i<size;i++){
				if(array[i].id == id){
					array[i].isEmpty = 1;
					outcome = 0;
				}
			}
		}else{
			printf("\n  Baja cancelada.");
		}
	}
	return outcome;
}


int sortPassengersByCode(Passenger* array, int size, int order){
    int outcome = 0;
    Passenger buffer;

    if(array != NULL && size > 0){
        for(int i=0; i < size-1; i++){
            for(int j= i+1; j < size; j++){
                if((order == 1 && strcmp(array[i].flycode, array[j].flycode) > 0)  //1==UP
                   || (order == 0 && strcmp(array[i].flycode, array[j].flycode) < 0)){  //0==DOWN
                	buffer = array[i];
                	array[i] = array[j];
                	array[j] = buffer;
                }
            }
        }
        outcome = 1;
    }
    return outcome;
}


int sortPassengersTypeAndLastname(Passenger* array, int size, int order){
    int outcome = 0;
    Passenger buffer;

    if(array != NULL && size > 0){
        for(int i=0; i < size-1; i++){
            for(int j= i+1; j < size; j++){
                if((order == 1 &&((array[i].typePassenger == array[j].typePassenger && strcmp(array[i].lastname,array[j].lastname) > 0) //1==UP
                        || (array[i].typePassenger != array[j].typePassenger && (array[i].typePassenger > array[j].typePassenger))))
					|| (order == 0 && ((array[i].typePassenger == array[j].typePassenger && strcmp(array[i].lastname,array[j].lastname) < 0) //0==DOWN
                        || (array[i].typePassenger != array[j].typePassenger && (array[i].typePassenger < array[j].typePassenger))))){
                	buffer = array[i];
                	array[i] = array[j];
                	array[j] = buffer;
                }
            }
        }
        outcome = 1;
    }
    return outcome;
}


int sortPassengersLastnameAndType(Passenger* array, int size, int order){
    int outcome = 0;
    Passenger buffer;

    if(array != NULL && size > 0){
        for(int i=0; i < size-1; i++){
            for(int j= i+1; j < size; j++){
                if((order == 1 && ((strcmp(array[i].lastname,array[j].lastname)==0 && array[i].typePassenger > array[j].typePassenger) //1==UP
                        || (strcmp(array[i].lastname,array[j].lastname)!=0 && strcmp(array[i].lastname,array[j].lastname)>0)))
					|| (order == 0 &&((strcmp(array[i].lastname,array[j].lastname)==0 && array[i].typePassenger < array[j].typePassenger) //0==DOWN
                        ||(strcmp(array[i].lastname,array[j].lastname)!=0 && strcmp(array[i].lastname,array[j].lastname)<0)))){
                	buffer = array[i];
                	array[i] = array[j];
                	array[j] = buffer;
                }
            }
        }
        outcome = 1;
    }
    return outcome;
}



