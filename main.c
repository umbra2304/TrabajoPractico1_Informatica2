#include <stdio.h>
#include "funciones.h"

int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};

    printf("Bienvenido al final de Info 1\n\n");

    cargarArticulos(articulos);

    printf("\n\nLISTADO ORIGINAL\n");
    mostrarArticulos(articulos);

    ordenarArticulos(articulos);

    printf("\n\n###################################");
    printf("\n############ ORDENADO ############");
    printf("\n###################################\n");

    mostrarArticulos(articulos);

    return 0;
}