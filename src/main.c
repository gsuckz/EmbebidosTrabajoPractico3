#include <stdio.h>
#include "alumno.h"

int main(void) {

    char cadena[256];
    alumno_t jesus = CrearAlumno("Avila", "Jesus Gerardo Daniel", 41650372);
    alumno_t pablo = CrearAlumno("Perez", "Pablo", 1234567);

    if (Serializar(jesus, cadena, sizeof(cadena)) >= 0) { // quitar "resultado"
        printf("%s\n", cadena);
    } else {
        printf("Error al serializar\n");
    }

    if (Serializar(pablo, cadena, sizeof(cadena)) >= 0) { // quitar "resultado"
        printf("%s\n", cadena);
    } else {
        printf("Error al serializar\n");
    }

    return 0;
}