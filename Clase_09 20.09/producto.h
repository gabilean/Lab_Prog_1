#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED


typedef struct producto
{
    int idProducto;
    char nombre[50];
    char descripcion[100];
    float precio;
    int isEmpty;
}sproducto;

int producto_cargarDatosArray(sproducto array[],int len,int indice);
int producto_init(sproducto array[],int len,int valor);
int producto_mostrar(sproducto array[],int len,int valor);
int producto_lugarLibre(sproducto array[],int limite,char* msje, char* msjErr);
void mostrarEdad(int edad);
#endif // UTN_H_INCLUDED
