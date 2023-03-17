/*
 * archivo.c
 *
 *  Created on: 31-01-2023
 *      Author: Ignacio Pereyra
 */
#include "archivo.h"


int validaArchivo(char * path)
{
	char  nombreArchivoCorrecto [50]= "Data_Pokemones.csv";
	int retorno;
	if(path != NULL)
	{
		retorno = strcmp(nombreArchivoCorrecto,path);
		printf("retorno %d \n",retorno);
	}
	return retorno;
}


int leerArchivo(char *path, LinkedList* listaProductos)
{

	FILE * pFile;
	   int retorno=-1;
	   if(path != NULL && listaProductos != NULL)
	   {
		   pFile= fopen(path,"r");
		   if(pFile != NULL)
		   {
			   if(parser_ProductoFromText(pFile,listaProductos))
			  {
				  retorno=1;
			  }
			   else
			   {
				   printf("Error al abrir el archivo\n");
				   retorno = 0;
			   }
		   }


	   }
	return retorno;
}

int parser_ProductoFromText(FILE* pFile , LinkedList* listaProducto)
{
	int retorno = 0;
	char numero[100];
	char nombre[100];
	char tipo[100];
	char tamanio[100];
	char ataqueCargado[100];
	char valorAtaque[100];
	char color[100];
	int cantidadLeida;
	ePokemon *poke;
	if(pFile != NULL && listaProducto != NULL)
	{
		//cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,color);
		while(!feof(pFile))
		{
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,color);
			if(cantidadLeida==7)
			{
				poke = prod_newParametros(numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,color);
				if(poke != NULL)
				{
					ll_add(listaProducto,poke);


					if(feof(pFile))
					{
						retorno = 1;
						break;
					}
				}
			}

		}
	}
return retorno;
}

/**
 * parsea una linkedlist binaria
 *
 */

/*
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int cantidad;
	int retorno=1;
	Electrodomestico*  unJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		while(!feof(pFile))
		{
			cantidad = fread(&unJugador,sizeof(Electrodomestico),1,pFile);
			if(cantidad!=6) // verificar cantidad de variables que tiene estructura
			{
				if(feof(pFile))
				{
					retorno=0;
					break;
				}
			}
		}
	}

    return retorno;
}
*/
/**
 * Guarda un archivo en binario
 */
/*
int guardaArchivoBinario(char *path, LinkedList* listaCargada )
{
	FILE * punteroFile;
	int retorno=0;
	int size;
	Electrodomestico* unProducto;

	if(path != NULL && listaCargada != NULL)
	{
		punteroFile = fopen(path,"wb");// abro el archivo en modo escribir binario
		if(punteroFile != NULL)
		{

			size = ll_len(listaCargada);
			for(int j=0; j<size; j++)
			{
				unProducto = ll_get(listaCargada, j);
				if(unProducto != NULL)
				{
					fwrite(unProducto,sizeof(Electrodomestico),1,punteroFile);
						retorno = 1;
				}
			}
		}
		else
		{

			printf("No se pudo escribir el archivo en binario \n");
		}
		fclose(punteroFile);
	}
return retorno;
}
*/
/**
 * GUARDA EL ARCHIVO EN TEXTO
 */
/*
int guardaArchivoTexto(char* path, LinkedList *listaCargada)
{
	int retorno = 0;
	int bufferId;
	char tipoAux[50];
	char marcaAux[50];
	char modeloAux[50];
	float precioAux;
	float descuentoAux;
	int size;

	FILE * punteroFile;
	Electrodomestico *unProducto;

	if(path != NULL && listaCargada != NULL)
	{
		punteroFile = fopen(path,"w");
		if(punteroFile != NULL)
		{

			size = ll_len(listaCargada);
			for( int i = 0;   i < size; i++)
			{
				unProducto = ll_get(listaCargada, i);
				if(prod_getId(unProducto, &bufferId) && prod_getTipo(unProducto, tipoAux) && prod_getMarca(unProducto, marcaAux) &&
						prod_getModelo(unProducto, modeloAux) && prod_getPrecio(unProducto, &precioAux) && prod_getPorcentaje(unProducto,&descuentoAux))
				{
					fprintf(punteroFile,"%d, %s,%s,%s,%f,%f",bufferId,tipoAux,marcaAux,modeloAux,precioAux,descuentoAux);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}


int asignaDescuento(void *unProducto)
{
	int retorno=0;
	float bufferDescuento;
	if(unProducto != NULL)
	{
		//prod_getPorcentaje((Electrodomestico*)unProducto,&bufferDescuento);
		bufferDescuento = 25;
		prod_setPorcentaje((Electrodomestico*)unProducto,bufferDescuento);
		retorno = 1;
	}
	return retorno;
}
*/
