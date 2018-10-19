#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    int id;
}Cliente;

int cliente_initCliente(Cliente* arrayCliente[], int sizeCliente);
Cliente* cliente_newCliente(void);
int cliente_deleteCliente(Cliente* this);
int cliente_setName(Cliente* auxCliente, char* name);
int cliente_setLastName(Cliente* auxCliente, char* lastName);
int cliente_setId(Cliente* auxCliente, int id);
int cliente_getName(Cliente* this, char* name);
int cliente_isEmpty(Cliente* arrayCliente[], int sizeCliente);
int cliente_findById(Cliente* arrayCliente[], int sizeCliente, int id);
int cliente_getNextId(void);


#endif // CLIENTE_H_INCLUDED
