#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "genericas.h"

/** \brief Recorre arrayList desde posicion desde, hasta la posicion hasta
 *          paginando cada el valor que se le pasa..
 *          y usando la funcion que se le pasa para mostrar...
 *          dicha funcion es la que muestra los datos de 1 solo elemento
 *
 * \param void*
 * \return int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int
 *
 */
int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);


/** \brief Clona array y ordena por funcion
 *
 * \param void*
 * \param void*
 * \return ArrayList* clonaOrdenado(ArrayList *this,int
 *
 */
ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden);


/** \brief Devuelve un Nuevo ArrayList solamente con los elementos del Array original filtrada por la funcion
 *
 * \param void*
 * \return ArrayList* al_filter(ArrayList* listIn , int
 *
 */
ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void*));


/** \brief Devuelve un nuevo Array generado a partir del filtro de la funcion entregada
 *          y el los elementos cargados en el listbuscar
 *          El parametro Existe  determina si el nuevo array debe contener los datos encontrados o la inversa
 *
 * \param void*
 * \param void*
 * \return ArrayList* al_filter2(ArrayList* listIn , int
 *
 */
ArrayList* al_filter2(ArrayList* listIn , int (*functionFilter)(void* ,void*),ArrayList* listBuscar,int Existe);

/** \brief Recorre ArrayList y entrega cada recorset a la funcion para que trabaje
 *
 * \param void*
 * \return int al_CompletaCampo(ArrayList *this,int
 *
 */
int al_CompletaCampo(ArrayList *this,int (*pFunc)(void*) );
