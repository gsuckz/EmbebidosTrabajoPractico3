#include <stdio.h>
#include "alumno.h"
/**
  @file MAIN
  @brief Modulo principal del programa
  Llama a las funciones "CrearAlumno()" y "Serializar()" para mostrar
  en formato JSON los datos de 2 alumnos (Yo y otro)
 */
int main(void) {
    /**
      @brief Funcion Principal
      Crea 2 alumnos con "CrearAlumno" y envía los datos en formato JSON a la consola con
      "Serializar"

     */
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