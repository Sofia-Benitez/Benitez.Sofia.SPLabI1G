#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED



/** \brief funcion que se utiliza en ll_filter para filtrar los paises con un porcentaje mayor a 30 en dos dosis
 *
 * \param p void*
 * \return int    devuelve 1 si el pais cumple con la condicion
 *
 */
int esExitoso(void* p);

/** \brief funcion que se utiliza en ll_filter para filtrar los paises con una cantidad de no vacunados mayor a la de vacunados
 *
 * \param p void*
 * \return int    devuelve 1 si el pais cumple con la condicion
 *
 */
int estaHorno(void* p);

/** \brief funcion que se utiliza en ll_sort para ordenar los paises segun el porcentaje de vacunacion con 1 dosis
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int pais_CompareVacunacion(void* a, void* b);

/** \brief funcion que busca el o los paises con mayor porcentaje de vacunados y los muestra junto al valor
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int masCastigados(LinkedList* lista);
