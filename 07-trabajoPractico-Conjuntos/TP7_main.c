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
int main_punto2()
{
    Conjunto Cinterseccion, Cunion, Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    printf("\n\t --- Carga del primer conjunto ---\n");
    A = cargarConjunto();
    printf("\n\t --- Carga del segundo conjunto ---\n");
    B = cargarConjunto();

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);

    bool pertenece = false;

    if (cardA == 0 && cardB == 0)
    {
        printf("Los conjuntos estan vacíos\n");
    }
    else
    {
        Cinterseccion = c_ej2_interseccion(A, B);
        Cdiferencia = c_ej2_diferencia(A, B);
        Cunion = c_ej2_union(A, B);
        pertenece = p2_pertenece(A, B);
        printf("Intersección: \n");
        cto_mostrar(Cinterseccion);
        printf("Diferencia de A con B: \n");
        cto_mostrar(Cdiferencia);
        printf("Diferencia de B con A: \n");
        Cdiferencia = c_ej2_diferencia(B, A);
        cto_mostrar(Cdiferencia);
        printf("Unión: \n");
        cto_mostrar(Cunion);
        printf("Pertenencia: \n");
        if (cardA <= cardB)
        {
            if (pertenece)
            {
                printf("El conjunto de A pertenece al conjunto de B\n");
            }
            else{
                printf("El conjunto de A NO pertenece al conjunto de B y viceversa\n");
            }
        }
        else{
            if (pertenece)
            {
                printf("El conjunto de B pertenece al conjunto de A\n");
            }
            else{
                printf("El conjunto de B NO pertenece al conjunto de A y viceversa\n");
            }
        }
        limpiarBuffer();
        pausar();
    }
    return 0;
}

//punto 3
int main_punto3()
{
    const int MIN = 2;
    const int MAX = 10;
    int cant_c;
    Lista lista_c = l_crear();
    Conjunto C = cto_crear();
    Conjunto C2 = cto_crear();
    printf("Cuantos conjuntos desea cargar? entre [2 - 10]: ");
    int validador = scanf("%d", &cant_c);
    limpiarBuffer();
    while (validador != 1 || cant_c < MIN || cant_c > MAX)
    {
        printf("----- ERROR -----");
        printf("DATO fuera de rango, ingrese una cantidad entre 2 y 10: ");
        validador = scanf("%d", &cant_c);
        limpiarBuffer();
    }
    for (int i = 0; i < cant_c; i++)
    {
        Conjunto conjunto = cto_crear();
        printf("\n\t --- Carga del conjunto ---\n");
        conjunto = cargarConjunto();
        TipoElemento x = te_crear_con_valor(i, conjunto);
        l_agregar(lista_c, x);
    }

    C = c_ej3_uniones(lista_c);
    printf("\nUnion de los conjuntos: ");
    cto_mostrar(C);
    C2 = c_ej3_intersecciones(lista_c);
    printf("\n intersecciones de los conjuntos: ");
    cto_mostrar(C2);
    pausar();
    return 0;
}

//punto 
int main_punto4() {
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    printf("\n\t --- Carga del primer conjunto ---\n");
    A = cargarConjunto();
    limpiarBuffer();
    printf("\n\t --- Carga del segundo conjunto ---\n");
    B = cargarConjunto();
    limpiarBuffer();
    printf("\n\t --- Carga del tercer conjunto ---\n");
    C = cargarConjunto();
    limpiarBuffer();
    if (c_ej4_transitividad(A, B, C)) {
        printf("\nSe cumple la transitividad\n");
    } else {
        printf("\nNo se cumple la transitividad\n");
    }
    return 0;
}

//punto 5
int main_punto5()
{
    Conjunto Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    printf("\n\t --- Carga del primer conjunto ---\n");
    A = cargarConjunto();
    printf("\n\t --- Carga del segundo conjunto ---\n");
    B = cargarConjunto();

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);

    if (cardA == 0 && cardB == 0)
    {
        printf("Los conjuntos estan vacíos\n");
    }
    else
    {
        printf("Diferencia simétrica: \n");
        Cdiferencia = c_ej5_dif_simetrica(A, B);
        cto_mostrar(Cdiferencia);
        limpiarBuffer();
        pausar();
    }
    return 0;
}

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
int main(){
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    int cant, res;
    bool valido;
    c_ej7_subconjtotalparcial(A, B, C);
    printf("\nComplejidad algoritmica:\n");
    printf("Sin tener en cuenta la TAD: O(n)\n");
    printf("Teniendo en cuenta la TAD: O(n^2)\n");
    pausar();
    return 0;
}

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

