#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"


int ValidarCantCaracteres(char* cadena,int cantidad)
{
    int longi,flag;
    longi=strlen(cadena);
    flag=0;
    if(longi<=cantidad)
    {
        flag=1;
    }
    return flag;
}
void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;

  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
    {
    i++;
    }
  }

  *i = 0;
}
int ComparaFrases(char* frase1,char* frase2)
 {
    char aux[20]={};
    char aux2[20]={};
    printf("Ingrese una frase\n");
    gets(frase1);
    printf("Ingrese una frase\n");
    gets(frase2);
    RemoveSpaces(frase1);
    RemoveSpaces(frase2);
    strlwr(frase1);
    strlwr(frase2);
    printf("frase1:%s",frase1);
    printf("frase1:%s",frase2);
    if(strcmp(frase1,frase2)==0)
    {
        printf("ya ingreso esa frase:");
    }
    else
        printf("Son distintas");
}
int PedirEntero(char mensaje[])
{
    int auxiliar;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}
long PedirNumLargo(char mensaje[])
{
    long auxiliar=0;
    do
    {
       printf("%s",mensaje);
       fflush(stdin);
       if(auxiliar >= 10000000 && auxiliar < 99999999)
       {
           auxiliar=1;
       }

    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
    }


char Responder(char mensaje[])
{
    char resp;
    //int flag=-1;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",&resp);
    resp=toupper(resp);
    while(resp!='S'&& resp!='N')
    {
      printf("\nDebe ingresar S(si) N(no)\n");
      scanf("%s",&resp);
      resp=toupper(resp);
    }

    return resp;
}

void ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)
        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);
}

void ShowMenu(char *opcion)
{
    system("cls");
    printf("MENU PRINCIPAL\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");
}
void Inicializar()
{
    ArrayList *ListaUrgent;
    ArrayList *ListaRegul;
    ArrayList *ListaAtendidosReg;
    ArrayList *ListaAtendidosUrg;
    ArrayList *ListaTemp;

    ListaUrgent=al_newArrayList();
    ListaRegul=al_newArrayList();
    ListaAtendidosReg=al_newArrayList();
    ListaAtendidosUrg=al_newArrayList();
    ListaTemp=al_newArrayList();

}
int ValidarNull(ArrayList *Lista1,ArrayList *List2, ArrayList *Lista2,ArrayList *Lista3, ArrayList *Lista4)
{
    int retorno=0;
    if(Lista1 !=NULL && Lista2 !=NULL && Lista3 !=NULL && Lista4!=NULL)
    {
        retorno=1;
    }
    return retorno;
}
