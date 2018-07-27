#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
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

// ----------------------------

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



/*
int funcionQueFiltra(void* item)
{
    int retorno=0;
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) item;

    if(get_Edad(tmp_1) > 30 )
    {
        retorno=1;
    }
    return retorno ;
}


int Alumno_setEdad(EAlumno* this, int dato)
{
    this->Edad = dato;
    return 0;
}

int Alumno_setLegajo(EAlumno* this, int dato)
{
    this->Legajo = dato;
    return 0;
}

int Alumno_setSexo(EAlumno* this,  char *dato)
{
    strcpy(this->Sexo,dato);
    return 0;
}


int Alumno_setName(EAlumno* this, const char* name)
{
    strcpy(this->Nombre, name);
    return 0;
}

int get_Edad(EAlumno * record)
{
    int retorno;
    retorno =record->Edad;
    return retorno;
}

int get_Legajo(void * record)
{
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) record;
    return tmp_1->Legajo;
}

char *get_Nombre(void * record)
{
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) record;

    return tmp_1->Nombre;
}

char get_Sexo(void * record)
{
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) record;

    return tmp_1->Sexo;
}


int Muestra1Record(ELetra * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf("Nombre: %s    \t\t",record->Nombre);
        printf("Edad: %d \t",record->Edad);
        printf("Legajo: %d \t",record->Legajo);
        printf("Sexo: %s \n",record->Sexo);
    }
    return retorno;
}

int compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno;
    EAlumno *tmp_1;
    EAlumno *tmp_2;
    tmp_1=(EAlumno * ) pElementA;
    tmp_2=(EAlumno * ) pElementB;

    if(tmp_1->Edad > tmp_2->Edad)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->Edad == tmp_2->Edad)
        {
            retorno=0;
        }

    }
    return retorno;
}
*/
