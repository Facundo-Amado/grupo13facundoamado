#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../tipoElemento/headers/tipo_elemento.h"
#include "../cola/headers/colas.h"
#include "../cola/headers/tp_4_colas.h"
#include "../pila/headers/pilas.h"
#include "../listas/headers/listas.h"

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}  

void pausar()
{
    limpiarBuffer();
    while (getchar() != '\n');
}

//ingreso de datos

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
        printf("ingrese un elemento de la pila. (solo se admiten numeros enteros): ");
        while (scanf("%d", &elemento) != 1)
        {
            printf("elemento invalido. ingrese un elemento de la pila: ");
            scanf("%d", &elemento);
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        p_apilar(p, elem);
        i++;
    }
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

int cargarTamanoej3()
{
    int tamano;
    printf("ingrese la cantidad de elementos que desea ingresar a la cola(no mas de 5): "); //si ingresa mas de 5 la cola auxiliar de la funcion del ejercicio tendria mas elementos de los admitidos por la TAD
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 5))
    {
        printf("Dato invalido. Ingrese un numero entero entre 1 y 5: ");
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
            printf("elemento invalido. ingrese un numero entero positivo: ");
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        c_encolar(c, elem);
        i++;
    }
}

Cola cargarColaSinRepetidos(Cola cola, int tamano)
{
    int elemento, validador;
    bool esRepetido = false;
    limpiarBuffer();
    for (int i = 0; i < tamano; i++)
    {
        printf("Ingrese clave del elemento a cargar (mayor a 2 y sin repetir): ");
        validador = scanf("%d", &elemento);
        if (c_es_vacia(cola))
        {
            esRepetido = false;
        }
        else
        {
            esRepetido = c_ej2_existeclave(cola, elemento);
        }
        limpiarBuffer();
        while (validador != 1 || elemento < 2 || esRepetido)
        {
            printf("elemento invalido. ingrese un numero mayor a 2 sin repetir: ");
            scanf("%d", &elemento);
            limpiarBuffer();
            validador = scanf("%d", &elemento);
            if (c_es_vacia(cola))
                esRepetido = false;
            else
                esRepetido = c_ej2_existeclave(cola, elemento);
            limpiarBuffer();
        }
        TipoElemento x = te_crear(elemento);
        c_encolar(cola, x);
    }
    c_mostrar(cola); // muestro la cola como quedo cargada
    printf("\n");
    return cola;
}

Cola cargarColaPositivos() {
    Cola resultante = c_crear();

    int tamano;
    printf("ingrese tamano de la cola: ");
    while(scanf("%d", &tamano) != 1 || tamano < 1 || tamano > 10) {
        limpiarBuffer();
        printf("invalido. ingrese numero entre 1 y 10: ");
    }
    limpiarBuffer();

    int dato;
    for(int i = 1; i <= tamano; i++) {
        printf("ingrese numero: ");
        while(scanf("%d", &dato) != 1 || dato < 1) {
            limpiarBuffer();
            printf("invalido, debe ser un numero, y mayor a cero: ");
        }
        limpiarBuffer();
        c_encolar(resultante, te_crear(dato));
    }

    return resultante;
}

//funciones para mostrar


void l_mostrar_con_valor(Lista l)
{
    if (l_es_vacia(l)){

        printf("LISTA VACIA! \n");
        return;
    }
    printf("Contenido de la lista: ");
    for (int i = 1; i < l_longitud(l); i++) 
    {
        TipoElemento elem = l_recuperar(l, i);
        printf("%d:%s ", elem->clave, (char*)elem->valor);
    }
    printf("\n");
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