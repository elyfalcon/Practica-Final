#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Producto.h"
#include "DataManager.h"
#define ENCABEZADO 0
#define CANTIDAD 3
#define UP 0
#define DOWN 1




int parserProducto(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    char cabecera[50];
    int guardoDato;
    eProducto* record;
    char Id[3];
    char descrip[25];
    char canti[3];

    if(pFile != NULL)
    {
        retorno = -2;

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo();
            if(record != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^\n]\n",Id,descrip,canti);
                    if(prod_set_Id(record,charToint(Id)))
                    {
                    break;
                    }
                    guardoDato = prod_set_descrip(record,descrip);
                    if(guardoDato !=0)
                    {
                        break;

                    }
                    guardoDato = prod_set_cantidad(record,charToint(canti));
                    if(guardoDato !=0)
                    {
                        break;
                    }
                    al_add(this, record);
                    cantidadFilasLeidas++;
                }
 else //Sin memoria
            {
                break;

            }
        }
    }
    return retorno;

}
//*************Defino los setters y getters

int prod_get_id(eProducto* this)
{
    return this->cod_prod;
}
char* prod_get_descripcion(eProducto* this)
{
    return this->descrip;
}
int prod_get_cantidad(eProducto* this)
{
    return this->cantidad;
}
int prod_set_Id(eProducto* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->cod_prod = dato;
    }
    return 0;
}
int prod_set_descrip(eProducto* this, char *dato)
{
    strcpy(this->descrip,dato);
    return 0;
}
int prod_set_cantidad(eProducto* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->cantidad = dato;
    }
    return 0;
}
int charToint(char* charInt)
{
    int nro;
    nro = atoi(charInt);
    return nro;
}
//****************
int prod_buscarId(ArrayList* this, int cod)
{
    int retorno=0;
    int i;
    eProducto* prod;
    if(this!=NULL && cod >0)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;

        if(prod !=NULL)
        {
            for(i=0;i<this->len(this);i++)
            {
            prod=this->get(this,i);
            if(prod_get_id(prod)==cod)
            {
                retorno=i;
                break;
            }//fin if
            }//fin for
        }//fin if(prod)
        }
    }//fin if(this!)
    return retorno;
}

int prod_mover(ArrayList* this,ArrayList* that,int id)
{
    int retorno=-1;
    eProducto* prod=NULL;
    if(this!=NULL && that!=NULL)
    {
        retorno=0;
      // prod = this->pop(this, this->indexOf(this, prod));
        prod = this->pop(this, id);
       if(prod!=NULL)
       {
           that->add(that,prod);
           this->sort(this,prod_comparaProducto,1);
           that->sort(that,prod_comparaProducto,1);
           printf("se movio correctamente\n");
           system("pause");
       }

        else
        {
            printf("No hay nada para mover\n");
            system("pause");
        }

    }
    return retorno;
}
int prod_BuscarYMover(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int cod_prod,id;
    char resp;

    vista_MostrarElementos(this,"Productos Deposito Nro 0",0,this->len(this));
    cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a mover:\n");
    if(cod_prod >0)
    {
        retorno=0;
        id=prod_buscarId(this,cod_prod);
        vista_Muestra1UnElemento(al_get(this,id));
        resp=Valida_confirmacion("Confirma mover este producto?");
        if(resp=='S')
        {
            retorno=prod_mover(this,that,id);
           // printf("retorno: %d",retorno);
           // system("pause");
           // retorno=1;
        }//fin if(resp)
        else
        {
            printf("Se cancelo la operacion:\n");
            retorno=2;
        }
    }//fin if(cod_prod)
    else
    {
        printf("Error no se encontro el codigo\n");
    }
    if(retorno=1)
    {
        printf("Se movio correctamente\n");
    }
    return retorno;
}
int prod_ComparaNombre(void* eEmpleadoA,void* eEmpleadoB)
{
    int retorno=-1;
    if (strcmp(((eProducto*)eEmpleadoA)->descrip,((eProducto*)eEmpleadoB)->descrip)==1)
    {
      retorno=1;
    }
        if (strcmp(((eProducto*)eEmpleadoA)->descrip,((eProducto*)eEmpleadoB)->descrip)==-1)
    {
      retorno=0;
    }
    return retorno;
}
int prod_comparaProducto(void* eEmpleadoA,void* eEmpleadoB)
{
 //   eEmpleado *eEmpleadoA;
 //   eEmpleado *eEmpleadoB;
    if(((eProducto*)eEmpleadoA)->cod_prod > ((eProducto*)eEmpleadoB)->cod_prod)
    {
        return 1;
    }
    if(((eProducto*)eEmpleadoA)->cod_prod < ((eProducto*)eEmpleadoB)->cod_prod)
    {
        return -1;
    }
    return 0;
}
int compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno;
    eProducto *tmp_1;
    eProducto *tmp_2;
    tmp_1=(eProducto * ) pElementA;
    tmp_2=(eProducto * ) pElementB;

    if(tmp_1->cod_prod > tmp_2->cod_prod)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->cod_prod < tmp_2->cod_prod)
        {
            retorno=0;
        }
    }
    return retorno;
}
