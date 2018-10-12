#include <stdio.h>
#include <stdlib.h>

//Declarar array de enteros, recorrer de arrays, iniciliazar sus valores, mostrar array de enteros

int* newArray(int size);
int initArray(int* arrayInt, int limite, int valor);
int showArray(int* arrayInt, int limite);
int deleteArray(int* arrayInt, int limite);
int reallocateArray(int* arrayInt, int size);

int main()
{
    int* arrayNum;

    arrayNum = newArray(3);
    initArray(arrayNum, 3, 1024);
    showArray(arrayNum, 3);
    deleteArray(arrayNum, 3);
    reallocateArray(arrayNum, 3);
    printf("\n LISTA REALOCADA");
    showArray(arrayNum, 3);

    return 0;
}

int* newArray(int size)
{
    int* retorno = NULL;
    int* auxArray;

    if(size > 0)
    {
        auxArray = (int*)malloc(sizeof(int)*size);

        if(auxArray != NULL)
        {
            retorno = auxArray;
        }
    }

    return retorno;
}

int initArray(int* arrayInt, int limite, int valor)
{
    int retorno = -1;
    int i;

    if(arrayInt != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            *(arrayInt+i) = valor;
            retorno = 0;
        }
    }

    return retorno;
}


int showArray(int* arrayInt, int limite)
{
    int retorno = -1;
    int i;

    if(arrayInt != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            printf("\nPuntero: %p - Indice: %d - Valor: %d", (arrayInt+i), i, *(arrayInt+i));
        }

        retorno = 0;
    }

    return retorno;
}

int deleteArray(int* arrayInt, int limite)
{
    int retorno = -1;

    if(arrayInt != NULL)
    {
        free(arrayInt);
        retorno = 0;
    }

    return retorno;
}

int reallocateArray(int* arrayInt, int size)
{
    int* retorno = NULL;

    if(arrayInt != NULL && size > 0)
    {
        retorno = (int*)realloc(arrayInt, sizeof(int)*size);
    }

    return retorno;
}
