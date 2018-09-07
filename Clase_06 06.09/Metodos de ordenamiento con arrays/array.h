#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define DATO_INVALIDO -1
#define false 0
#define true 1

int array_Mostrar(int* pArray, int limite);
int array_CalcularMaximo(int* pArray, int limite, int* pMaximo);
int array_Init(int* pArray, int limite, int valor);
int array_MinimoDesde(int* pArray, int limite, int desde, int* pMinimo);
int array_Ordenar(int* pArray, int limite, int orden);
int array_Ordenar2(int* pArray, int limite, int orden);
void array_swap(int* elementoA, int* elementoB);


#endif // ARRAY_H_INCLUDED
