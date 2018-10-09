#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_menuInformes(void);
int informes_clientesNameAndCuit(Cliente* listClientes, int limite);
int informes_less10Afiches(Afiche* list, int limite);
int informes_more10Afiches(Afiche* list, int limite);
Afiche* informes_arrayLess10Afiches(Afiche* listAfiche, int limite);
int informes_clientsWithLess10Afiches(Afiche* listAfiche, Cliente* listCliente, int limite);

#endif // INFORMES_H_INCLUDED
