#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"
#include "publicacion.h"
#include "myLibrary.h"
#include "informes.h"
#define CLIENTES 3
#define PUBLICACIONES 3

/** \brief  Muestra menú ABM de clientes y publicaciones
 * \param void
 * \return void
 */

void avisoDiario_menu(void)
{
    Cliente arrayClientes[CLIENTES];
    cliente_initCliente(arrayClientes, CLIENTES);

    Publicacion arrayPublicaciones[PUBLICACIONES];
    publicacion_initPublicacion(arrayPublicaciones, PUBLICACIONES);


    int opcion = 0;
    int idCliente;
    int idPublicacion;

    int flag = 0;

    do
    {
        printf("\n\nMenu");
        printf("\n1. Alta cliente");
        printf("\n2. Modificacion cliente");
        printf("\n3. Baja cliente y publicacion");
        printf("\n4. Publicar");
        printf("\n5. Informar");
        printf("\n6. Pausar publicacion");
        printf("\n9. Salir");
        myLibrary_getInt(&opcion, 10, "\nOpcion: ", "\nIngrese solo un numero!", 1);

            switch(opcion)
            {
                case 1:
                    cliente_altaCliente(arrayClientes, cliente_isEmpty(arrayClientes, CLIENTES));
                    flag = 1;
                    break;
                case 2:
                    cliente_modifyCliente(arrayClientes, cliente_getIDClient(arrayClientes, CLIENTES, cliente_obtainID()));
                    break;
                case 3:

                    cliente_printClientes(arrayClientes, CLIENTES);
                    printf("\nA continuacion ingrese ID de cliente:");
                    idCliente = cliente_getIDClient(arrayClientes, CLIENTES, cliente_obtainID());
                    publicacion_printPublicacionConClientes(arrayPublicaciones, PUBLICACIONES, idCliente);
                    cliente_removeCliente(arrayClientes, idCliente);
                    publicacion_removePublicacion(arrayPublicaciones, PUBLICACIONES, idCliente);
                    break;
                case 4:
                    cliente_printClientes(arrayClientes, CLIENTES);
                    publicacion_altaPublicacion(arrayPublicaciones,publicacion_isEmpty(arrayPublicaciones, PUBLICACIONES), cliente_getIDClient(arrayClientes, CLIENTES, cliente_obtainID()));
                    break;
                case 5:
                    cliente_printClientes(arrayClientes, CLIENTES);
                    publicacion_printPublicacion(arrayPublicaciones, CLIENTES);
                    break;
                case 6:
                    publicacion_printPublicacion(arrayPublicaciones, PUBLICACIONES);
                    printf("\nA continuacion ingrese ID de publicacion: ");
                    publicacion_pausePublicacion(arrayPublicaciones, arrayClientes, PUBLICACIONES, cliente_getIDClient(arrayClientes, CLIENTES, cliente_obtainID()));
                    break;
                default:
                    opcion = 9;
            }
        }while(opcion != 9);
}
