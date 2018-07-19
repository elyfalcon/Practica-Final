#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#define TAM_DESCR 20
#include "ArrayList.h"


typedef struct
{
    int cod_prod;
    char descrip[TAM_DESCR];
    int cantidad;
}eProducto;


int parserProducto(FILE* pFile, ArrayList* this);
int prod_BuscarYMover(ArrayList* this,ArrayList* that);
int prod_mover(ArrayList* this,ArrayList* that,int id);
int prod_buscarId(ArrayList* this, int cod);
int prod_comparaProducto(void* eEmpleadoA,void* eEmpleadoB);
int compara_elementos_Estructura(void* pElementA,void* pElementB);





















#endif // PRODUCTO_H_INCLUDED
