#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
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


    /*
    ﻿id,first_name,last_name,is_empty
    1,Eric,Knight,false
    */
    return 0;
}
