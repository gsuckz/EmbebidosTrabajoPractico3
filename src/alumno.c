#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANO 100

struct alumno_s {
    char apellido[TAMANO];
    char nombre[TAMANO];
    uint32_t documento;
    //   bool ocupado;             //otra forma
};

static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

// static struct alumno_s instancias[50] = {0}; //50 huecos              //otra forma

alumno_t CrearAlumno(char * apellido, char * nombre, int documento) {
    alumno_t resultado =
        malloc(sizeof(struct alumno_s)); // Malloc se usa para crear "objetos" de forma dinamica
    strcpy(resultado->apellido, apellido);
    strcpy(resultado->nombre, nombre);
    resultado->documento = documento;
    return resultado;
}

int GetCompleto(alumno_t alumno, char cadena[], uint32_t espacio) {
    return -1; // para sacar warning
}

int GetDocumento(alumno_t alumno) {
    return -1; // para sacar warning
}

int Serializar(alumno_t alumno, char cadena[], uint32_t espacio) {
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;

    disponibles--;
    resultado = SerializarCadena("apellido", alumno->apellido, cadena, disponibles);

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre", alumno->nombre, cadena, disponibles);
    }

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento", alumno->documento, cadena, disponibles);
    }

    if (resultado > 0) {
        cadena += resultado;
        *(cadena - 1) = '}';
        resultado = espacio - disponibles;
    }

    return resultado;
}
