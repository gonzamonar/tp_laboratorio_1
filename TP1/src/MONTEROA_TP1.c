/*
 ============================================================================
 Name        : MONTEROA_TP1.c
 Author      : Gonzalo F. Montero Arguibay
 Description : Proyecto TP1 - UTN-FRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include <conio.h>
#include "bibliotecaTP1.h"

#define MSJ_ERROR "Error, ingrese un número válido.\n"
#define MSJ_INTENTOS "Se superó el límite de intentos, inténtelo nuevamente.\n"
#define MSJ_CONFIRM "Los datos ya fueron ingresados, ¿desea corregirlos? (S/N): "
#define MSJ_ERROR_CONFIRM "Error, ingrese una respuesta válida.\n"



int main(){
	float costosVuelo[9];
	float costosVuelof[9];
	int x;
	int x_last;
	float y;
	float y_last;
	float z;
	float z_last;
	int flag[4] = {1,1,1,0}; //Flag 0: 1º Ingreso KM; Flag 1: 1º Ingreso Costos de vuelos; Flag 2: 1º Cálculo de costos; Flag 3: Edit en datos 1 y 2.
	int selection;

	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");

	do{
		switch (printMenuTP1(flag, x, y, z)){

			case 1:
					if(flag[0]){
							if(getInteger(&x, "Ingrese el kilometraje: ", MSJ_ERROR, 1, 30000, 2)){
								flag[0] = 0;
								x_last = x;
							}else{
								printf(MSJ_INTENTOS);
								stopAndGo();
							}
					}else{
							char rta;
							if(getConfirm(&rta, MSJ_CONFIRM, MSJ_ERROR_CONFIRM, 2) && rta == 'S'){
								x_last = x;
								if(getInteger(&x, "Ingrese el kilometraje: ", MSJ_ERROR, 1, 30000, 2)){
									flag[3] = 1;
								}else{
									printf(MSJ_INTENTOS);
									stopAndGo();
								}
							}
					}
					break;

			case 2:
					if(flag[1]){
							if(getFloatingPoint(&y, "Ingrese el precio de Aerolíneas: ", MSJ_ERROR, 1, 10000000, 2)
								&& getFloatingPoint(&z, "Ingrese el precio de LATAM: ", MSJ_ERROR, 1, 10000000, 2)){
								flag[1] = 0;
								y_last = y;
								z_last = z;
							}else{
								printf(MSJ_INTENTOS);
								stopAndGo();
							}
					}else{
							char rta;
							if(getConfirm(&rta, MSJ_CONFIRM, MSJ_ERROR_CONFIRM, 2) && rta == 'S'){
								y_last = y;
								z_last = z;
								int reintentos = 3;
								do{
									switch(printSubmenu2TP1()){
										case 1:
												if(getFloatingPoint(&y, "Ingrese el precio de Aerolíneas: ", MSJ_ERROR, 1, 10000000, 2)){
													flag[3] = 1;
												}else{
													printf(MSJ_INTENTOS);
													stopAndGo();
												}
												reintentos = 0;
												break;
										case 2:
												if(getFloatingPoint(&z, "Ingrese el precio de LATAM: ", MSJ_ERROR, 1, 10000000, 2)){
													flag[3] = 1;
												}else{
													printf(MSJ_INTENTOS);
													stopAndGo();
												}
												reintentos = 0;
												break;
										case 3:
												if(getFloatingPoint(&y, "Ingrese el precio de Aerolíneas: ", MSJ_ERROR, 1, 10000000, 2)
													&& getFloatingPoint(&z, "Ingrese el precio de LATAM: ", MSJ_ERROR, 1, 10000000, 2)){
													flag[3] = 1;
												}else{
													printf(MSJ_INTENTOS);
													stopAndGo();
												}
												reintentos = 0;
												break;
										default:
												reintentos--;
												break;
										}
								}while(reintentos > 0);
							}
					}
					break;

			case 3:
					if(flag[0] || flag[1]){
							if(flag[0] && flag[1]){
								printf("Error. Para calcular costos debe ingresar primero datos de kilometraje (1) y de precio de vuelos (2).\n");
							}else{
								if(flag[0]){
									printf("\nError. Para calcular costos debe ingresar primero datos de kilometraje (1).\n");
								}else{
									printf("\nError. Para calcular costos debe ingresar primero datos de precio de vuelos (2).\n");
								}
							}
					}else{
							if(flag[2] || flag[3]){
								calculoCostosTP1(x, y, z, costosVuelo);
								flag[2] = 0;
								flag[3] = 0;
								printf("Costos calculados exitosamente.\n");
							}else{
								printf("Los costos ya fueron calculados previamente.\n");
							}
					}
					stopAndGo();
					break;

			case 4:
					if(flag[3] && !flag[2]){
							int reintentos = 3;
							do{
								switch(printSubmenu4TP1()){
									case 1:
											printf("\n----------------------------------------------\n");
											printTP1(x_last, y_last, z_last, costosVuelo);
											stopAndGo();
											reintentos = 0;
											break;
									case 2:
											printf("\n----------------------------------------------\n");
											calculoCostosTP1(x, y, z, costosVuelo);
											flag[3] = 0;
											printTP1(x, y, z, costosVuelo);
											stopAndGo();
											reintentos = 0;
											break;
									case 3:
											reintentos = 0;
											break;
									default:
											reintentos--;
											break;
									}
							}while(reintentos > 0);
					}else{
							if(flag[2]){
								printf("Para informar los resultados, debe calcular los costos (3) previamente.\n");
							}else{
								printTP1(x, y, z, costosVuelo);
							}
							stopAndGo();
					}
					break;

			case 5:
					calculoCostosTP1(7090, 162965, 159339, costosVuelof);
					printTP1(7090, 162965, 159339, costosVuelof);
					stopAndGo();
					break;

			case 6:
					selection = 6;
					printf("\nPrograma concluido.");
					stopAndGo();
					break;

			default:
					stopAndGo();
					break;
		}
	}while(selection != 6);
}

