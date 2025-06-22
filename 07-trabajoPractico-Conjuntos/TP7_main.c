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
int main_punto6(){
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    int opcion, res;
    bool esSubConj;

     printf("\n\t --- Carga del primer conjunto ---\n");
    A = cargarConjunto();
    limpiarBuffer();
    printf("\n\t --- Carga del segundo conjunto ---\n");
    B = cargarConjunto();
    limpiarBuffer();

    do{
        printf("\n--- Menu ejercicio 6 ---\n");
        printf("\n1- Determinar si A es subconjunto de B.\n");
        printf("\n2- Determinar si B es subconjunto de A.\n");
        res = scanf("%d", &opcion);
        if(res != 1){
            limpiarBuffer();
        }
    } while(res != 1 || opcion < 1 || opcion > 2);

    switch(opcion){
        case 1:
            esSubConj = c_ej6_subconjuntopropio(A, B);
	        if(esSubConj){
		        printf("\nA es subconjunto de B.\n");
	        } else{
		        printf("\nA no es subconjunto de B.\n");
	        }

            printf("\nComplejidad algoritmica: \n");
            printf("\nLa funcion de este ejercicio es O(n), ya que recorre n veces los elementos del conjunto A.\n");
            printf("Si usamos la TAD Conjunto implementada con listas, la complejidad es O(n * m), porque la funcion cto_pertenece recorre todos los elementos del conjunto B.\n");
            printf("En cambio, si usamos la TAD Conjunto con arboles AVL, la complejidad es O(n * log m), ya que cto_pertenece utiliza una funcion recursiva propia de AVL que busca en tiempo logaritmico.\n");
            break;
        case 2:
            esSubConj = c_ej6_subconjuntopropio(B, A);
	        if(esSubConj){
	        	printf("\nB es subconjunto de A.\n");
	        } else{
	        	printf("\nB no es subconjunto de A.\n");
	        }
            printf("\n\t\t\t\t --- Complejidad algoritmica del ejercicio ---\n");
            printf("\nLa funcion de este ejercicio es O(n), ya que recorre n veces los elementos del conjunto A. Si usamos la TAD Conjunto \nimplementada con listas, la complejidad es O(n * m), porque la funcion cto_pertenece recorre todos los elementos \ndel conjunto B. En cambio, si usamos la TAD Conjunto con árboles \nAVL, la complejidad es O(n * log m), ya que cto_pertenece utiliza una funcion recursiva propia de AVL que busca en \ntiempo logaritmico.\n");
            break;
        default:
            break;
    }
    pausar();
    return 0;
}

//punto 7

//punto 8
int main_punto8()
{
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    bool iguales;
    printf("\n\t --- Carga del primer conjunto ---\n");
    A = cargarConjunto();
    limpiarBuffer();
    printf("\n\t --- Carga del segundo conjunto ---\n");
    B = cargarConjunto();
    limpiarBuffer();

    if (cto_cantidad_elementos(A) != cto_cantidad_elementos(B))
    {
        printf("\n\nLos conjuntos NO son iguales pues no tiene el mismo tamaño uno del otro!\n");
    }
    else
    {
        iguales = c_ej8_soniguales(A, B);
        if (iguales == true)
        {
            printf("\n\nAmbos conjuntos son iguales\n");
        }
        else
        {
            printf("\n\nLos conjuntos son distintos\n");
        }
    }
    printf("\n\t\t\t\t --- Complejidad algoritmica del ejercicio ---\n");
    printf("La complejidad algorítmica utilizando la implementación de Arboles AVL seria O(n * log n) ya que el 'cto_recuperar' \nes O(n) y el 'cto_pertenece' es O(log n), resultado en Orden lineal * logaritmo, que su vez se repite n veces por el \nwhile que depende de la cantidad de elementos del subconjunto.\n\nLa complejidad algorítmica utilizando la implementación de listas seria O(n^2) ya que 'cto_recuperar' es O(n) y el \n'cto_pertenece' O(n) que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto.\n");
    pausar();
    return 0;
}

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
            //main_punto2();
            break;
        case 3:
            //main_punto3();
            break;
        case 4:
            //main_punto4();
            break;
        case 5:
            //main_punto5();
            break;
        case 6:
            main_punto6();
            break;
        case 7:
            //main_punto7();
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

