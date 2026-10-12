#include <stdio.h>
#include "datos.h"

void mostrarCompetidor(Competidor c) {
    printf("ID: %d, Nombre: %s\n", c.id, c.nombre);
    for(int i=0; i<3; i++) {
        printf("%d ", c.puntajes[i]);
    }
    printf("\n");
}
