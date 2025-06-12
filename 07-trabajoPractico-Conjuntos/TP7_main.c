#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/validaciones/FuncionesAuxiliares.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/arboles/headers/tp_arboles.h"
#include "../libs/arboles/headers/arbol-avl.h"
#include "../libs/conjuntos/headers/conjuntos.h"
#include "../libs/conjuntos/headers/tp_conjunto.h"

//punto 2

//punto 3

//punto 4

//punto 5

//punto 6

//punto 7

//punto 8


void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                               TP6 CONJUNTOS                               |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Interseccion, union, diferencia y pertenencia entre conjuntos\n");
    printf("  3   Union e intersección entre conjuntos\n");
    printf("  4   Demostrar la propiedad de la transitividad\n");
    printf("  5   Diferencia simétrica\n");
    printf("  6   Subconjuntos propios\n");
    printf("  7   Subconjuntos parciales o totales\n");
    printf("  8   Conjuntos iguales\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

int main()
{
    bool salir = false;
    int opcion;

    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opcion);
        limpiarBuffer();
        while (validador != 1 || opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf("Opción incorrecta\n");
            printf("Seleccione una opción: ");
            validador = scanf("%i", &opcion);
            limpiarBuffer();
        }
        switch (opcion)
        {
        case 2:
            main_punto2();
            break;
        case 3:
            main_punto3();
            break;
        case 4:
            main_punto4();
            break;
        case 5:
            main_punto5();
            break;
        case 6:
            main_punto6();
            break;
        case 7:
            main_punto7();
            break;
        case 8:
            main_punto8();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}

