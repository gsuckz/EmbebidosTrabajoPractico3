#ifndef ALUMNO_H
#define ALUMNO_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

//! Estructura para almacenar datos de un alumno
typedef struct alumno_s * alumno_t;

alumno_t CrearAlumno(char * apellido, char * nombre, int documento);

int GetCompleto(alumno_t alumno, char cadena[], uint32_t espacio);

int GetDocumento(alumno_t alumno);

int Serializar(alumno_t alumno, char cadena[], uint32_t espacio);

#ifdef __cplusplus
}
#endif

#endif /* ALUMNO_H */