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