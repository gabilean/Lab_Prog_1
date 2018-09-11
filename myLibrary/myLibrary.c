#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"

int retornarTotal(int notas[], int tamanio)
{
    int acumulador=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        acumulador = acumulador + notas[i];
    }

    return acumulador;
}

int retornarPromedio(int notas[], int tamanio)
{
    int suma=0;
    int promedio=0;

    suma = retornarTotal(notas, tamanio);
    promedio = suma/promedio;

    return promedio;
}

void cargarListado(int notas[], int tamanio)
{
    int i;
    int numeroIngresado;

    for(i=0;i<tamanio;i++)
    {
        printf("\n Ingrese nota: ");
        scanf("%d", &numeroIngresado);
        notas[i] = numeroIngresado;
    }
}

void mostrarListado(int notas[], int tamanio)
{
    int i;

    for(i=0;i<tamanio;i++)
    {
        printf("\nNotas guardadas: %d", notas[i]);
    }
}

/*
    mayor, menor, cantidad de pares, suma total, promedio

    aprobado, desaprobado, rinde final (6 y 10)
*/


void mostrarInformacionDelArray(int notas[], int tamanio)
{
    printf("\nEl mayor es: %d", retornarMaximo(notas, tamanio));
    printf("\nEl menor es: %d", retornarMinimo(notas, tamanio));
    printf("\nEl suma es: %d", retornarPromedio(notas, tamanio));
    printf("\nEl promedio es: %d", retornarTotal(notas, tamanio));
    printf("\nCantidad de pares: %d", retornarCantidadPares(notas, tamanio));
    //printf("\nDesaprobados: %d", retornarCantidadEntreNotas(notas, tamanio, 1, 3));
    //printf("\nAprobados: %d", retornarCantidadEntreNotas(notas, tamanio, 4, 5));
    //printf("\nA final: %d", retornarCantidadEntreNotas(notas, tamanio, 6, 10));
}

int retornarMaximo(int notas[], int tamanio)
{
    int max;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(i==0 || notas[i] > max)
        {
            max = notas[i];
        }
    }

    return max;
}

int retornarMinimo(int notas[], int tamanio)
{
    int min;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(i==0 || notas[i] < min)
        {
            min = notas[i];
        }
    }

    return min;
}
int retornarCantidadPares(int notas[], int tamanio)
{
    int contadorPares=0;
    int par;
    int i;

    for(i=0; i<tamanio; i++)
    {
        par = notas[i]%2;

        if(par == 0)
        {
            contadorPares++;
        }
    }

    return contadorPares;
}

int retornarCantidadEntreNotas(int notas[], int tamanio, int limInferior, int limSuperior)
{
    int contador=0;

    for(i=0;i<tamanio;i++)
    {
        if(notas[i]>=limInferior && notas[i]<=limSuperior)
        {
            contador++;
        }
    }

    return contador;
}
