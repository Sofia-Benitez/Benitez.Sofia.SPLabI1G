#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "LinkedList.h"
#include "utn.h"
#include "paises.h"
#include "parsers.h"
#include "informes.h"

int main()
{
    srand(time(NULL));
    int opcion;
    char path[100];
    int len;
    int flagMap=0;

    ///instancio un linkedlist
    LinkedList* lista = ll_newLinkedList();
    if(lista==NULL)
    {
        printf("No se pudo crear la lista\n");
        exit(1);
    }

    ///intancio LL para las nuevas listas
    LinkedList* mapeados=NULL;
    LinkedList* exitosos=NULL;
    LinkedList* alHorno=NULL;

    do{
        system("cls");
        menu();
        utn_getNumero(&opcion, "Ingrese una opcion: ", "Error. Ingrese una opcion: ", 1, 8, 3);

        switch(opcion)
        {
        case 1:

            ///cargar archivo csv y agregar al LL
            len=ll_len(lista);
            printf("Cantidad de elementos en la lista: %d\n",len);

            printf("Ingrese path (.csv): ");
            fflush(stdin);
            gets(path);

            if(cargarDesdeTexto(path, lista))
            {
                printf("Arhivo leido\n");
            }
            else
            {
                printf("No es posible abrir el archivo\n");
            }

            len=ll_len(lista);
            printf("Cantidad de elementos en la lista: %d\n",len);

            listarPaises(lista);

            break;
        case 2:
            ///mostrar

            if(flagMap==1)
            {
                listarPaises(mapeados);
            }
            else
            {
                printf("Primero se deben asignar las estadisticas\n");
            }

            break;
        case 3:
            ///asignar estadisticas

            mapeados = ll_map(lista, asignarValores);
            if(mapeados!=NULL)
            {
                printf("Estadisticas asignadas con exito\n");
                flagMap=1;
                ll_deleteLinkedList(lista);
            }
            else
            {
                printf("Error al cargar los datos\n");
            }


            break;
        case 4:

            if(flagMap==1)
            {
                exitosos = ll_filter(mapeados, esExitoso);
                if(exitosos!=NULL)
                {
                    printf("Ingrese path para guardar el archivo (.csv): ");
                    fflush(stdin);
                    gets(path);

                    if(escribirArchivoTexto(path, exitosos))
                    {
                        printf("Archivo guardado con exito\n");
                    }
                    else
                    {
                        printf("Error. No se pudo guardar el archivo\n");
                    }
                }

            }
            else
            {
                printf("Primero se deben asignar las estadisticas\n");
            }


            break;
        case 5:

            if(flagMap==1)
            {

                alHorno = ll_filter(lista, estaHorno);
                if(alHorno!=NULL)
                {
                    printf("Ingrese path para guardar el archivo (.csv): ");
                    fflush(stdin);
                    gets(path);

                    if(escribirArchivoTexto(path, alHorno))
                    {
                        printf("Archivo guardado con exito\n");
                    }
                    else
                    {
                        printf("Error. No se pudo guardar el archivo\n");
                    }
                }

            }
            else
            {
                printf("Primero se deben asignar las estadisticas\n");
            }

            break;
        case 6:
                ///ordenar por nivel de vacunacion 1 dosis descendente

                if(flagMap==1)
                {

                    ll_sort(mapeados, pais_CompareVacunacion, 1);
                    listarPaises(mapeados);

                }
                else
                {
                    printf("Primero se deben asignar las estadisticas\n");
                }

            break;
         case 7:
             ///pais o paises con mayor porcentaje de no vacunados y numero

             if(flagMap==1)
             {
                 masCastigados(mapeados);
             }
             else
             {
                printf("Primero se deben asignar las estadisticas\n");
             }

            break;
        case 8:
            printf("Salir\n");
            break;
        }


        system("pause");
    }while(opcion!=8);

    return 0;
}
