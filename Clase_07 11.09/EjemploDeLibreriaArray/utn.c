#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer, int limite)
{
    int retorno = 0;
    int i;

    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString(char* pBuffer, int limite)
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


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre,int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[4096];

    if(pNombre != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", msg);
            if(getString(bufferNombre,limite)==0 && isValidNombre(bufferNombre, limite))
            {
                strncpy(pNombre, bufferNombre, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
            //continue (viene aca)
        }while(reintentos >= 0);
        //break (viene aca)
    }
    return retorno;
}




















