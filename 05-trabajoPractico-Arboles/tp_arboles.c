#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/cola/headers/colas.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/arboles/headers/arbol-binario.h"
#include "../libs/arboles/headers/nodo.h"
#include "../libs/arboles/headers/tp_arboles.h"
#include "../libs/arboles/headers/arbol-avl.h"
#include "../libs/arboles/headers/arbol-binario-busqueda.h"


//punto 2
Lista a_ej2_hojas(ArbolBinario A){

}

Lista a_ej2_interiores(ArbolBinario A){

}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){

}


//punto 3
int a_ej3_clavepadre(ArbolBinario A, int clavehijo){

}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre){

}

int a_ej3_hermano(ArbolBinario A, int clave){

}

int a_ej3_nivel(ArbolBinario A, int clave){

}

int a_ej3_alturarama(ArbolBinario A, int clave){

}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel){

}


//punto 4
//a
Lista a_ej4_anchura(ArbolBinario A)
{
    Lista lista = l_crear();
    if (a_es_vacio(A))
    {
        return lista;
    }    
    Cola c = c_crear();
    NodoArbol actual = a_raiz(A), hijo, hermano;
    TipoElemento te = te_crear_con_valor(0, actual);
    c_encolar(c, te);
    while (!c_es_vacia(c)) 
    {
        te = c_desencolar(c);
        actual = (NodoArbol)te->valor;
        l_agregar(lista, n_recuperar(actual));
        hijo = n_hijoizquierdo(actual);
        if (hijo != NULL) 
        {
            te = te_crear_con_valor(0, hijo);
            c_encolar(c, te);
            hermano = n_hijoderecho(hijo);
            while (hermano != NULL) 
            {
                te = te_crear_con_valor(0, hermano);
                c_encolar(c, te);
                hermano = n_hijoderecho(hermano);
            }
        }
    }
    return lista;
}

//b
int contar_hojas(NodoArbol nodo) 
{
    if (nodo == NULL) 
    {
        return 0;
    }
    if (n_hijoizquierdo(nodo) == NULL) 
    {
        return 1;
    }
    int hojas = 0;
    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (hijo != NULL) 
    {
        hojas += contar_hojas(hijo);
        hijo = n_hijoderecho(hijo);
    }
    return hojas;
}

int a_ej4_q_hojas(ArbolBinario A)
{
    return contar_hojas(a_raiz(A));
}

//c
bool son_similares(NodoArbol a, NodoArbol b) 
{
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return son_similares(n_hijoizquierdo(a), n_hijoizquierdo(b)) && son_similares(n_hijoderecho(a), n_hijoderecho(b));
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B)
{
    return son_similares(a_raiz(A), a_raiz(B));
}

//d
TipoElemento buscar_padre(NodoArbol nodo, int clave, NodoArbol padre) {
    if (nodo == NULL) 
    {
        return NULL;
    }
    if (n_recuperar(nodo)->clave == clave) 
    {
        if (padre == NULL)  
        {
            return NULL;    
        }
        return n_recuperar(padre);
    }
    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (hijo != NULL) 
    {
        TipoElemento resultado = buscar_padre(hijo, clave, nodo);
        if (resultado != NULL) return resultado;
        hijo = n_hijoderecho(hijo);
    }
    return NULL;
}

TipoElemento a_ej4_padre(ArbolBinario A, int clave)
{
    return buscar_padre(a_raiz(A), clave, NULL);
}

//e
void buscar_hermanos(NodoArbol nodo, int clave, Lista lista) 
{
    if (nodo == NULL) 
    {
        return;
    }
    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (hijo != NULL) 
    {
        if (n_recuperar(hijo)->clave == clave) 
        {
            NodoArbol temp = n_hijoizquierdo(nodo);
            while (temp != NULL) 
            {
                if (n_recuperar(temp)->clave != clave) 
                {
                    l_agregar(lista, n_recuperar(temp));
                }
                temp = n_hijoderecho(temp);
            }
            return;
        }
        buscar_hermanos(hijo, clave, lista);
        hijo = n_hijoderecho(hijo);
    }
}

Lista a_ej4_hermanos(ArbolBinario A, int clave)
{
    Lista lista = l_crear();
    buscar_hermanos(a_raiz(A), clave, lista);
    return lista;
}

//punto 7
bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){

}


//punto 8
int a_ej8_altura(ArbolBinario A)
{

}

int a_ej8_nivel(ArbolBinario A, int clave)
{

}

Lista a_ej8_internos(ArbolBinario A)
{

}

bool a_ej8_hojasmismonivel(ArbolBinario A)
{

}


//punto 9
ArbolAVL a_ej9_construiravl(ArbolBinario A){

}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL){

}


//punto 10
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo){

}

ArbolBinarioBusqueda a_ej10_crearABB(Lista L){

}

ArbolAVL a_ej10_crearAVL(Lista L){

}

int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL){

}

Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar){

}