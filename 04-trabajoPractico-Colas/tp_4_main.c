#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/cola/headers/colas.h"
#include "../libs/cola/headers/tp_4_colas.h"



//Punto 2


//Punto 3


//Punto 4


//Punto 5


//Punto 6


//Punto 7



//menu
void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 TP4 COLAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con colas\n");
    printf("  3   Colas iguales\n");
    printf("  4   Elementos no repetidos\n");
    printf("  5   Divisores\n");
    printf("  6   Lista con valores comunes\n");
    printf("  7   Cola de clientes\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

/// @brief Menu del Punto 2: Operaciones con cola
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
    printf("  4   Contar los elementos\n");
    printf("  5   Realizar una copia\n");
    printf("  6   Invertir\n");
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
        while (getchar() != '\n')
            ;
        while (validador != 1 || opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf("Opción incorrecta\n");
            printf("  Por favor seleccione una opción: ");
            validador = scanf("%i", &opcion);
            while (getchar() != '\n')
                ;
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
                    //main_buscarElemento();
                    getch();
                    break;
                case 2:
                    //main_insertar_en_cola();
                    getch();
                    break;
                case 3:
                    //main_eliminar_repeticiones();
                    // main_borrar();
                    getch();
                    break;
                case 4:
                    //main_contador();
                    getch();
                    break;
                case 5:
                    //main_clonar();
                    getch();
                    break;
                case 6:
                    //main_invertida();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            //main_punto3();
            // getch();
            break;
        case 4:
            //main_punto4();
            // getch();
            break;
        case 5:
            //main_divisores();
            getch();
            break;
        case 6:
            //main_valores_comunes();
            // getch();
            break;
        case 7:
            //main_ventanillas();
            // getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}