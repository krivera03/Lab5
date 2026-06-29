

//Listas Doblemente Enlazadas

/* DADA: crear nodo */
DNodo *dnodo_crear(int dato) {
    DNodo *n = malloc(sizeof(DNodo));
    if (n) { n->dato = dato; n->next = NULL; n->prev = NULL; }
    return n;
}

/* DADA: imprimir hacia adelante y atrás */
void dlista_imprimir_adelante(DNodo *head) {
    DNodo *cur = head;
    //printf("FWD: ");
    while (cur) {
        printf("%d ", cur->dato);
        ultimo = cur;
        cur = cur->next;
    }
    printf("\n");
    //printf("\nBWD: ");
   
    }

/* DADA: imprimir hacia adelante y atrás */
void dlista_imprimir_atras(DNodo *head) {
    DNodo *cur = NULL;
    while (cur) {
        printf("%d ", cur->dato);
        cur = cur->prev;
        }
    printf("\n");
    //printf("\nBWD: ");
   
    }
    

/* TODO: insertar al inicio
 * Similar a la lista simple pero también actualizar prev
 * del nodo que era head para que apunte al nuevo. */
void dlista_insertar_inicio(DNodo **head, int dato) {
    /* TODO */
}

/* TODO: insertar después de pos
 * Casos a manejar:
 * - pos->next != NULL: el nuevo nodo queda entre pos y pos->next
 * - pos->next == NULL: el nuevo nodo queda al final */
void dlista_insertar_despues(DNodo **head, DNodo *pos, int dato) {
    /* TODO */
    (void)head;
}

/* TODO: eliminar un nodo dado su puntero — O(1)
 * Reconectar el prev del siguiente y el next del anterior.
 * Caso especial: el nodo a eliminar es *head. */
void dlista_eliminar_nodo(DNodo **head, DNodo *nodo) {
    /* TODO */
}

/* TODO: liberar toda la lista */
void dlista_liberar(DNodo **head) {
    /* TODO */
}