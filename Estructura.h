#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "genericas.h"

#define MASACARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n]\n"
#define CANTIDAD_CAMPOS_ARCHIVO 4
#define TIENE_ENCABEZADO_ARCHIVO 1

typedef struct{
    //letra,nombre,vocal,consonante
    char letra;
    char Nombre[21];
    int vocal;
    int consonante;
}ELetra;


ELetra* nuevo(void);
int ELetra_setLetra(ELetra* this, char *dato);
int ELetra_setNombre(ELetra* this, const char* dato);
int ELetra_setVocal(ELetra* this, int dato);
int ELetra_setConsonante(ELetra* this, int dato);

int Muestra1Record(ELetra * record);

int cargarDesdeArchivo(const char* nombreArchivo, ArrayList* this);
int parserEstructura(FILE* pFile, ArrayList* this);

//#------- sin revizar ----#
/*

int compara_elementos_Estructura(void* pElementA,void* pElementB);



int Alumno_setEdad(EAlumno* this, int dato);
int Alumno_setLegajo(EAlumno* this, int dato);
//int Alumno_setSexo(EAlumno* this, char dato);
int Alumno_setSexo(EAlumno* this,  char *dato);
int Alumno_setName(EAlumno* this, const char* name);


int funcionQueFiltra(void* item);
*/

