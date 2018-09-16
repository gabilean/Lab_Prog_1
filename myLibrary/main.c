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
    eEmpleado empleado;
    int i;

    myLibrary_getNombre(empleado.nombre, 4, "\nIngrese un nombre: ", "Ingrese solo letras!\n", 3);
    myLibrary_getNombre(empleado.apellido, 4, "\nIngrese un apellido: ", "Ingrese solo letras!\n", 3);
    myLibrary_getStringNumeros(empleado.edad, 4, "\nIngrese edad: ");

    for(i=0; i<1; i++)
    {
        printf("Datos: %s - %s - %s", empleado.nombre, empleado.apellido, empleado.edad);
    }
    //myLibrary_mostrarEmpleados(empleado, 1);
    return 0;
}
