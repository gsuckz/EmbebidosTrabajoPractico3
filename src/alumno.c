#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define sizeword 100
#define opcion   2
struct alumno_s {
    char apellido[sizeword];
    char nombre[sizeword];
    uint32_t documento;
    bool ocupado;
};
/// @brief Imprime una cadena de caracteres en consola
/// @param campo
/// @param valor
/// @param cadena
/// @param espacio
/// @return Tamaño de la cadena o un numero negatico si no fue suficiente
static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}
/// @brief Imprime un numero en la consola
/// @param campo
/// @param valor
/// @param cadena
/// @param espacio
/// @return Tamaño de la cadena o un numero negatico si no fue suficiente
static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}
/// @brief Genera un Struct con los datos del alumno, puede almacenarse de forma estática o dinámica
/// @param apellido
/// @param nombre
/// @param documento
/// @return Retorna Puntero a la estructura creada
alumno_t CrearAlumno(char * apellido, char * nombre, int documento) {
    alumno_t resultado;

#if opcion == 1
    resultado =
        malloc(sizeof(struct alumno_s)); // Malloc se usa para crear "objetos" de forma dinamica
    if (resultado != NULL) {
        strcpy(resultado->apellido, apellido);
        strcpy(resultado->nombre, nombre);
        resultado->documento = documento;
    } else {
        return NULL;
    }

#else

    static struct alumno_s instancias[50] = {0};

    uint8_t i = 0;

    for (uint8_t i = 0; i <= 50; i++) {

        if (instancias[i].ocupado == 0) {

            resultado = &instancias[i];
            strcpy(instancias[i].apellido, apellido);
            strcpy(instancias[i].nombre, nombre);
            instancias[i].documento = documento;
            instancias[i].ocupado = true;

            return resultado;
        }
    }

#endif

    return resultado;
}
/// @brief Convierte a una cadena los datos del struct en formato JSON
/// @param alumno Struct con los datos
/// @param cadena Direccion de la cadena donde se guardaran los datos
/// @param espacio Tamaño de la cadena
/// @return Tamaño de la cadena o -1 si no fue suficiente el espacio
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
    if (resultado < 0) {
        return -1;
    }
    return resultado;
}
