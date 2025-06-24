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
Conjunto c_ej2_interseccion(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        if (cto_pertenece(B, X->clave))
        {
            cto_agregar(res, X);
        }
    }
    return res;
}

Conjunto c_ej2_union(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        cto_agregar(res, X);
    }

    card = cto_cantidad_elementos(B);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(B, i);
        if (!cto_pertenece(res, X->clave))
            cto_agregar(res, X);
    }

    return res;
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        if (!cto_pertenece(B, X->clave))
        {
            cto_agregar(res, X);
        }
    }
    return res;
}

//punto 3
Conjunto c_ej3_uniones(Lista lista_c)
{
    Conjunto rta = cto_crear();
    TipoElemento x = te_crear(0);
    TipoElemento c = te_crear(0);
    int card;
    int largo = l_longitud(lista_c);

    for (int i = 0; i < largo; i++)
    {
        x = l_recuperar(lista_c, i + 1);
        card = cto_cantidad_elementos((Conjunto)x->valor);
        for (int j = 1; j <= card; j++)
        {
            c = cto_recuperar(x->valor, j);
            if (!cto_pertenece(rta, c->clave))
            {
                cto_agregar(rta, c);
            }
        }
    }
    return rta;
}

Conjunto c_ej3_intersecciones(Lista lista_c)
{
    Conjunto rta = cto_crear();
    TipoElemento x = te_crear(0);
    TipoElemento c = te_crear(0);
    TipoElemento c2 = te_crear(0);
    int card, existe = 0;
    int largo = l_longitud(lista_c);

    c = l_recuperar(lista_c, 1);
    card = cto_cantidad_elementos((Conjunto)c->valor);
    for (int i = 1; i <= card; i++)
    {
        x = cto_recuperar(c->valor, i);
        for (int j = largo; j > 1; j--)
        {
            c2 = l_recuperar(lista_c, j);
            if (cto_pertenece(c2->valor, x->clave))
            {
                existe++;
            }
        }
        if (existe == (largo - 1))
        {
            cto_agregar(rta, x);
        }
        existe = 0;
    }
    return rta;
}

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
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    Conjunto difA = cto_diferencia(A, B);
    Conjunto difB = cto_diferencia(B, A);
    res = cto_union(difA, difB);
    free(difA);
    free(difB);
    return res;
}

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
bool esSubconjunto(Conjunto A, Conjunto B){
    bool subconj = true;
    if (cto_cantidad_elementos(A) > cto_cantidad_elementos(B)){
        return false;
    }else{
        TipoElemento X;
        for (int i = 1; i <= cto_cantidad_elementos(A); i++){
            X = cto_recuperar(A, i);
            if (!cto_pertenece(B, X->clave)){
                subconj = false;
            }
        }
    }
    return subconj;
}

bool esSubconjuntoParcial(Conjunto A, Conjunto B){
    int contador = 0;
    TipoElemento X;
    int cantelem_a, cantelem_b;
    cantelem_a = cto_cantidad_elementos(A);
    cantelem_b = cto_cantidad_elementos(B);
    for (int i = 1; i <= cantelem_a; i++){
        X = cto_recuperar(A, i);
        if (cto_pertenece(B, X->clave)){
            contador += 1;
        }
    }

    if ((cantelem_a % 2) != 0){
        cantelem_a += 1;
    }

    if (contador >= (cantelem_a / 2)){
        return true;
    }else{
        return false;
    }
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
    bool AsubctB, AsubcpB, AsubctC, AsubcpC;
    bool BsubctA, BsubcpA, BsubctC, BsubcpC;
    bool CsubctA, CsubcpA, CsubctB, CsubcpB;

    AsubctB = esSubconjunto(A, B);
    if (AsubctB){
        printf("A es subconjunto total de B.\n");
    }else{
        AsubcpB = esSubconjuntoParcial(A, B);
        if (AsubcpB){
            printf("A es subconjunto PARCIAL de B.\n");
        }
    }
    AsubctC = esSubconjunto(A, C);
    if (AsubctC){
        printf("A es subconjunto total de C.\n");
    }else{
        AsubcpC = esSubconjuntoParcial(A, C);
        if (AsubcpC){
            printf("A es subconjunto PARCIAL de C.\n");
        }
    }
    BsubctA = esSubconjunto(B, A);
    if (BsubctA){
        printf("B es subconjunto total de A.\n");
    }else{
        BsubcpA = esSubconjuntoParcial(B, A);
        if (BsubcpA){
            printf("B es subconjunto PARCIAL de A.\n");
        }
    }
    BsubctC = esSubconjunto(B, C);
    if (BsubctC){
        printf("B es subconjunto total de C.\n");
    }else{
        BsubcpC = esSubconjuntoParcial(B, C);
        if (BsubcpC){
            printf("B es subconjunto PARCIAL de C.\n");
        }
    }
    CsubctA = esSubconjunto(C, A);
    if (CsubctA){
        printf("C es subconjunto total de A.\n");
    }else{
        CsubcpA = esSubconjuntoParcial(C, A);
        if (CsubcpA){
            printf("C es subconjunto PARCIAL de A.\n");
        }
    }
    CsubctB = esSubconjunto(C, B);
    if (CsubctB){
        printf("C es subconjunto total de B.\n");
    }else{
        CsubcpB = esSubconjuntoParcial(C, B);
        if (CsubcpB){
            printf("C es subconjunto PARCIAL de B.\n");
        }
    }
}

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