#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 6

int ordenarArray(char pNombres[][50]);
int sortEmpleadosPorNombre(Empleado pEmpleado, int limite, int orden);

int main()
{
    char nombres[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    char apellidos[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    char dni[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i], 50, "\nNombre: ", "\nError", 2 );
    }

    printf("Listado de nombres\n\n");

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s - %s - %s\n", nombres[i]);
    }

    ordenarArray(nombres);
   // ordenarPorNombre(nombres, apellidos, dni, CANTIDAD_EMPLEADOS)

    printf("Ordenado\n\n");

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s - %s - %s\n", nombres[i], apellidos[i], dni[i]);
    }

    return 0;
}

int ordenarArray(char pNombres[][50])
{
    int i;
    int j;
    char auxBuffer[5000];

    for(i=0; i<CANTIDAD_EMPLEADOS; i++)
    {
        for(j=i+1; j<CANTIDAD_EMPLEADOS; j++)
        {
            if(strcmp(pNombres[i], pNombres[j]) < 0)
            {
                strcpy(auxBuffer,pNombres[i]);
                strcpy(pNombres[i], pNombres[j]);
                strcpy(pNombres[j], auxBuffer);
            }
        }
    }
}

int sortEmpleadosPorNombre(Empleado* pEmpleado, int limite, int orden);
{


}
/*void ordenarPorNombre(char* pNombres, char* pApellidos, char* pDni, int limite)
{
    int swap;
    int i;
    char bufferStr[256];

    do
    {
        swap = 0;
        for(i=0; i<limite; i++)
        {
            if(strcmp(pNombres[i], pNombres[i+1]) > 0)
            {
                swap = 1;

                strcpy(auxBuffer,pNombres[i]);
                strcpy(pNombres[i], pNombres[j]);
                strcpy(pNombres[j], auxBuffer

                strcpy(auxBuffer,pApellidos[i]);
                strcpy(pApellidos[i], pApellidos[j]);
                strcpy(pApellidos[j], auxBuffer);
            }
        }
    }while(swap);
}*/
