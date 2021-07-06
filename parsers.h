#ifndef PARSERS_H_INCLUDED
#define PARSERS_H_INCLUDED
#include "LinkedList.h"



#endif // PARSERS_H_INCLUDED


/** \brief funcion que abre un archivo de texto en modo lectura y llama al parser
 *
 * \param path char*   direccion del archivo a escribir
 * \param lista LinkedList*    lista que recorre
 * \return int      devuelve 1 si funciona correctamente y 0 sino
 *
 */
int cargarDesdeTexto(char* path, LinkedList* lista);

/** \brief funcion que analiza el texto del archivo y lo almacena en una estructura para añadirla al linkedlist
 *
 * \param pFile FILE*     puntero al archivo que se analiza
 * \param lista LinkedList*    lista donce se agregan las estructuras
 * \return int      devuelve 1 si se agregan las estructuras correctamente
 *
 */
int parserTexto(FILE* pFile, LinkedList* lista);

/** \brief funcion que almacena los datos del programa en un archivo .csv
 *
 * \param path char*     direccion del archivo a guardar
 * \param lista LinkedList*    lista de la que se obtiene la informacion
 * \return int    devuelve 1 si se cargan los datos en el archivo
 *
 */
int escribirArchivoTexto(char* path, LinkedList* lista);
