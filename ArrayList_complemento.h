#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "genericas.h"

int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);
ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden);
ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void*));

