#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
#include "LinkedList.h"

typedef struct{

    int id;
    char nombre[51];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

}ePais;

void menu();

///getters y setters

int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setVac1dosis(ePais* this,int vac1dosis);
int pais_getVac1dosis(ePais* this,int* vac1dosis);
int pais_setVac2dosis(ePais* this,int vac2dosis);
int pais_getVac2dosis(ePais* this,int* vac2dosis);
int pais_setSinVacunar(ePais* this,int sinVacunar);
int pais_getSinVacunar(ePais* this,int* sinVacunar);



/** \brief funcion que pide memoria para una estructura y le carga los datos pasados por parametro con los setters
 *
 * \param id char*
 * \param nombre char*
 * \param vac1dosis char*
 * \param vac2dosis char*
 * \param sinVacunar char*
 * \return ePais*              devuelve un puntero a la estructura creada con sus datos cargados
 *
 */
ePais* pais_newPaisParametros(char* id, char* nombre, char* vac1dosis, char* vac2dosis, char* sinVacunar);

/** \brief funcion que muestra el contenido de una estructura ePais
 *
 * \param p ePais*     puntero a estructura que se imprime
 * \return int         devuelve 1 si se muestra correctamente
 *
 */
int mostrarPais(ePais* p);


/** \brief     funcion que muestra todas las estructuras cargadas en una lista
 *
 * \param lista LinkedList*     lista que se muestra
 * \return int
 *
 */
int listarPaises(LinkedList* lista);


/** \brief funcion para utilizar en ll_map para asignar valores a cada pais. Asigna un valor random entre cierto margen a las dosis 1 y dos y el resto hasta el 100 a no vacunados
 *
 * \param p void*
 * \return void*  devuelve una estructura con datos cargados
 *
 */
void* asignarValores(void* p);

#endif // PAISES_H_INCLUDED
