


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