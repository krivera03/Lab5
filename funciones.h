#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

Nodo *nodo_crear(int dato);

#endif