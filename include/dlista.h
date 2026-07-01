#ifndef DLISTA_H
#define DLISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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