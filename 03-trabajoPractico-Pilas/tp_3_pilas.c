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

//Punto 6

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