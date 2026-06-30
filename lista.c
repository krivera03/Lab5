


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

    nuevo->next = actual->next;              /*Inserta el nodo en la posición específica*/
    actual->next = nuevo;
} 

/*Buscar elemento en la lista*/
Nodo *lista_buscar(Nodo *head, int dato) {
    Nodo *actual = head;

    while (actual != NULL) {               /*Recorre toda la lista*/
        if (actual->dato == dato) {
            return actual;                 /*Devuelve el nodo cuando lo encuentra*/
        } 
        actual = actual->next;
    }
    return NULL;                       
}

/*Eliminar la primera ocurrencia de un valor en la lista*/
int lista_eliminar(Nodo **head, int dato) {
    Nodo *actual = *head;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->dato != dato) {   /*Buscar el nodo*/
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL) return 0;                   /*Si no existe el valor*/

    if (anterior == NULL) {                        /*Si el nodo a eliminar es el primero*/
        *head = actual->next;
    } else {
        anterior->next = actual->next;
    }

    free(actual);                                 /*Libera la memoria del nodo eliminado*/
    return 1;
}

/*Imprimir la lista hacia delante*/
void lista_imprimir(Nodo *head) {
    Nodo *actual = head;

    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    }

    printf("NULL\n");
}

/*Liberar memoria de la lista enlazada*/
void lista_liberar(Nodo **head) {
    Nodo *actual = *head;
    Nodo *siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    *head = NULL;  /*Lista queda vacía*/
}