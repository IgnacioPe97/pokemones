/*
 * poke.h
 *
 *  Created on: 15 feb 2023
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"

#define LARGE 100
#ifndef POKE_H_
#define POKE_H_

typedef struct
{
	int numero;
	char nombre[LARGE];
	char tipo[LARGE];
	char tamanio[LARGE];
	char ataqueCargado[LARGE];
	int valorAtaque;
	int esVarioColor;
}ePokemon;



ePokemon* prod_newParametros(char* numero ,char* nombre,char* tipo, char* tamanio, char* ataqueCarga, char* valorAtaque,char *color);
ePokemon* producto_new();
int imprimePokemones(LinkedList *listaCargada);




//SETTERS
int prod_setNumeroTxt(ePokemon* this,char* numero);
int prod_setTipo(ePokemon* this,char* tipo);
int prod_setNombre(ePokemon* this,char* nombre);
int prod_setAtaqueCargado(ePokemon* this,char* ataqueCargado);
int prod_setTamanio(ePokemon* this,char* tamanio);
int prod_setValorAtaqueTxt(ePokemon* this,char* valorAtaque);
int prod_setColorTxt(ePokemon* this,char* color);
//GETTERS
int prod_getTipo(ePokemon* this,char* nombreTipo);
int prod_getNombre(ePokemon* this,char* nombre);
int prod_getNumero(ePokemon *this, int *numero);
int prod_getAtaquCargado(ePokemon* this,char* ataqueCargado);
int prod_getTamanio(ePokemon* this,char* tamanio);
int prod_getValorAtaque(ePokemon *this, int *valorAtaque);
int prod_getColor(ePokemon *this, int *color);


int retornaListaFuego(void * unPokemon);
int retornaPokeWaterBF(void* unPokemon);
int retornaPokeFireBF(void* unPokemon);
int retornaPokeBatallaFinal(void * unPokemon);


int comparaCadena(char* cadena,char *cadenaDos);












#endif /* POKE_H_ */
