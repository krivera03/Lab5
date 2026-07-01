# Laboratorio 5: Estructuras de Datos en C

## Descripción del contenido del repositorio

Este repositorio contiene la implementación de diversas estructuras de datos y sus operaciones básicas utilizando el lenguaje C.

Se inicia con la implementación de arreglos dinámicos, incluyendo las operaciones para crear el arreglo, agregar y eliminar elementos, obtener un elemento mediante su índice e imprimir su contenido.

Posteriormente, se implementan listas enlazadas simples y listas doblemente enlazadas, las cuales permiten insertar elementos al inicio, al final o en una posición específica, eliminar y buscar elementos, así como imprimir la lista hacia adelante. En el caso de las listas doblemente enlazadas, también se incorpora la función de recorrer e imprimir la lista hacia atrás.

Finalmente, se desarrolla la implementación de una pila (stack), que incluye las operaciones para insertar elementos en la parte superior de la pila (push), eliminar el elemento superior (pop), consultar el elemento ubicado en la cima sin eliminarlo (peek) y verificar si la pila se encuentra vacía (isEmpty).


### Archivos principales

- **main.c**: Contiene la función principal del programa y el menú de interacción.
- **dinarr.c / dinarr.h**: Implementación de arreglos dinámicos con sus operaciones.
- **lista.c / lista.h**: Implementación de listas enlazadas con sus operaciones.
- **dlista.c / dlista.h**: Implementación de listas doblemente enlazadas con sus operaciones.
- **stackarr.c / stackarr.h**: Implementación de stack con sus operaciones.
- **Makefile**: Archivo que realiza la compilación del proyecto.
- **README.md**: Documentación del proyecto.

## Pasos para compilar

1. Abrir una terminal.
2. Ubicarse en la carpeta del proyecto:

```bash
cd ruta/al/proyecto
```

3. Ejecutar el siguiente comando:

```bash
make run
```

Si la compilación es exitosa, se generará el archivo ejecutable del programa.

4. Para revisión de fugas de memoria ejecutar:
```bash
make valgrind
```

## Pasos para ejecutar

Una vez compilado el proyecto, ejecutar:

```bash
./labo5
```


## Limpieza de archivos compilados

Para eliminar los archivos objeto y el ejecutable generado:

```bash
make clean
```

## Requisitos

- Compilador GCC.
- Utilidad `make`.
- Sistema operativo Linux, macOS o Windows con MinGW/MSYS2 o WSL.

## Autores

- Karen Rivera
- Ismael Alvarado