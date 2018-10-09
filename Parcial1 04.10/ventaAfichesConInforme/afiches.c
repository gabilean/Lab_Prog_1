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

//static int buscarPorId(Publicacion* array,int limite, int id);

/** \brief  Indica que todas las posiciones en el array estan libres, esta funcion pone la bandera (isEmpty) en TRUE
 * en todas las posiciones del array
 * \param list Afiche* Puntero al array de empleados
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int afiches_initAfiches(Afiche* list, int len)
{
    int i;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = TRUE;
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief  Devuelve una posición del array de afiches que tenga la bandera isEmpty en TRUE
 * \param list Afiche* Puntero al array de afiches
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int afiches_isEmpty(Afiche* list, int len)
{
    int i;
    int retorno = -1;

    if(list != NULL && len >= 0)
    {
        for(i=0; i<=len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

/**
* \brief busca un afiche con el id ingresado
* \param list Afiche*
* \param int len
* \param id
* \return int return -1 si no da de alta - 0 alta correcta
*/

int afiches_findAfiches(Afiche* list, int len, int id)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = -2;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

/**
* \brief Asigna un ID
* \return int return id
*/

int afiches_assignID(void)
{
    static int id = 0;

    return id++;
}

/**
* \brief Pide un id
* \return int num devulve un entero
*/

int afiches_obtainID(void)
{
    int num;

    myLibrary_getInt(&num, 20, "\nIngrese ID: ", "\nIngrese solo numeros!", 1);

    return num;
}

/** \brief Busca un afiche recibiendo como parámetro de búsqueda su Id
 * \param list Afiche*
 * \param len int
 * \param id int
 * \return int return (-1) es error [Largo invalido o puntero nulo]
 */

int afiches_getIDAfiche(Afiche* list, int len, int id)
{
    int i;
    int retorno = -1;

    if(list != NULL && len >= 0 && id >= 0)
    {
        for(i=0; i<=len; i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Obtiene la el id de cliente
* \param list Cliente*
* \param int len
* \param int id
* \return int return -1 si no da de alta - 0 alta correcta
*/

int afiches_getIDClienteAfiche(Afiche* list, int len, int id)
{
    int i;
    int retorno = -1;

    if(list != NULL && len >= 0 && id >= 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                retorno = list[i].idCliente;
                break;
            }
        }
    }
    return retorno;
}


/**
* \brief Da de alta un afiche
* \param list Afiche* Cliente*
* \param int indice
* \return int return -1 si no da de alta - 0 alta correcta
*/

int afiches_altaAfiche(Afiche* list, int indice, int id)
{
    int retorno = -1;

    if(indice != -1)
    {
        myLibrary_getNombre(list[indice].nombreArchivo, 90, "\nIngrese nombre de archivo: ", "\nIngrese solo letras!", 2);
        myLibrary_getNombre(list[indice].zona, 90, "\nIngrese su zona: ", "\nIngrese solo letras!", 2);
        myLibrary_getInt(&list[indice].cantidad, 20, "\nIngrese su cantidad: ", "\nIngrese solo numeros", 2);
        list[indice].idCliente = id;
        list[indice].id = afiches_assignID();
        list[indice].isEmpty = COBRAR;
        printf("\n\nNumero de ID generado para esta publicacion: %d", list[indice].id);
        retorno = 0;
    }
    else
    {
        printf("\nNo queda más espacio para guardar afiches!!");
    }
    return retorno;
}

/**
* \brief modifica la informacion de un afiche
* \param list Afiche*
* \param int indice
* \return int return -1 si no se modifico - 0 si se cargo correctamente
*/

int afiches_modifyAfiche(Afiche* list, int indice)
{
    int opcion;
    int retorno = -1;


    if(indice != -1)
    {
        printf("\n1. Cantidad de afiches");
        printf("\n2. Zona");
        myLibrary_getInt(&opcion, 20, "\nOpcion: ", "\nIngrese solo numeros!", 2);

        switch(opcion)
        {
            case 1:
                myLibrary_getInt(&list[indice].cantidad, 20, "\nIngrese cantidad: ", "\nIngrese solo numeros!", 1);
                break;
            case 2:
                myLibrary_getNombre(list[indice].zona, 20, "\nIngrese nombre: ", "\nIngrese solo letras!", 1);
                break;
            default:
                printf("\nIngreso una opcion no valida! Saliendo...");
        }

        retorno = 0;
    }
    else
    {
        printf("\nIngresó un ID invalido!");
    }


        return retorno;
}

/**
* \brief elimina un afiche del la lista
* \param int Afiche*
* \param int limite
* \param int idCliente
* \return int return -1 si no se elimino el afiche - 0 afiche eliminado
*/

int afiches_removeAfiche(Afiche* list, int limite, int idCliente)
{
    int retorno = -1;
    int i;

    if(list != NULL && limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if(idCliente == list[i].idCliente)
            {
                list[i].isEmpty = -2;
                retorno = 0;
            }
        }
    }
    else
    {
        printf("\nIngreso un ID invalido!");
    }

    return retorno;
}

/**
* \brief cambia el estado del afiche a cobrado
* \param list Afiche*
* \param int indice
* \return int return -1 estado no cambiado - 0 estado cambiado
*/

int afiches_cashAfiche(Afiche* list, int indice)
{
    int retorno = -1;
    int opcion;

    myLibrary_getInt(&opcion, 20, "\nEsta seguro que desea cobrar? Si (1) - No (cualquiera): ", "Ingrese solo numeros!", 1);

    if(list != NULL && indice >= 0)
    {
        if(indice != -1)
        {
            if(opcion == 1)
            {
                list[indice].isEmpty = COBRADO;
                retorno = 0;
            }
            else
            {
                printf("\n\nSaliendo!");
            }
        }
        else
        {
            printf("\nIngreso un ID invalido!");
        }

    }

    return retorno;
}

/** \brief Imprime el array de afiches de forma encolumnada
 * \param list Afiche*
 * \param len int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int afiches_printAfiche(Afiche* list, int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len >= 0)
    {
        printf("\n\nListado de ventas\n\n");

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == COBRAR || list[i].isEmpty == COBRADO)
            {
                printf("ID: %d - IDCliente: %d - Archivo: %s - Zona: %s - Cantidad: %d - isEmpty: %d\n", list[i].id, list[i].idCliente, list[i].nombreArchivo, list[i].zona, list[i].cantidad, list[i].isEmpty);
            }
        }

        retorno = 0;
    }
    return retorno;
}

/**
* \brief Imprime el array de afiches cobrados de forma encolumnada
* \param list Afiche*
* \param int len
* \return int return -1 si el array de afiches es NULL - 0 muestra correcta
*/

int afiches_printCobradosAfiches(Afiche* list, int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len >= 0)
    {
        printf("\n\nListado de ventas cobradas\n\n");

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == COBRADO)
            {
                printf("ID: %d - IDCliente: %d - Archivo: %s - Zona: %s - isEmpty: %d\n", list[i].id, list[i].idCliente, list[i].nombreArchivo, list[i].zona, list[i].isEmpty);
            }
        }

        retorno = 0;
    }

    return retorno;
}

/**
* \brief muestra Afiches de un cliente en particular
* \param list Afiche*
* \param int limite
* \return -1 si el array es NULL - 0 muestra correcta
*/

int afiches_printAficheConClientes(Afiche* list, int limite, int idCliente)
{
    int i;
    int retorno = 0;

    printf("\nVentas del cliente ingresado\n");

    if(list != NULL && limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if(idCliente == list[i].idCliente)
            {
                if(list[i].isEmpty == COBRAR)
                {
                    printf("ID Cliente: %d - Archivo: %s - Zona: %s - Cantidad: %d\n", list[i].idCliente, list[i].nombreArchivo, list[i].zona, list[i].cantidad);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

/**


*/

int afiches_printClientesACobrar(Cliente* listCliente, Afiche* listAfiche, int len)
{
    int retorno = -1;
    int i;
    int aCobrar;

    if(listCliente != NULL && len >= 0)
    {
        printf("\n\nListado de clientes con ventas a cobrar\n\n");

        for(i=0; i<len; i++)
        {
            aCobrar = afiches_cantidadAfichesACobrar(listAfiche, len, listCliente[i].id);

            if(aCobrar > 0)
            {
                printf("ID: %d - Nombre: %s - Apellido: %s - Cuit: %s - A cobrar: %d\n", listCliente[i].id, listCliente[i].name, listCliente[i].lastName, listCliente[i].cuit, aCobrar);
            }
        }

        retorno = 0;
    }
    return retorno;
}

/**

*/

int afiches_cantidadAfichesACobrar(Afiche* list, int limite, int idCliente)
{
    int i;
    int contador = 0;

    if(list != NULL && limite>=0)
    {
        for(i=0; i<limite; i++)
        {
            if(list[i].isEmpty == COBRAR && list[i].idCliente == idCliente)
            {
                contador++;
            }
        }
    }
    return contador;
}

/**
* \brief carga el array de afiches forzadamente
* \param listAfiches Afiche*
* \param int limite
* \param listClientes Cliente*
* \param int lenClientes
* \param int idCliente
* \param char zona*
* \param char archivo*
* \param int cantidad
* \return -1 si el array es NULL - 0 carga correcta
*/

int afiches_altaForzada(Afiche* listAfiches,int limite, Cliente* listClientes, int lenClientes, int idCliente, char* zona, char* archivo, int cantidad)
{
    int retorno = -1;
    int i;
    int posCliente;
    if(limite > 0 && listAfiches != NULL)
    {
        i = afiches_isEmpty(listAfiches,limite);
        if(i >= 0)
        {
            posCliente = cliente_findClient(listClientes,lenClientes,idCliente);
            if(posCliente>=0)
            {
                strcpy(listAfiches[i].zona, zona);
                strcpy(listAfiches[i].nombreArchivo,archivo);
                listAfiches[i].cantidad = cantidad;
                listAfiches[i].idCliente = idCliente;
                listAfiches[i].isEmpty= COBRAR;
                listAfiches[i].id = afiches_assignID();
            }
        }
        retorno = 0;
    }
    return retorno;
}
