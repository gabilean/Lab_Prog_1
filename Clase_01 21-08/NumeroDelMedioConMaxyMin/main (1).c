#include <stdio.h>
#include <stdlib.h>

//Ingresar 3 numero e indicar cual es el número del medio.

int main()
{
    int num;
    int num2;
    int num3;
    int numMin;
    int numMax;
    //int middleNumber;

    printf("Ingrese numero 1: ");
    scanf("%d", &num);
    numMin = num;
    numMax = num;

    printf("Ingrese numero 2: ");
    scanf("%d", &num2);
    if(num2 < numMin)
    {
        numMin = num2;
    }
    else if(num2 > numMax)
    {
        numMax = num2;
    }

    printf("Ingrese numero 3: ");
    scanf("%d", &num3);
    if(num3 < numMin)
    {
        numMin = num3;
    }
    else if(num3 > numMax)
    {
        numMax = num3;
    }

    printf("\n El mayor es: %d", numMax);
    printf("\n El menor es: %d", numMin);

    if(num > numMin && num < numMax)
    {
        printf("\nNumero del medio: %d", num);
    }
    else
    {
        if(num2 > numMin && num2 < numMax)
        {
            printf("\nNumero del medio: %d",num2);
        }
        else
        {
            if(num3 > numMin && num3 < numMax)
            {
                printf("\nNumero del medio: %d", num3);
            }
            else
            {
                printf("\nNo hay numero del medio.");
            }
        }
    }
    return 0;
}
