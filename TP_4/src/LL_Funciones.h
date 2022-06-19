/*
 * LL_Funciones.h
 *
 *  Created on: Jun 18, 2022
 *      Author: GM
 */

#ifndef LL_FUNCIONES_H_
#define LL_FUNCIONES_H_

#include "../inc/LinkedList.h"

#endif /* LL_FUNCIONES_H_ */


void llfunciones_menuPrincipal(LinkedList* pArrayListPassenger, LinkedList* pBackupList);
int llfunciones_recortarLinkedlist(LinkedList* pBackupList);
int llfunciones_popPassenger(LinkedList* pBackupList);
LinkedList* llfunciones_ListNotContainedPassengers(LinkedList* pArrayListPassenger, LinkedList* pBackupList);
int llfunciones_backupPassenger(LinkedList* pArrayListPassenger, LinkedList* uncontained);
