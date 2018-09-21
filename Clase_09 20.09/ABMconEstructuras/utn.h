#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int getOnlyInt (char* palabra , int arrayConvertidoAint);


 int getString(char* pBuffer, int limite);

int getFloat(char* mensaje,
               char* mensajeError,
               int reintentos,
               float minimo,
               float maximo,
               double precioDelArray);
 int isValidNombre(char* pBuffer,int limite);



#endif // UTN_H_INCLUDED
