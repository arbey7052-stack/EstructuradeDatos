#include <stdio.h>
#include "datos.h"
#include "ordenamiento.h"

int main() {
    Competidor c;
    c.id = 1;
    printf("Ingrese nombre: ");
    if (scanf("%19s", c.nombre) != 1) {
        printf("No se pudo leer el nombre.\n");
        return 1;
    }

    printf("Ingrese 3 puntajes:\n");
    for(int i=0; i<3; i++) {
        if (scanf("%d", &c.puntajes[i]) != 1) {
            printf("Ingrese puntajes numericos.\n");
            return 1;
        }
    }

    printf("Puntajes originales:\n");
    mostrarCompetidor(c);

    int puntajesOriginales[3];
    for (int i = 0; i < 3; i++) {
        puntajesOriginales[i] = c.puntajes[i];
    }

    int opcion = 0;
    while (opcion != 4) {
        printf("\nMetodo de ordenamiento:\n");
        printf("1. Bubble\n2. Selection\n3. Insertion\n4. Salir\n");
        printf("Escoja una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF) {
            }
            if (caracter == EOF) {
                printf("No se pudo leer la opcion.\n");
                return 1;
            }
            printf("Ingrese un numero del 1 al 4.\n");
            opcion = 0;
            continue;
        }

        if (opcion == 4) {
            printf("Programa finalizado.\n");
            break;
        }

        if (opcion < 1 || opcion > 3) {
            printf("Opcion no valida. Seleccione 1, 2, 3 o 4.\n");
            continue;
        }

        for (int i = 0; i < 3; i++) {
            c.puntajes[i] = puntajesOriginales[i];
        }

        printf("Resultado con ");
        switch (opcion) {
            case 1:
                printf("Bubble:\n");
                bubbleSort(c.puntajes, 3);
                break;
            case 2:
                printf("Selection:\n");
                selectionSort(c.puntajes, 3);
                break;
            case 3:
                printf("Insertion:\n");
                insertionSort(c.puntajes, 3);
                break;
        }

        mostrarCompetidor(c);
    }

    return 0;
}

