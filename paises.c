#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paises.h"
#include "LinkedList.h"


void menu()
{
    printf("********          Menu       *************\n");
    printf(" 1.        Cargar archivo           \n");
    printf(" 2.        Imprimir lista           \n");
    printf(" 3.        Asignar estadisticas     \n");
    printf(" 4.        Filtrar paises exitosos         \n");
    printf(" 5.        Filtrar por paises en el horno  \n");
    printf(" 6.      Ordenar por nivel de vacunacion  \n");
    printf(" 7.     Mostrar mas castigado      \n");
    printf(" 8.              Salir                      \n");
    printf("******************************************\n");

}

int pais_setId(ePais* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
        this->id = id;
        todoOk=1;
    }
    return todoOk;
}
int pais_getId(ePais* this,int* id)
{
    int todoOk=0;
    if(id!=NULL && this!=NULL)
    {
        *id = this->id;///obtengo el dato de legajo y lo guardo en la direccion de memoria del puntero a legajo
        todoOk=1;
    }
    return todoOk;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre!=NULL  && strlen(nombre)>0 && strlen(nombre)<50)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}
int pais_getNombre(ePais* this,char* nombre)
{
    int todoOk=0;
    if(nombre!=NULL && this!=NULL)
    {
       strcpy(nombre, this->nombre);
        todoOk=1;
    }
    return todoOk;
}

int pais_setVac1dosis(ePais* this,int vac1dosis)
{
    int todoOk=0;
    if(this!=NULL && vac1dosis>=0)
    {
        this->vac1dosis = vac1dosis;
        todoOk=1;
    }
    return todoOk;
}
int pais_getVac1dosis(ePais* this,int* vac1dosis)
{
    int todoOk=0;
    if(vac1dosis!=NULL && this!=NULL)
    {
        *vac1dosis = this->vac1dosis;///obtengo el dato de legajo y lo guardo en la direccion de memoria del puntero a legajo
        todoOk=1;
    }
    return todoOk;
}

int pais_setVac2dosis(ePais* this,int vac2dosis)
{
    int todoOk=0;
    if(this!=NULL && vac2dosis>=0)
    {
        this->vac2dosis = vac2dosis;
        todoOk=1;
    }
    return todoOk;
}
int pais_getVac2dosis(ePais* this,int* vac2dosis)
{
    int todoOk=0;
    if(vac2dosis!=NULL && this!=NULL)
    {
        *vac2dosis = this->vac2dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_setSinVacunar(ePais* this,int sinVacunar)
{
    int todoOk=0;
    if(this!=NULL && sinVacunar>=0)
    {
        this->sinVacunar = sinVacunar;
        todoOk=1;
    }
    return todoOk;
}
int pais_getSinVacunar(ePais* this,int* sinVacunar)
{
    int todoOk=0;
    if(sinVacunar!=NULL && this!=NULL)
    {
        *sinVacunar = this->sinVacunar;
        todoOk=1;
    }
    return todoOk;
}


ePais* pais_newPaisParametros(char* id, char* nombre, char* vac1dosis, char* vac2dosis, char* sinVacunar)
{
    ePais* newPais=NULL;

    ///pido lugar en memoria para un nuevo pais
    newPais = (ePais*) malloc(sizeof(ePais));

    //cargo los datos que se pasan en la funcion con los setters
         if(!(pais_setId(newPais, atoi(id)) &&
         pais_setNombre(newPais, nombre) &&
         pais_setVac1dosis(newPais, atoi(vac1dosis)) &&
         pais_setVac2dosis(newPais, atoi(vac2dosis)) &&
         pais_setSinVacunar(newPais, atoi(sinVacunar))))
       {
            free(newPais);
            newPais=NULL;
            printf("los datos del pais no se cargaron\n");
       }

    return newPais;
}

//imprimir

int mostrarPais(ePais* p)
{
    int todoOk=0;
    int id;
    char nombre[50];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;


    if(p!=NULL)
    {
        if(pais_getId(p, &id)&& pais_getNombre(p, nombre)&& pais_getVac1dosis(p, &vac1dosis)&& pais_getVac2dosis(p, &vac2dosis)&& pais_getSinVacunar(p, &sinVacunar))
        {
            printf("  %2d              %.20s               %d                  %d                %d    \n", id, nombre, vac1dosis, vac2dosis,  sinVacunar);

        }else
        {
            printf("No se puede mostrar el pais\n");
        }
        todoOk=1;
    }

    return todoOk;
}

int listarPaises(LinkedList* lista)
{
    int todoOk=0;
    int len;
    if(lista!=NULL)
    {
        len=ll_len(lista);
        if(len>0)
        {
            printf("  ID               NOMBRE          PRIMERA DOSIS        SEGUNDA DOSIS         SIN VACUNAR \n");
            for(int i=0; i<len; i++)
            {
                mostrarPais((ePais*) ll_get(lista, i));
            }
            todoOk=1;
        }
    }
    return todoOk;
}


void* asignarValores(void* p)
{

    ePais* unPais=NULL;
    int vac1dosisRand;
    int vac2dosisRand;
    int sinVacunar;

    unPais=(ePais*) p;

    ///rand() % (max-min+1) + min
    vac1dosisRand=rand() % 58 + 1;///entre 1 y 60
    vac2dosisRand=rand() %  38 + 1;///entre 1 y 40
    sinVacunar= 100 - (vac1dosisRand+vac2dosisRand);///lo que queda hasta 100

    unPais->vac1dosis=vac1dosisRand;

    unPais->vac2dosis=vac2dosisRand;

    unPais->sinVacunar=sinVacunar;

    return unPais;
}
