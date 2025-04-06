#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

//Punto 1

//Punto 2

//Punto 3

//Punto 4

//Punto 5

//Punto 6

void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 TP2 LISTAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con listas\n");
    printf("  3   Múltiplo\n");
    printf("  4   Comparar 2 listas\n");
    printf("  5   Polinomio\n");
    printf("  6   Sublista\n");
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
    printf(" |                         2   Operaciones con listas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Menor de los datos\n");
    printf("  2   Mayor de los datos\n");
    printf("  3   Promedio\n");
    printf("  4   Lista de múltiplos\n");
    ;
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
        scanf("%d", &opcion);
        while (opcion < 0 || opcion > 6 || opcion == 1)
        {
            printf("Opción incorrecta\n");
            printf("Por favor seleccione una opción: ");
            while (getchar() != '\n')
                ;
            scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                scanf("%i", &opcion);
                while (opcion < 0 || opcion > 4)
                {
                    printf("Opción incorrecta\n");
                    printf("Por favor seleccione una opción: ");
                    while (getchar() != '\n')
                        ;
                    scanf("%i", &opcion);
                }
                switch (opcion)
                {
                case 1:
                    main_menor();
                    getch();
                    break;
                case 2:
                    main_mayor();
                    getch();
                    break;
                case 3:
                    main_promedio();
                    getch();
                    break;
                case 4:
                    main_multiplos();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            main_multiplo();
            getch();
            break;
        case 4:
            main_comparar();
            getch();
            break;
        case 5:
            main_polinomio();
            getch();
            break;
        case 6:
            main_sublista();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}