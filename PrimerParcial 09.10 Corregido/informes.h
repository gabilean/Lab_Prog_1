#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_menuInformes(void);
Afiche* informes_arrayMore500Afiches(Afiche* listAfiche, int limite);
int informes_printClientsWithMore500Afiches(Afiche* listAfiche, Cliente* listCliente, int limite);
int informes_minAfiches(Afiche* listAfiches, int limite);
int informes_clientWithMinAfiches(Afiche* listAfiches, Cliente* listClientes, int limite);
int informes_printClientWithMinAfiches(Cliente* listClientes, Afiche* listAfiches, int limite);
int informes_ventasPorZonaOrdenada(Afiche* listAfiches, int limite);
int informes_maxAfiches(Afiche* listAfiches, int limite);
int informes_clientWithMaxAfiches(Afiche* listAfiches, Cliente* listClientes, int limite);
int informes_printClientWithMaxAfiches(Cliente* listClientes, Afiche* listAfiches, int limite);

#endif // INFORMES_H_INCLUDED
