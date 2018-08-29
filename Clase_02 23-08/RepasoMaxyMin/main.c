#include <stdio_ext.h> //esta libreria contiene fpurge
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int numMax;
    int numMin;
    int middleNumber;

    printf("\nNumero 1:");

    while(scanf("%d", &num1) != 1)
    {
        printf("\n Error - Numero 1:");
        __fpurge(stdin);
    }

    numMax = num1;
    numMin = num1;

    printf("\nNumero 2:");

    while(scanf("%d", &num2) != 1)
    {
        printf("\n Error - Numero 2");
        __fpurge(stdin);
    }

    if(num2 > numMax)
    {
        numMax = num2;
    }
    else if(num2 < numMin)
    {
        numMin = num2;
    }

    printf("\nNumero 3: ");

    while(scanf("%d", &num3) != 1)
    {
        printf("\n Error - Numero 3:");
        __fpurge(stdin);
    }

    if(num3 > numMax)
    {
        numMax = num3;
    }
    else if(num3 < numMin)
    {
        numMin = num3;
    }

    printf("\nNumero minimo: %d - Numero maximo: %d", numMin, numMax);

    if((num1 < num2 && num1 > num3) || (num1 > num2 && num1 < num3))
    {
        middleNumber = num1;
    }
    else
    {
        if((num2 < num1 && num2 > num3) || (num2 > num1 && num2 < num3))
        {
            middleNumber = num2;
        }
        else
        {
            middleNumber = num3;
        }
    }

    printf("\n El numero del medio es: %d", middleNumber);



}
