
#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

/*
    Inicializa la estructura y reserva memoria para los datos.
*/
void da_init(DinaArray *arreglo, size_t capacidad){

    arreglo->data = malloc(capacidad * sizeof(int));

    if(arreglo->data == NULL){
        arreglo->size = 0;
        arreglo->capacidad = 0;
        return;
    }

    arreglo->size = 0;
    arreglo->capacidad = capacidad;
}

/*
    Agrega un elemento al final del arreglo.
    Si el arreglo está lleno no inserta el nuevo elemento.
*/
void da_push(DinaArray *arreglo, int valor){

    if(arreglo->size == arreglo->capacidad){

        size_t nueva_capacidad = arreglo->capacidad * 2;

        int *nuevo_arreglo = realloc(arreglo->data,
                                     nueva_capacidad * sizeof(int));

        if(nuevo_arreglo == NULL){
            return;
        }

        arreglo->data = nuevo_arreglo;
        arreglo->capacidad = nueva_capacidad;
    }

    arreglo->data[arreglo->size] = valor;
    arreglo->size++;
}

/*
    Devuelve el elemento solicitado.
    Si el índice es inválido retorna -1.
*/
int da_get(DinaArray *arreglo, size_t indice){

    if(indice >= arreglo->size){
        return -1;
    }

    return arreglo->data[indice];
}

/*
    Recorre el arreglo e imprime todos sus elementos.
*/
void da_print(DinaArray *arreglo){

    printf("[ ");

    for(size_t i = 0; i < arreglo->size; i++){
        printf("%d ", arreglo->data[i]);
    }

    printf("]\n");
}

/*
    Elimina un elemento del arreglo.
    Los elementos posteriores se desplazan una posición hacia la izquierda.
*/
void da_remove(DinaArray *arreglo, size_t indice){

    if(indice >= arreglo->size){
        return;
    }

    for(size_t i = indice; i < arreglo->size - 1; i++){
        arreglo->data[i] = arreglo->data[i + 1];
    }

    arreglo->size--;
}

/*
    Libera la memoria utilizada por el arreglo
    y reinicia sus campos.
*/
void da_free(DinaArray *arreglo){

    free(arreglo->data);

    arreglo->data = NULL;
    arreglo->size = 0;
    arreglo->capacidad = 0;



/*------Listas Enlazadas--------*/

/*Crea un nuevo nodo con el dato indicado por el usuario*/
Nodo *nodo_crear(int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        return NULL;
    }

    nuevo->dato = dato;     /*Asinga el valor al nodo*/
    nuevo->next = NULL;

    return nuevo;
}


/*Inserta un nodo al inicio de la lista*/
void lista_insertar_inicio(Nodo **head, int dato) {
    Nodo *nuevo = nodo_crear(dato);

    if (nuevo == NULL) return;

    nuevo->next = *head;     /*El nuevo nodo apunta al anterior primer nodo*/
    *head = nuevo;
}

/*Inserta un nodo al final de la lista*/
void lista_insertar_final(Nodo **head, int dato) {
    Nodo *nuevo = nodo_crear(dato);

    if (nuevo == NULL) return;

    if (*head == NULL) {            /*Cuando la lista esta vacía*/
        *head = nuevo;
        return;
    }

    Nodo *actual = *head;          /*Recorre todos los nodos*/

    while (actual->next != NULL) {
        actual = actual->next;
    }

    actual->next = nuevo;         
}

/*Insertar en una posición específica*/
void lista_insertar_pos(Nodo **head, int dato, int pos) {
    if (pos <= 0 || *head == NULL) {          /*Si la lista esta vacía inserta al incio de la misma*/
        lista_insertar_inicio(head, dato);
        return;
    }

    Nodo *nuevo = nodo_crear(dato);
    if (nuevo == NULL) return;

    Nodo *actual = *head;

    for (int i = 0; actual->next != NULL && i < pos -1; i++) {      /*Recorre hasta la posición específica*/
        actual = actual->next;
    }

    nuevo->next = actual->next;   /*Inserta el nodo en la posición específica*/
    actual->next = nuevo;
} 



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
        Dnodo *ultimo = *head; // crea un puntero para recorrer la lista y encontrar el ultimo nodo
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
    
    (void)head;
}

/* TODO: eliminar un nodo dado su puntero — O(1)
 * Reconectar el prev del siguiente y el next del anterior.
 * Caso especial: el nodo a eliminar es *head. */
void dlista_eliminar_nodo(DNodo **head, int dato) {
    DNodo *cur = *head;
    DNodo *past = NULL;
    int salvo = 0; // para identificar si  se encontro nodo a eliminar o solo llega al final
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
            if (past == NULL) { // si es el unico nodo
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

