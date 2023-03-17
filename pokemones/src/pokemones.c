/*
 ============================================================================
 Name        : pokemones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "poke.h"
#include "archivo.h"
#include "menuInicio.h"





int main(void) {
	setbuf(stdout,NULL);
	int numeroMenuInicio;
	char nombreArchivo[50];
	LinkedList * listaPokemones = ll_newLinkedList();
	LinkedList * listaAuxiliar= ll_newLinkedList();
	LinkedList * listaAuxiliar2= ll_newLinkedList();

	int cantidadPokeBF;




	do {

				numeroMenuInicio = muestraMenuInicio();

				switch (numeroMenuInicio) {
					case 1:
						//printf("Ingrese nombre de archivo\n");
						//fflush(stdin);
					//	gets(nombreArchivo);
						if(leerArchivo("Data_Pokemones.csv",listaPokemones))
						{
							printf("Se abrio el archivo\n");
						}
						else
						{
							printf("No abrio el archivo\n");
						}
						break;
					case 2:
						imprimePokemones(listaPokemones);
						break;
					case 3:
						listaAuxiliar = ll_filter(listaPokemones,retornaListaFuego);
						imprimePokemones(listaAuxiliar);
						break;
					case 4:

						ll_count(listaPokemones, retornaPokeBatallaFinal);
						imprimePokemones(listaAuxiliar2);
							printf("cantidad de poke bf %d\n",cantidadPokeBF);
							if(cantidadPokeBF > 3)
							{
								printf("Ganamos la batalla\n");

							}
							else
							{
								printf("No se llego a completar los pokemones\n");
							}
						break;

			}




		} while (numeroMenuInicio != 5);





	return EXIT_SUCCESS;
}
