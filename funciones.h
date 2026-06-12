#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2

typedef struct
{
    char descripcion[90];
    int cantidad_sucursal[3];
    int total;
} articulos_t;

int buscarOCrearArticulo(articulos_t articulos[], char descripcion[]);
void calcularTotalArticulo(articulos_t *articulo);
void cargarArticulos(articulos_t articulos[]);
void mostrarArticulos(articulos_t articulos[]);
void intercambiarArticulos(articulos_t *a, articulos_t *b);
void ordenarArticulos(articulos_t articulos[]);

#endif