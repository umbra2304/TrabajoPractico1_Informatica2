#include <stdio.h>
#include <string.h>
#include "funciones.h"

int buscarOCrearArticulo(articulos_t articulos[], char descripcion[])
{
    int i = 0;

    while (i < CANT_ARTICULOS &&
           articulos[i].descripcion[0] &&
           strcmp(descripcion, articulos[i].descripcion))
    {
        i++;
    }

    if (i < CANT_ARTICULOS &&
        !articulos[i].descripcion[0])
    {
        strcpy(articulos[i].descripcion, descripcion);
    }

    return i;
}

void calcularTotalArticulo(articulos_t *articulo)
{
    int i;

    articulo->total = 0;

    for (i = 0; i < 3; i++)
    {
        articulo->total += articulo->cantidad_sucursal[i];
    }
}

void cargarArticulos(articulos_t articulos[])
{
    int opcion;
    int sucursal;
    int indice;
    char descripcion[90];

    do
    {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%89s", descripcion);

        indice = buscarOCrearArticulo(
                    articulos,
                    descripcion
                 );

        printf("Para que sucursal va a realizar la carga? (1,2,3): ");
        scanf("%d", &sucursal);

        while (sucursal < 1 || sucursal > 3)
        {
            printf("Sucursal invalida. Ingrese 1, 2 o 3: ");
            scanf("%d", &sucursal);
        }

        printf("Ingrese la cantidad del articulo para la sucursal %d: ",
               sucursal);

        scanf("%d",
              &articulos[indice]
                    .cantidad_sucursal[sucursal - 1]);

        calcularTotalArticulo(
            &articulos[indice]
        );

        printf("Desea ingresar otro articulo? (1-Si, 2-No): ");
        scanf("%d", &opcion);

    } while (opcion == 1);
}

void mostrarArticulos(articulos_t articulos[])
{
    int i = 0;

    printf("\n");
    printf("Articulo\tSucursal1\tSucursal2\tSucursal3\tTotal\n");

    while (i < CANT_ARTICULOS &&
           articulos[i].descripcion[0])
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[SUCURSAL_1],
               articulos[i].cantidad_sucursal[SUCURSAL_2],
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);

        i++;
    }
}

void intercambiarArticulos(articulos_t *a, articulos_t *b)
{
    articulos_t aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenarArticulos(articulos_t articulos[])
{
    int i;
    int j;

    for (j = 0; j < CANT_ARTICULOS - 1; j++)
    {
        for (i = 0; i < CANT_ARTICULOS - 1; i++)
        {
            if (articulos[i].total <
                articulos[i + 1].total)
            {
                intercambiarArticulos(
                    &articulos[i],
                    &articulos[i + 1]
                );
            }
        }
    }
}