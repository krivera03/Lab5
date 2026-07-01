#ifndef STACKARR_H
#define STACKARR_H
#include <stddef.h>
#include "dinarr.h"

typedef struct {
    DinaArray arr;
} StackArr;

void sa_init (StackArr *s, size_t cap_inicial);
void sa_push (StackArr *s, int valor);
int  sa_pop  (StackArr *s);            /* retorna el valor extraído */
int  sa_peek (StackArr *s);            /* retorna el tope sin extraer */
int  sa_empty(StackArr *s);            /* retorna 1 si está vacío */
void sa_free (StackArr *s);

#endif