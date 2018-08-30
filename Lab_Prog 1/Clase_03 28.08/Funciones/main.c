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

    int contador = 0;

    while(edad>min || edad<max)
    {
        contador++;
        if(contador == 3)
        {
            edad = -1;
            break;
        }
        printf("Ingrese su edad nuevamente: ");
        scanf("%d", &edad);
    }

    return edad;
}

int pedirEdad(void)
{
    int edad;

    printf("\nIngrese edad: ");
    scanf("%d", &edad);
    edad=validarEdad(edad, 1, 100);

    return edad;
}
