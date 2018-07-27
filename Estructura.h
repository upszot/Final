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

#------- sin revizar ----#
int Muestra1Record(EAlumno * record);
int compara_elementos_Estructura(void* pElementA,void* pElementB);


int cargarDesdeArchivo(const char* nombreArchivo, ArrayList* this);

int parserEstructura(FILE* pFile, ArrayList* this);
int Alumno_setEdad(EAlumno* this, int dato);
int Alumno_setLegajo(EAlumno* this, int dato);
//int Alumno_setSexo(EAlumno* this, char dato);
int Alumno_setSexo(EAlumno* this,  char *dato);
int Alumno_setName(EAlumno* this, const char* name);


int funcionQueFiltra(void* item);
