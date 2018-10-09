#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"
#include "afiches.h"
#include "myLibrary.h"
#include "informes.h"
#define CLIENTES 4
#define VENTAS 5

/** \brief  Muestra menú ABM de clientes y ventas
 * \param void
 * \return void
 */

void afichesViaPublica_menu(void)
{
    Cliente arrayClientes[CLIENTES];
    cliente_initCliente(arrayClientes, CLIENTES);

    Afiche arrayAfiches[VENTAS];
    afiches_initAfiches(arrayAfiches, VENTAS);

    int opcion = 0;
    int idCliente;
    int idVenta;

    cliente_altaForzada(arrayClientes, CLIENTES, "Gabriel", "Mendoza", "24");
    cliente_altaForzada(arrayClientes, CLIENTES, "Cristian", "Mendoza", "24");
    cliente_altaForzada(arrayClientes, CLIENTES, "Susana", "Perez", "50");
    cliente_altaForzada(arrayClientes, CLIENTES, "Maria", "Schell", "2");

    afiches_altaForzada(arrayAfiches,VENTAS,arrayClientes, CLIENTES,0,"CABA","archivoMuestra1", 2);
    afiches_altaForzada(arrayAfiches,VENTAS,arrayClientes, CLIENTES,0,"ZonaSur","archivoMuestra2", 3);
    afiches_altaForzada(arrayAfiches,VENTAS,arrayClientes, CLIENTES,1,"ZonaOeste","archivoMuestra66", 77);
    afiches_altaForzada(arrayAfiches,VENTAS,arrayClientes, CLIENTES,3,"GBA","archivoMuestra100", 5);


    do
    {
        printf("\n\nMenu");
        printf("\n1. Alta cliente");
        printf("\n2. Modificacion cliente");
        printf("\n3. Baja cliente y ventas");
        printf("\n4. Vender afiches");
        printf("\n5. Editar venta");
        printf("\n6. Cobrar venta");
        printf("\n7. Imprimir clientes");
        printf("\n8. Menu informes");
        printf("\n9. Salir");
        myLibrary_getInt(&opcion, 10, "\nOpcion: ", "\nIngrese solo un numero!", 1);

            switch(opcion)
            {
                case 1:
                    cliente_altaCliente(arrayClientes, cliente_isEmpty(arrayClientes, CLIENTES));
                    break;
                case 2:
                    cliente_printClientes(arrayClientes, CLIENTES);
                    cliente_modifyCliente(arrayClientes, cliente_getIDClient(arrayClientes, CLIENTES, cliente_obtainID()));
                    break;
                case 3:
                    cliente_printClientes(arrayClientes, CLIENTES);
                    printf("\nA continuacion ingrese ID de cliente:");
                    idCliente = cliente_getIDClient(arrayClientes, CLIENTES, cliente_obtainID());
                    afiches_printAficheConClientes(arrayAfiches, VENTAS, idCliente);
                    cliente_removeCliente(arrayClientes, idCliente);
                    afiches_removeAfiche(arrayAfiches, VENTAS, idCliente);
                    break;
                case 4:
                    cliente_printClientes(arrayClientes, CLIENTES);
                    afiches_altaAfiche(arrayAfiches,afiches_isEmpty(arrayAfiches, VENTAS), cliente_getIDClient(arrayClientes, VENTAS, cliente_obtainID()));
                    break;
                case 5:
                    afiches_printAfiche(arrayAfiches, VENTAS);
                    afiches_modifyAfiche(arrayAfiches, afiches_getIDAfiche(arrayAfiches, VENTAS, afiches_obtainID()));
                    break;
                case 6:
                    afiches_printAfiche(arrayAfiches, VENTAS);
                    printf("\nA continuacion ingrese ID de venta:");
                    idVenta = afiches_getIDAfiche(arrayAfiches, VENTAS, afiches_obtainID());
                    afiches_cashAfiche(arrayAfiches, idVenta);
                    break;
                case 7:
                    cliente_printClientes(arrayClientes, CLIENTES);
                    afiches_printAfiche(arrayAfiches, VENTAS);
                    afiches_printCobradosAfiches(arrayAfiches, VENTAS);
                    afiches_printClientesACobrar(arrayClientes, arrayAfiches, VENTAS);
                    break;
                case 8:
                    switch(informes_menuInformes())
                    {
                        case 1:
                            informes_clientesNameAndCuit(arrayClientes, CLIENTES);
                            cliente_printClientes(arrayClientes, CLIENTES);
                            break;
                        case 2:
                            informes_less10Afiches(arrayAfiches, VENTAS);
                            break;
                        case 3:
                            informes_more10Afiches(arrayAfiches, VENTAS);
                            break;
                        case 4:
                            informes_clientsWithLess10Afiches(informes_arrayLess10Afiches(arrayAfiches, VENTAS), arrayClientes, VENTAS);
                            break;
                        default:
                            break;
                    }

                    break;
                default:
                    opcion = 9;
            }
        }while(opcion != 9);
}
