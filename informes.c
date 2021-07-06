#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paises.h"
#include "informes.h"
#include "LinkedList.h"


///filtrados
///paises con dos dosis mayor a %30
int esExitoso(void* p)
{
    int ok=0;
    ePais* unPais=NULL;

    if(p!=NULL)
    {

        unPais=(ePais*) p;
        if((unPais->vac2dosis)>30)
        {
            ok=1;
        }
    }

    return ok;
}

///paises con no vacunados mayor a vacunados
int estaHorno(void* p)
{
    int ok=0;
    ePais* unPais=NULL;
    int vacunados;
    int noVacunados;


    if(p!=NULL)
    {
        unPais=(ePais*) p;
        vacunados=(unPais->vac1dosis)+(unPais->vac2dosis);
        noVacunados=unPais->sinVacunar;
        if(noVacunados>vacunados)
        {
            ok=1;
        }
    }

    return ok;
}

///compara por 1dosis
int pais_CompareVacunacion(void* a, void* b)
{
    int retorno = -1;
    ePais* p1=NULL;
    ePais* p2=NULL;

    if(a!=NULL && b!=NULL)
    {
        p1= (ePais*) a;
        p2= (ePais*) b;
        if(p1->vac1dosis < p2->vac1dosis)
        {
            retorno=1;
        }else if(p1->vac1dosis > p2->vac1dosis)
        {
            retorno=0;
        }
    }

    return retorno;

}

///paises con mayor cant no vacunados
int masCastigados(LinkedList* lista)
{
    int todoOk=0;
    ePais* aux=NULL;
    int tam=ll_len(lista);
    int acumulador[tam];
    int flag=0;
    int mayor;

    for(int i=0; i<tam; i++)
    {
        acumulador[i]=0;
    }

    if(lista!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            aux=(ePais*) ll_get(lista, i);
            acumulador[i]=aux->sinVacunar;
        }

        for(int i=0; i<tam; i++)
        {
            if(flag==0||acumulador[i]>mayor)
            {
                flag=1;
                mayor=acumulador[i];
            }
        }

        printf("Paises con mayor porcentaje de personas sin vacunar: \n");
         for(int i=0; i<tam; i++)
        {
            if(acumulador[i]==mayor)
            {
                aux=(ePais*) ll_get(lista, i);
                printf("%s    Porcentaje: %d\n", aux->nombre, acumulador[i]);
            }
        }
    todoOk=1;
    }
    return todoOk;
}


