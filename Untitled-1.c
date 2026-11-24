#include <stdio.h>
#include <stdlib.h>

typedef struct Contenedor{
    int id;
    float tara;
    float carga;
    float pesoTotal;
    float costo;

    struct Contenedor *sig;
    struct Contenedor *ant;
}Contenedor;

Contenedor *inicio = NULL;
Contenedor *fin = NULL;
int contadorID = 1;

void registrarContenedor(){
    Contenedor *nuevo = (Contenedor *)malloc(sizeof(Contenedor));

    if(nuevo == NULL){
        printf("Error al asignar memoria.\n");
        return;
    }

    nuevo->id = contadorID++;

    printf("\nPeso vacio (tara): ");
    scanf("%f", &nuevo->tara);

    printf("Peso de carga: ");
    scanf("%f", &nuevo->carga);

    printf("Costo asociado: ");
    scanf("%f", &nuevo->costo);

    nuevo->pesoTotal = nuevo->tara + nuevo->carga;

    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if(inicio == NULL){
        inicio = nuevo;
        fin = nuevo;
    }else{
        fin->sig = nuevo;
        nuevo->ant = fin;
        fin = nuevo;
    }

    printf("\nContenedor registrado correctamente.\n");
    printf("ID asignado: %d\n", nuevo->id);
}

Contenedor* buscarContenedor(int id){
    Contenedor *aux = inicio;

    while(aux != NULL){
        if(aux->id == id){
            return aux;
        }
        aux = aux->sig;
    }

    return NULL;
}

void mostrarContenedor(Contenedor *c){
    if(c == NULL){
        printf("Contenedor no encontrado.\n");
        return;
    }

    printf("\n===== DATOS DEL CONTENEDOR =====\n");
    printf("ID: %d\n", c->id);
    printf("Tara: %.2f\n", c->tara);
    printf("Carga: %.2f\n", c->carga);
    printf("Peso Total: %.2f\n", c->pesoTotal);
    printf("Costo: %.2f\n", c->costo);
}

void actualizarContenedor(){
    int id;

    printf("Ingrese ID a actualizar: ");
    scanf("%d", &id);

    Contenedor *c = buscarContenedor(id);

    if(c == NULL){
        printf("Contenedor no encontrado.\n");
        return;
    }

    printf("Nueva tara: ");
    scanf("%f", &c->tara);

    printf("Nueva carga: ");
    scanf("%f", &c->carga);

    printf("Nuevo costo: ");
    scanf("%f", &c->costo);

    c->pesoTotal = c->tara + c->carga;

    printf("Contenedor actualizado correctamente.\n");
}

void eliminarContenedor(){
    int id;

    printf("Ingrese ID a eliminar: ");
    scanf("%d", &id);

    Contenedor *actual = buscarContenedor(id);

    if(actual == NULL){
        printf("Contenedor no encontrado.\n");
        return;
    }

    
    if(actual == inicio){
        inicio = actual->sig;

        if(inicio != NULL)
            inicio->ant = NULL;
    }

    
    if(actual == fin){
        fin = actual->ant;

        if(fin != NULL)
            fin->sig = NULL;
    }

    
    if(actual->ant != NULL){
        actual->ant->sig = actual->sig;
    }

    if(actual->sig != NULL){
        actual->sig->ant = actual->ant;
    }

    free(actual);

    printf("Contenedor eliminado correctamente.\n");
}


void mostrarTodos(){
    Contenedor *aux = inicio;

    if(aux == NULL){
        printf("No hay contenedores registrados.\n");
        return;
    }

    printf("\n===== LISTA DE CONTENEDORES =====\n");

    while(aux != NULL){
        printf("\nID: %d\n", aux->id);
        printf("Tara: %.2f\n", aux->tara);
        printf("Carga: %.2f\n", aux->carga);
        printf("Peso Total: %.2f\n", aux->pesoTotal);
        printf("Costo: %.2f\n", aux->costo);

        aux = aux->sig;
    }
}


void liberarMemoria(){
    Contenedor *aux;

    while(inicio != NULL){
        aux = inicio;
        inicio = inicio->sig;
        free(aux);
    }
}

int main(){

    int opcion;
    int id;
    Contenedor *resultado;

    do{
        printf("\n===== SISTEMA DE CONTENEDORES =====\n");
        printf("1. Registrar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Mostrar todos\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

            case 1:
                registrarContenedor();
                break;

            case 2:
                printf("Ingrese ID a buscar: ");
                scanf("%d", &id);

                resultado = buscarContenedor(id);
                mostrarContenedor(resultado);
                break;

            case 3:
                actualizarContenedor();
                break;

            case 4:
                eliminarContenedor();
                break;

            case 5:
                mostrarTodos();
                break;

            case 6:
                liberarMemoria();
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    }while(opcion != 6);

    return 0;
}