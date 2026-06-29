#ifndef DLISTA_H
#define DLISTA_H

typedef struct DNodo {
    int           dato;
    struct DNodo *next;
    struct DNodo *prev;
} DNodo;

/* Crea un nodo. Retorna NULL si falla malloc. */
DNodo *dnodo_crear(int dato);

/* Inserta al inicio. */
void dlista_insertar_inicio(DNodo **head, int dato);

/* Inserta después del nodo apuntado por 'pos'. */
void dlista_insertar_despues(DNodo **head, DNodo *pos, int dato);

/* Elimina el nodo apuntado por 'nodo'. O(1). */
void dlista_eliminar_nodo(DNodo **head, DNodo *nodo);

/* Imprime hacia adelante  */
void dlista_imprimir_adelante(DNodo *head);

/* Imprime hacia atrás. */
void dlista_imprimir_atras(DNodo *head);

/* Libera todos los nodos. */
void dlista_liberar(DNodo **head);

#endif