/*
 * menuInicio.c
 *
 *  Created on: 31-01-2023
 *      Author: Ignacio Pereyra
 */

#include "menuInicio.h"

int muestraMenuInicio(void)
{
	int numeroElegido;
	utn_getNumero(&numeroElegido,"1-Cargar Archivo\n 2- Imprimir Lista\n 3-Filtrar por tipo fuego\n 4-Batalla Pokemon\n 5- Salir\n",
			"Error en el ingreso\n", 1,5,3);
return numeroElegido;
}
