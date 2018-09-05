#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.c"
#define CANTIDAD 5

int main()
{
    int listadoDeNotas[CANTIDAD];

    cargarListado(listadoDeNotas, CANTIDAD);
    mostrarListado(listadoDeNotas, CANTIDAD);
    mostrarInformacionDelArray(listadoDeNotas, CANTIDAD);

    return 0;
}
