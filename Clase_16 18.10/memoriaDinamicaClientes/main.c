#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define CLIENTES 2

int main()
{
    Cliente* arrayClientes[CLIENTES];
    Cliente* auxCliente;
    char auxName[50];
    int indexVacio;

    cliente_initCliente(arrayClientes, CLIENTES);

    auxCliente = cliente_newCliente();

    indexVacio = cliente_isEmpty(arrayClientes, CLIENTES);

    if(auxCliente != NULL)
    {
        cliente_setName(auxCliente, "Gabriel");
        cliente_setLastName(auxCliente, "Mendoza");
        cliente_setId(auxCliente, cliente_getNextId());
        arrayClientes[indexVacio] = auxCliente;

        cliente_getName(auxCliente, auxName);

        printf("\nNombre: %s", auxName);
    }

    //auxCliente = cliente_isEmpty(arrayClientes, CLIENTES);

    return 0;
}
