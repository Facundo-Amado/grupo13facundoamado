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
bool es_subconjunto(Conjunto A, Conjunto B) {
    int n = cto_cantidad_elementos(A);
    for (int i = 1; i <= n; i++) {
        TipoElemento elem = cto_recuperar(A, i);
        if (!cto_pertenece(B, elem->clave)) {
            return false;
        }
    }
    return true;
}

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C) {
    bool A_en_B = es_subconjunto(A, B);
    bool B_en_C = es_subconjunto(B, C);
    if (A_en_B && B_en_C) {
        
        bool A_en_C = es_subconjunto(A, C);
        return A_en_C;
    }
    return false;
}

//punto 5

//punto 6
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){
    if(cto_es_vacio(B)){
        return false;
    }
    int cantidadA = cto_cantidad_elementos(A);
    for(int i = 1; i <= cantidadA; i++)
    {
        TipoElemento elem = cto_recuperar(A, i);
        if(!cto_pertenece(B, elem->clave)){
            return false;  
        }
    }
    if(cantidadA == cto_cantidad_elementos(B)){
        return false; 
    }
    return true;
}

//punto 7

//punto 8
bool c_ej8_soniguales(Conjunto a, Conjunto b)
{
    TipoElemento x = te_crear(0);
    int cantidad = cto_cantidad_elementos(a);

    for (int i = 1; i <= cantidad; i++)
    {
        x = cto_recuperar(a, i);
        if (!cto_pertenece(b, x->clave))
        {
            return false;
        }
    }
    return true;
}