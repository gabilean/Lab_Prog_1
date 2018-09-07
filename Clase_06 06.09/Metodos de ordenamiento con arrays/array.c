#include <stdio_ext.h>
#include <stdlib.h>
#include "array.h"

int array_Mostrar(int* pArray, int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);

    }

    return 0;
}

int array_CalcularMaximo(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int array_Init(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}

int array_Ordenar(int* pArray, int limite, int orden)
{
    int retorno = -1;
    int j;
    int indiceMinimo;

    if(pArray != NULL && limite > 0)
    {
        for(j=0; j<limite; j++)
        {
            array_MinimoDesde(pArray, limite, j, &indiceMinimo);
            array_swap(&pArray[j], &pArray[indiceMinimo]);
        }

        retorno = 0;
    }

    return retorno;
}

int array_Ordenar2(int* pArray, int limite, int orden)
{
    int retorno = -1;
    int j;
    int indiceMinimo;
    int flagSwap;

    if(pArray != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;
            for(j=0; j<limite-1; j++)
            {
                if((orden == 0 && pArray[j] > pArray[j+1]) || (orden == 1 && pArray[j] < pArray[j+1]))
                {
                    flagSwap = 1;
                    array_swap(&pArray[j], &pArray[j+1]);
                }
            }

        }while(flagSwap);

        retorno = 0;
    }

    return retorno;
}


int array_MinimoDesde(int* pArray, int limite, int desde, int* pMinimo)
{
    int retorno = -1;
    int i;
    int auxValorMinimo;
    int auxIndexMinimo;

    if(pArray != NULL && limite > 0 && limite >= desde && pMinimo != NULL)
    {
        for(i=desde; i<limite; i++)
        {
            if(i == desde || pArray[i] < auxValorMinimo)
            {
                auxValorMinimo = pArray[i];
                auxIndexMinimo = i;
            }
        }

        *pMinimo = auxIndexMinimo;
        retorno = 0;
    }

    return retorno;
}

/*int array_MaximoDesde(int* pArray, int limite, int desde, int* pMaximo)
{
    int retorno = -1;
    int i;
    int auxValorMinimo;
    int auxIndexMinimo;

    if(pArray != NULL && limite > 0 && limite >= desde && pMinimo != NULL)
    {
        for(i=desde; i<limite; i++)
        {
            if(i == desde || pArray[i] < auxValorMinimo)
            {
                auxValorMinimo = pArray[i];
                auxIndexMinimo = i;
            }
        }

        *pMinimo = auxIndexMinimo;
        retorno = 0;
    }

    return retorno;
}*/

void array_swap(int* elementoA, int* elementoB)
{
    int aux;

    aux = *elementoA;
    *elementoA = *elementoB;
    *elementoB = aux;
}
