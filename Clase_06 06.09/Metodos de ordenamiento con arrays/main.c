#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"

#define CANTIDAD_EMPLEADOS 6

int main()
{
    int edades[CANTIDAD_EMPLEADOS] = {55,10,30,50,1,22};
    /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = DATO_INVALIDO;
        }
    }*/
    //array_Ordenar(edades, CANTIDAD_EMPLEADOS, 0);
    array_Ordenar2(edades, CANTIDAD_EMPLEADOS, 0);
    array_Mostrar(edades,CANTIDAD_EMPLEADOS);

    /*
    strncpy(destino, origen, tamaño)

    int cantidad;
    char nombre[81];
    char bufferNombre[4097];
    scanf("%s", nombre);
    cantidad = strlen(bufferNombre);

    strncpy(nombre, bufferNombre, 81)

    strncpy hace el favor de agregar \0?
    */

    //getint y getfloat va a ser %s para tomar todo lo que agarra por teclado y después verificar si lo ingresado es lo que pidio


    return 0;
}
