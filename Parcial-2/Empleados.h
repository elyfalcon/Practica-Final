#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    float sueldo;
    char nombre[20];
    char direccion[25];
    int horas;
}eEmpleado;


int cargarDesdeArchivo(ArrayList *this,const char* nombre);
int ComparaNombre(void* eEmpleadoA,void* eEmpleadoB);
ArrayList* ListarPorNombre(ArrayList *this,int orden);
void MostrarElementos(ArrayList *this,char titulo[],int desde, int hasta);
void MostrarElementosId(ArrayList *this,char titulo[],int desde, int hasta);
int CalculaSalario(ArrayList *this);
int CalcularSalary(eEmpleado* element);
int comparaEmpleado(void* eEmpleadoA,void* eEmpleadoB);
int compara_elementos_Estructura(void* pElementA,void* pElementB);
ArrayList* ListarPorSalario(ArrayList *this,int orden);





#endif // EMPLEADOS_H_INCLUDED
