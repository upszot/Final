#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "ArrayList_complemento.h"
#include "Estructura.h"
#include "genericas.h"

ELetra* nuevo(void)
{
    ELetra* returnAux;
    returnAux = (ELetra*)malloc(sizeof(ELetra));
    return returnAux;
}

//-------- SETERS ----------//
int ELetra_setLetra(ELetra* this, char *dato)
{
    this->letra=dato[0];
    return 0;
}

int ELetra_setNombre(ELetra* this, const char* dato)
{
    strcpy(this->Nombre, dato);
    return 0;
}

int ELetra_setVocal(ELetra* this, int dato)
{
    this->vocal = dato;
    return 0;
}

int ELetra_setConsonante(ELetra* this, int dato)
{
    this->consonante = dato;
    return 0;
}
// --------- GETERS -------------------
char ELetra_getLetra(void * record)
{
    ELetra *tmp_1;
    tmp_1=(ELetra * ) record;

    return tmp_1->letra;
}

// ---------------------------------------

int Muestra1Record(ELetra * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf("letra: %c  \t",record->letra);
        printf("Nombre: %s        \t\t",record->Nombre);
        printf("vocal: %d     \t",record->vocal);
        printf("consonante: %d    \n",record->consonante);
    }
    return retorno;
}

int completa_vocal_consonante(ELetra * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        //  si es vocal (1) o consonante (0), devuelve (-1) si hay error
        if( isVocal(ELetra_getLetra(record) ) ==1 )
        {
            retorno= ELetra_setVocal(record, 1);
        }

        if( isVocal(ELetra_getLetra(record) ) ==0 )
        {
            retorno= ELetra_setConsonante(record, 1);
        }
    }
    //system("pause");
    return retorno;
}

// -------- ARCHIVOS -------------
int parserEstructura(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    int agregoRecord;
    char cabecera[80];
    int guardoDato;

    ELetra* record;

    char campo1[30];
    char campo2[30];
    char campo3[30];
    char campo4[30];

    if(pFile != NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO_ARCHIVO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo();
            if(record != NULL)
            {
                cantidadDatosLeidos = fscanf(pFile,MASACARA_ARCHIVO,campo1,campo2,campo3,campo4);
                if(cantidadDatosLeidos == CANTIDAD_CAMPOS_ARCHIVO)
                {////letra,nombre,vocal,consonante

                    guardoDato = ELetra_setLetra(record,(char*) campo1);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = ELetra_setNombre(record,(char*) campo2);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = ELetra_setVocal(record, charToint(campo3) );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = ELetra_setConsonante(record, charToint(campo4) );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    agregoRecord = al_add(this, record);
                    if(agregoRecord < 0) //Hubo error
                    {
                        break;
                    }

                    cantidadFilasLeidas++;
                }
                else //Fin de archivo u otro error
                {
                    break;
                }
            }
            else //Sin memoria
            {
                break;
            }
        }
    }

    return retorno;
}



int cargarDesdeArchivo(const char* nombreArchivo, ArrayList* this)
{
    FILE* archivo;
    int retorno = -1;
    int parseoArchivo;
    int cerroArchivo;

    archivo = fopen(nombreArchivo, "r");
    if(archivo != NULL)
    {
        retorno = -2;
        if(parserEstructura(archivo, this)==0)
        {
            retorno = -3;
            if(fclose(archivo)==0)
            {
                retorno = 0;
            }
        }
    }//FIN if(archivo != NULL)

    return retorno;
}


int parserEstructuraCadena(char* cadena,int LongitudCadena, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    int agregoRecord;
    char cabecera[80];
    int guardoDato;

    ELetra* record;

    char campo1[30];

    if(cadena != NULL)
    {
        retorno = -2;


        for(int i=0;i<LongitudCadena;i++)
        //while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo();
            if(record != NULL)
            {
                if( cadena[i] != '\0' )
                {
                    campo1[0]=cadena[i];
                    campo1[1]='\0';
                    guardoDato = ELetra_setLetra(record,(char*) campo1);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = ELetra_setNombre(record,(char*) campo1);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = ELetra_setVocal(record, 0 );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = ELetra_setConsonante(record, 0 );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    agregoRecord = al_add(this, record);
                    if(agregoRecord < 0) //Hubo error
                    {
                        break;
                    }

                    cantidadFilasLeidas++;
                }
                else //Fin de archivo u otro error
                {
                    break;
                }
            }
            else //Sin memoria
            {
                break;
            }
        }
    }

    return retorno;
}

int compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno;
    ELetra *tmp_1;
    ELetra *tmp_2;
    tmp_1=(ELetra * ) pElementA;
    tmp_2=(ELetra * ) pElementB;

    if(tmp_1->letra > tmp_2->letra)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->letra == tmp_2->letra)
        {
            retorno=0;
        }

    }
    return retorno;
}


// ------------------------

int al_indexOfPotenciado(void* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && pElement!=NULL)
    {
        ArrayList *Aux_List;
        Aux_List= (ArrayList*)  this;

        ELetra *tmp_1;
        tmp_1=(ELetra * ) pElement;
        ELetra *Aux;

        for(int i=0;i < al_len(Aux_List) ;i++)
        {
            Aux= (ELetra * ) al_get(Aux_List,i);

            if( (char)  Aux->letra ==  tmp_1->letra)
            {//encontro
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}

/*
int funcionQueFiltra(void* item, ArrayList* this)
{
    int retorno=0;
    ELetra *tmp_1;
    tmp_1=(ELetra * ) item;

    //busco en array this el campo letra del item..
    int al_CompletaCampo(ArrayList *this,int (*pFunc)(void*) );
    if( tmp_1->letra  )
    //if(get_Edad(tmp_1) > 30 )
    {
        retorno=1;
    }
    return retorno ;
}
*/


