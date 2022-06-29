<<<<<<< HEAD
<<<<<<< HEAD
/*
 * user_entry.h
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#ifndef SRC_USER_ENTRY_H_
#define SRC_USER_ENTRY_H_

#include "Passenger.h"

#endif /* SRC_USER_ENTRY_H_ */

void userEntry_requestName(int* stage, char* name, int* flags);
void userEntry_requestLastname(int* stage, char* lastName, int* flags);
void userEntry_requestPrice(int* stage, float* price, int* flags);
void userEntry_requestPType(int* stage, int* pTypeId, char* description, int* flags);
void userEntry_requestFlycode(int* stage, char* flycode, int* flags);

void userEntry_editName(Passenger* passenger, int* editFlag);
void userEntry_editLastame(Passenger* passenger, int* editFlag);
void userEntry_editPrice(Passenger* passenger, int* editFlag);
void userEntry_editPType(Passenger* passenger, int* editFlag);
void userEntry_editFlycode(Passenger* passenger, int* editFlag);

int userEntry_requestPassengerId(LinkedList* pArrayListPassenger, int* index, int maxId);
=======
/*
 * user_entry.h
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#ifndef SRC_USER_ENTRY_H_
#define SRC_USER_ENTRY_H_

#include "Passenger.h"

#endif /* SRC_USER_ENTRY_H_ */

void userEntry_requestName(int* stage, char* name, int* flags);
void userEntry_requestLastname(int* stage, char* lastName, int* flags);
void userEntry_requestPrice(int* stage, float* price, int* flags);
void userEntry_requestPType(int* stage, int* pTypeId, char* description, int* flags);
void userEntry_requestFlycode(int* stage, char* flycode, int* flags);

void userEntry_editName(Passenger* passenger, int* editFlag);
void userEntry_editLastame(Passenger* passenger, int* editFlag);
void userEntry_editPrice(Passenger* passenger, int* editFlag);
void userEntry_editPType(Passenger* passenger, int* editFlag);
void userEntry_editFlycode(Passenger* passenger, int* editFlag);

int userEntry_requestPassengerId(LinkedList* pArrayListPassenger, int* index, int maxId);
>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
=======
/*
 * user_entry.h
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#ifndef SRC_USER_ENTRY_H_
#define SRC_USER_ENTRY_H_

#include "Passenger.h"

#endif /* SRC_USER_ENTRY_H_ */

void userEntry_requestName(int* stage, char* name, int* flags);
void userEntry_requestLastname(int* stage, char* lastName, int* flags);
void userEntry_requestPrice(int* stage, float* price, int* flags);
void userEntry_requestPType(int* stage, int* pTypeId, char* description, int* flags);
void userEntry_requestFlycode(int* stage, char* flycode, int* flags);

void userEntry_editName(Passenger* passenger, int* editFlag);
void userEntry_editLastame(Passenger* passenger, int* editFlag);
void userEntry_editPrice(Passenger* passenger, int* editFlag);
void userEntry_editPType(Passenger* passenger, int* editFlag);
void userEntry_editFlycode(Passenger* passenger, int* editFlag);

int userEntry_requestPassengerId(LinkedList* pArrayListPassenger, int* index, int maxId);
>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
