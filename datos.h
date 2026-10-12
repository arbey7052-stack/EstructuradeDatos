#ifndef DATOS_H
#define DATOS_H

typedef struct {
    int id;
    char nombre[20];
    int puntajes[3]; 
} Competidor;

void mostrarCompetidor(Competidor c);

#endif
