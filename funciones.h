#ifndef LISTA_H
#define LISTA_H

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

/*Buscar elemento en la lista*/
Nodo *lista_buscar(Nodo *head, int dato);

/*Eliminar la primera ocurrencia de un valor en la lista*/
int lista_eliminar(Nodo **head, int dato);



#endif