#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/cola/headers/colas.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/arboles/headers/arbol-binario.h"
#include "../libs/arboles/headers/nodo.h"
#include "../libs/arboles/headers/tp_arboles.h"
//#include "arbol-avl.h"
//#include "arbol-binario-busqueda.h"
#include "../libs/validaciones/FuncionesAuxiliares.h"

//punto 2

//punto 3

//punto 4

//punto 7

//punto 8

//punto 9

//punto 10


void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 TP5 ARBOLES                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con un arbol binario\n");
    printf("  3   Operaciones con un nodo\n");
    printf("  4   Operaciones con un arbol n-ario\n");
    printf("  7   Arboles binarios equivalentes\n");
    printf("  8   Operaciones con un arbol n-ario\n");
    printf("  9   Convertir Arbol binario a arbol AVL\n");
    printf("  10  Alturas arbol binario de búsqueda vs AVL\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

/// @brief Menu del Punto 2: Operaciones con un arbol binario
void menu_punto2()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                    2   Operaciones con un arbol binario                     |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Mostrar nodos terminales u hojas\n");
    printf("  2   Nodos interiores\n");
    printf("  3   Buscar todas las ocurrencias de una clave con su posición\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

/// @brief Menu del Punto 4
void menu_punto4()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                    4   Operaciones con un arbol n-ario                    |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Mostrar recorrido en anchura\n");
    printf("  2   Cantidad de hojas\n");
    printf("  3   Arbol similar\n");
    printf("  4   Padre del nodo\n");
    printf("  5   Hermanos del nodo\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

void menu_punto8()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                    8   Operaciones con un arbol n-ario                    |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Altura del arbol\n");
    printf("  2   Nivel de un nodo\n");
    printf("  3   Nodos interiores\n");
    printf("  4   Nivel de todas las hojas\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

int main()
{
    bool salir = false, salir_p2 = false, salir_p4 = false, salir_p8 = false;
    int opc, opc2, opc4, opc8;
    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opc);
        limpiarBuffer();
        while (validador != 1 || opc < 0 || opc > 10 || opc == 1 || opc == 5 || opc == 6)
        {
            printf("Opción incorrecta\n");
            printf("Seleccione una opción: ");
            validador = scanf("%i", &opc);
            limpiarBuffer();

        }
        switch (opc)
        {
        case 2:
            while (!salir_p2)
            {
                menu_punto2();
                validador = scanf("%i", &opc2);
                while (validador != 1 || opc2 < 0 || opc2 > 3)
                {
                    printf("Opción incorrecta\n");
                    printf("Seleccione una opción: ");
                    limpiarBuffer();
                    validador = scanf("%i", &opc2);
                }
                switch (opc2)
                {
                case 1:
                    //main_hojas();
                    break;
                case 2:
                    //main_interior();
                    break;
                case 3:
                    //main_buscar();
                    break;
                case 0:
                    salir_p2 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            //main_nodo_binario();
            break;
        case 4:
            while (!salir_p4)
            {
                menu_punto4();
                int validador = scanf("%i", &opc4);
                while (validador != 1 || opc4 < 0 || opc4 > 5)
                {
                    printf("Opción incorrecta\n");
                    printf("Seleccione una opción: ");
                    limpiarBuffer();
                    validador = scanf("%i", &opc4);
                }
                switch (opc4)
                {
                case 1:
                    //main_anchura_nario();
                    break;
                case 2:
                    //main_cantidad_hojas();
                    break;
                case 3:
                    //main_arboles_similares();
                    break;
                case 4:
                    //main_padre_nario();
                    break;
                case 5:
                    //main_hermanos_nario();
                    break;
                }
                break;
                menu_principal();
            }
        case 8:
            while (!salir_p8)
            {
                menu_punto8();
                validador = scanf("%i", &opc8);
                while (validador != 1 || opc8 < 0 || opc8 > 4)
                {
                    printf("Opción incorrecta\n");
                    printf("Seleccione una opción: ");
                    limpiarBuffer();
                    validador = scanf("%i", &opc8);
                }
                switch (opc8)
                {
                case 1:
                    //main_hojas();
                    break;
                case 2:
                    //main_interior();
                    break;
                case 3:
                    //main_buscar();
                    break;
                case 0:
                    salir_p8 = true;
                }
            }
            break;
            menu_principal();
        case 7:
            //main_equivalentes();
            break;
        case 9:
            //main_punto9();
            break;
        case 10:
            //main_punto10();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}