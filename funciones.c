#include <stdlib.h>
#include "lista.h"

Nodo *nodo_crear(int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        return NULL;
    }

    nuevo->dato = dato;
    nuevo->next = NULL;

    return nuevo;
}