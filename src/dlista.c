#include "dlista.h"

//Listas Doblemente Enlazadas

/* DADA: crear nodo */
DNodo *dnodo_crear(int dato) {
    DNodo *n = malloc(sizeof(DNodo));
    if (n) { n->dato = dato; n->next = NULL; n->prev = NULL; }
    return n;
}

/* DADA: imprimir hacia adelante */
void dlista_imprimir_adelante(DNodo *head) {
    DNodo *cur = head;
    //printf("FWD: ");
    while (cur) {
        printf("%d ", cur->dato);
        cur = cur->next;
    }
    printf("\n");
    //printf("\nBWD: ");
   
    }

/* DADA: imprimir hacia atrás */
void dlista_imprimir_atras(DNodo *head) {
    DNodo *cur = head;
    DNodo *ultimo = NULL;
    //printf("FWD: ");
    while (cur) {
        //printf("%d ", cur->dato);
        ultimo = cur;
        cur = cur->next;
    }
    cur = ultimo;
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
    //Se debe revisar si la lista esta vacia, si no lo esta se debe actualizar el puntero prev del nodo que era head para que apunte al nuevo nodo creado.
    
    if (*head == NULL) {
        *head = dnodo_crear(dato); //crea nodo y asignarle head si no existe
    } else {
        DNodo *nuevo = dnodo_crear(dato); // crea nodo
        nuevo->next = *head; // hace que el next sea head actual
        nuevo->prev = NULL; // hace que el prev sea NULL
        (*head)->prev = nuevo; // actualiza que prev de head actual apunte al nuevo nodo
        *head = nuevo; //cambia head al nuevo nodo
    }
    /* TODO */
}

void dlista_insertar_final(DNodo **head, int dato) {
    //Se debe revisar si la lista esta vacia, si no lo esta se debe actualizar el puntero prev del nodo que era head para que apunte al nuevo nodo creado.
    
    if (*head == NULL) {
        *head = dnodo_crear(dato); //crea nodo y asignarle head si no existe
    } else {
        DNodo *nuevo_ultimo = dnodo_crear(dato); // crea nodo
        DNodo *ultimo = *head; // crea un puntero para recorrer la lista y encontrar el ultimo nodo
        while (ultimo->next != NULL) { // recorre la lista hasta encontrar el ultimo
            ultimo = ultimo->next;
        }
        ultimo->next = nuevo_ultimo; // hace que el next del ultimo nodo apunte al nuevo nodo
        nuevo_ultimo->prev = ultimo; // hace que el prev del nuevo nodo apunte al ultimo
        nuevo_ultimo->next = NULL; // hace que el next del nuevo nodo sea NULL
    }
    /* TODO */
}




/* TODO: insertar después de pos
 * Casos a manejar:
 * - pos->next != NULL: el nuevo nodo queda entre pos y pos->next
 * - pos->next == NULL: el nuevo nodo queda al final */
void dlista_insertar_posicion(DNodo **head, DNodo *pos, int dato) {
    /* TODO */
    if (pos == NULL) return;

    DNodo *nuevo = dnodo_crear(dato);

    // Insertar en el medio de la lista
    if (pos->next != NULL) {
        DNodo *siguiente = pos->next; // guarda el siguiente nodo de pos
        nuevo->next = siguiente; // hace que el next del nuevo nodo apunte al siguiente de pos
        nuevo->prev = pos; // hace que el prev del nuevo nodo apunte a pos
        pos->next = nuevo; // hace que el next de pos apunte al nuevo nodo
        siguiente->prev = nuevo; // hace que el prev del siguiente de pos apunte al nuevo nodo  
        
    }
    // Insertar al final 
    else {
        dlista_insertar_final(head, dato); // si pos->next es NULL, inserta al final
    }  
}

/* TODO: eliminar un nodo dado su puntero — O(1)
 * Reconectar el prev del siguiente y el next del anterior.
 * Caso especial: el nodo a eliminar es *head. */
void dlista_eliminar_nodo(DNodo **head, int dato) {
    DNodo *cur = *head;
    DNodo *past = NULL;
    //printf("FWD: ");
    while (cur != NULL && cur->dato != dato) {
        past = cur;
        cur = cur->next;
    }
    if (cur == NULL || cur->dato != dato) {
        printf("No se encontro el nodo a eliminar\n");
        return;
    } else {
        if (cur == *head) { // si es el head
            if (cur->next == NULL) { // si es el unico nodo
                free(cur);
                *head = NULL;
                return;
            }
            *head = cur->next; // actualiza head al siguiente nodo    
            (*head)->prev = NULL; // actualiza el prev del nuevo head a NULL
            
        } else {

            past->next = cur->next; // reconecta el next del anterior al siguiente
            if (cur->next != NULL) { // si hay un siguiente nodo, actualiza su prev al anterior
                cur->next->prev = past;
            }
        }
        free(cur); // libera el nodo eliminado
    }

}
    /* TODO */
void dlista_buscar_elemento(DNodo **head, int dato) {
    DNodo *cur = *head;
    while (cur != NULL) {
        if (cur->dato == dato) {
            printf("Elemento %d encontrado\n", dato);
            return;
        }
        cur = cur->next;
    }
    printf("Elemento %d no encontrado\n", dato);
}

/* TODO: liberar toda la lista */
void dlista_liberar(DNodo **head) {
    DNodo *cur = *head;
    while (cur != NULL) {
        DNodo *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}