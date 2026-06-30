#ifndef FUNCIONES_H
#define FUNCIONES_H


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

/* Libera la memoria reservada para el arreglo dinámico. */
void da_free(DinaArray *arreglo);


/*Estructura que representa un nodo de la lista enlanzada*/
typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

/*Genera un nodo con un valor específico*/
Nodo *nodo_crear(int dato);

/*Insertar un nodo al inicio de la lista*/
void lista_insertar_inicio(Nodo **head, int dato);

/*Insertar un nodo al final de la lista*/
void lista_insertar_final(Nodo **head, int dato);

/*Insertar en una posición específica*/
void lista_insertar_pos(Nodo **head, int dato, int pos);





#endif