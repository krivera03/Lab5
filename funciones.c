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
        return;
    }

    arreglo->data[arreglo->size] = valor;
    arreglo->size++;
}