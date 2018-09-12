#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char usuario[9];
    char clave[9];
    char auxContrasenia[] = "admin\n"; //En este caso se agrego \n al array porque la funcion gets agregar una nueva linea debajo de lo guardado
    char auxUsuario[] = "admin\n";
    int otroAux;

    printf("Ingrese usuario: ");
    fgets(usuario, 9, stdin);
    __fpurge(stdin);
    printf("\nIngrese contraseña: ");
    fgets(clave, 9, stdin);
    __fpurge(stdin);

    otroAux = strlen(usuario);

    printf("\nTamanio: %d", otroAux);


    if(strcmp(usuario,auxUsuario)==0 && strcmp(clave,auxContrasenia)==0)
    {
        printf("\nIngreso\n");
    }
    else
    {
        printf("\nIncorrecto");
    }

    /*char nombre[10];
    char apellido[10];
    char localidad[10];

    fgets(nombre, 9, stdin);
    __fpurge(stdin);
    fgets(apellido, 9, stdin);
    __fpurge(stdin);
    fgets(localidad, 9, stdin);
    __fpurge(stdin);

    printf("\n El apellido ingresado es: %s y usted es: %s y vive en %s", apellido, nombre, localidad);*/

    return 0;
}
