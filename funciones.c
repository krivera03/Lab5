


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


/*Ingresa un nodo al inicio de la lista*/
void lista_insertar_inicio(Nodo **head, int dato) {
    Nodo *nuevo = nodo_crear(dato);

    if (nuevo == NULL) return;

    nuevo->next = *head;     /*El nuevo nodo apunta al anterior primer nodo*/
    *head = nuevo;
}