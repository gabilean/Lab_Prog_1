#include <stdio_ext.h>
#include <stdlib.h>

#define ARRAY_LIMIT 5

int main()
{
    int num[ARRAY_LIMIT];
    int i;
    int total;

    for(i=0;i<ARRAY_LIMIT;i++)
    {
        printf("\nIngrese numero %d: ", i+1);
        while(scanf("%d", &num[i]) != 1)
        {
            printf("Error - Reingrese numero:");
            __fpurge(stdin);
        }
    }
    printf("\nElementos guardados\n");
    for(i=0; i<ARRAY_LIMIT;i++)
    {
        printf("\nNumero %d: %d",i+1,num[i]);
        total = num[i] + total;
    }
    printf("\nEl promedio es: %d", total/ARRAY_LIMIT);

    return 0;
}
