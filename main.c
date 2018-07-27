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

    ArrayList *ListTemp;
    ListTemp= al_newArrayList();

    char seguir='s';
    int opcion=0;
    int Error=-9;

    if(List!=NULL && ListTemp!=NULL)
    {
        Error=0;
    }

    if(Error==0)
    {
        do
        {
            menu(   "\n 1. Parse del archivo CVS"
                    "\n 2. Completar campos (vocal,consonante)"
                    "\n 3. Listar"
                    "\n 4. Generar archivos"
                );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error = cargarDesdeArchivo(NOMBRE_ARCHIVO, List);
                    break;
                case 2:
                    /*
//                    ListAlumno->sort(compara_elementos_Estructura,1)
                    ListTemp= clonaOrdenado(ListAlumno,compara_elementos_Estructura,1);
                    if(ListTemp!=NULL)
                    {
                        Error=al_MuestraElemento_desde_hasta(ListTemp,"Alumnos Ordenados por Edad",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);
                    }
                    */
                    break;
                case 3://LISTAR
                    Error=al_MuestraElemento_desde_hasta(List,"Original  datos.cvs ",Muestra1Record ,0,List->len(List),PAGINADO);
                    break;
                case 4:
                    /*
                        ListTemp= al_filter(ListAlumno ,funcionQueFiltra);
                        Error=al_MuestraElemento_desde_hasta(ListTemp,"Alumnos Filtrado por Edad",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);
                        */
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
