#include <stdio.h>
#include "datos.h"
#include "ordenamiento.h"

int main() {
    Competidor c;
    c.id = 1;
    printf("Ingrese nombre: ");
    scanf("%19s", c.nombre);

    printf("Ingrese 3 puntajes:\n");
    for(int i=0; i<3; i++) {
        scanf("%d", &c.puntajes[i]);
    }

    printf("Puntajes originales:\n");
    mostrarCompetidor(c);

    int opcion;
    printf("Metodo de ordenamiento:\n1. Bubble\n2. Selection\n3. Insertion\n");
    scanf("%d", &opcion);

    if(opcion==1) bubbleSort(c.puntajes, 3);
    else if(opcion==2) selectionSort(c.puntajes, 3);
    else insertionSort(c.puntajes, 3);

    printf("Puntajes ordenados:\n");
    mostrarCompetidor(c);

    return 0;
}
