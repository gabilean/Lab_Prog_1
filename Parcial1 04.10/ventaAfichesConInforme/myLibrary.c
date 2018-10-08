#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "myLibrary.h"

static int getFloat(float* num);
static int getInt(int* num);
static int getCuit(char* cuit);

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_sumaTotal(int notas[], int tamanio)
{
    int acumulador=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        acumulador = acumulador + notas[i];
    }

    return acumulador;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_Promedio(int notas[], int tamanio)
{
    int suma=0;
    int promedio=0;

    suma = myLibrary_sumaTotal(notas, tamanio);
    promedio = suma/promedio;

    return promedio;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

void myLibrary_cargarListado(int notas[], int tamanio)
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

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_numMaximo(int num[], int tamanio)
{
    int max=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(i==0 || num[i] > max)
        {
            max = num[i];
        }
    }

    return max;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_numMinimo(int num[], int tamanio)
{
    int min=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(i==0 || num[i] < min)
        {
            min = num[i];
        }
    }

    return min;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_CantidadPares(int num[], int tamanio)
{
    int contadorPares=0;
    int par;
    int i;

    for(i=0; i<tamanio; i++)
    {
        par = num[i]%2;

        if(par == 0)
        {
            contadorPares++;
        }
    }

    return contadorPares;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_CantidadEntreNotas(int num[], int tamanio, int limInferior, int limSuperior)
{
    int contador=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(num[i]>=limInferior && num[i]<=limSuperior)
        {
            contador++;
        }
    }

    return contador;
}

/** \brief Verifica si es entero
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esInt(char* str)
{
    int i = 0;
    int retorno = -1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            break;
        }
        i++;

        if(str[i] == '\0')
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Verifica si es flotante
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esFloat(char* str)
{
    int i=0;
    int contPuntos = 0;
    int retorno = -1;

    while(str[i] != '\0')
    {
        if(str[i] == ',' || str[i] == '.')
        {
            str[i] = '.';
            contPuntos++;

            if(contPuntos == '2')
            {
                break;
            }
        }

        else if((str[i] < '0') || (str[i] > '9'))
        {
            break;
        }

        i++;

        if(str[i] == '\0')
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Verifica si es solo letras
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esSoloLetras(char* str)
{
    int i = 0;
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

/** \brief Verifica si es alfanumerico
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esAlfaNumerico(char* str)
{
    int i = 0;
    int retorno = -1;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||  str[i] > 'Z') && (str[i] < '0' && str[i] > '9'))
        {
            break;
        }
        i++;

        if(str[i] == '\0')
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Verifica si es string
 * \param char pBuffer*
 * \param int limite tamaño
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_getString(char* pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferStr[4096];

    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferStr, limite, stdin);
        len = strlen(bufferStr);
        if(len != limite-1 || bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        strncpy(pBuffer, bufferStr, limite);
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene un string y verifica si es float
 * \param float num*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

static int getFloat(float* num)
{
    char bufferStr[100];
    int retorno = -1;

    if(myLibrary_getString(bufferStr, 100) == 0 && myLibrary_esFloat(bufferStr) == 0)
    {
        *num = atof(bufferStr);
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene un string y verifica si es int
 * \param int num*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

static int getInt(int* num)
{
    char bufferStr[100];
    int retorno = -1;

    if(myLibrary_getString(bufferStr, 100) == 0 && myLibrary_esInt(bufferStr) == 0)
    {
        *num = atoi(bufferStr);
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene un string y verifica si es cuit
 * \param char cuit*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

static int getCuit(char* cuit)
{
    char bufferStr[4000];
    int retorno = -1;

    if(myLibrary_getString(bufferStr, 4000) == 0 && myLibrary_esAlfaNumerico(bufferStr) == 0)
    {
        strcpy(cuit, bufferStr);
        retorno = 0;
    }

    return retorno;
}


/** \brief Pide un numero flotante, lo valida y lo guarda en la variable pasada por referencia
 * \param float num*
 * \param char msg*
 * \param char msgErr*
 * \param int reintentos
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_getFloat(float* num, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    float bufferNumero;

    if(num != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(getFloat(&bufferNumero) == 0)
            {
                *num = bufferNumero;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Pide un numero entero, lo valida y lo guarda en la variable pasada por referencia
 * \param int num*
 * \param int limite
 * \param char msg*
 * \param char msgErr*
 * \param int reintentos
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */
int myLibrary_getInt(int* num, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    int bufferNumero;

    if(num != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(getInt(&bufferNumero) == 0)
            {

                *num = bufferNumero;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Valida si la cadena pasada por referncia es solo letras
 * \param char pBuffer*
 * \param int limite
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_isValidLetras(char* pBuffer, int limite)
{
    int retorno = 0;
    int i;

    if(pBuffer != NULL && limite > 0)
    {
        //retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = -1;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Pide un nombre, lo valida y lo guarda en la variable pasada por referencia
 * \param char pNombre*
 * \param int limite
 * \param char msg*
 * \param char msgErr*
 * \param int reintentos
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_getNombre(char* pNombre,int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNombre[4096];

    if(pNombre != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(myLibrary_getString(bufferNombre,limite) == 0 && myLibrary_isValidLetras(bufferNombre, limite) == 0)
            {
                strncpy(pNombre, bufferNombre, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

int myLibrary_getCuit(char* cuit, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferCuit[5000];

    if(cuit != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(getCuit(bufferCuit) == 0)
            {
                strcpy(cuit, bufferCuit);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
