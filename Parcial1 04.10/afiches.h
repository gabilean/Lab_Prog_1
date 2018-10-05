#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED

#include "cliente.h"

typedef struct
{
    char nombreArchivo[64];
    char zona[64];
    int cantidad;
    int id;
    int idCliente;
    int isEmpty;
}Afiche;

int afiches_initAfiches(Afiche* list, int len);
int afiches_isEmpty(Afiche* list, int len);
int afiches_findAfiche(Afiche* listAfiches, int limite, int id);
int afiches_assignID(void);
int afiches_obtainID(void);
int afiches_getIDAfiche(Afiche* list, int len, int id);
int afiches_getIDClienteAfiche(Afiche* list, int len, int id);
int afiches_altaAfiche(Afiche* list, int indice, int id);
int afiches_removeAfiche(Afiche* list, int limite, int idCliente);
int afiches_cashAfiche(Afiche* list, int indice);
int afiches_modifyAfiche(Afiche* list, int indice);
int afiches_pauseAfiche(Afiche* list, Cliente* listCliente, int limite, int idAfiche);
int afiches_printAfiche(Afiche* list, int len);
int afiches_printCobradosAfiches(Afiche* list, int len);
int afiches_printAficheConClientes(Afiche* list, int limite, int idCliente);
int afiches_altaForzada(Afiche* listAfiches,int limite, Cliente* listClientes, int lenClientes, int idCliente, char* zona, char* archivo, int cantidad);

#endif // AFICHES_H_INCLUDED
