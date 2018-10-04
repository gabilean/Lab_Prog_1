#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLibrary.h"

typedef struct
{
    char nombre[3];
    char apellido[3];
    char edad[3];

}eEmpleado;

int main()
{
    char nombre[100];
    char nombre1[3];
    char apellido[100];

    myLibrary_getNombre(nombre, 4, "\nIngrese un nombre: ", "Ingrese solo letras!\n", 3);
    //myLibrary_getNombre(apellido, 4, "\nIngrese un apellido: ", "Ingrese solo letras!\n", 3);
    //myLibrary_getStringNumeros(edad, 4, "\nIngrese edad: ", "Ingrese solo numeros!\n", 3);
    //myLibrary_getNombre(nombre1, 4, "\nIngrese un nombre: ", "Ingrese solo letras!\n", 3);

    printf("\nDatos: %s - %s - %s", nombre, apellido, nombre1);
    //myLibrary_mostrarEmpleados(empleado, 1);
    return 0;
}
