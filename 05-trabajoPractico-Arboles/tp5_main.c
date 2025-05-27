#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/validaciones/FuncionesAuxiliares.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/cola/headers/colas.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/arboles/headers/arbol-binario.h"
#include "../libs/arboles/headers/nodo.h"
#include "../libs/arboles/headers/tp_arboles.h"
#include "../libs/arboles/headers/arbol-avl.h"
#include "../libs/arboles/headers/arbol-binario-busqueda.h"


/*2. Dado un árbol binario no vacío determinar:
a. Retornar una lista con todos los nodos hojas.
b. Retornar en una estructura todos los nodos interiores (los que no son ni 
hojas ni raíz)
c. Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la
posición de cada ocurrencia (puntero al nodo).
d. Determinar la complejidad algorítmica de los puntos “a”, “b”, “c”. */

//punto 2

//punto 3

//punto 4

void cargarArbol(ArbolBinario A)
{
    printf("\n\t --- Carga del arbol ---\n");
    cargar_arbol_binario(A);
    printf("Pulse enter para volver al menu");
    return;
}

//a
int mainAnchoArbol(ArbolBinario A)
{
    Lista arbol = a_ej4_anchura(A);
    printf("\nElementos del arbol: ");
    l_mostrar(arbol);
    return 0;
}

//b
int mainCantHojas(ArbolBinario A)
{
    int cantHojas = a_ej4_q_hojas(A);
    printf("\nEl arbol tiene %d hojas", cantHojas);
    return 0;
}

//c
int mainArbolSimilar(ArbolBinario A)
{
    ArbolBinario B = a_crear();
    printf("\n\t --- Carga del arbol a comparar---\n");
    cargar_arbol_binario(B);
    bool res = a_ej4_similares(A, B);
    if (res == true)
    {
        printf("\nLos arboles son similares");
    }
    else
    {
        printf("\nLos arboles no son similares");

    }
    return 0;
}

//d
int mainPadreNodo(ArbolBinario A)
{
    int clave;
    printf("Ingrese la clave del nodo: ");
    while(scanf("%d", &clave) !=1)
    {
        printf("Dato invalido. Ingrese un numero entero: ");
        limpiarBuffer();
    }
    TipoElemento x = a_ej4_padre(A, clave);
    if (x == NULL)
    {
        printf("\nEl nodo no tiene padre porque es la raiz del arbol");
    }
    else
    {
        printf("\nPadre del nodo %d: %d", clave, x->clave);
    }
    return 0;
}

//e
int mainHermanosNodo(ArbolBinario A)
{
    int clave;
    printf("Ingrese la clave del nodo: ");
    while(scanf("%d", &clave) !=1)
    {
        printf("Dato invalido. Ingrese un numero entero: ");
        limpiarBuffer();
    }
    Lista hermanos = a_ej4_hermanos(A, clave);
    if (l_es_vacia(hermanos))
    {
        printf("\nEl nodo no tiene hermanos");
    }
    else
    {
        printf("\nHermanos del nodo: ");
        l_mostrar(hermanos);
    }
    return 0;
}

//punto 7

//punto 8

//punto 9

//punto 10
int main_punto10() {
    int N, valormin, valormax, cantidad;

    printf("Comparacion de alturas entre ABB y AVL\n");
    printf("Ingrese cantidad de repeticiones (N): ");
    scanf("%d", &N);

    printf("Ingrese el valor minimo de las claves: ");
    scanf("%d", &valormin);
    printf("Ingrese el valor maximo de las claves: ");
    scanf("%d", &valormax);
    printf("Ingrese la cantidad de claves a generar: ");
    scanf("%d", &cantidad);

    if (cantidad > valormax - valormin + 1) {
        printf("Error: No se pueden generar tantas claves únicas con el rango dado.\n");
        return 1;
    }

    Lista diferencias = a_ej10_comparacionarboles(N, valormin, valormax, cantidad);

    printf("\nSe puede concluir que un arbol AVL, al estar balanceado automaticamente\n");
    printf("mantiene alturas menores o iguales que un ABB, lo que garantiza un rendimiento\n");
    printf("mas eficiente en operaciones de busqueda, insercion y eliminacion a medida que la cantidad de datos crece.\n");
    return 0;
}

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
    printf("  1   Cargar Arbol\n");
    printf("  2   Mostrar nodos terminales u hojas\n");
    printf("  3   Nodos interiores\n");
    printf("  4   Buscar todas las ocurrencias de una clave con su posición\n");
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
    printf("  1   Cargar Arbol\n");
    printf("  2   Mostrar recorrido en anchura\n");
    printf("  3   Cantidad de hojas\n");
    printf("  4   Arbol similar\n");
    printf("  5   Padre del nodo\n");
    printf("  6   Hermanos del nodo\n");
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
    printf("  1   Cargar Arbol\n");
    printf("  2   Altura del arbol\n");
    printf("  3   Nivel de un nodo\n");
    printf("  4   Nodos interiores\n");
    printf("  5   Nivel de todas las hojas\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

int main()
{
    bool salir = false, salir_p2 = false, salir_p4 = false, salir_p8 = false, arbolCargadoej2 = false, arbolCargadoej4 = false, arbolCargadoej8 = false;
    int opc, opc2, opc4, opc8;
    ArbolBinario A2 = a_crear(), A4 = a_crear(), A8 = a_crear();
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
            salir_p2 = false;
            while (!salir_p2)
            {
                menu_punto2();
                validador = scanf("%i", &opc2);
                while (validador != 1 || opc2 < 0 || opc2 > 4)
                {
                    printf("Opción incorrecta\n");
                    printf("Seleccione una opción: ");
                    limpiarBuffer();
                    validador = scanf("%i", &opc2);
                }
                switch (opc2)
                {
                case 1:
                    cargarArbol(A2);
                    arbolCargadoej2 = true;
                    pausar();
                    break;
                case 2:
                    if(arbolCargadoej2)
                    {
                        //main_hojas(A2);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 3:
                    if(arbolCargadoej2)
                    {
                        //main_interior(A2);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 4:
                    if(arbolCargadoej2)
                    {
                        //main_buscar(A2);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");                    
                    pausar();
                    break;
                case 0:
                    salir_p2 = true;
                }
            }
            break;
        case 3:
            //main_nodo_binario();
            break;
        case 4:
            salir_p4 = false;
            while (!salir_p4)
            {
                menu_punto4();
                validador = scanf("%i", &opc4);
                while (validador != 1 || opc4 < 0 || opc4 > 6)
                {
                    printf("Opción incorrecta\n");
                    printf("Seleccione una opción: ");
                    limpiarBuffer();
                    validador = scanf("%i", &opc4);
                }
                switch (opc4)
                {
                case 1:
                    cargarArbol(A4);
                    arbolCargadoej4 = true;
                    pausar();
                    break;
                case 2:
                    if (arbolCargadoej4)
                    {
                        mainAnchoArbol(A4);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 3:
                    if (arbolCargadoej4)
                    {
                        mainCantHojas(A4);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 4:
                    if (arbolCargadoej4)
                    {
                        mainArbolSimilar(A4);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 5:
                    if (arbolCargadoej4)
                    {
                        mainPadreNodo(A4);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 6:
                    if (arbolCargadoej4)
                    {
                        mainHermanosNodo(A4);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 0:
                    salir_p4 = true;
                }
            }
            break;
        case 7:
            //main_equivalentes();
            break;
        case 8:
            salir_p8 = false;
            while (!salir_p8)
            {
                menu_punto8();
                validador = scanf("%i", &opc8);
                while (validador != 1 || opc8 < 0 || opc8 > 5)
                {
                    printf("Opción incorrecta\n");
                    printf("Seleccione una opción: ");
                    limpiarBuffer();
                    validador = scanf("%i", &opc8);
                }
                switch (opc8)
                {
                case 1:
                    cargarArbol(A8);
                    arbolCargadoej8 = true;
                    pausar();
                    break;
                case 2:
                    if(arbolCargadoej8)
                    {
                        //alturaArbol(A8);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 3:
                    if(arbolCargadoej8)
                    {
                        //Nivel_Nodo(A8);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 4:
                    if(arbolCargadoej8)
                    {
                        //Nodos_interiores(A8);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 5:
                    if(arbolCargadoej8)
                    {
                        //main_nivel_hojas(A8);
                    }
                    else printf("Primero debe cargar el arbol (opcion 1).\n");
                    pausar();
                    break;
                case 0:
                    salir_p8 = true;
                }
            }
            break;
        case 9:
            //main_punto9();
            break;
        case 10:
            main_punto10();
            pausar();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}