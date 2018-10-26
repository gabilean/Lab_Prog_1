#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    printf("\nSize de la lista: %d", ll_len(listaEmpleados));

    do{
        printf("\nIngrese opcion:");
        scanf("%d", &option);

        switch(option)
        {
            //Se podria crear la funcion mostrar con el get del linkedlist, no debería aparecer en ningun lado -> para acceder a los campos de la estructura
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\nSize de la lista: %d", ll_len(listaEmpleados));
                break;
            case 2:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 3:
                //controller_addEmployee()
                break;
            case 6:
                ll_sort(listaEmpleados, Employee_criterioSortNombre,0);
                controller_showEmployees(listaEmpleados,ll_len(listaEmpleados));
                break;
                //controller_
        }

    }while(option != 10);

    return 0;
}
