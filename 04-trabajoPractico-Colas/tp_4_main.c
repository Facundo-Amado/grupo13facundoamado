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
#include "../libs/pila/headers/pilas.h"
#include "../libs/listas/headers/listas.h"


void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}  

int cargarTamano()
{
    int tamano;
    printf("ingrese la cantidad de elementos que desea ingresar a la cola: ");
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 10))
    {
        printf("Dato invalido. Ingrese un numero entero entre 1 y 10: ");
        limpiarBuffer();
    }
    tamano = (int)tamano;
    return tamano;
}

void cargarCola(Cola c, int tamano)
{
    int i = 0, elemento;
    TipoElemento elem;
    while (i< tamano)
    {
        printf("ingrese un elemento de la cola. (solo se admiten numeros enteros): ");
        while (scanf("%d", &elemento) != 1)
        {
            printf("elemento invalido. ingrese un elemento de la cola: ");
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        c_encolar(c, elem);
        i++;
    }
}

void cargarColaej5(Cola c, int tamano)
{
    int i = 0, elemento;
    TipoElemento elem;
    while (i< tamano)
    {
        printf("ingrese un elemento de la cola. (solo se admiten numeros enteros mayores a 2): ");
        while (scanf("%d", &elemento) != 1 || elemento < 2)
        {
            printf("elemento invalido. ingrese un numero mayor a 2: ");
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        c_encolar(c, elem);
        i++;
    }
}
void c_mostrar_con_valor(Cola cola)
{
    if (c_es_vacia(cola)){

        printf("COLA VACIA! \n");
        return;
    }
    Pila paux = p_crear();
    TipoElemento x = te_crear(0);
    printf ("\nContenido de la cola: ");
    while (!c_es_vacia(cola)) 
    {
        x = c_desencolar(cola);
        p_apilar(paux, x);
    }
    while (!p_es_vacia(paux)){

        x = p_desapilar(paux);
        printf("{%d:%lld},", x->clave, (intptr_t)x->valor);
        c_encolar(cola, x);
    }
}
void c_mostrar_con_valortf(Cola cola)
{
    int valor;
    Pila paux = p_crear();
    TipoElemento x = te_crear(0);
    if (c_es_vacia(cola)){

        printf("COLA VACIA! \n");
        return;
    }
    printf ("Contenido de la cola: ");
    while (!c_es_vacia(cola)) 
    {
        x = c_desencolar(cola);
        p_apilar(paux, x);
    }
    while (!p_es_vacia(paux)){

        x = p_desapilar(paux);
        valor = (int)(intptr_t)(x->valor);
        printf("{%d: %s},", x->clave, (valor ? "true" : "false"));
        c_encolar(cola, x);
    }
}

/*Cola cargarColaSinRepetidos(Cola cola, int *tamano)
{
    int elemento, validador;
    bool esRepetido = false;
    limpiarBuffer();
    for (int i = 0; i < *tamano; i++)
    {
        printf("Ingrese clave del elemento a cargar (mayor a 2 y sin repetir): ");
        validador = scanf("%d", &elemento);
        if (c_es_vacia(cola))
        {
            esRepetido = false;
        }
        else
        {
            esRepetido = buscar(cola, elemento);
        }
        limpiarBuffer();
        while (validador != 1 || elemento < 2 || esRepetido)
        {
            printf("elemento invalido. ingrese un numero mayor a 2: ");
            scanf("%d", &elemento);
            limpiarBuffer();
            validador = scanf("%d", &elemento);
            if (c_es_vacia(cola))
                esRepetido = false;
            else
                esRepetido = buscar(cola, elemento);
            limpiarBuffer();
        }
        TipoElemento x = te_crear(elemento);
        c_encolar(cola, x);
    }
    c_mostrar(cola); // muestro la cola como quedo cargada
    printf("\n");
    return cola;
}*/

//Punto 2
//item A

//item B

//item C

//item D

//item E

//item F


//Punto 3


//Punto 4


//Punto 5
int mainDivisores()
{
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    printf("\n\t\t --- Carga de la cola --- \n");    
    int tamano = cargarTamano();
    cargarColaej5(c1, tamano);
    c2 = c_ej5_divisortotal(c1);
    c_mostrar_con_valortf(c2);
    printf("\n\n\t\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("La complejidad de la solución empleada es lineal O(n^2) porque hay varios ciclos que dependen de la cantidad de elementos \nde la cola, y ademas se encuentran anidados.");
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

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

//Menu del Punto 2: Operaciones con cola
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
    int opc1, opc2;
    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opc1);
        while (getchar() != '\n')
            ;
        while (validador != 1 || opc1 < 0 || opc1 > 8 || opc1 == 1)
        {
            printf("Opción incorrecta\n");
            printf("  Por favor seleccione una opción: ");
            validador = scanf("%i", &opc1);
            while (getchar() != '\n');
        }
        switch (opc1)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                validador = scanf("%i", &opc2);
                while (validador != 1 || opc2 < 0 || opc2 > 6)
                {
                    printf("Opción incorrecta\n");
                    printf("  Por favor seleccione una opción: ");
                    while (getchar() != '\n');
                    validador = scanf("%i", &opc2);
                }
                switch (opc2)
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
            mainDivisores();
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