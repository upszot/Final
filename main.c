#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "ArrayList_complemento.h"
#include "Estructura.h"
#include "genericas.h"


#define NOMBRE_ARCHIVO "datos.csv"

#define ARCHIVO_COMPLETO "Completo.csv"
#define ARCHIVO_REPETIDO "repetido.csv"
#define ARCHIVO_DEPURADO "depurado.csv"

#define PAGINADO 10



int main()
{
    ArrayList *List;
    List= al_newArrayList();

    ArrayList *ListLetrasIN;
    ListLetrasIN= al_newArrayList();

    ArrayList *ListLetrasOUT;
    ListLetrasOUT= al_newArrayList();

    ArrayList *ListTemp;
    ListTemp= al_newArrayList();

    char * cadena;

    char seguir='s';
    int opcion=0;
    int Error=-9;

    if(List!=NULL && ListTemp!=NULL && cadena!=NULL)
    {
        Error=0;
    }

    if(Error==0)
    {
        do
        {
            menu(   "\n 1. Parse del archivo CVS"
                    "\n 2. Completar campos (vocal,consonante)"
                    "\n 3. Generar Arrays"
                    "\n 4. Generar archivos"
                    "\n 5. Listar datos.cvs"
                    "\n 6. Listar arrays punto 3"
                );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error = cargarDesdeArchivo(NOMBRE_ARCHIVO, List);
                    break;
                case 2:
                    Error = al_CompletaCampo(List,completa_vocal_consonante );
                    //int completa_vocal_consonante(ELetra * record)
                    /*
//                    ListAlumno->sort(compara_elementos_Estructura,1)
                    ListTemp= clonaOrdenado(ListAlumno,compara_elementos_Estructura,1);
                    if(ListTemp!=NULL)
                    {
                        Error=al_MuestraElemento_desde_hasta(ListTemp,"Alumnos Ordenados por Edad",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);
                    }
                    */
                    break;
                case 3://
                    //Error=al_MuestraElemento_desde_hasta(List,"Original  datos.cvs ",Muestra1Record ,0,List->len(List),PAGINADO);
                    cadena=get_char("Ingrese cadenade caracteres",100);
                    //printf("\n Cadena: %s\n",cadena);

                    Error= parserEstructuraCadena(cadena,100, ListTemp);
                    Error = al_CompletaCampo(ListTemp,completa_vocal_consonante );


                    system("pause");
                    break;
                case 4:
                    /*
                        ListTemp= al_filter(ListAlumno ,funcionQueFiltra);
                        Error=al_MuestraElemento_desde_hasta(ListTemp,"Alumnos Filtrado por Edad",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);
                        */
                    break;
                case 5://LISTAR
                    Error=al_MuestraElemento_desde_hasta(List,"Original  datos.cvs ",Muestra1Record ,0,List->len(List),PAGINADO);
                    break;
                case 6:

                    //al_sort(ListTemp,compara_elementos_Estructura,0);
                    Error=al_MuestraElemento_desde_hasta(ListTemp,"List Cadena",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);


                    ListLetrasIN= al_filter2(List, al_indexOfPotenciado,ListTemp,1);
                    Error=al_MuestraElemento_desde_hasta(ListLetrasIN,"Lista Con Letras Filtrada a partir de ListaCadena",Muestra1Record ,0,ListLetrasIN->len(ListLetrasIN),PAGINADO);

                    ListLetrasOUT= al_filter2(List, al_indexOfPotenciado,ListTemp,0);
                    Error=al_MuestraElemento_desde_hasta(ListLetrasOUT,"Lista SIN Letras Filtrada a partir de ListaCadena",Muestra1Record ,0,ListLetrasOUT->len(ListLetrasOUT),PAGINADO);

                    //ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void* ,void*),ArrayList* listBuscar)
                    //ListLetrasOUT

                    //compara_elementos_Estructura
                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
                    break;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }
        }while(seguir=='s');
    }
    else
    {
        sms_error(-1,Error);
    }//FIN if(Error==0)

    return Error;
}//int main()
