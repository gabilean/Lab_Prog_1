#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int ingresarNombre(char str[]);
int esSoloLetras(char str[]);

int main()
{
    char nombre[50];

    if(ingresarNombre(nombre))
    {
        printf("\n\nNombre ingresado: %s", nombre);
    }

    /*("Ingrese su nombre: ");
    scanf("%s", auxNombre);

    if(!esSoloLetras(auxNombre, strlen(auxNombre)))
    {
        strcpy(nombre, auxNombre);
        printf("\n\nNombre ingresado: %s", nombre);
    }
    else
    {
        printf("Ingrese solo letras");
    */

    return 0;
}

int ingresarNombre(char str[])
{
    char auxStr[100];
    int retorno = 0;

    do
    {
        printf("Ingrese un nombre: ");
        __fpurge(stdin);
        scanf("%s", auxStr);

    }while(!esSoloLetras(auxStr));

    strcpy(str, auxStr);
    printf("\nNombre ingresado con exito!");
    retorno = 1;

    return retorno;
}

int esSoloLetras(char str[])
{
    int i;
    int tam;
    int retorno = 1;

    tam = strlen(str);

    for(i=0; i<tam; i++)
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||  str[i] > 'Z'))
        {
            retorno = 0;
        }
    }

    return retorno;
}
