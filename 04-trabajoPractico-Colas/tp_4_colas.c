#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/cola/headers/colas.h"
#include "../libs/cola/headers/tp_4_colas.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/listas/headers/listas.h"


//Punto 2
//item a
bool c_ej2_existeclave(Cola c, int clave)
{
    TipoElemento x;
    Cola caux = c_crear();
    bool encontrado = false;
    while (!c_es_vacia(c) && !encontrado)
    {
        x = c_desencolar(c);
        if (clave == x->clave)
        {
            encontrado = true;
        }
        c_encolar(caux, x);
    }
    while(!c_es_vacia(caux))
    {
        c_encolar(c, c_desencolar(caux));
    }
    return encontrado;
}

//item b
Cola c_ej2_colarelemento(Cola c, int pos, TipoElemento x)
{
    Cola caux = c_crear();
    int i = 1;
    TipoElemento x1;
    while(!c_es_vacia(c))
    {
        x1 = c_desencolar(c);
        if (i == pos)
        {
            c_encolar(caux, x);
        }
        c_encolar(caux, x1);
        i++;
    }
    while (!c_es_vacia(caux))
    {
        c_encolar(c, c_desencolar(caux));
    }
    return c;
}


//item c
Cola c_ej2_sacarelemento(Cola c, int clave)
{
    TipoElemento x;
    Cola caux = c_crear();
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        if (clave != x->clave)
        {
               c_encolar(caux, x);
        }
    }
    while (!c_es_vacia(caux))
    {
        c_encolar(c, c_desencolar(caux));
    }
    return c;   
}

//item d
//item e
//item f

//Punto 3
bool c_ej3_iguales(Cola c1, Cola c2){
    Cola aux = c_crear();
    bool sonIguales = true;
    TipoElemento elem1, elem2; 
    while(!c_es_vacia(c1) && !c_es_vacia(c2)){
        elem1 = c_desencolar(c1);
        elem2 = c_desencolar(c2);
        if(elem1->clave != elem2->clave)
        {
            sonIguales = false;
        }
                c_encolar(aux, elem1);
        c_encolar(aux, elem2);
    }
    while(!c_es_vacia(aux))
    {
        c_encolar(c1, c_desencolar(aux));
        c_encolar(c2, c_desencolar(aux));
    }
    return sonIguales;
}

//Punto 4
Cola c_ej4_colanorepetidos(Cola c) 
{  
    Cola aux = c_crear(), aux2 = c_crear(), sinRepetidos = c_crear();
    Pila paux = p_crear();
    TipoElemento x, x1, x2;
    bool repetido;
    while (!c_es_vacia(c)) 
    {
        x1 = c_desencolar(c);
        repetido = false;
        while (!c_es_vacia(c)) 
        {
            x2 = c_desencolar(c);
            if (x2->clave == x1->clave) {
                repetido = true;
            }
            c_encolar(aux2, x2);
        }
        if (!repetido) 
        {
            c_encolar(sinRepetidos, x2);
        }
        c_encolar(aux, x1);
        while (!c_es_vacia(aux2)) 
        {
            c_encolar(c, c_desencolar(aux2));
        }
    }
    while(!c_es_vacia(sinRepetidos))
    {
        p_apilar(paux, c_desencolar(sinRepetidos));
    }
    while(!p_es_vacia(paux))
    {
        c_encolar(sinRepetidos, p_desapilar(paux));
    }
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }
    return sinRepetidos;
}

//Punto 5
Cola c_ej5_divisortotal(Cola c)
{
    int contDiv = 0, tamano = 0;
    TipoElemento x, x2, elemtot, elemparcial;
    Cola aux = c_crear(), aux2 = c_crear(), temp = c_crear(), divTotales = c_crear(), divParciales = c_crear(), copia = c_crear();
    bool divTotal, divParcial;
    if (c_es_vacia(c))
    {
        return c;
    }
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        c_encolar(aux, x);
        c_encolar(aux2, x);
        c_encolar(copia, x);
        tamano ++;
    }
    while (!c_es_vacia(aux))
    {
        divTotal = false; 
        divParcial = false;
        contDiv = 0;
        x = c_desencolar(aux);
        while (!c_es_vacia(aux2))
        {
            x2 = c_desencolar(aux2);
            if (x2->clave % x->clave == 0)
            {
                contDiv ++;
            }
            c_encolar(temp, x2);
        }
        while (!c_es_vacia(temp))
        {
            c_encolar(aux2, c_desencolar(temp));
        }
        if (contDiv == tamano)
        {
            divTotal = true;
        }
        else if (contDiv >= tamano/2)
        {
            divParcial = true;
        }
        elemtot = te_crear_con_valor(x->clave, (void*)(intptr_t)divTotal);
        elemparcial = te_crear_con_valor(x->clave, (void*)(intptr_t)divParcial);
        c_encolar(divTotales, elemtot);
        c_encolar(divParciales, elemparcial);
    }
    while (!c_es_vacia(copia)) {
        c_encolar(c, c_desencolar(copia));
    }
    return divTotales;
}


//Punto 6


//Punto 7