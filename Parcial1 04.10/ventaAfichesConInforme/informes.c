#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "myLibrary.h"
#include "afiches.h"
#include "cliente.h"

#define FALSE 0
#define TRUE 1
#define COBRAR 2
#define COBRADO 3

int informes_menuInformes(void)
{
    int opcion = -1;

    printf("\n1. Por nombre y cuit");
    printf("\n2. Ventas con menos de 10 afiches");
    printf("\n3. Ventas con mas de 10 afiches");
    printf("\n4. Ventas menores a 10 afiches con datos de clientes");
    myLibrary_getInt(&opcion, 20, "\nOpcion: ", "\nIngrese solo numeros!", 1);

    return opcion;
}

int informes_clientesNameAndCuit(Cliente* listClientes, int limite)
{
    int i;
    int flagswap;
    int retorno = -1;

    Cliente auxCliente;

    if(listClientes != NULL && limite > 0)
    {
        do
        {
            flagswap = 0;
            for(i=0; i<limite-1; i++)
            {
                if(listClientes[i].isEmpty == 0 && listClientes[i+1].isEmpty == 0)
                {
                    if(strcmp(listClientes[i].cuit, listClientes[i+1].cuit) > 0)
                    {
                        auxCliente = listClientes[i];
                        listClientes[i] = listClientes[i+1];
                        listClientes[i+1] = auxCliente;
                        flagswap = 1;
                    }
                    if(strcmp(listClientes[i].cuit, listClientes[i+1].cuit) == 0 && strcmp(listClientes[i].name, listClientes[i+1].name) > 0)
                    {
                        auxCliente = listClientes[i];
                        listClientes[i] = listClientes[i+1];
                        listClientes[i+1] = auxCliente;
                        flagswap = 1;
                    }
                }
            }
        }while(flagswap == 1);

        retorno = 0;

    }

    return retorno;
}

int informes_less10Afiches(Afiche* list, int limite)
{
    int i;
    int retorno = 0;

    for(i=0; i<limite; i++)
    {
        if(list[i].cantidad <= 10 && (list[i].isEmpty == COBRAR || list[i].isEmpty == COBRADO))
        {
            printf("\nID: %d - Nombre archivo: %s - Zona: %s - Cantidad: %d\n", list[i].id, list[i].nombreArchivo, list[i].zona , list[i].cantidad);
        }
    }

    return retorno;
}

int informes_more10Afiches(Afiche* list, int limite)
{
    int i;
    int retorno = 0;

    for(i=0; i<limite; i++)
    {
        if(list[i].cantidad > 10 && (list[i].isEmpty == COBRAR || list[i].isEmpty == COBRADO))
        {
            printf("\nID: %d - Nombre archivo: %s - Zona: %s - Cantidad: %d\n", list[i].id, list[i].nombreArchivo, list[i].zona , list[i].cantidad);
        }
    }

    return retorno;
}

/*Todas las ventas cuya cantidad de afiches es menor o igual a 10,
indicando nombre del cliente, cuit, cantidad de afiches y zona del afiche*/

Afiche* informes_arrayLess10Afiches(Afiche* listAfiche, int limite)
{
    int i;
    int j = 0;

    Afiche* auxAfiches = NULL;
    auxAfiches = malloc(2 * sizeof(Afiche));


    for(i=0; i<limite; i++)
    {
        if(listAfiche[i].cantidad <= 10)
        {
            auxAfiches[j] = listAfiche[i];
            j++;
        }
    }
    return auxAfiches;
}

int informes_clientsWithLess10Afiches(Afiche* listAfiche, Cliente* listCliente, int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(listAfiche[i].isEmpty == COBRADO || listAfiche[i].isEmpty == COBRAR)
        {
            printf("IDCliente: %d - Nombre cliente: %s - Cuit: %s - Cantidad: %d - Zona: %s\n", listAfiche[i].idCliente,listCliente[listAfiche[i].idCliente].name, listCliente[listAfiche[i].idCliente].cuit, listAfiche[i].cantidad, listAfiche[i].zona);
        }

    }
    return 0;
}

/*Listado de clientes en el cual se indique la cantidad de ventas que ha realizado
    y cuantos afiches por venta. Ordenado por los siguientes criterios:
        o Cantidad afiches (descendentemente)
        o Cuit (ascendentemente)*/


