#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "tipo_elemento.h"
#include "tp_2_listas.h"
#include "listas.h"

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//Punto 2

//Punto 3

//Punto 4

//Punto 5

//Punto 6
Lista cargarLista(Lista l)
{
    int i = 0;
    int tamano;
    int elemento;
    TipoElemento elem;
    printf("ingrese la cantidad de elementos que desea ingresar en la lista: ");
    while ((scanf("%d", &tamano) != 1) || (tamano < 0 || tamano > 99))
    {
        printf("dato invalido. ingrese la cantidad de elementos que desea ingresar en la lista: ");
        scanf("%d", &tamano);
        limpiarBuffer();
    }
    tamano = (int)tamano;
    while(i < tamano)
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
        l_agregar(l, elem);
        i++;
    }
    return l;
}

int mainSublista()
{
    printf("\t--- Carga de la lista 1 ---\n");
    Lista l1 = l_crear();
    l1 = cargarLista(l1);
    printf("\t--- Carga de la lista 2 ---\n");
    Lista l2 = l_crear();
    l2 = cargarLista(l2);
    bool rta = esSublista(l1, l2);
    if (rta == true)
    {
    printf("\nla lista 2 es sublista de la lista 1");
    }
    else
    {
        printf("\nla lista 2 no es sublista de la lista 1");
        rta = esSublista(l2, l1);
        if (rta == true)
        {
            printf("\nla lista 1 es sublista de la lista 2");
        }
        else
        {
            printf("\nla lista 1 no es sublista de la lista 2");
        }
    }
    return 0;
}


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
                    //main_menor();
                    getch();
                    break;
                case 2:
                    //main_mayor();
                    getch();
                    break;
                case 3:
                    //main_promedio();
                    getch();
                    break;
                case 4:
                    //main_multiplos();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            //menu_principal();
        case 3:
            //main_multiplo();
            getch();
            break;
        case 4:
            //mainComparar();
            getch();
            break;
        case 5:
            //main_polinomio();
            getch();
            break;
        case 6:
            mainSublista();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}