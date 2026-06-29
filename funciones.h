#ifndef DINARR_H
#define DINARR_H

#include <stddef.h>

typedef struct{
    int *data;
    size_t size;
    size_t capacidad;
} DinaArray;

/*Inicia el arreglo dinámico*/
void da_init(DinaArray *arreglo, size_t capacidad);

/* Agrega un elemento al final del arreglo. */
void da_push(DinaArray *arreglo, int valor);

/* Devuelve el elemento almacenado en la posición indicada. */
int da_get(DinaArray *arreglo, size_t indice);

/* Imprime todos los elementos del arreglo. */
void da_print(DinaArray *arreglo);

/* Elimina el elemento ubicado en la posición indicada. */
void da_remove(DinaArray *arreglo, size_t indice);


#endif