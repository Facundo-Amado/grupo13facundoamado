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

//Punto 2

//Punto 3

//Punto 4

//Punto 5

//Punto 6
void cargarPila(Pila p) {
    int a;
    for(int i = 0; i < 10; i++){
        printf("Ingrese elemento de la pila: ");
        while( scanf("%d", &a) != 1 ) {
            limpiarBuffer();
            printf("Invalido. Ingrese un numero entero: ");
        }
        TipoElemento temp = te_crear(a);
        p_apilar(p, temp);
        limpiarBuffer();
    }
}

int cargarClave(Pila p) {
    int a;
    printf("\nIngrese clave a borrar: ");
    while( scanf("%d", &a) != 1 ) {
        limpiarBuffer();
        printf("Invalido. Ingrese un numero entero: ");
    }
    limpiarBuffer();

    return a;
}

// Version iterativa
Pila p_ej6_eliminarclave(Pila p, int clave) {
    if (p_es_vacia(p)) {
        return NULL;
    }

    Pila paux = p_crear();
    Pila paux2 = p_crear();
    TipoElemento temp = te_crear(0);

    while(!p_es_vacia(p)) {
        temp = p_tope(p);
        p_apilar(paux, temp);
        temp = p_desapilar(p);
        p_apilar(paux2, temp);
    }

    while(!p_es_vacia(paux)) {
        temp = p_desapilar(paux);
        p_apilar(p, temp);
    }

    while(!p_es_vacia(paux2)) {
        temp = p_desapilar(paux2);
        if (temp->clave != clave) {
            p_apilar(paux, temp);
        }
    }

    return paux;
}

// Version recursiva
Pila eliminarClaveRAUX(Pila p, Pila paux, TipoElemento temp, int clave) {
    if (p_es_vacia(p)) {
        return paux;
    }
    else {
        temp = p_desapilar(p);
        if (temp->clave != clave) {
            p_apilar(paux, temp);
        }

        eliminarClaveRAUX(p, paux, temp, clave);
    }
}

Pila p_ej6_eliminarclave_r(Pila p, int clave) {
    if (p_es_vacia(p)) {
        return NULL;
    }

    Pila paux = p_crear();
    Pila paux2 = p_crear();
    TipoElemento temp = te_crear(0);

    while(!p_es_vacia(p)) {
        temp = p_tope(p);
        p_apilar(paux, temp);
        temp = p_desapilar(p);
        p_apilar(paux2, temp);
    }

    while(!p_es_vacia(paux)) {
        temp = p_desapilar(paux);
        p_apilar(p, temp);
    }

    while(!p_es_vacia(paux2)) {
        temp = p_desapilar(paux2);
        if (temp->clave != clave) {
            p_apilar(paux, temp);
        }
    }

    paux2 = p_crear();
    paux = eliminarClaveRAUX(paux, paux2, temp, clave);

    paux2 = p_crear();
    while(!p_es_vacia(paux)) {
        temp = p_desapilar(paux);
        p_apilar(paux2, temp);
    }

    return paux2;
}


int main_eliminar_ocurrencias() {

    Pila nueva_pila = p_crear();
    cargarPila(nueva_pila);
    
    printf("\n");
    int clave = cargarClave(nueva_pila);
    printf("\n\n");


    p_mostrar(nueva_pila);

    printf("\n\nResuelto iterativamente: \n");
    Pila nueva_pila2 = p_crear();
    nueva_pila2 = p_ej6_eliminarclave(nueva_pila, clave);
    p_mostrar(nueva_pila2);
    printf("Complejidad algoritima lineal, en este caso 3n, ya que hay tres ciclos while consecutivos que dependen de la cantidad de elementos (a mas elementos, mas tardaran los tres, a menos elementos, seran mas rapidos)");

    printf("\n\nResuelto recursivamente: \n");
    Pila nueva_pila_r = p_crear();
    nueva_pila_r = p_ej6_eliminarclave_r(nueva_pila, clave);
    p_mostrar(nueva_pila_r);
    printf("Complejidad algoritmica lineal, en este caso 5n, ya que hay cuatro ciclos while en la funcion principal, y luego la funcion auxiliar recursiva realiza un proceso equivalente a otro ciclo while dependiente de la cantidad de elementos");

    printf("\n\nPila original sin modificar: \n");
    p_mostrar(nueva_pila);
    system("pause");


    return 0;
}

//Punto 7
void cargarpila(Pila p)
{
    int i = 0, tamano, elemento;
    TipoElemento elem;
    printf("ingrese la cantidad de elementos que desea ingresar a la pila: ");
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 10))
    {
        printf("Dato invalido. Ingrese un numero entero entre 1 y 10: ");
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

int mainElementosComunes()
{
    Pila p1 = p_crear();
    printf("\n\t --- Carga de la primera pila ---\n");
    cargarpila(p1);
    p_mostrar(p1);
    Pila p2 = p_crear();
    printf("\n\t --- Carga de la segunda pila ---\n");
    cargarpila(p2);
    p_mostrar(p2);
    Pila comunes = p_ej7_elementoscomunes(p1, p2);
    printf("\n\t --- Elementos en comun ---\n");
    p_mostrar(comunes);
    printf("\n\t\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("el ejercicio es de complejidad cuadratica (O(n*m)) ya que se deben recorer 2 pilas cuyos tamanos \npueden ser iguales o no, pero la complejidad aumenta dependiendo del tamano de las pilas.\n");
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
    printf("  7   Elementos en comun\n");
    printf("  8   Contador de valores\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opcion: ");
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
    printf("  Por favor seleccione una opcion: ");
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
            printf("Opcion incorrecta\n");
            printf("  Por favor seleccione una opcion: ");
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
                    printf("Opcion incorrecta\n");
                    printf("  Por favor seleccione una opcion: ");
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
            main_eliminar_ocurrencias();
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