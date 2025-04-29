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


//Punto 3


//Punto 4


//Punto 5
Cola c_ej5_divisortotal(Cola c)
{
    int contDiv = 0, tamano = 0;
    TipoElemento x, x2, elemtot, elemparcial;
    Cola aux = c_crear(), aux2 = c_crear(), temp = c_crear(), divTotales = c_crear(), divParciales = c_crear();
    Pila copia = p_crear();
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
        p_apilar(copia, x);
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
    while (!p_es_vacia(copia)) {
        c_encolar(c, p_desapilar(copia));
    }
    return divTotales;
}


//Punto 6


//Punto 7