#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Persona_initPersona(Persona* arrayPersona[], int sizePersona)
{
    int retorno = -1;
    int i;

    for(i=0; i<sizePersona; i++)
    {
        arrayPersona[i] = NULL;
        retorno = 0;
    }

    return retorno;
}

Persona* Persona_new()
{
    Persona* this;
    this=malloc(sizeof(Persona));
    return this;
}

void Persona_delete(Persona* this)
{
    free(this);
}

Persona* Persona_newConParametros(char* nombre,char* apellido,char* isEmpty,char* id)
{
    Persona* this;
    this=Persona_new();

    //Validar las entradas, ej:
    //int idInt = atoi(id);
    //Y devolver idInt NO id como esta abajo!

    if(
    !Persona_setNombre(this,nombre)&&
    !Persona_setApellido(this,apellido)&&
    !Persona_setIsEmpty(this,isEmpty)&&
    !Persona_setId(this,id))
        return this;

    Persona_delete(this);
    return NULL;
}

int Persona_setNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Persona_getNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Persona_setApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int Persona_getApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int Persona_isEmpty(Persona* arrayPersona[], int sizePersona)
{
    int i;
    int retorno = -1;

    if(arrayPersona != NULL)
    {
        for(i=0; i<sizePersona; i++)
        {
            if(arrayPersona[i] == NULL)
            {
                retorno = i;
                break;
            }
            else
            {
                printf("\nNo queda espacio en el array!");
                break;
            }
        }
    }

    return retorno;
}

int Persona_setIsEmpty(Persona* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        strcpy(this->isEmpty,isEmpty);
        retorno=0;
    }
    return retorno;
}

int Persona_getIsEmpty(Persona* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        strcpy(isEmpty,this->isEmpty);
        retorno=0;
    }
    return retorno;
}

int Persona_setId(Persona* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        strcpy(this->id,id);
        retorno=0;
    }
    return retorno;
}

int Persona_getId(Persona* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        strcpy(id,this->id);
        retorno=0;
    }
    return retorno;
}

