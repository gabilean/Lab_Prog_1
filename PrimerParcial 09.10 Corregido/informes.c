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

/**
* \brief Menu informes
* \return int return devuelve la opcion ingresada
*/


int informes_menuInformes(void)
{
    int opcion = -1;

    printf("\n1. Cliente con menos ventas a cobrar");
    printf("\n2. Cliente con menos ventas cobradas");
    printf("\n3. Cliente con menos ventas");
    printf("\n4. Zona con mas afiches vendidos");
    printf("\n5. Cliente que compro menos afiches (Hecho)");
    printf("\n6. Cliente con mas afiches a cobrar (Hecho)");
    printf("\n7. Cantidad de clientes que compraron mas de 500 afiches (Hecho)");
    printf("\n8. Cantidad de afiches vendidos por cada una de las 3 zonas");
    printf("\n9. Cantidad de afiches vendidos promedio por cliente");
    printf("\n10. Listar ventas ordenadas por zona (Hecho)");
    myLibrary_getInt(&opcion, 20, "\nOpcion: ", "\nIngrese solo numeros!", 1);

    return opcion;
}

/**
* \brief Devuelve la cantidad mayor de afiches encontrados en al array
* \param list Afiche*
* \param int limite
* \return int return valor minimo encontrado
*/

int informes_maxAfiches(Afiche* listAfiches, int limite)
{
    int i;
    int max;

    for(i=0; i<limite; i++)
    {
        if(i == 0)
        {
            max = listAfiches[i].cantidad;
        }
        else if(listAfiches[i].cantidad > max)
        {
            max = listAfiches[i].cantidad;
        }
    }

    return max;
}

/**
* \brief Comprueba cual de las ventas es la mayor y deuvlve el ID del cliente
* \param list Afiche*
* \param list Cliente*
* \param int limite
* \return int return ID del cliente que coincide con la menor cantidad de afiches
*/

int informes_clientWithMaxAfiches(Afiche* listAfiches, Cliente* listClientes, int limite)
{
    int retorno;
    int i;

    for(i=0; i<limite; i++)
    {
        if(listAfiches[i].cantidad == informes_maxAfiches(listAfiches, limite) && listAfiches[i].isEmpty == COBRAR)
        {
            retorno = listAfiches[i].idCliente;
        }
    }

    return retorno;
}

/**
* \brief Imprime el cliente con menor cantidad de afiches
* \param list Cliente*
* \param list Afiche*
* \param int limite
* \return int return 0 si se imprime correctamente
*/

int informes_printClientWithMaxAfiches(Cliente* listClientes, Afiche* listAfiches, int limite)
{
    printf("\nEl cliente con la mayor cantidad de afiches a cobrar es: ");
    printf("\n\nNombre: %s - Cuit: %s\n", listClientes[informes_clientWithMaxAfiches(listAfiches, listClientes, limite)].name, listClientes[informes_clientWithMaxAfiches(listAfiches, listClientes, limite)].cuit);

    return 0;
}


/**
* \brief Devuelve la cantidad menor de afiches encontrados en al array
* \param list Afiche*
* \param int limite
* \return int return valor minimo encontrado
*/

int informes_minAfiches(Afiche* listAfiches, int limite)
{
    int i;
    int min;

    for(i=0; i<limite; i++)
    {
        if(i == 0)
        {
            min = listAfiches[i].cantidad;
        }
        else if(listAfiches[i].cantidad < min)
        {
            min = listAfiches[i].cantidad;
        }
    }

    return min;
}

/**
* \brief Comprueba cual de las ventas es la menor y deuvlve el ID del cliente
* \param list Afiche*
* \param list Cliente*
* \param int limite
* \return int return ID del cliente que coincide con la menor cantidad de afiches
*/

int informes_clientWithMinAfiches(Afiche* listAfiches, Cliente* listClientes, int limite)
{
    int retorno;
    int i;

    for(i=0; i<limite; i++)
    {
        if(listAfiches[i].cantidad == informes_minAfiches(listAfiches, limite))
        {
            retorno = listAfiches[i].idCliente;
        }
    }

    return retorno;
}

/**
* \brief Imprime el cliente con menor cantidad de afiches
* \param list Cliente*
* \param list Afiche*
* \param int limite
* \return int return 0 si se imprime correctamente
*/

int informes_printClientWithMinAfiches(Cliente* listClientes, Afiche* listAfiches, int limite)
{
    printf("\nEl cliente con la menor cantidad de afiches es: ");
    printf("\n\nNombre: %s - Cuit: %s\n", listClientes[informes_clientWithMinAfiches(listAfiches, listClientes, limite)].name, listClientes[informes_clientWithMinAfiches(listAfiches, listClientes, limite)].cuit);

    return 0;
}

/**
* \brief Imprime el cliente con menor cantidad de afiches
* \param list Cliente*
* \param list Afiche*
* \param int limite
* \return int return ID del cliente que coincide con la menor cantidad de afiches
*/

int informes_ventasPorZonaOrdenada(Afiche* listAfiches, int limite)
{
    int i;
    int flagswap;
    int retorno = -1;

    Afiche auxAfiche;

    if(listAfiches != NULL && limite > 0)
    {
        do
        {
            flagswap = 0;

            for(i=0; i<limite-1; i++)
            {
                if(strcmp(listAfiches[i].zona, listAfiches[i+1].zona) > 0)
                {
                    auxAfiche = listAfiches[i];
                    listAfiches[i] = listAfiches[i+1];
                    listAfiches[i+1] = auxAfiche;
                    flagswap = 1;
                }
            }
        }while(flagswap == 1);

        retorno = 0;
    }
    return retorno;
}

/**
* \brief devuelve una estrucutra con las ventas filtradas
* \param list Afiche*
* \param int limite
* \return int return nueva estructura a partir de la estructura original
*/

Afiche* informes_arrayMore500Afiches(Afiche* listAfiche, int limite)
{
    int i;
    int j = 0;

    Afiche* auxAfiches = NULL;
    auxAfiches = malloc(sizeof(Afiche));


    for(i=0; i<limite; i++)
    {
        if(listAfiche[i].cantidad > 500)
        {
            auxAfiches[j] = listAfiche[i];
            j++;
        }
    }
    return auxAfiches;
}

/**
* \brief Imprime los clientes con mas de 500 afiches
* \param list Cliente*
* \param list Afiche*
* \param int limite
* \return int return 0 si se imprimio correctamente
*/

int informes_printClientsWithMore500Afiches(Afiche* listAfiche, Cliente* listCliente, int limite)
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

/*int informes_clientesNameAndCuit(Cliente* listClientes, int limite)
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

Todas las ventas cuya cantidad de afiches es menor o igual a 10,
indicando nombre del cliente, cuit, cantidad de afiches y zona del afiche*/

/*Afiche* informes_arrayLess10Afiches(Afiche* listAfiche, int limite)
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
}*/

/*Listado de clientes en el cual se indique la cantidad de ventas que ha realizado
    y cuantos afiches por venta. Ordenado por los siguientes criterios:
        o Cantidad afiches (descendentemente)
        o Cuit (ascendentemente)*/


