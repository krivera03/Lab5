#include "stackarr.h"

/* DADA: inicializar */
void sa_init(StackArr *s, size_t cap) {
    da_init(&s->arr, cap);
}

/* TODO: push — agregar al tope
 * Delegar en da_push. */
void sa_push(StackArr *s, int valor) {
    /* TODO */
    da_push(&s->arr, valor);
}

/* TODO: pop — extraer del tope
 * Verificar que no esté vacío (imprimir error y retornar -1 si lo está).
 * Decrementar size y retornar el valor que estaba en el tope. */
int sa_pop(StackArr *s) {
    if (s->arr.size == 0) {
        printf("Stack vacío\n");
        return -1;
    }

    int valor = s->arr.data[s->arr.size - 1]; // obtener el valor del tope
    s->arr.size--; //reduce el tamaño del arreglo dinámico

    return valor;
   
}

/* TODO: peek — ver el tope sin extraer */
int sa_peek(StackArr *s) {
    if (s->arr.size == 0) {
        printf("Stack vacío\n");
        return -1;
    }

    int valor = s->arr.data[s->arr.size - 1]; // obtener el valor del tope/final
    printf("Valor en el tope: %d\n", valor);

    /* TODO */
    return valor;
}

/* TODO: empty */ //regresa 1 si está vacío, 0 si no lo está
int sa_empty(StackArr *s) {
     if (s->arr.size == 0) {
        printf("Stack vacío\n");
        return 1;
    }
    /* TODO */
    return 0;
}

/* TODO: free */
void sa_free(StackArr *s) {
    /* TODO */
    free(s->arr.data);
    s->arr.data = NULL; //Limpia estructura
    s->arr.size = 0;
    s->arr.capacidad = 0;
}