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
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int filtrar_pares(void* pElement);
int criterio_menor(void* pElement1, void* pElement2);
void printLinkedList(LinkedList* Lista);
void pause(void);


int main(void)
{
	setlocale(LC_ALL, "");
	int* element;
	int len;


	printf("ll_newLinkedlist: Se crea una nueva lista de números.\n\n");
	LinkedList* ListaNumeros = ll_newLinkedList();


	printf("ll_add: Se agregan los números del 1 al 10.\n\n");
	for(int i=1;i<11;i++){
		int* number = (int*) malloc(sizeof(int));
		*number = i;
		ll_add(ListaNumeros, number);
	}


	len = ll_len(ListaNumeros);
	printf("ll_len: El tamaño de la lista es %d.\n\n", len);


	printf("ll_get: Se imprime la lista empleando el método Get.\n");
	printf("Lista de Números: ");
	for(int i=0;i<len;i++){
		element = (int*) ll_get(ListaNumeros, i);
		printf("%d ", *element);
	}


	int* numberAux = (int*) malloc(sizeof(int));
	*numberAux = 20;
	printf("\n\nll_set: Se reemplaza el elemento en índice 4 (nº 5) por otro nuevo, de valor 20.\n\n");
	ll_set(ListaNumeros, 4, numberAux);


	printf("ll_remove: Se remueve el elemento en índice 7 (nº 8).\n\n");
	ll_remove(ListaNumeros, 7);
	printf("Reimpresión de la lista con los cambios.\n");
	printf("Lista de Números: ");
	printLinkedList(ListaNumeros);


	int index = ll_indexOf(ListaNumeros, numberAux);
	printf("\n\nll_indexOf: El índice del elemento 20 es: %d.\n\n", index);


	printf("ll_clone: Se realiza una copia de la lista.\n\n");
	LinkedList* ListaCopiada = ll_clone(ListaNumeros);


	printf("ll_pop: Se elimina el elemento en índice 3 de la lista original.\n");
	printf("ll_push: y se lo inserta en el índice 6 de la lista copiada mediante el método push.\n");
	int* popNumber = ll_pop(ListaNumeros, 3);
	ll_push(ListaCopiada, 6, popNumber);
	printf("Impresión de ambas listas con los cambios:\n");
	printf("Lista de Números: ");
	printLinkedList(ListaNumeros);
	printf("\nCopia de lista de Números: ");
	printLinkedList(ListaCopiada);


	printf("\n\nll_contains: ¿La lista original contiene el elemento en índice 3? (nº4)\n");
	ll_contains(ListaNumeros, ll_get(ListaCopiada, 3)) ? printf("\nSí lo contiene.") : printf("\nNo lo contiene.") ;


	printf("\n\nll_containsAll: ¿La lista copiada contiene todos los elementos de la lista original?\n");
	ll_containsAll(ListaCopiada, ListaNumeros) ? printf("\nSí los contiene.") : printf("\nNo los contiene.") ;


	printf("\n\nll_sublist: Se recorta la lista original desde el índice 4 al 7 (nros 20 6 7 9)\n\n");
	LinkedList* ListaRecortada = ll_subList(ListaNumeros, 4, 7);


	printf("ll_filter: Se filtran los nros pares de la lista original.");
	LinkedList* ListaFiltrada = ll_filter(ListaNumeros, filtrar_pares);

	printf("\nLista Original: ");
	printLinkedList(ListaNumeros);
	printf("\nLista Copiada: ");
	printLinkedList(ListaCopiada);
	printf("\nLista Recortada: ");
	printLinkedList(ListaRecortada);
	printf("\nLista filtrada: ");
	printLinkedList(ListaFiltrada);


	printf("\n\nll_sort & ll_clear: Se ordena de mayor a menor la lista original, de menor a mayor la copiada y se limpia la lista recortada.\n\n");
	ll_sort(ListaNumeros, criterio_menor, 1);
	ll_sort(ListaCopiada, criterio_menor, 0);
	ll_clear(ListaRecortada);

	printf("\n**Reimpresión de Listas**\n");
	printf("\nLista Original: ");
	printLinkedList(ListaNumeros);
	printf("\nLista Copiada: ");
	printLinkedList(ListaCopiada);
	printf("\nLista Recortada: ");
	printLinkedList(ListaRecortada);
	printf("\nLista filtrada: ");
	printLinkedList(ListaFiltrada);


	printf("\n\nll_isEmpty: \n");
	printf("La Lista Original");
	ll_isEmpty(ListaNumeros) ? printf(" está vacía.\n") : printf(" no está vacía.\n") ;
	printf("La Lista Copiada");
	ll_isEmpty(ListaCopiada) ? printf(" está vacía.\n") : printf(" no está vacía.\n") ;
	printf("La Lista Recortada");
	ll_isEmpty(ListaRecortada) ? printf(" está vacía.\n") : printf(" no está vacía.\n") ;
	printf("La Lista Filtrada");
	ll_isEmpty(ListaFiltrada) ? printf(" está vacía.\n") : printf(" no está vacía.\n") ;


	printf("\n\nll_deleteLinkedList: Se eliminan las listas creadas durante la demostración.\n\n");
	ll_deleteLinkedList(ListaNumeros);
	ll_deleteLinkedList(ListaFiltrada);
	ll_deleteLinkedList(ListaRecortada);
	ll_deleteLinkedList(ListaCopiada);

	pause();
	system("cls");

	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort

	pause();

    return 0;
}






///FUNCIONES AUXILIARES

int filtrar_pares(void* pElement){
	int* numero = (int*) pElement;
	if(*numero % 2 == 0){
		return 1;
	}else{
		return 0;
	}
}


int criterio_menor(void* pElement1, void* pElement2){
	int* numero1 = (int*) pElement1;
	int* numero2 = (int*) pElement2;
	int comparison = 0;
	if(*numero1 > *numero2)
	{
		comparison = 1;
	}
	else if(*numero1 < *numero2)
	{
		comparison = -1;
	}
	return comparison;
}



void printLinkedList(LinkedList* Lista){
	int len = ll_len(Lista);
	int* number;

	for(int i=0;i<len;i++){
		number = (int*) ll_get(Lista, i);
		printf("%d ", *number);
	}
}

void pause(void){
	char c;
	fflush(stdin);
	printf("\n\n  ***** Presione enter para continuar. *****");
	scanf("%c", &c);
	fflush(stdin);
}
