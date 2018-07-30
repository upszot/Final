#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Estructura.h"
#include "genericas.h"
#include "ArrayList_complemento.h"

//int al_indexOfPotenciado(ArrayList* this, void* pElement)

ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void*))
{
    ArrayList *ListaTemp=NULL;
    ListaTemp= al_newArrayList();

    if(listIn!=NULL && functionFilter!=NULL && ListaTemp!=NULL)
    {
        for(int i=0;i<listIn->len(listIn);i++)
        {
                if( functionFilter(listIn->get(listIn,i) )==1  )
                {
                    ListaTemp->add(ListaTemp,listIn->get(listIn,i) );
                }
        }
        return ListaTemp;
    }
}

ArrayList* al_filter2(ArrayList* listIn , int (*functionFilter)(void* ,void*),ArrayList* listBuscar,int Existe)
{
    ArrayList *ListaTemp=NULL;
    ListaTemp= al_newArrayList();

    if(listIn!=NULL && functionFilter!=NULL && ListaTemp!=NULL && listBuscar!=NULL && ( Existe==0 || Existe==1 ))
    {
        for(int i=0;i<listIn->len(listIn);i++)
        {
                if( functionFilter(listBuscar,listIn->get(listIn,i) )== Existe )
                {
                    ListaTemp->add(ListaTemp,listIn->get(listIn,i) );
                }
        }
        return ListaTemp;
    }
}

ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden)
{
    ArrayList *ListaOrdenada=NULL;
    if(this!=NULL)
    {
        ListaOrdenada = al_newArrayList();
        ListaOrdenada=al_clone(this);
        if(ListaOrdenada!=NULL)
        {
            //if(ListaOrdenada->sort(ListaOrdenada,compara_elementos_Estructura,1)==-1)
            if(ListaOrdenada->sort(ListaOrdenada,pFunc,1)==-1)
            {
                ListaOrdenada=NULL;
            }
        }
    }
    return ListaOrdenada;
}


int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int cont=0;
    if(this!=NULL && Titulo!=NULL)
    {
        retorno=0;
        system("cls");
        printf("\n\n-------- %s --------\n",Titulo);
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(int index=desde;index<hasta;index++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                    printf("\n\n-------- %s --------\n",Titulo);
                }
                pFunc(al_get(this,index));
                cont++;
            }

            if(cont!=0)
            {//pausa la ultima tanda de elementos mostrados
                system("pause");
            }
        }//if(this->isEmpty(this)==0)
        else
        {//o con error o sin datos a mostrar
            printf("\n Sin Datos a Motrar...\n");
            system("pause");
        }
    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}


int al_CompletaCampo(ArrayList *this,int (*pFunc)(void*) )
{
    int retorno=-1;
    if(this!=NULL )
    {
        retorno=-2;

        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(int index=0; index<this->len(this) ; index++)
            {
                retorno=pFunc(al_get(this,index));

            }
        }//if(this->isEmpty(this)==0)

    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}


ArrayList* Al_EliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
            {
                for(int j=i+1;j < ListAux->len(ListAux) ; )
                {
                    if(pFunc(al_get(ListAux,i),al_get(ListAux,j))==0)
                    {
                      ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        j++;
                    }
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }
    }
    return ListAux;
}



int al_Existen_Letras(ArrayList* listIn , int (*functionFilter)(void* ,void*),char * cadLetras)
{//devuelve 1 si estan todas las letras.. 0 si no estan.

    int retorno=-1;
    ArrayList* ListAux;

    if(listIn!=NULL && functionFilter!=NULL && cadLetras!=NULL )
    {
        ListAux=al_clone(listIn);
        if(ListAux!=NULL)
        {
            retorno=1;

            for(int i=0; i<strlen(cadLetras) || retorno==0 ;i++)
            {
                for(int j=0;j<ListAux->len(ListAux);j++)
                {
                    if( functionFilter(cadLetras[i],ListAux->get(ListAux,j) )== 0 )
                    {//Existe=0    Esta la letra
                        ListAux->pop(ListAux,j);
                        break;
                    }
                    else
                    {//no esta la letra
                        retorno=0;
                        break;
                    }
                }//fin for recorre ArrayList
            }//fin for recorre caracteres string

        }// FIN if(ListAux!=NULL)
    }//FIN if(listIn!=NULL && functionFilter!=NULL && cadLetras!=NULL )
    return retorno;
}
