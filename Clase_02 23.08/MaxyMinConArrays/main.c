#include <stdio_ext.h>
#include <stdlib.h>

#define ARRAY_LIMIT 3

int main()
{
    int num[ARRAY_LIMIT];
    int numMin;
    int numMax;
    int middleNumber;
    int i;

    for(i=0;i<ARRAY_LIMIT;i++)
    {
        printf("\nNumero %d:", i+1);
        while(scanf("%d", &num[i]) != 1)
        {
            printf("\n Error - Numero %d:", i+1);
            __fpurge(stdin);
        }

        if(i==0)
        {
            numMin = num[i];
            numMax = num[i];
        }
        else if(num[i] > numMax)
        {
            numMax = num[i];
        }
        else if(num[i] < numMin)
        {
            numMin = num[i];
        }
    }
     printf("\nNumero minimo: %d | Numero maximo: %d", numMin, numMax);
     for(i=0;i<ARRAY_LIMIT;i++)
     {
        if(num[i] > numMin && num[i] < numMax)
        {
            middleNumber = num[i];
            break;
        }
     }
     printf("\nEl numero del medio es: %d", middleNumber);

    return 0;
}
