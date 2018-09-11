#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLibrary.h"

int main()
{
    char auxNombre[100];
    char nombre[100] = {};

    if(!getStringLetras("Ingrese un nombre: ", auxNombre))
    {
        printf("Ingrese solo letras!\n");
    }
    else
    {
        strcpy(nombre, auxNombre);
        printf("Nombre: %s", nombre);
    }

    return 0;
}
