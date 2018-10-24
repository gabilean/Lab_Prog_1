#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    char nombre[1024];
    char apellido[1024];
    char isEmpty[1024];
    char id[1024];
}Persona;

int Persona_initPersona(Persona* arrayPersona[], int sizePersona);

Persona* Persona_new();
void Persona_delete();
Persona* Persona_newConParametros(char* nombre,char* apellido,char* isEmpty,char* id);

int Persona_setNombre(Persona* this,char* nombre);
int Persona_getNombre(Persona* this,char* nombre);

int Persona_setApellido(Persona* this,char* apellido);
int Persona_getApellido(Persona* this,char* apellido);

int Persona_isEmpty(Persona* arrayPersona[], int sizePersona);
int Persona_setIsEmpty(Persona* this,char* isEmpty);
int Persona_getIsEmpty(Persona* this,char* isEmpty);

int Persona_setId(Persona* this,char* id);
int Persona_getId(Persona* this,char* id);

#endif // PERSONA_H_INCLUDED
