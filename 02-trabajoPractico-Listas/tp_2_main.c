#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\listas\headers\tp_2_listas.h"
#include "..\libs\listas\headers\listas.h"

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar()
{
    limpiarBuffer();
    printf("\nPresione Enter para continuar...");
    while (getchar() != '\n');
}

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

/*Lista cargarListaAuto(Lista lista, int tam) 
{
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        int numero_aleatorio = 1 + rand() % (99 - 1 + 1);
        TipoElemento te = te_crear(numero_aleatorio);
        l_agregar(lista, te);
    }
}*/

//Punto 2

void crearlistas(Lista l1, Lista l2)
{
    printf("\n\t --- Cargar primera lista --- \n");    
    cargarLista(l1);
    printf("\n\t --- Cargar segunda lista --- \n");
    cargarLista(l2);
    printf("Pulse enter para volver al menú");
    return;
}

Resultados promedioAmbasListas(Lista l1, Lista l2) {

    Resultados resultado;
    resultado.resultado1 = promedio(l1);
    resultado.resultado2 = promedio(l2);
    return resultado;
}

//puntos a y b
int mainNoRepetidos(Lista l1, Lista l2)
{
    Lista valores = l_crear();
    //a
    valores = verElementosQueNoSeRepiten(l1, l2);
    printf("Valores de l1 que no estan en l2: ");
    l_mostrar(valores);
    printf("\n");
    //b
    valores = verElementosQueNoSeRepiten(l2, l1);
    printf("Valores de l2 que no estan en l1: ");
    l_mostrar(valores);
    return 0;
}

//punto c
int mainRepetidos(Lista l1, Lista l2)
{
    Lista valores = l_crear();
    valores = verElementosRepetidos(l1, l2);
    printf("Elementos comunes a ambas listas: ");
    l_mostrar(valores);
    return 0;
}

//punto d
int mainPromedio(Lista l1, Lista l2)
{
    Resultados resultado = promedioAmbasListas(l1, l2);
    printf("Promedio de l1: %f\nPromedio de l2: %f", resultado.resultado1, resultado.resultado2);
    return 0;
}

//punto e
int mainMenorValor(Lista l1, Lista l2)
{
    ResultadoValorMinimo valorMenor = valorMinimo(l1, l2);
    printf("Menor valor de la lista 1: %d. Está en la posición %d",valorMenor.valor, valorMenor.pos);
    printf("Menor valor de la lista 2: %d. Está en la posición %d",valorMenor.valor_2, valorMenor.pos_2);
    return 0;
}

//Punto 3
int mainMultiplo() {
    int n1, n2;

    // Crear y llenar la Lista 1
    printf("Ingrese la cantidad de elementos para la Lista 1: ");
    Lista l1 = l_crear();
    while (scanf("%d", &n1) != 1 || n1 <= 0) {
        limpiarBuffer();
        printf("Error: ingrese un numero entero positivo para el tamano: ");
    }
    
    if (n1 <= 0) {
        printf("Tamano invalido.\n");
        return 1;
    }

    printf("Ingrese los %d elementos de la Lista 1:\n", n1);
    for (int i = 0; i < n1; i++) {
        int valor;
        printf("Elemento %d: ", i + 1);
        while (scanf("%d", &valor) != 1 || valor == 0) {
            limpiarBuffer();
            printf("Error: ingrese un numero entero valido para el elemento %d: ", i + 1);
        }
        l_agregar(l1, te_crear(valor));
    }

    // Crear y llenar la Lista 2
    printf("Ingrese la cantidad de elementos para la Lista 2: ");
    Lista l2 = l_crear();
    while (scanf("%d", &n2) != 1 || n2 <= 0) {
        limpiarBuffer();
        printf("Error: ingrese un numero entero positivo para el tamano: ");
    }
    
    if (n2 <= 0) {
        printf("Tamano invalido.\n");
        return 1;
    }

    printf("Ingrese los %d elementos de la Lista 2:\n", n2);
    for (int i = 0; i < n2; i++) {
        int valor;
        printf("Elemento %d: ", i + 1);
        while (scanf("%d", &valor) != 1 || valor == 0) {
            limpiarBuffer();
            printf("Error: ingrese un numero entero valido para el elemento %d: ", i + 1);
        }
        l_agregar(l2, te_crear(valor));
    }

    // Verificar si L2 es múltiplo de L1
    ResultadosMul resultado = multiplo(l1, l2);

    if (!resultado.esMultiplo) {
        printf("L2 NO es multiplo de L1.\n");
    } else {
        printf("L2 ES multiplo de L1.\n");
        if (resultado.escalar) {
            printf("Es ESCALAR con el numero %d.\n", resultado.numEscalar);
        }
    }
    return 0;
}

//Punto 4
Lista cargarlistas(Lista l){
    float entrada;
    int tam, i = 0;
    printf("Ingrese la cantidad de elementos para la lista: ");
    while (scanf("%d", &tam) != 1 || tam <= 0) 
    {
        limpiarBuffer();
        printf("Error: ingrese un numero entero positivo para el tamano: ");
    }
    while (i < tam)
    {
        printf("ingrese un numero:");
        while (scanf("%f", &entrada) != 1)
        {
            printf("Error. Solo se admiten numeros enteros y flotantes\n");            
            printf("ingrese un numero:");
            scanf("%f", &entrada);
            limpiarBuffer();

        }
        l_agregar(l, te_crear(entrada));
        i++;
    }
    return l;
}

int mainComparar()
{
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    printf("\n --- Comparador de listas de igual tamaño --- ");    
    printf("\n\t --- Cargar primera lista --- \n");    
    cargarlistas(l1);
    l_mostrar(l1);
    printf("\n\t --- Cargar segunda lista --- \n");
    cargarlistas(l2);
    l_mostrar(l2);
    int res = CompararListas(l1,l2);
    if (res == 0)
    {
        printf("\nLas listas son iguales\n");
    }
    if(res == 1)
    {
        printf("\nL1 es mayor a L2\n");
    }
    if(res == 2)
    {
        printf("\nL1 es menor a L2\n");
    }
    printf("\n\t --- Complejidad algoritmica del ejercicio ---\n");
    printf("el ejercicio es de complejidad lineal, ya que cuenta con una sola estructura iterativa de complejidad O(n).\n");
    return 0;
}

//Punto 5
void mostrarComplejidad() {
    printf("\n=== Complejidad Algoritmica ===\n");
    printf("Ingreso del polinomio: O(n), donde n es la cantidad de terminos del polinomio\n");
    printf("Evaluacion de polinomio: O(n)\n");
    printf("Calcular rango: O(m x n), con m = cantidad de puntos evaluados entre [desde, hasta] segun el intervalo.\n");
}

int mainPolinomio() {
    Lista polinomio = l_crear();
    printf("=== Calculo de valores de un polinomio ===\n");
    printf("\n");
    printf("=== Ingreso del polinomio ===\n");
    hacerPolinomio(polinomio);

    if(l_es_vacia(polinomio)) {
        printf("Error: no se ingreso ningun polinomio.\n");
        return EXIT_FAILURE;
    }

    double desde, hasta, intervalo;
    printf("\n=== Evaluacion en rango ===\n");
    printf("Desde X: ");
    scanf("%lf", &desde);
    printf("Hasta X: ");
    scanf("%lf", &hasta);

    printf("Intervalo: ");
    scanf("%lf", &intervalo);

    if (intervalo == 0.0) {
        printf("Error: el intervalo no puede ser cero.\n");
        return EXIT_FAILURE;
    }

    if ((hasta - desde) * intervalo < 0) {
        printf("Error: el intervalo no es coherente con el rango.\n");
        return EXIT_FAILURE;
    }

    Lista resultados = calcularRango(polinomio, desde, hasta, intervalo);

    printf("\n=== Resultados F(x) ===\n");
    Iterador it = iterador(resultados);
    int i = 0;
    for (double x = desde; hay_siguiente(it); x += intervalo) {
        TipoElemento te = siguiente(it);
        double* fx = (double*)te->valor;
        printf("F(%.2lf) = %.2lf\n", x, *fx);
        free(fx);
        i++;
    }

    it = iterador(polinomio);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        free(te->valor);
    }

    // mostrarComplejidad();

    return EXIT_SUCCESS;
}

//Punto 6
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
    printf("\n\t --- Complejidad algoritmica del ejercicio ---\n");
    printf("el ejercicio es de complejidad cuadratica (O(n*m)) ya que las operaciones de mayor complejidad \nutilizadas son 2 while anidados. cada while se itera n veces, lo que equivale a n*n 0 n^2.\n");
    return 0;
}


void menuPrincipal()
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

void menuPunto2()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                         2   Operaciones con listas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Crear Listas\n");
    printf("  2   Claves no repetidas\n");
    printf("  3   Claves repetidas\n");
    printf("  4   Promedio de claves\n");
    printf("  5   Menor valor\n");
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
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    bool listasCargadas = false;
    bool salir1 = false;
    bool salir = false;
    int opcion;
    while (!salir)
    {
        menuPrincipal();
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
                menuPunto2();
                scanf("%i", &opcion);
                while (opcion < 0 || opcion > 5)
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
                    crearlistas(l1, l2);
                    listasCargadas = true;
                    pausar();
                    break;
                case 2:
                    if (listasCargadas) 
                    {
                        mainNoRepetidos(l1, l2);
                    }
                    else 
                    {
                        printf("Primero debe cargar las listas (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 3:
                    if (listasCargadas) 
                    {
                        mainRepetidos(l1, l2);
                    }
                    else 
                    {
                        printf("Primero debe cargar las listas (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 4:
                    if (listasCargadas) 
                    {
                        mainPromedio(l1, l2);
                    }
                    else 
                    {
                        printf("Primero debe cargar las listas (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 5:
                    if (listasCargadas) 
                    {
                        mainMenorValor(l1, l2);
                    }
                    else 
                    {
                        printf("Primero debe cargar las listas (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menuPrincipal();
        case 3:
            mainMultiplo();
            pausar();
            break;
        case 4:
            mainComparar();
            pausar();
            break;
        case 5:
            mainPolinomio();
            pausar();
            break;
        case 6:
            mainSublista();
            pausar();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}