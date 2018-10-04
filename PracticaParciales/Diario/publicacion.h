#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

#include "cliente.h"

typedef struct
{
    char mensaje[64];
    int id;
    int idCliente;
    int rubro;
    int isEmpty;
}Publicacion;

int publicacion_initPublicacion(Publicacion* list, int len);
int publicacion_isEmpty(Publicacion* list, int len);
int publicacion_assignID(void);
int publicacion_obtainID(void);
int publicacion_getIDPublicacion(Publicacion* list, int len, int id);
int publicacion_altaPublicacion(Publicacion* list, int indice, int id);
int publicacion_removePublicacion(Publicacion* list, int limite,int idCliente);
int publicacion_pausePublicacion(Publicacion* list, Cliente* listCliente, int limite, int idPublicacion);
int publicacion_printPublicacion(Publicacion* list, int len);
int publicacion_printPublicacionConClientes(Publicacion* list, int limite, int idCliente);

#endif // PUBLICACION_H_INCLUDED
