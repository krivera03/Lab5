#include <stdlib.h>
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
    Devuelve el elemento ubicado en el índice indicado.
*/
int da_get(DinaArray *arreglo, size_t indice){

    return arreglo->data[indice];
}