#ifndef MYLIBRARY_H_INCLUDED
#define MYLIBRARY_H_INCLUDED

void cargarListado(int notas[], int tamanio);
void mostrarListado(int notas[], int tamanio);
void mostrarInformacionDelArray(int notas[], int tamanio);
int retornarTotal(int notas[], int tamanio);
int retornarPromedio(int notas[], int tamanio);
int retornarMaximo(int notas[], int tamanio);
int retornarMinimo(int notas[], int tamanio);
int retornarCantidadPares(int notas[], int tamanio);
int retornarCantidadEntreNotas(int notas[], int tamanio, int limInferior, int limSuperior)

#endif // MYLIBRARY_H_INCLUDED
