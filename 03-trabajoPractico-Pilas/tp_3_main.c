#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/pila/headers/tp_3_pilas.h"

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}    

void cargarpila(Pila p)
{
    int i = 0, tamano, elemento;
    TipoElemento elem;
    printf("ingrese la cantidad de elementos que desea ingresar a la pila: ");
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 10))
    {
        printf("Dato invalido. Ingrese un número entero entre 1 y 10: ");
        scanf("%d", &tamano);
        limpiarBuffer();
    }
    tamano = (int)tamano;
    while (i< tamano)
    {
        printf("ingrese un elemento de la lista. (solo se admiten numeros enteros): ");
        while (scanf("%d", &elemento) != 1)
        {
            printf("elemento invalido. ingrese un elemento de la lista: ");
            scanf("%d", &elemento);
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        p_apilar(p, elem);
        i++;
    }
}

//Punto 2

//Punto 3

//Punto 4

//Punto 5
int mainInvertida(){
    Pila p = p_crear();
    Pila p_invertida = p_crear();
    printf("\n\t\t --- Carga de la pila ---\n");
    cargarpila(p);
    printf("\nPila ingresada: ");
    p_mostrar(p);
    p_invertida = p_ej5_invertir(p);
    printf("\nPila invertida: ");
    p_mostrar(p_invertida);
    printf("\n\t\t--- Complejidad algoritmica ---\n");
    printf("el ejercicio tiene complejidad algoritmica O(2n) en el peor de los casos, ya que contiene \ndos ciclos while separados que recorren la pila de tamaño n.\n");
    system("pause");
    return 0;
}

//Punto 6

//Punto 7
int mainElementosComunes()
{
    Pila p1 = p_crear();
    printf("\n\t\t --- Carga de la primera pila ---\n");
    cargarpila(p1);
    p_mostrar(p1);
    Pila p2 = p_crear();
    printf("\n\t\t --- Carga de la segunda pila ---\n");
    cargarpila(p2);
    p_mostrar(p2);
    Pila comunes = p_ej7_elementoscomunes(p1, p2);
    printf("\n\t --- Elementos en común ---\n");
    p_mostrar(comunes);
    printf("\n\t\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("el ejercicio es de complejidad cuadratica (O(n*m)) ya que se deben recorer 2 pilas cuyos tamaños \npueden ser iguales o no, pero la complejidad aumenta dependiendo del tamaño de las pilas.\n");
    system("pause");
    return 0;
}

//Punto 8


void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 TP3 PILAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con pilas\n");
    printf("  3   Pilas iguales\n");
    printf("  4   Conversor de base\n");
    printf("  5   Invertir pila\n");
    printf("  6   Eliminar item\n");
    printf("  7   Elementos en común\n");
    printf("  8   Contador de valores\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

void menu_punto2()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                         2   Operaciones con pilas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Buscar elemento\n");
    printf("  2   Insertar elemento\n");
    printf("  3   Eliminar elemento\n");
    printf("  4   Intercambiar elementos\n");
    printf("  5   Duplicar pila\n");
    printf("  6   Contar elementos\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

int main()
{
    bool salir1 = false;
    bool salir = false;
    int opcion;
    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf("Opción incorrecta\n");
            printf("  Por favor seleccione una opción: ");
            while (getchar() != '\n')
                ;
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                validador = scanf("%i", &opcion);
                while (validador != 1 || opcion < 0 || opcion > 6)
                {
                    printf("Opción incorrecta\n");
                    printf("  Por favor seleccione una opción: ");
                    while (getchar() != '\n')
                        ;
                    validador = scanf("%i", &opcion);
                }
                switch (opcion)
                {
                case 1:
                    //main_buscar_clave();
                    // getch();
                    break;
                case 2:
                    //main_insertar_en_pila();
                    getch();
                    break;
                case 3:
                    //main_eliminar_por_clave();
                    // getch();
                    break;
                case 4:
                    //main_intercambiar();
                    // getch();
                    break;
                case 5:
                    //main_duplicar_pila();
                    getch();
                    break;
                case 6:
                    //main_contador();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            //main_compara_pilas();
            getch();
            break;
        case 4:
            //main_conversor();
            getch();
            break;
        case 5:
            mainInvertida();
            getch();
            break;
        case 6:
            //main_eliminar_ocurrencias();
            getch();
            break;
        case 7:
            mainElementosComunes();
            getch();
            break;
        case 8:
            //main_contador_valores();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}