#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

//#include "afiches.h"

typedef struct
{
    int id;
    char name[50];
    char lastName[50];
    char cuit[20];
    int isEmpty;
}Cliente;


int cliente_initCliente(Cliente* list, int len);
int cliente_isEmpty(Cliente* list, int len);
int cliente_findClient(Cliente* list, int len, int id);
int cliente_assignID(void);
int cliente_getIDClient(Cliente* list, int len, int id);
int cliente_obtainID(void);
Cliente* cliente_getClienteById(Cliente* pBuffer,int limite, int id);
int cliente_altaCliente(Cliente* pCliente, int indice);
int cliente_altaForzada(Cliente* array, int limite, char* nombre, char* apellido, char* cuit);
int cliente_modifyCliente(Cliente* list, int indice);
int cliente_removeCliente(Cliente* list, int indice);
int cliente_printClientes(Cliente* list, int len);

#endif // CLIENTE_H_INCLUDED
