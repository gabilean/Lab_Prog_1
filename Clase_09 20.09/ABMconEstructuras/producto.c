#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "producto.h"

static int getNextId();

int producto_init(sproducto array[],int len,int valor)
{
    int i;
    int retorno = -1;
    if(array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty=1;

        }
        retorno= 0;
    }
    return retorno;
}



int producto_cargarDatosArray(sproducto array[],int len,int indice)
{
    int retorno = -1;
    char auxNombre[50];
    double auxPrecio =13.55;
    char auxDescripcion[100];

    if(array != NULL && len > 0 && indice >=0 && indice < len && array[indice].isEmpty)
    {
        __fpurge(stdin);

       if(!utn_getNombre(auxNombre,50,"Nombre producto?\n","nombre no valido\n",2) &&
       !utn_getNombre(auxDescripcion,100,"Descripcion producto?\n","descripcion no valida\n",2))
       {
            __fpurge(stdin);
            strncpy(array[indice].nombre,auxNombre,50);
            strncpy(array[indice].descripcion,auxDescripcion,50);
            array[indice].precio = auxPrecio;
            array[indice].isEmpty = 0;
            //array[indice].idProducto = getNextId();

            retorno = 0;
       }

    }

    return retorno;
}



int producto_mostrar(sproducto array[],int len,int valor)
{
    int i;
    int retorno = -1;
    if(array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {

            if(!array[i].isEmpty)
            {
                printf("N: %s - D: %s - P: %f - Indice: %d\n\n",array[i].nombre, array[i].descripcion, array[i].precio, array[i].idProducto);
            }

        }
        retorno= 0;
    }
    return retorno;
}


int producto_lugarLibre(sproducto array[],int limite,char* msje, char* msjErr)
{
    int i;
    int retorno = -1;

    if(array!=NULL && limite >= 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                printf("%s %d: \n",msje,i);
                retorno = 0;
            }
            else
            {
                printf("%s",msjErr);
            }
        }
    }



  return retorno;
}

static int getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}


/*int producto_mostrarMenu(char* msje, char* msjErr, sproducto array[])
{

}*/
