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

