#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"
#include "myLibrary.h"

#define TRUE 1
#define FALSE 0

/** \brief  Indica que todas las posiciones en el array estan libres, esta funcion pone la bandera (isEmpty) en TRUE
 * en todas las posiciones del array
 * \param list Employee* Puntero al array de empleados
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int cliente_initCliente(Cliente* list, int len)
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

/** \brief  Devuelve una posición del array de empleados que tenga la bandera isEmpty en TRUE
 * \param list Employee* Puntero al array de empleados
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int cliente_isEmpty(Cliente* list, int len)
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

/** \brief Asigna un id
 * \param void
 * \return int return Primera devolucion es 0, luego incrementa
 */

int cliente_assignID(void)
{
    static int id = 0;

    return id++;
}

/**


*/

int cliente_obtainID(void)
{
    int num;

    myLibrary_getInt(&num, 20, "\nIngrese ID: ", "\nIngrese solo numeros!", 1);

    return num;
}

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return (-1) es error [Largo invalido o puntero nulo]
 */

int cliente_getIDClient(Cliente* list, int len, int id)
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

*/

/*Cliente* cliente_getClienteById(Cliente* pBuffer,int limite, int id)
{
    Cliente* retorno = NULL;
    int i;

    if(pBuffer != NULL && limite >= 0 && id != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].isEmpty == 0 && pBuffer[i].id == id)
            {
                retorno = &pBuffer[i]; //pBuffer+i
                printf("%s", )
                break;
            }
        }
    }
    return retorno;
}*/

int cliente_getClienteById(Cliente* pBuffer,int limite, int id)
{
    Cliente* retorno = NULL;
    int i;

    if(pBuffer != NULL && limite >= 0 && id != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].isEmpty == 0 && pBuffer[i].id == id)
            {
                retorno = i; //pBuffer+i
                break;
            }
        }
    }
    return retorno;
}

/**


*/

int cliente_altaCliente(Cliente* pCliente, int indice)
{
    int retorno = -1;

    if(indice != -1)
    {
        myLibrary_getNombre(pCliente[indice].name, 50, "\nIngrese su nombre: ", "\nIngrese solo letras!", 2);
        myLibrary_getNombre(pCliente[indice].lastName, 50, "\nIngrese su apellido: ", "\nIngrese solo letras!", 2);
        myLibrary_getCuit(pCliente[indice].cuit, 20, "\nIngrese su cuit: ", "\nIngrese solo leteras y numeros!", 2);
        pCliente[indice].id = cliente_assignID();
        pCliente[indice].isEmpty = FALSE;
        printf("\n\nNumero de ID generado para este cliente: %d", pCliente[indice].id);
        retorno = 0;
    }
    else
    {
        printf("\nNo queda más espacio para guardar clientes!!");
    }

    return retorno;

}

/**

*/

int cliente_modifyCliente(Cliente* list, int indice)
{
    int opcion;
    int retorno = -1;


    if(indice != -1)
    {
        printf("\n1. Nombre");
        printf("\n2. Apellido");
        printf("\n3. Cuit");
        myLibrary_getInt(&opcion, 20, "\nOpcion: ", "\nIngrese solo numeros!", 2);

        switch(opcion)
        {
            case 1:
                myLibrary_getNombre(list[indice].name, 20, "\nIngrese nombre: ", "\nIngrese solo letras!", 1);
                break;
            case 2:
                myLibrary_getNombre(list[indice].lastName, 20, "\nIngrese apellido: ", "\nIngrese solo letras!", 1);
                break;
            case 3:
                myLibrary_getCuit(list[indice].cuit, 20, "\nIngrese su cuit: ", "\nIngrese solo leteras y numeros!", 2);
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


*/

int cliente_removeCliente(Cliente* list, int indice)
{
    int retorno = -1;
    int opcion;

    myLibrary_getInt(&opcion, 20, "\nEsta seguro que desea eliminar? Si (1) - No (cualquiera): ", "Ingrese solo numeros!", 1);

    if(list != NULL && indice >= 0)
    {
        if(indice != -1)
        {
            if(opcion == 1)
            {
                list[indice].isEmpty = -2;
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

/** \brief Imprime el array de empleados de forma encolumnada
 * \param list Employee*
 * \param len int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int cliente_printClientes(Cliente* list, int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len >= 0)
    {
        printf("\n\nListado de empleados\n\n");

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                printf("ID: %d - Nombre: %s - Apellido: %s - Cuit: %s\n", list[i].id, list[i].name, list[i].lastName, list[i].cuit);
            }
        }

        retorno = 0;
    }
    return retorno;
}

