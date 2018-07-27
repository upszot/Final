#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "genericas.h"

int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);
ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden);


/** \brief Devuelve un Nuevo ArrayList solamente con los elementos del Array original filtrada por la funcion
 *
 * \param void*
 * \return ArrayList* al_filter(ArrayList* listIn , int
 *
 */
ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void*));


ArrayList* al_filter2(ArrayList* listIn , int (*functionFilter)(void* ,void*),ArrayList* listBuscar);

/** \brief Recorre ArrayList y entrega cada recorset a la funcion para que trabaje
 *
 * \param void*
 * \return int al_CompletaCampo(ArrayList *this,int
 *
 */
int al_CompletaCampo(ArrayList *this,int (*pFunc)(void*) );
