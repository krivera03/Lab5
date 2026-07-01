#include <stdio.h>
#include <stdlib.h>
#include "dinarr.h"
#include "lista.h"
#include "dlista.h"
#include "stackarr.h"

int main(void) {
    //DNodo *head =NULL

    printf("\n=== PRUEBA ARREGLO DINAMICO ===\n\n");
    DinaArray arr;

    printf("INIT capacidad 2\n");
    da_init(&arr, 2);
    da_print(&arr);

    printf("\nPush de 10, 20, 30, 40\n");
    da_push(&arr, 10);
    da_push(&arr, 20);
    da_push(&arr, 30); // fuerza realloc
    da_push(&arr, 40);
    da_print(&arr);

    printf("\nGET");
    printf("Elemento en indice 1: %d\n", da_get(&arr, 1));
    printf("Elemento en indice 10 (invalido): %d\n", da_get(&arr, 10));

    printf("\nEliminar elemento en indice 1\n");
    da_remove(&arr, 1);
    da_print(&arr);

    printf("\nEliminar invalido indice 100\n");
    da_remove(&arr, 100); // no debe crashear
    da_print(&arr);

    printf("\nOtros push de 50 y 60\n");
    da_push(&arr, 50);
    da_push(&arr, 60);
    da_print(&arr);

    printf("\nLiberar arreglo:\n");
    da_free(&arr);
    printf("Liberado. Imprimir arreglo:\n");
    da_print(&arr); // debería mostrar vacío
    ////

    printf("\n=== FIN PRUEBA ARREGLO DINAMICO ===\n\n");
    Nodo *head = NULL;

    printf("=== PRUEBA LISTA ENLAZADA ===\n\n");

    // Insertar al inicio
    printf("Insertar al inicio:\n");
    lista_insertar_inicio(&head, 3);
    lista_insertar_inicio(&head, 2);
    lista_insertar_inicio(&head, 1);
    lista_imprimir(head);

    //  Insertar al final
    printf("\nInsertar al final:\n");
    lista_insertar_final(&head, 4);
    lista_insertar_final(&head, 5);
    lista_imprimir(head);

    //  Insertar en posición
    printf("\nInsertar en posicion 2:\n");
    lista_insertar_pos(&head, 99, 2);
    lista_imprimir(head);

    //  Buscar
    printf("\nBuscar elemento 3:\n");
    Nodo *encontrado = lista_buscar(head, 3);
    if(encontrado != NULL){
        printf("Encontrado: %d\n", encontrado->dato);
    } else {
        printf("No encontrado\n");
    }

    //  Eliminar
    printf("\nEliminar elemento 99:\n");
    lista_eliminar(&head, 99);
    lista_imprimir(head);

    //  Eliminar elemento que no existe
    printf("\nEliminar elemento inexistente (100):\n");
    int res = lista_eliminar(&head, 100);
    printf("Resultado: %d\n", res);
    lista_imprimir(head);

    //  Liberar memoria
    printf("\nLiberando lista:\n");
    lista_liberar(&head);
    lista_imprimir(head); // debería estar vacía

    printf("\n=== FIN PRUEBA LISTA ===\n\n");
     DNodo *cabeza = NULL;

    printf("=== PRUEBA LISTA DOBLEMENTE ENLAZADA ===\n\n");

    // Insertar al inicio
    printf("Insertar al inicio:\n");
    dlista_insertar_inicio(&cabeza, 3);
    dlista_insertar_inicio(&cabeza, 20);
    dlista_insertar_inicio(&cabeza, 1);
    dlista_imprimir_adelante(cabeza);

    //  Insertar al final
    printf("\nInsertar al final:\n");
    dlista_insertar_final(&cabeza, 40);
    dlista_insertar_final(&cabeza, 5);
    dlista_imprimir_adelante(cabeza);

    //  Insertar en posición
    printf("\nInsertar después del head:\n");
    dlista_insertar_posicion(&cabeza, cabeza, 99); // inserta después del head
    dlista_imprimir_adelante(cabeza);

    //  Imprimir hacia atrás
    printf("\nImprimir hacia atrás:\n");
    dlista_imprimir_atras(cabeza);

    //  Buscar
    printf("\nBuscar elemento 3:\n");
    dlista_buscar_elemento(&cabeza, 3);

    printf("\nBuscar elemento inexistente (100):\n");
    dlista_buscar_elemento(&cabeza, 100);

    //  Eliminar nodo intermedio
    printf("\nEliminar elemento 3:\n");
    dlista_eliminar_nodo(&cabeza, 3);
    dlista_imprimir_adelante(cabeza);

    //  Eliminar head
    printf("\nEliminar head (1):\n");
    dlista_eliminar_nodo(&cabeza, 1);
    dlista_imprimir_adelante(cabeza);

    //  Eliminar ultimo
    printf("\nEliminar último (5):\n");
    dlista_eliminar_nodo(&cabeza, 5);
    dlista_imprimir_adelante(cabeza);

    // Imprimir hacia atrás otra vez
    printf("\nImprimir hacia atrás:\n");
    dlista_imprimir_atras(cabeza);

    //  Liberar
    printf("\nLiberando lista:\n");
    dlista_liberar(&cabeza);
    dlista_imprimir_adelante(cabeza); // debería no imprimir nada

    printf("\n=== FIN PRUEBA DLISTA ===\n\n");

    StackArr s;
    sa_init(&s, 2);

    printf("=== PRUEBA STACK ARRAY ===\n\n");

    //  Push
    printf("Push 10, 20, 30:\n");
    sa_push(&s, 10);
    sa_push(&s, 20);
    sa_push(&s, 30);

    //  Peek
   
    sa_peek(&s);


    //  Pop
    printf("Pop: %d\n", sa_pop(&s));
    sa_peek(&s);
    printf("Pop: %d\n", sa_pop(&s));

    //  Peek otra vez
  
    sa_peek(&s);
  

    //  Pop hasta vacío
    printf("\nVaciar stack:\n");
    printf("Pop: %d\n", sa_pop(&s));
    printf("Pop extra (error esperado): %d\n", sa_pop(&s));

    //  Empty
    printf("\n¿Está vacío?\n");
    printf("%d\n", sa_empty(&s));

    //  Push después de vacío
    printf("\nPush después de vaciar:\n");
    sa_push(&s, 99);
    sa_peek(&s);

    //  Free
    printf("\nLiberando stack:\n");
    sa_free(&s);

    printf("\n=== FIN PRUEBA STACK ===\n\n");

    return 0;
}