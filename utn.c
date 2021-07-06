#include "utn.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int todoOk = 0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<= maximo && reintentos>=0) // valido los parametros que recibo
    {
        do
        {
            printf("%s", mensaje);

            if(scanf("%d", &bufferInt)==1)
            {
                if(bufferInt>=minimo && bufferInt<=maximo)
                {
                    *pResultado = bufferInt;
                    todoOk=1;
                    break;
                }
            }
            fflush(stdin);

            printf("%s", mensajeError);
            reintentos--;


        }while(reintentos>=0);
    }
    return todoOk;

}

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    float buffer;
    int todoOk = 0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<= maximo && reintentos>=0) // valido los parametros que recibo
    {
        do
        {
            printf("%s", mensaje);

            if(scanf("%f", &buffer)==1)
            {
                if(buffer>=minimo && buffer<=maximo)
                {
                    *pResultado = buffer;
                    todoOk=1;
                    break;
                }
            }
            fflush(stdin);

            printf("%s", mensajeError);
            reintentos--;


        }while(reintentos>=0);
    }
    return todoOk;

}



int utn_esNumerica(char cadena[])
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen (cadena) > 0)
    {
        while(cadena[i] != '\0' )
        {
            if(cadena[i] < '0' || cadena[i] > '9' )//pregunta si alguno de los elementos no cumplen con la condicion
            {
                retorno = 0;
                break ;
            }
            i++;
        }
    }
    return retorno;
}
int utn_getStringNumerica(char input[], char mensaje[], char mensajeError[], int reintentos)
{
    char aux[256];
    int todoOk=0;

    do{
        printf("%s", mensaje);
        fflush(stdin);
        gets(aux);
        if(utn_esNumerica(aux))
        {
            strcpy(input,aux);
            todoOk=1;
            break;
        }
        else
        {
            printf("%s", mensajeError);
            reintentos--;
        }
    }while(reintentos>=0);


    return todoOk;
}

int utn_esSoloLetras(char cadena[])
{
   int i=0;
   int retorno =1;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
       {
           retorno= 0;
           break;
       }

       i++;
   }
   return retorno;
}


int utn_getStringLetras(char input[], char mensaje[], char mensajeError[], int reintentos)
{
    char aux[256];
    int todoOk=0;

    do{
        printf("%s", mensaje);
        fflush(stdin);
        gets(aux);
        if(utn_esSoloLetras(aux))
        {
            strcpy(input,aux);
            todoOk=1;
            break;
        }
        else
        {
            printf("%s", mensajeError);
            reintentos--;
        }
    }while(reintentos>=0);


    return todoOk;
}

int utn_getStringNombre(char input[], char mensaje[], char mensajeError[], int tam, int reintentos)
{
    char aux[256];
    int todoOk=0;


    if(input!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0 && reintentos>0)
    {

        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(aux);
            if(utn_esSoloLetras(aux) && strlen(aux)<=tam)
            {
                strlwr(aux);
                aux[0]=toupper(aux[0]);
                for(int i=0; aux[i] !='\0'; i++)
                {
                    if(aux[i]== ' ')
                    {
                        aux[i+1] = toupper(aux[i+1]);//convierto a mayuscula el caracter siguiente al indice
                    }
                }
                strcpy(input,aux);

                todoOk=1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);



    }

    return todoOk;
}


int utn_getGenero(char* pResultado, char mensaje[])
{
    int todoOk=0;
    char buffer;


        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &buffer);

            while(buffer!='f' && buffer!='m' && buffer!='o')
            {
                printf("Error. Ingrese f (femenino), m (masculino), o (otro): ");
                fflush(stdin);
                scanf("%c",&buffer);
            }
                *pResultado = buffer;
                todoOk=1;




    return todoOk;
}



int utn_esTelefono(char cadena[])
{
   int i=0;
   int retorno=1;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] != '-') && (cadena[i] != '+') && (cadena[i] < '0' || cadena[i] > '9' ))
       {
           retorno = 0;
           break;
       }

    return retorno;
    }
}

int utn_getTelefono(char input[], char mensaje[], char mensajeError[], int tam, int reintentos)
{
    char tel[30];
    int todoOk=0;

    if(input!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0 && reintentos>0)
    {

        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(tel);
            if(utn_esTelefono(tel) && strlen(tel)<=tam)
            {

                strcpy(input,tel);
                todoOk= 1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }

    return todoOk;
}





