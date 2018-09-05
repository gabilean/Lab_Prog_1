#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int num2;
    int num3;
    int middleNumber;

    printf("Ingrese numero 1: ");
    scanf("%d", &num);
    printf("Ingrese numero 2: ");
    scanf("%d", &num2);
    printf("Ingrese numero 3: ");
    scanf("%d", &num3);

    if((num < num2 && num > num3) || (num > num2 && num < num3))
    {
        middleNumber = num;
    }
    else
    {
        if((num2 < num && num2 > num3) || (num2 > num && num2 < num3))
        {
            middleNumber = num2;
        }
        else
        {
            middleNumber = num3;
        }
    }
    printf("\n El numero del medio es: %d", middleNumber);
    return 0;
}
