#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED




#endif // UTN_H_INCLUDED
/** \brief funcion para pedir un numero entero por consola y validar si es un numero
 *
 * \param pResultado int*   puntero a variable donde se escribe el valor ingresado si es correcto
 * \param mensaje char*    puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param mensajeError char*    puntero a cadena de caracteres con mensaje de error en el caso del que el numero ingresado no sea valido
 * \param minimo int    valor minimo admitido
 * \param maximo int    valor maximo admitido
 * \param reintentos int   cantidad de reintentos para ingresar el numero
 * \return int   devuelve 1 si la funcion es realizada correctamente y 0 si no se realiza
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);



/** \brief funcion para pedir un numero flotante por consola y validar si es un numero
 *
 * \param pResultado int*   puntero a variable donde se escribe el valor ingresado si es correcto
 * \param mensaje char*    puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param mensajeError char*    puntero a cadena de caracteres con mensaje de error en el caso del que el numero ingresado no sea valido
 * \param minimo int    valor minimo admitido
 * \param maximo int    valor maximo admitido
 * \param reintentos int   cantidad de reintentos para ingresar el numero
 * \return int   devuelve 1 si la funcion es realizada correctamente y 0 si no se realiza
 *
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);



/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena[] char cadena a ser analizada
 * \return int  devuelve 1 si la cadena es numerica y 0 si no lo es
 *
 */
int utn_esNumerica(char cadena[]);



/**
 * \brief funcion que Verifica si el valor recibido contiene solo letras
 * \param cadena Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int utn_esSoloLetras(char cadena[]);


/**
 * \brief funcion para pedirle un texto al usuario y almacenarlo
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 *\param mensajeError
 *\param reintentos cantidad de reintentes
 * \return devuleve 1 si el texto contiene solo letras y 0 si no
 */
int utn_getStringLetras(char input[], char mensaje[], char mensajeError[], int reintentos);


/** \brief funcion que pide un texto, pasa la cadena a minuscula y luego pasa las iniciales a mayuscula
 *
 * \param input[] char  Array donde se almacena la cadena obtenida
 * \param mensaje[] char  Mensaje para el usuario
 * \param mensajeError[] char   Mensaje de error para el usuario
 * \param tam int    tamanio del array
 * \param reintentos int
 * \return int   devuleve 1 si toma correctamente la cadena y 0 si no puede hacerlo
 *
 */
int utn_getStringNombre(char input[], char mensaje[], char mensajeError[], int tam, int reintentos);



/** \brief funcion que pide un char 'f', 'm', 'o' y lo almacena
 *
 * \param pResultado char*   puntero a variable donde se escribe el char si es correcto
 * \param mensaje[] char     mensaje para el usuario
 * \return int
 *
 */
int utn_getGenero(char* pResultado, char mensaje[]);

///funcion para pedir y validar fecha


/** \brief
 *
 * \param cadena[] char   array con la cadena a ser analizada
 * \return int
 *  devuelve 1 si contiene solo numeros, espacios y un guion
 */
int utn_esTelefono(char cadena[]);

int utn_getTelefono(char input[], char mensaje[], char mensajeError[], int tam, int reintentos);

int utn_getStringNumerica(char input[], char mensaje[], char mensajeError[], int reintentos);
