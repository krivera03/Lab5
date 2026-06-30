#ifndef LISTA_H
#define LISTA_H

/*Estructura que representa un nodo de la lista enlanzada*/
typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

/*Genera un nodo con un valor específico*/
Nodo *nodo_crear(int dato);

/*Ingresa un nodo al inicio de la lista*/
void lista_insertar_inicio(Nodo **head, int dato);





#endif