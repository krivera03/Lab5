
#include "dinarr.h"
/*
    Inicializa la estructura y reserva memoria para los datos.
*/
void da_init(DinaArray *arreglo, size_t capacidad){

    arreglo->data = malloc(capacidad * sizeof(int));

    if(arreglo->data == NULL){
        arreglo->size = 0;
        arreglo->capacidad = 0;
        return;
    }

    arreglo->size = 0;
    arreglo->capacidad = capacidad;
}

/*
    Agrega un elemento al final del arreglo.
    Si el arreglo está lleno no inserta el nuevo elemento.
*/
void da_push(DinaArray *arreglo, int valor){

    if(arreglo->size == arreglo->capacidad){

        size_t nueva_capacidad = arreglo->capacidad * 2;

        int *nuevo_arreglo = realloc(arreglo->data,
                                     nueva_capacidad * sizeof(int));

        if(nuevo_arreglo == NULL){
            return;
        }

        arreglo->data = nuevo_arreglo;
        arreglo->capacidad = nueva_capacidad;
    }

    arreglo->data[arreglo->size] = valor;
    arreglo->size++;
}

/*
    Devuelve el elemento solicitado.
    Si el índice es inválido retorna -1.
*/
int da_get(DinaArray *arreglo, size_t indice){

    if(indice >= arreglo->size){
        return -1;
    }

    return arreglo->data[indice];
}

/*
    Recorre el arreglo e imprime todos sus elementos.
*/
void da_print(DinaArray *arreglo){

    printf("[ ");

    for(size_t i = 0; i < arreglo->size; i++){
        printf("%d ", arreglo->data[i]);
    }

    printf("]\n");
}

/*
    Elimina un elemento del arreglo.
    Los elementos posteriores se desplazan una posición hacia la izquierda.
*/
void da_remove(DinaArray *arreglo, size_t indice){

    if(indice >= arreglo->size){
        return;
    }

    for(size_t i = indice; i < arreglo->size - 1; i++){
        arreglo->data[i] = arreglo->data[i + 1];
    }

    arreglo->size--;
}

/*
    Libera la memoria utilizada por el arreglo
    y reinicia sus campos.
*/
void da_free(DinaArray *arreglo){

    free(arreglo->data);

    arreglo->data = NULL;
    arreglo->size = 0;
    arreglo->capacidad = 0;
}