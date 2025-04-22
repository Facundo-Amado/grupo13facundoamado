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

//Punto 2

//Punto 3

//Punto 4

//Punto 5

//Punto 6

//Punto 7

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
            //main_invertida();
            getch();
            break;
        case 6:
            //main_eliminar_ocurrencias();
            getch();
            break;
        case 7:
            //main_elemento_en_comun();
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