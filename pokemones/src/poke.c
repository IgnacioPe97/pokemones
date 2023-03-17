/*
 * poke.c
 *
 *  Created on: 15 feb 2023
 *      Author: alumno
 */
#include "poke.h"
#include <string.h>



ePokemon* producto_new()
{
	ePokemon *unProducto = NULL;
	unProducto = (ePokemon*)calloc(sizeof(ePokemon),1);

return unProducto;
}

ePokemon* prod_newParametros(char* numero ,char* nombre,char* tipo, char* tamanio, char* ataqueCarga, char* valorAtaque,char *color)
{
	ePokemon *unProducto = producto_new();
		if(unProducto != NULL && nombre != NULL && tipo != NULL && numero != NULL && tamanio != NULL && ataqueCarga!= NULL && valorAtaque != NULL && color!= NULL)
		{

			if(prod_setNumeroTxt(unProducto, numero)&&
				prod_setNombre(unProducto, nombre) &&
				prod_setTamanio(unProducto, tamanio) &&
				prod_setAtaqueCargado(unProducto, ataqueCarga) &&
				prod_setTipo(unProducto, tipo) &&
				prod_setColorTxt(unProducto, color) &&
				prod_setValorAtaqueTxt(unProducto, valorAtaque)
				)
			{
				//printf("Salio BIEN el ingreso\n");

			}
			else
			{
				printf("Salio MAL el ingreso\n");
			}
		}

return unProducto;
}
/*transforma un numero que viene por cadena a numero y lo setea como numero
 *  * Si devuelve 0 exito, si devuelve 1 salio mal
 */
int prod_setNumeroTxt(ePokemon* this,char* numero)
{
	int retorno = 0;
	int bufferId;
		if(this != NULL && numero != NULL)
		{
				bufferId = atoi(numero);
				this->numero = bufferId;
				retorno=1;

		}
	return retorno;
}
/*
 * Setea una cadena en el tipo de electrodomestico
 *  * Si devuelve 0 exito, si devuelve 1 salio mal
 */
int prod_setTipo(ePokemon* this,char* tipo)
{
	int retorno = 0;
		if(this != NULL && tipo != NULL)
		{
			strncpy(this->tipo,tipo,LARGE);

			retorno=1;
		}
return retorno;
}
/*
 * Setea una cadena en la marca de electrodomestico
 *  * Si devuelve 0 exito, si devuelve 1 salio mal
 */

int prod_setNombre(ePokemon* this,char* nombre)
{
	int retorno = 0;


		if(this != NULL && nombre != NULL)
		{
			strncpy(this->nombre,nombre,LARGE);
			retorno=1;
		}
return retorno;
}

/*
 * Setea una cadena en el modelo del electrodomestico
 * Si devuelve 0 exito, si devuelve 1 salio mal
 */
int prod_setAtaqueCargado(ePokemon* this,char* ataqueCargado)
{
	int retorno = 0;
		if(this != NULL && ataqueCargado != NULL)
		{
			strncpy(this->ataqueCargado,ataqueCargado,LARGE);
			retorno=1;

		}
return retorno;
}

int prod_setTamanio(ePokemon* this,char* tamanio)
{
	int retorno = 0;
		if(this != NULL && tamanio != NULL)
		{
			strncpy(this->tamanio,tamanio,LARGE);
			retorno=1;

		}
return retorno;
}
/*
 * Transforma una cadena a numero y la setea en el precio del electrodomestico
 * Si devuelve 0 exito, si devuelve 1 salio mal
 */
int prod_setValorAtaqueTxt(ePokemon* this,char* valorAtaque)
{
	int retorno = 0;
	int bufferPrecio;
		if(this != NULL && valorAtaque != NULL)
		{
			bufferPrecio = atoi(valorAtaque);
			this->valorAtaque = bufferPrecio;
			retorno=1;
		}
	return retorno;
}

int prod_setColorTxt(ePokemon* this,char* color)
{
	int retorno = 0;
	int bufferPrecio;
		if(this != NULL && color != NULL)
		{
			bufferPrecio = atoi(color);
			this->esVarioColor = bufferPrecio;
			retorno=1;
		}
	return retorno;
}


int prod_getNumero(ePokemon *this, int *numero)
{
	int retorno=0;

		if(this != NULL && numero != NULL)
		{
			*numero = this->numero;
			retorno=1;
		}
return retorno;
}



int prod_getValorAtaque(ePokemon *this, int *valorAtaque)
{
	int retorno=0;

		if(this != NULL && valorAtaque != NULL)
		{
			*valorAtaque=this->valorAtaque;
			retorno=1;
		}
return retorno;
}

int prod_getNombre(ePokemon* this,char* nombre)
{
	int retorno = 0;
		if(this != NULL && nombre!= NULL)
		{
			strncpy(nombre,this->nombre,LARGE);
			retorno=1;
		}
return retorno;
}


int prod_getTamanio(ePokemon* this,char* tamanio)
{
	int retorno = 0;
		if(this != NULL && tamanio != NULL)
		{
				strncpy(tamanio,this->tamanio,LARGE);
				retorno=1;
		}
return retorno;
}

int prod_getTipo(ePokemon* this,char* nombreTipo)
{
	int retorno = 0;

		if(this != NULL && nombreTipo != NULL)
		{
				strncpy(nombreTipo,this->tipo,LARGE);
				retorno=1;

		}
return retorno;
}
int prod_getAtaquCargado(ePokemon* this,char* ataqueCargado)
{
	int retorno = 0;

		if(this != NULL && ataqueCargado != NULL)
		{
				strncpy(ataqueCargado,this->ataqueCargado,LARGE);
				retorno=1;

		}
return retorno;
}

int prod_getColor(ePokemon *this, int *color)
{
	int retorno=0;
		if(this != NULL && color != NULL)
		{
			*color=this->esVarioColor;
			retorno=1;
		}
return retorno;
}

int imprimePokemones(LinkedList *listaCargada)
{
	int numero;
		char nombre[100];
		char tipo[100];
		char tamanio[100] ;
		char ataqueCargado[100] ;
		int valorAtaque;
		int color;
		int size;
		int retorno = 0;

		ePokemon * unPoke = NULL;
		size = ll_len(listaCargada);
		if(listaCargada != NULL)
		{
			for (int i  = 0;  i < size; i++)
					{
						unPoke = ll_get(listaCargada, i);
						if(unPoke != NULL)
						{
							if(prod_getNumero(unPoke, &numero) &&
									prod_getNombre(unPoke, nombre) &&
									prod_getTipo(unPoke, tipo)&&
									prod_getTamanio(unPoke, tamanio) &&
									prod_getAtaquCargado(unPoke, ataqueCargado) &&
									prod_getValorAtaque(unPoke, &valorAtaque)&&
									prod_getColor(unPoke, &color))
							{
								printf("%4d  %20s  %20s  %20s %20s  %4d  %.4d\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,color);
								retorno = 1;
							}
							else
							{
								printf("esNulo\n");
							}
						}
					}

		}

return retorno;
}

int retornaListaFuego(void * unPokemon)
{
	char nombreTipo[100];
	char nombreFuego[5] = "Fire";
	int retorno;
	int valor;

	prod_getTipo((ePokemon*)unPokemon, nombreTipo);
	valor = strncmp(nombreTipo,nombreFuego,5);
	if(valor < 0)
	{
		retorno = -1;;
	}
	else if(valor > 0)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}
int retornaPokeBatallaFinal(void * unPokemon)
{
char nombreTipo[6];
char nombreAgua[6] = "Water";
char tamanioAgua[5] ="L";
char ataqueCargadoOkAgua[11]="Hidrobomba";

char nombreFuego[5] = "Fuego";
char tamanioFuego[5] ="XL";
char ataqueCargadoOkFuego[12]="Lanzallamas";
char tamanio[5];
char ataqueCargadopChar[12];

int ataqueCargado;
int retorno;


			prod_getTipo((ePokemon*)unPokemon, nombreTipo);
			prod_getTamanio((ePokemon*)unPokemon, tamanio);
			prod_getAtaquCargado((ePokemon*)unPokemon, ataqueCargadopChar);
			prod_getValorAtaque((ePokemon*)unPokemon, &ataqueCargado);


		if(!comparaCadena(nombreTipo,nombreFuego) && !comparaCadena(tamanio, tamanioFuego) &&!comparaCadena(ataqueCargadopChar, ataqueCargadoOkFuego) && ataqueCargado > 80 )
		{
			printf("Ingreso primer if\n");
			retorno=1;
		}
		else
		{
			if(!comparaCadena(nombreTipo,nombreAgua) && !comparaCadena(tamanio, tamanioAgua) && !comparaCadena(ataqueCargadopChar, ataqueCargadoOkAgua) && ataqueCargado > 80 )
			{
				printf("Ingreso segundo if\n");

				retorno=1;
			}
			else
			{
				printf("no cumple condiciones\n");
				retorno = 0;
			}
		}





return retorno;
}


int comparaCadena(char* cadena,char *cadenaDos)
{
	int retorno;

	if(cadena!=NULL || cadenaDos !=NULL)
	{
		retorno = strcmp(cadena,cadenaDos);
		if(retorno<0)
		{
			retorno =-1;
		}
		else if(retorno > 0)
		{
			retorno=1;
		}
		else
		{
			retorno=0;
		}
	}
	return retorno;
}



