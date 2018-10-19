#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int cliente_initCliente(Cliente* arrayCliente[], int sizeCliente)
{
    int retorno = -1;
    int i;

    for(i=0; i<sizeCliente; i++)
    {
        arrayCliente[i] = NULL;
        retorno = 0;
    }

    return retorno;
}

Cliente* cliente_newCliente(void)
{
    Cliente* auxCliente;

    auxCliente = (Cliente*)malloc(sizeof(Cliente));

    return auxCliente;
}

Cliente* cliente_newClienteParametros(char* name, char* lastName, int id)
{
    Cliente* auxCliente;

    auxCliente = cliente_newCliente();

    if(auxCliente != NULL)
    {
        if(cliente_setName(auxCliente, name) == -1 || cliente_setLastName(auxCliente, lastName) == -1 || cliente_setId(auxCliente, id) == -1)
        {
            cliente_deleteCliente(auxCliente);
            auxCliente = NULL;
        }
    }

    return auxCliente;
}

int cliente_deleteCliente(Cliente* this)
{
    int retorno = -1;

    if(this!=NULL)
    {
        free(this);
        retorno = 0;
    }

    return retorno;
}

int cliente_setName(Cliente* this, char* name)
{
    //if(this != NULL && isValidNombre(name)) //validar
    //{
        strncpy(this->nombre, name, sizeof(this->nombre));
    //}

    return 0;
}

int cliente_setLastName(Cliente* this, char* lastName)
{
    //validar
    strncpy(this->apellido, lastName, sizeof(this->apellido));

    return 0;
}

int cliente_setId(Cliente* this, int id)
{
    //validar
    this->id = id; //getNextId

    return 0;
}

int cliente_getName(Cliente* this, char* name)
{
    if(this != NULL && name != NULL)
    {
        strncpy(name, this->nombre, sizeof(this->nombre));
        return 0;
    }

    return 1;
}

int cliente_isEmpty(Cliente* arrayCliente[], int sizeCliente)
{
    int i;
    int retorno = -1;

    if(arrayCliente != NULL)
    {
        for(i=0; i<sizeCliente; i++)
        {
            if(arrayCliente[i] == NULL)
            {
                retorno = i;
                break;
            }
            else
            {
                printf("\nNo queda espacio en el array!");
            }
        }
    }

    return retorno;
}

int cliente_findById(Cliente* arrayCliente[], int sizeCliente, int id)
{
    Cliente* auxCliente;
    int i;
    int retorno = -1;

    for(i=0; i<sizeCliente; i++)
    {
        auxCliente = arrayCliente[i];

        if(auxCliente != NULL && auxCliente->id == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int cliente_getNextId(void)
{
    int id = 0;

    return id++;
}
