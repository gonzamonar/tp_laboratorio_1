/*
 * sorters.h
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#ifndef SRC_SORTERS_H_
#define SRC_SORTERS_H_

#include "Passenger.h"

#endif /* SRC_SORTERS_H_ */


int sorter_ID(void* A, void* B);
int sorter_name(void* A, void* B);
int sorter_lastname(void* A, void* B);
int sorter_price(void* A, void* B);
int sorter_passengerType(void* A, void* B);
int sorter_flycode(void* A, void* B);
int sorter_flightStatus(void* A, void* B);

int sorter_lastname_name(void* A, void* B);
int sorter_lastname_price(void* A, void* B);
int sorter_lastname_passengerType(void* A, void* B);
int sorter_flycode_lastname(void* A, void* B);
int sorter_flycode_passengerType(void* A, void* B);
int sorter_flycode_price(void* A, void* B);
int sorter_passengerType_lastname(void* A, void* B);
int sorter_passengerType_flycode(void* A, void* B);
