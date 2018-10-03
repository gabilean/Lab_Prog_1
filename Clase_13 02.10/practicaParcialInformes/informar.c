#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}

int informar_ordenarNameNPrice(Pantalla* array, int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(!array[i].isEmpty && !array[i+1].isEmpty)
                    {
                        if(array[i].precio > array[i+1].precio)
                        {
                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;
                            flagSwap = 1;
                        }

                        if(array[i].precio == array[i+1].precio && strcmp(array[i].nombre,array[i+1].nombre) > 0)
                        {
                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }
    return retorno;
}

int informar_ordenarLess10(Pantalla* array, int limite)
{
    int i;
    int retorno = 0;

    for(i=0; i<limite; i++)
    {
        if(array[i].precio <= 10 && array[i].isEmpty == 0)
        {
            printf("\n[RELEASE] - %d - %s - %.2f\n",array[i].idPantalla, array[i].nombre, array[i].precio);
        }
    }

    return retorno;
}

int informar_ordenarMore10(Pantalla* array, int limite)
{
    int i;
    int retorno = 0;

    for(i=0; i<limite; i++)
    {
        if(array[i].precio > 10 && array[i].isEmpty == 0)
        {
            printf("\n[RELEASE] - %d - %s - %.2f\n",array[i].idPantalla, array[i].nombre, array[i].precio);
        }
    }

    return retorno;
}

static float priceAverage(Pantalla* array, int limite)
{
    int i;
    int promedio = 0;
    int contador = 0;
    float suma = 0;

    for(i=0; i<limite; i++)
    {
        contador++;
        suma = suma + array[i].precio;
    }

    promedio = suma/contador;

    return promedio;
}

int informar_moreThanAverage(Pantalla* array, int limite)
{
    int i;
    int retorno = 0;

    printf("\n\nPROMEDIO:%.2f\n", priceAverage(array, limite));

    for(i=0; i<limite; i++)
    {
        if(array[i].precio > priceAverage(array, limite) && array[i].isEmpty == 0)
        {
            printf("\n[RELEASE] - %d - %s - %.2f\n",array[i].idPantalla, array[i].nombre, array[i].precio);
        }
    }

    return retorno;
}

int informar_lessThanAverage(Pantalla* array, int limite)
{
    int i;
    int retorno = 0;

    printf("\n\nPROMEDIO:%.2f\n", priceAverage(array, limite));

    for(i=0; i<limite; i++)
    {
        if(array[i].precio < priceAverage(array, limite) && array[i].isEmpty == 0)
        {
            printf("\n[RELEASE] - %d - %s - %.2f\n",array[i].idPantalla, array[i].nombre, array[i].precio);
        }
    }

    return retorno;
}

static int addCuit(Contrataciones* arrayC, char* cuit, int limite)
{
    int i;

    for(i=0; i<limte; i++)
    {

    }
}

int informar_contPerClients(Contratacion* arrayC, Pantalla* arrayP, char* cuit, int limite)
{

}

/*int informar_contLessThan10Days(Pantalla* arrayPan, Contratacion* arrayCont, int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(arrayCont[i].dias < 10 && )
        {

        }
    }
}*/



 /*if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && ordenName) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !ordenName))
                        {
                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;
                            flagSwap = 1;
                        }*/

