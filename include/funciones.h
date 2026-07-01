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





typedef struct DNodo {
    int           dato;
    struct DNodo *next;
    struct DNodo *prev;
} DNodo;

/* Crea un nodo. Retorna NULL si falla malloc. */
DNodo *dnodo_crear(int dato);

/* Inserta al inicio. */
void dlista_insertar_inicio(DNodo **head, int dato);

/* Inserta al final. */
void dlista_insertar_final(DNodo **head, int dato);

/* Inserta en nodo apuntado por 'pos'. */
void dlista_insertar_posicion(DNodo **head, DNodo *pos, int dato);

/* Elimina el nodo a su primera ocurrencia con valor de dato*/
void dlista_eliminar_nodo(DNodo **head, int dato);

/* Busca un elemento en la lista */
void dlista_buscar_elemento(DNodo **head, int dato);

/* Imprime hacia adelante  */
void dlista_imprimir_adelante(DNodo *head);

/* Imprime hacia atrás. */
void dlista_imprimir_atras(DNodo *head);

/* Libera todos los nodos. */
void dlista_liberar(DNodo **head);

#endif
/*  STACK  */
typedef struct {
    DinaArray arr;
} StackArr;

void sa_init (StackArr *s, size_t cap_inicial);
void sa_push (StackArr *s, int valor);
int  sa_pop  (StackArr *s);            /* retorna el valor extraído */
int  sa_peek (StackArr *s);            /* retorna el tope sin extraer */
int  sa_empty(StackArr *s);            /* retorna 1 si está vacío */
void sa_free (StackArr *s);

