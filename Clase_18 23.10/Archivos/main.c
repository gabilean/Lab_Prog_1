#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int main()
{
    FILE* pArchivo;

    pArchivo = fopen("data.csv","r");

    Persona* arrayPersona[1024];

    char bufferId[1024];
    char bufferName[1024];
    char bufferLastName[1024];
    char bufferIsEmpty[1024];
    int i;

    if(pArchivo != NULL)
    {
        fscanf(pArchivo, "%s\n", bufferId);
        while(!feof(pArchivo))
        {
            fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferLastName, bufferIsEmpty);
            arrayPersona[i] = Persona_newConParametros(bufferName, bufferLastName, bufferIsEmpty, bufferId);
            i++;
        }

        fclose(pArchivo);
    }
    else
    {
        printf("\nError, no existe!");
    }

    for(i=0; i<1000; i++)
    {
        printf("\nID: %s - Name: %s - LastName: %s - isEmpty: %s", arrayPersona[i]->id, arrayPersona[i]->nombre, arrayPersona[i]->apellido, arrayPersona[i]->isEmpty);
    }
    /*FILE* pArchivo;
    FILE* backupArchivo;

    pArchivo = fopen("data.csv","r");
    backupArchivo = fopen("backupArchivo.csv", "w");
    char bufferId[1024];
    char bufferName[1024];
    char bufferLastName[1024];
    char bufferIsEmpty[1024];

    if(pArchivo != NULL)
    {
        fscanf(pArchivo, "%s\n", bufferId);
        while(!feof(pArchivo))
        {
            fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferLastName, bufferIsEmpty);
            //fprintf(backupArchivo, "%s\n",bufferName);
            printf("\n%s - %s - %s - %s", bufferId, bufferName, bufferLastName, bufferIsEmpty);
        }

        fclose(pArchivo);
        fclose(backupArchivo);
    }
    else
    {
        printf("\nError, no existe!");
    }

    */
    return 0;
}
