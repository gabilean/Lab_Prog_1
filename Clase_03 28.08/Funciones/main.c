#include <stdio.h>
#include <stdlib.h>

int pedirEdad(void);
int validarEdad(int, int, int);

int main()
{
    int edad;

    edad = pedirEdad();

    printf("Edad guardada: %d", edad);

    return 0;
}

int validarEdad(int edad, int max, int min)
{
    int edadValidada=0;

    if(edad<=min && edad>=max)
    {
        edadValidada=1;
    }

    return edadValidada;
}

int pedirEdad(void)
{
    int edad;
    int edadValidada = 0;

    do
    {
        printf("\nIngrese edad: ");
        scanf("%d", &edad);
        edadValidada=validarEdad(edad, 1, 100);

    }while(edadValidada != 1);

    return edad;
}
