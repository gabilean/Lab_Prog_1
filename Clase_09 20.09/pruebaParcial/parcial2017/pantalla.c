int pantalla_init(Pantalla* array, int len);
{
    int i;
    int retorno = -1;
    if(array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty=1;

        }
        retorno= 0;
    }

    return retorno;
}

static int getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
static int getLugarLibre(Pantalla* array, int len);
{
    int i;
    int retorno = -1;
    if(array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }

        retorno= 0;
    }

    return retorno;
}

int pantalla_alta(Pantalla* array, int len);
{
    int retorno = -1;
    int indice;

    char nombre[50];
    char direccion[200];
    float precio;
    int tipo;

    indice = getLugarLibre(array,len);

    if(array != NULL && len > 0 && indice >=0 && indice < len && array[indice].isEmpty)
    {
        __fpurge(stdin);

       if(!utn_getNombre(nombre,50,"Nombre producto?\n","nombre no valido\n",2) &&
       !utn_getNombre(direccion,100,"Descripcion producto?\n","descripcion no valida\n",2))
       {
            __fpurge(stdin);
            strncpy(array[indice].nombre,nombre,50);
            strncpy(array[indice].direccion,direccion,50);
            array[indice].precio = precio;
            array[indice].tipo = tipo;
            array[indice].isEmpty = 0;
            array[indice].idProducto = getNextId();

            retorno = 0;
       }

    }

    return retorno;

}

Pantalla* pantalla_getById(Pantalla* array, int len, int id);
{
    int i;
    Pantalla* retorno = NULL;
    if(array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
int pantalla_modificar(Pantalla* array, int len);
int pantalla_baja(Pantalla* array, int len);
int pantalla_mostrar(Pantalla* array, int len);
int pantalla_ordenar(Pantalla* array, int len);
