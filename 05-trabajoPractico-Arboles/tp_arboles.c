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
#include "../libs/validaciones/FuncionesAuxiliares.h"


//punto 2
//a
void es_hoja(NodoArbol n, Lista l) {
    if (a_es_rama_nula(n)) {
        return;
    }
    NodoArbol hijoDer = n_hijoizquierdo(n);
    NodoArbol hijoIzq = n_hijoderecho(n);

    if (a_es_rama_nula(hijoIzq) && a_es_rama_nula(hijoDer)) {
        l_agregar(l, te_crear_con_valor(n_recuperar(n)->clave, n));
    }
    es_hoja(hijoIzq, l);
    es_hoja(hijoDer, l);
}

Lista a_ej2_hojas(ArbolBinario A){
    Lista hojas = l_crear();
    es_hoja(a_raiz(A), hojas);
    return hojas;
}

//b
void es_interno(NodoArbol n, Lista l, NodoArbol raiz) {
    if (a_es_rama_nula(n)) {
        return;
    }

    NodoArbol hijoDer = n_hijoizquierdo(n);
    NodoArbol hijoIzq = n_hijoderecho(n);

    if (n != raiz) {
        if (!a_es_rama_nula(hijoIzq) || !a_es_rama_nula(hijoDer)) {
            l_agregar(l, te_crear_con_valor(n_recuperar(n)->clave, n));
        }
    }
    es_interno(hijoIzq, l, raiz);
    es_interno(hijoDer, l, raiz);
}

Lista a_ej2_interiores(ArbolBinario A){
    Lista internos = l_crear();
    NodoArbol raiz = a_raiz(A);
    es_interno(raiz, internos, raiz);
    return internos;
}

void es_igual_a_clave(NodoArbol n, Lista l, int clave) {
    if (a_es_rama_nula(n)) {
        return;
    }

    NodoArbol hijoIzq = n_hijoizquierdo(n);
    NodoArbol hijoDer = n_hijoderecho(n);

    if (n_recuperar(n)->clave == clave) {
        l_agregar(l, te_crear_con_valor(n_recuperar(n)->clave, n));
    }
    es_igual_a_clave(hijoIzq, l, clave);
    es_igual_a_clave(hijoDer, l, clave);
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave)
{
    Lista direcciones = l_crear();
    es_igual_a_clave(a_raiz(A), direcciones, clave);
    return direcciones;
}

//punto 3
//a
int buscar_padre(NodoArbol nodo, int clavehijo) {
    if (nodo == NULL) {
        return clavehijo;
    }

    if ((nodo->hi != NULL && nodo->hi->datos->clave == clavehijo) ||
        (nodo->hd != NULL && nodo->hd->datos->clave == clavehijo)) {
        return nodo->datos->clave;
    }

    int izq = buscar_padre(n_hijoizquierdo(nodo), clavehijo);
    if (izq != clavehijo) return izq;

    int der = buscar_padre(n_hijoderecho(nodo), clavehijo);
    if (der != clavehijo) return der;

    return clavehijo;
}

int a_ej3_clavepadre(ArbolBinario A, int clavehijo) {
    NodoArbol nodo = a_raiz(A);
    if (nodo == NULL) {
        return clavehijo;
    }
    if (nodo->datos->clave == clavehijo) {
        return clavehijo;
    }
    return buscar_padre(nodo, clavehijo);
}

//b
void buscar_hijos(NodoArbol nodo, int clavepadre, Lista hijos) {
    if (nodo == NULL) {
        return;
    }

    if (nodo->datos->clave == clavepadre) {
        if (nodo->hi != NULL) {
            l_agregar(hijos, nodo->hi->datos);
        }
        if (nodo->hd != NULL) {
            l_agregar(hijos, nodo->hd->datos);
        }
        return;
    }

    buscar_hijos(n_hijoizquierdo(nodo), clavepadre, hijos);
    buscar_hijos(n_hijoderecho(nodo), clavepadre, hijos);
}


Lista a_ej3_hijos(ArbolBinario A, int clavepadre) {
    Lista hijos = l_crear();
    buscar_hijos(a_raiz(A), clavepadre, hijos);
    return hijos;
}

//c
NodoArbol buscar_padre_ejc(NodoArbol nodo, int clavehijo) {
    if (nodo == NULL) {
        return NULL;
    }

    if (n_hijoizquierdo(nodo) != NULL && n_recuperar(n_hijoizquierdo(nodo))->clave == clavehijo) {
        return nodo;
    }

    if (n_hijoderecho(nodo) != NULL && n_recuperar(n_hijoderecho(nodo))->clave == clavehijo) {
        return nodo;
    }

    NodoArbol izquierdo = buscar_padre_ejc(n_hijoizquierdo(nodo), clavehijo);
    if (izquierdo != NULL) {
        return izquierdo;
    }

    NodoArbol derecho = buscar_padre_ejc(n_hijoderecho(nodo), clavehijo);
    if (derecho != NULL) {
        return derecho;
    }
    return NULL;
}

int buscar_hermano(NodoArbol nodo, int clave) {
    NodoArbol padre = buscar_padre_ejc(nodo, clave);
    if (padre == NULL) {
        return clave;
    }

    if (n_hijoizquierdo(padre) != NULL && n_recuperar(n_hijoizquierdo(padre))->clave == clave) {
        if (n_hijoderecho(padre) != NULL) {
            return n_recuperar(n_hijoderecho(padre))->clave;
        }
    } else {
        if (n_hijoizquierdo(padre) != NULL) {
            return n_recuperar(n_hijoizquierdo(padre))->clave;
        }
    }
    return clave;
}

int a_ej3_hermano(ArbolBinario A, int clave) {
    int clave_hermano = buscar_hermano(a_raiz(A), clave);
    return clave_hermano;
}

//d
int nivelInt(NodoArbol nodo, int clave, int cont){

    if(nodo == NULL){

        return -1;
    }
    if(n_recuperar(nodo)->clave == clave){
        return cont;
    }
    int izq = nivelInt(n_hijoizquierdo(nodo), clave, cont+1);
    if(izq != -1){
        return izq;
    }
    int der = nivelInt(n_hijoderecho(nodo), clave, cont+1);
    if(der != -1){
        return der;
    }
    return -1;
}

int a_ej3_nivel(ArbolBinario A, int clave){
    int cont= 0;
    int nivel = nivelInt(a_raiz(A), clave, cont);
    return nivel;
}

//e
int calcular_altura(NodoArbol nodo) {
    if (nodo == NULL) {
        return 0;
    } else {
        int altura_izquierda = calcular_altura(n_hijoizquierdo(nodo));
        int altura_derecha = calcular_altura(n_hijoderecho(nodo));
        return (altura_izquierda > altura_derecha ? altura_izquierda : altura_derecha) + 1;
    }
}

int altura_subarbol(NodoArbol nodo, int clave) {
    if (nodo == NULL) {
        return -1;
    }

    if (n_recuperar(nodo)->clave == clave) {
        return calcular_altura(nodo);
    }

    int altura_izquierda = altura_subarbol(n_hijoizquierdo(nodo), clave);
    if (altura_izquierda != -1) {
        return altura_izquierda;
    }

    return altura_subarbol(n_hijoderecho(nodo), clave);
}

int a_ej3_alturarama(ArbolBinario A, int clave) {
    return altura_subarbol(a_raiz(A), clave);
}

//f
void clavesnivel(NodoArbol nodo, int nivel, int cont, Lista claves) {
    if (nodo == NULL) {
        return;
    }

    if (cont == nivel) {
        l_agregar(claves, nodo->datos);
    }

    clavesnivel(n_hijoizquierdo(nodo), nivel, cont + 1, claves);
    clavesnivel(n_hijoderecho(nodo), nivel, cont + 1, claves);
}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel) {
    Lista claves = l_crear();
    clavesnivel(a_raiz(A), nivel, 0, claves);
    return claves;
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
    if (a == NULL && b == NULL) 
    {
        return true;
    }
    if (a == NULL || b == NULL) 
    {
        return false;
    }
    return son_similares(n_hijoizquierdo(a), n_hijoizquierdo(b)) && son_similares(n_hijoderecho(a), n_hijoderecho(b));
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B)
{
    return son_similares(a_raiz(A), a_raiz(B));
}

//d
TipoElemento buscar_padre_te(NodoArbol nodo, int clave, NodoArbol padre) {
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
        TipoElemento resultado = buscar_padre_te(hijo, clave, nodo);
        if (resultado != NULL) return resultado;
        hijo = n_hijoderecho(hijo);
    }
    return NULL;
}

TipoElemento a_ej4_padre(ArbolBinario A, int clave)
{
    return buscar_padre_te(a_raiz(A), clave, NULL);
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
bool son_equivalentes(NodoArbol a, NodoArbol b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {                                   
        return false;
    }
    if ((n_recuperar(a)->clave != n_recuperar(b)->clave)) 
    {    
        return false;                                             
    }                                                            
    return son_equivalentes(n_hijoizquierdo(a), n_hijoizquierdo(b)) &&
           son_equivalentes(n_hijoderecho(a), n_hijoderecho(b));
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B)
{
    return son_equivalentes(a_raiz(A), a_raiz(B));
}

//punto 8
//a
void altura_arbol(NodoArbol nodo, int c, int *alt) 
{                                
    if (a_es_rama_nula(nodo))
    {
        if (c > *alt) 
        {
            *alt = c;
        }
    }
    else
    {
        altura_arbol(n_hijoizquierdo(nodo), c + 1, alt);
        altura_arbol(n_hijoderecho(nodo), c, alt);
    }    
}

int altura_nario(NodoArbol n)
{
    int alt = 0;
    altura_arbol(n, 0, &alt);
    return alt;
}

int a_ej8_altura(ArbolBinario A)
{
    if (A == NULL) return 0;                               //A es nulo o no, si la altura es igual a 0 
    return altura_nario(a_raiz(A));  
}

//b
void nivel_nodo(NodoArbol nodo, int clave, int nivel_actual, int *res) {            
    TipoElemento X = te_crear(0);
    if (!a_es_rama_nula(nodo))
    {
        X = n_recuperar(nodo);
        if (X->clave == clave)
        {
            *res = nivel_actual;
        }
        else
        {
            nivel_nodo(n_hijoizquierdo(nodo), clave, nivel_actual + 1, res);
            nivel_nodo(n_hijoderecho(nodo), clave, nivel_actual, res);
        }
    }              
}

int a_ej8_nivel(ArbolBinario A, int clave)
{
    int N = -1;
    NodoArbol R = a_raiz(A);
    nivel_nodo(R, clave, 0, &N);
    return N;
}

//c
void a_ej8_internos_otra(NodoArbol nodo, Lista *lista, ArbolBinario A) {
    if (nodo == NULL) 
    {
        return;
    }
    else if (!a_es_rama_nula(nodo))
    {
        if (!a_es_rama_nula(n_hijoizquierdo(nodo)) && n_recuperar(a_raiz(A))->clave != n_recuperar(nodo)->clave) 
        {
            l_agregar(*lista, n_recuperar(nodo));
        }
        a_ej8_internos_otra(n_hijoizquierdo(nodo), lista, A);
        a_ej8_internos_otra(n_hijoderecho(nodo), lista, A);
    }
}

Lista a_ej8_internos(ArbolBinario A) {
    Lista lista = l_crear();
    if (A != NULL && a_raiz(A) != NULL) {
        a_ej8_internos_otra(a_raiz(A), &lista, A);
    }
    return lista;
}

//d
void obtener_hojas_recursivamente(NodoArbol nodo, Lista lista, ArbolBinario A) {
        if (!a_es_rama_nula(nodo))
    {
        if (a_es_rama_nula(n_hijoizquierdo(nodo)))
        {
            TipoElemento X = n_recuperar(nodo);
            int nivel = a_ej8_nivel(A, X->clave);
            TipoElemento X1 = te_crear(nivel);
            l_agregar(lista, X1);
        }
        obtener_hojas_recursivamente(n_hijoizquierdo(nodo), lista, A);
        obtener_hojas_recursivamente(n_hijoderecho(nodo), lista, A);
    }
}

bool a_ej8_hojasmismonivel(ArbolBinario A)
{
    Lista l = l_crear();
    bool res = true;
    TipoElemento X, X1;
    obtener_hojas_recursivamente(a_raiz(A), l, A);
    Iterador ite = iterador(l);
    if (!l_es_vacia(l))
    {
        X = siguiente(ite);
        while (hay_siguiente(ite) && res != false)
        {
            X1 = siguiente(ite);
            if (X->clave != X1->clave)
            {
                res = false;
            }
        }
    }
    else
    {
        res = false;
    }
    return res;
}


//punto 9
void a_ej9_construiravlAUX(ArbolAVL AB, NodoArbol n) {
    if (!a_es_rama_nula(n)) {

        TipoElemento temp = n_recuperar(n);
        TipoElemento x = te_crear(temp->clave);
        avl_insertar(AB, x);

        a_ej9_construiravlAUX(AB, n_hijoizquierdo(n));
        a_ej9_construiravlAUX(AB, n_hijoderecho(n));
    }

}

ArbolAVL a_ej9_construiravl(ArbolBinario A) {
    ArbolAVL AB = avl_crear();
    NodoArbol n = a_raiz(A);
    a_ej9_construiravlAUX(AB, n);

    return AB;
}



void alturaArbol(NodoArbol n, int *altura_final, int c) {

    if (n != NULL) {
        alturaArbol(n_hijoizquierdo(n), altura_final, c+1);
        alturaArbol(n_hijoderecho(n), altura_final, c+1);
    }
    else {
        if (c > *altura_final) {
            *altura_final = c;
        }
    }
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL) {

    int altura_A = -1;
    int altura_AVL = -1;
    alturaArbol(a_raiz(A), &altura_A, 0);
    alturaArbol(avl_raiz(AVL), &altura_AVL, 0);

    return altura_A - altura_AVL;
}


//punto 10
bool clave_existente(Lista L, int clave) {
    Iterador it = iterador(L);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        if (te->clave == clave) return true;
    }
    return false;
}

Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo){
    Lista L = l_crear();
    for (int i = 0; i < cantidadclavesagenerar; i++) {
        int clave = rand() % (valormaximo - valorminimo + 1) + valorminimo;
        if (clave_existente(L, clave)) {
            i--;
            continue;
        }
        TipoElemento te = te_crear_con_valor(clave, NULL);
        l_agregar(L, te);
    }
    
    return L;
}

ArbolBinarioBusqueda a_ej10_crearABB(Lista L){
    ArbolBinarioBusqueda abb = abb_crear();
    Iterador it = iterador(L);
    while (hay_siguiente(it)) {
        TipoElemento te_lista = siguiente(it);
        int clave = te_lista->clave;
        TipoElemento te = te_crear(clave);
        abb_insertar(abb, te);
    }

    return abb;
}

ArbolAVL a_ej10_crearAVL(Lista L){
    ArbolAVL avl = avl_crear();
    Iterador it = iterador(L);
    while (hay_siguiente(it)) {
        TipoElemento te_lista = siguiente(it);
        int clave = te_lista->clave;
        TipoElemento te = te_crear(clave);
        avl_insertar(avl, te);
    }

    return avl;
}

int altura(NodoArbol nodo) {
    if (nodo == NULL) return -1;
    int hi = altura(n_hijoizquierdo(nodo));
    int hd = altura(n_hijoderecho(nodo));
    return 1 + (hi > hd ? hi : hd);
}

int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL){
    int alturaABB = altura(abb_raiz(ABB));
    int alturaAVL = altura(avl_raiz(AVL));
    return alturaABB - alturaAVL;
}

Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar){
    Lista diferencias = l_crear();
    for (int i = 0; i < N_repeticiones; i++) {
        Lista claves = a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);
        ArbolBinarioBusqueda abb = a_ej10_crearABB(claves);
        ArbolAVL avl = a_ej10_crearAVL(claves);
        int diferencia = a_ej10_difalturas(abb, avl);

        printf("\nRepeticion %d:\n", i + 1);
        printf("  Altura ABB: %d\n", altura(abb_raiz(abb)));
        printf("  Altura AVL: %d\n", altura(avl_raiz(avl)));
        printf("  Diferencia (ABB - AVL): %d\n", diferencia);

        TipoElemento te = te_crear(diferencia);
        l_agregar(diferencias, te);
    }

    return diferencias;
}
