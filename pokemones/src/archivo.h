/*
 * archivo.h
 *
 *  Created on: 31-01-2023
 *      Author: Ignacio Pereyra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "poke.h"



#ifndef ARCHIVO_H_
#define ARCHIVO_H_

int leerArchivo(char *path, LinkedList* listaProductos);
int parser_ProductoFromText(FILE* pFile , LinkedList* listaProducto);
int validaArchivo(char * path);
int asignaDescuento(void *unProducto);







#endif /* ARCHIVO_H_ */
