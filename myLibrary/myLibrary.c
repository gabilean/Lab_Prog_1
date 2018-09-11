#include <stdio.h>
#include <string.h>
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
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(notas[i]>=limInferior && notas[i]<=limSuperior)
        {
            contador++;
        }
    }

    return contador;
}

int getInt(char mensaje[])
{
    int auxiliar;

    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    return auxiliar;
}

float getFloat(char mensaje[])
{
    float auxiliar;

    printf("%s", mensaje);
    scanf("%f", &auxiliar);

    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);

    return auxiliar;
}

int esNumerico(char str[])
{
    int i;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' && str[i] > '9')
        {
            retorno = 0;
        }
        i++;
    }

    return retorno;
}

int esSoloLetras(char str[])
{
    int i;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||  str[i] > 'Z'))
        {
            retorno = 0;
        }
        i++;
    }

    return retorno;
}

int esAlfaNumerico(char str[])
{
    int i;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||  str[i] > 'Z') && (str[i] < '0' && str[i] > '9'))
        {
            retorno = 0;
        }
        i++;
    }

    return retorno;
}

void getString(char str[], char input[])
{
    printf(str);
    scanf("%s", input);
}

int getStringLetras(char str[], char input[])
{
    char aux[4000];
    int retorno = 0;
    getString(str, aux);

    if(esSoloLetras(aux))
    {
        strcpy(input, aux);
        retorno = 1;
    }

    return retorno;
}

int getStringNumeros(char str[], char input[])
{
    char aux[4000];
    int retorno = 0;
    getString(str, aux);

    if(esNumerico(aux))
    {
        input = aux;
        retorno = 1;
    }

    return retorno;
}
