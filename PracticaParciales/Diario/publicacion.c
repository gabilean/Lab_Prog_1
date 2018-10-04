#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "myLibrary.h"
#include "publicacion.h"
#include "cliente.h"

#define TRUE 1
#define FALSE 0

//static int buscarIndiceVacio(Publicacion* pBuffer,int limite,int* indice);

/** \brief  Indica que todas las posiciones en el array estan libres, esta funcion pone la bandera (isEmpty) en TRUE
 * en todas las posiciones del array
 * \param list Employee* Puntero al array de empleados
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int publicacion_initPublicacion(Publicacion* list, int len)
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

int publicacion_isEmpty(Publicacion* list, int len)
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

int publicacion_assignID(void)
{
    static int id = 0;

    return id++;
}

/**


*/

int publicacion_obtainID(void)
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

int publicacion_getIDPublicacion(Publicacion* list, int len, int id)
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

int publicacion_getIDClientePublicacion(Publicacion* list, int len, int id)
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


*/

int publicacion_altaPublicacion(Publicacion* list, int indice, int id)
{
    int retorno = -1;

    if(indice != -1)
    {
        myLibrary_getNombre(list[indice].mensaje, 90, "\nIngrese su mensaje: ", "\nIngrese solo letras!", 2);
        myLibrary_getInt(&list[indice].rubro, 90, "\nIngrese su rubro: ", "\nIngrese solo numeros", 2);
        list[indice].idCliente = id;
        list[indice].id = publicacion_assignID();
        list[indice].isEmpty = FALSE;
        printf("\n\nNumero de ID generado para esta publicacion: %d", list[indice].id);
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

int publicacion_removePublicacion(Publicacion* list, int limite, int idCliente)
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

*/

int publicacion_pausePublicacion(Publicacion* list, Cliente* listCliente, int limite, int idPublicacion)
{
    int retorno = -1;
    int idCliente;
    int i;
    //Cliente* auxCliente = NULL;
    int auxCliente;

    idCliente = publicacion_getIDClientePublicacion(list, limite, idPublicacion);

    printf("\nidCliente: %d", idCliente);

    auxCliente = cliente_getClienteById(listCliente, limite, idCliente);

    printf("idCliente2: %d", auxCliente);

    //printf("\nNombre: %s - Apellido: %s - Cuit: %s", auxCliente->name, auxCliente->lastName, auxCliente->cuit);

    retorno = 0;

    return retorno;
}

/** \brief Imprime el array de empleados de forma encolumnada
 * \param list Employee*
 * \param len int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int publicacion_printPublicacion(Publicacion* list, int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len >= 0)
    {
        printf("\n\nListado de publicaciones\n\n");

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                printf("ID: %d - IDCliente: %d - Mensaje: %s - Rubro: %d\n", list[i].id, list[i].idCliente, list[i].mensaje, list[i].rubro);
            }
        }

        retorno = 0;
    }
    return retorno;
}

int publicacion_printPublicacionConClientes(Publicacion* list, int limite, int idCliente)
{
    int i;
    int retorno = 0;

    printf("\nPublicaciones del cliente ingresado\n");

    for(i=0; i<limite; i++)
    {
        if(idCliente == list[i].idCliente)
        {
            printf("ID Cliente: %d - Mensaje: %s\n", list[i].idCliente, list[i].mensaje);
        }
    }

    return retorno;
}

/*static int buscarIndiceVacio(Publicacion* pBuffer,int limite,int* indice)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpty == TRUE)
        {
            *indice = i;
            retorno = 0;
            break;
        }
    }

    return retorno;
}*/
