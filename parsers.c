#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsers.h"
#include "LinkedList.h"
#include "paises.h"


///leer archivos

int cargarDesdeTexto(char* path, LinkedList* lista)
{
    int todoOk=0;

    FILE* f = fopen(path, "r");
    if(f==NULL)
    {
        printf("No se puede abrir el archivo\n");
        system("pause");
        exit(1);
    }

    if(parserTexto(f, lista))
    {
        printf("Archivo leido con exito\n");
        todoOk=1;
    }

    fclose(f);
    return todoOk;

}

int parserTexto(FILE* pFile, LinkedList* lista)
{
    char buffer[10][1000];
    int cant;
    int todoOk=0;
    ePais* auxPais=NULL;

    if(pFile!=NULL){


        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        do{
            cant = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            if(cant<5)
            {
                break;
            }

            //creo un pais con el newParametros
            auxPais=pais_newPaisParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            //lo agrego al linkedlist
            if(ll_add(lista, auxPais)==-1)
            {
                printf("No es posible agregar el pais a la lista (add)\n");
                break;
            }
            todoOk=1;



        }while(!feof(pFile));
    }

    return todoOk;
}


///escribir archivo

int escribirArchivoTexto(char* path, LinkedList* lista)
{
    ///escribir un archivo de texto
    ePais* auxPais;
    int auxId;
    char auxNombre[60];
    int auxvac1dosis;
    int auxvac2dosis;
    int auxsinVacunar;
    char confirm='s';
    int todoOk=0;

    FILE* f = fopen(path, "w");
    if(f==NULL)
    {
        printf("No se puede escribir el archivo");
    }
    else
    {
            fprintf(f, "ID, NOMBRE, PRIMERA DOSIS, SEGUNDA DOSIS, SIN VACUNAR\n");

            for(int i=0; i<ll_len(lista); i++)
            {
                auxPais=ll_get(lista, i);
                if(pais_getId(auxPais, &auxId)&&
                        pais_getNombre(auxPais, auxNombre)&&
                        pais_getVac1dosis(auxPais, &auxvac1dosis) &&
                        pais_getVac2dosis(auxPais, &auxvac2dosis) &&
                        pais_getSinVacunar(auxPais, &auxsinVacunar))
                {
                    fprintf(f, "%d, %s, %d, %d, %d\n", auxId, auxNombre, auxvac1dosis, auxvac2dosis, auxsinVacunar);
                }
            }
            todoOk=1;

    }
    fclose(f);
    return todoOk;
}
