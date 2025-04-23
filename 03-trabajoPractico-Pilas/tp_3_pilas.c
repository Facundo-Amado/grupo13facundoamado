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
Pila  p_ej5_invertir(Pila p){
    Pila p_invertida = p_crear();
    Pila aux = p_crear();
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        p_apilar(p_invertida, elem);
        p_apilar(aux, elem);
    }
    while (!p_es_vacia(aux)){
        TipoElemento elemento = p_desapilar(aux);
        p_apilar(p, elemento);
    }
    return p_invertida;
}

//Punto 6

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
    printf("\n\t\t\t--- Complejidad algoritmica ---\n");
    printf("La complejidad algoritima es lineal, en este caso 3n, ya que hay tres ciclos while consecutivos \nque dependen de la cantidad de elementos (a mas elementos, mas tardaran los tres, a menos elementos, \nseran mas rapidos)\n");
    return paux;
}

// Version recursiva
Pila p_ej6_eliminarclave_r(Pila p, int clave) {
    Pila paux = p_crear();
    TipoElemento temp = te_crear(0);
    if (p_es_vacia(p)) {
        return paux;
    }
    else {
        temp = p_desapilar(p);
        if (temp->clave != clave) {
            p_apilar(paux, temp);
        }
        p_ej6_eliminarclave_r(p, clave);
        p_apilar(p, temp);
    }
    return paux;
}

//Punto 7
Pila copiarpila(Pila p)
{
    Pila copia = p_crear();
    Pila aux = p_crear();

    while (!p_es_vacia(p)) {
        TipoElemento elemento = p_desapilar(p);
        p_apilar(aux, elemento);
        p_apilar(copia, elemento);
    }
    while (!p_es_vacia(aux)) {
        TipoElemento elemento = p_desapilar(aux);
        p_apilar(p, elemento);
    }
    return copia;
}

Pila p_ej7_elementoscomunes(Pila p1, Pila p2)
{
    Pila elemcomunes = p_crear();
    Pila p1copia = copiarpila(p1);
    Pila p2copia = copiarpila(p2);
    TipoElemento te1;
    TipoElemento te2;
    while (!p_es_vacia(p1copia))
    {
        te1 = p_desapilar(p1copia);
        p2copia = copiarpila(p2);
        while (!p_es_vacia(p2copia))
        {
            te2 = p_desapilar(p2copia);
            if (te1->clave == te2->clave)
            {
                p_apilar(elemcomunes, te1);
            }
        }    
    }
    return elemcomunes;
}

//Punto 8