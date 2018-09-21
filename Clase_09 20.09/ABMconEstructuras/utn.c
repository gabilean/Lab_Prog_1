#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096

/**
    utn_getNombre :
    @param
    @param
    @return
*/
 int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
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
int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[BUFFER_STR];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}



/*int getFloat(char* mensaje,
               char* mensajeError,
               int reintentos,
               float minimo,
               float maximo,
               double precioDelArray)
    {
        int retorno=-1;
        double auxiliar;
        do
        {
            reintentos--;
            printf("%s" ,mensaje);
            scanf("%lf" ,&auxiliar);
            if(auxiliar>=minimo && auxiliar<=maximo)
            {
                retorno=0;
                precioDelArray=auxiliar;
                break;
            }

            printf("%s" ,mensajeError);
            }while(reintentos >= 0);
             return retorno;
    }
*/




int getOnlyInt (char* palabra , int arrayConvertidoAint)
{
    int retorno=0;
    char auxPalabra[100];
    int i;
    strcpy(auxPalabra , palabra);
    int largo= strlen(auxPalabra);
    for(i=0; i <= largo-1 ; i++ ) {
        if((auxPalabra[i]>='a' && auxPalabra[i]<='z')||(auxPalabra[i]>='A' && auxPalabra[i]<='Z')){
            retorno=1;
            printf("no son numeros, hay letras en estos caracteres.");
            break;
        }else{
            if(i == largo-1){
                printf("todos son caracteres, se pudo  transformar la cadena correctamente \n");
                arrayConvertidoAint=atoi(auxPalabra);
            }
        }
    }
    return retorno;
}
/*int getDato (productos* pNombre)
{
    char auxiliar;
    printf("Ingrese nombre del Producto: ");
    fgets(pNombre.nombre,50,stdin);

}*/
