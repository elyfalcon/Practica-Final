#ifndef TOOLS_INCLUDED
#define TOOLS_INCLUDED



int ValidarCantCaracteres(char* cadena,int cantidad);
void RemoveSpaces(char* source);
int ComparaFrases(char* frase1,char* frase2);
void ShowMenu(char *opcion);
int ingresarInt (char pregunta[], int minimo,int maximo);
int tools_buscarId(ArrayList* this, int cod);
char Responder(char mensaje[]);
void tools_ShowTitulo(char titulo[]);


#endif // TOOLS_INCLUDED

