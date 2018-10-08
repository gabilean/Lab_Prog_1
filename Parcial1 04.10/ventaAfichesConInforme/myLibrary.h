#ifndef MYLIBRARY_H_INCLUDED
#define MYLIBRARY_H_INCLUDED

void myLibrary_cargarListado(int notas[], int tamanio);
void myLibrary_mostrarInformacionDelArray(int notas[], int tamanio);
int myLibrary_retornarTotal(int notas[], int tamanio);
int myLibrary_retornarPromedio(int notas[], int tamanio);
int myLibrary_retornarMaximo(int notas[], int tamanio);
int myLibrary_retornarMinimo(int notas[], int tamanio);
int myLibrary_retornarCantidadPares(int notas[], int tamanio);
int myLibrary_retornarCantidadEntreNotas(int notas[], int tamanio, int limInferior, int limSuperior);
int myLibrary_esInt(char* str);
int myLibrary_esFloat(char* str);
int myLibrary_esSoloLetras(char* str);
int myLibrary_esAlfaNumerico(char* str);
int myLibrary_getString(char* pBuffer, int limite);
int myLibrary_getFloat(float* num, int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_getInt(int* num, int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_isValidLetras(char* pBuffer, int limite);
int myLibrary_getNombre(char* pNombre,int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_getInt(int* num, int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_getFloat(float* num, int limite, char* msg, char* msgErr, int reintentos);
int myLibrary_getCuit(char* cuit, int limite, char* msg, char* msgErr, int reintentos);

//void myLibrary_mostrarEmpleado(struct datos, int);




#endif // MYLIBRARY_H_INCLUDED
