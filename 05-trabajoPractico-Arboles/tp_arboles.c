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
void pre_orden_recursivo(NodoArbol N) {
    if (N == NULL) {
        printf(".");
    } else {
        printf(" %d", N->datos->clave);
        pre_orden_recursivo(n_hijoizquierdo(N));
        pre_orden_recursivo(n_hijoderecho(N));
    }
}

bool validarEntero(char* cadena) {
    int i = 0;
    int longitud = strlen(cadena);

    if (cadena[0] == '-') i = 1;

    for (; i < longitud; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ingresoEntero(int* n) {
    char s[10];
    while (true) {
        printf("Ingrese una clave numerica o '.' para nulo: ");
        if (fgets(s, sizeof(s), stdin) != NULL) {
            size_t len = strlen(s);
            if (len > 0 && s[len-1] == '\n') {
                s[len-1] = '\0';
            }

            if (validarEntero(s)) {
                *n = atoi(s);
                return true;
            } else if (s[0] == '.' && strlen(s) == 1) {
                return false;
            } else {
                printf("SOLO SE ACEPTAN NUMEROS ENTEROS\n");
            }
        }
    }
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
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
void pre_orden_recursivo(NodoArbol N) {
    if (N == NULL) {
        printf(" .");
    } else {
        printf(" %d", N->datos->clave);
        pre_orden_recursivo(n_hijoizquierdo(N));
        pre_orden_recursivo(n_hijoderecho(N));
    }
}

bool validarEntero(char* cadena) {
    int i = 0;
    if (cadena[0] == '-') i = 1;

    for (; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ingresoEntero(int* n) {
    char s[10];
    while (true) {
        printf("Ingrese una clave numerica o '.' para nulo: ");
        if (fgets(s, sizeof(s), stdin) != NULL) {
            size_t len = strlen(s);
            if (len > 0 && s[len - 1] == '\n') {
                s[len - 1] = '\0';
            }

            if (validarEntero(s)) {
                *n = atoi(s);
                return true;
            } else if (s[0] == '.' && strlen(s) == 1) {
                return false;
            } else {
                printf("SOLO SE ACEPTAN NUMEROS ENTEROS\n");
            }
        }
    }
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
}
Lista a_ej3_hijos(ArbolBinario A, int clavepadre) {
    Lista hijos = l_crear();
    buscar_hijos(a_raiz(A), clavepadre, hijos);
    return hijos;
}

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

void pre_orden_recursivo(NodoArbol N) {
    if (N == NULL) {
        printf(" .");
    } else {
        printf(" %d", N->datos->clave);
        pre_orden_recursivo(n_hijoizquierdo(N));
        pre_orden_recursivo(n_hijoderecho(N));
    }
}

bool validarEntero(char* cadena) {
    int i = 0;
    if (cadena[0] == '-') i = 1;

    for (; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ingresoEntero(int* n) {
    char s[10];
    while (true) {
        printf("Ingrese una clave numerica o '.' para nulo: ");
        if (fgets(s, sizeof(s), stdin) != NULL) {
            size_t len = strlen(s);
            if (len > 0 && s[len - 1] == '\n') {
                s[len - 1] = '\0';
            }

            if (validarEntero(s)) {
                *n = atoi(s);
                return true;
            } else if (s[0] == '.' && strlen(s) == 1) {
                return false;
            } else {
                printf("SOLO SE ACEPTAN NUMEROS ENTEROS\n");
            }
        }
    }
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
}

int a_ej3_hermano(ArbolBinario A, int clave) {
    int clave_hermano = buscar_hermano(a_raiz(A), clave);
    return clave_hermano;
}
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



void pre_orden_recursivo(NodoArbol N) {
    if (N == NULL) {
        printf(" .");
    } else {
        printf(" %d", N->datos->clave);
        pre_orden_recursivo(n_hijoizquierdo(N));
        pre_orden_recursivo(n_hijoderecho(N));
    }
}

bool validarEntero(char* cadena) {
    int i = 0;
    if (cadena[0] == '-') i = 1;

    for (; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ingresoEntero(int* n) {
    char s[10];
    while (true) {
        printf("Ingrese una clave numerica o '.' para nulo: ");
        if (fgets(s, sizeof(s), stdin) != NULL) {
            size_t len = strlen(s);
            if (len > 0 && s[len - 1] == '\n') {
                s[len - 1] = '\0';
            }

            if (validarEntero(s)) {
                *n = atoi(s);
                return true;
            } else if (s[0] == '.' && strlen(s) == 1) {
                return false;
            } else {
                printf("SOLO SE ACEPTAN NUMEROS ENTEROS\n");
            }
        }
    }
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
}

int a_ej3_nivel(ArbolBinario A, int clave){
    int cont= 0;
    int nivel = nivelInt(a_raiz(A), clave, cont);
    return nivel;
}
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

void pre_orden_recursivo(NodoArbol N) {
    if (N == NULL) {
        printf(" .");
    } else {
        printf(" %d", N->datos->clave);
        pre_orden_recursivo(n_hijoizquierdo(N));
        pre_orden_recursivo(n_hijoderecho(N));
    }
}

bool validarEntero(char* cadena) {
    int i = 0;
    if (cadena[0] == '-') i = 1;

    for (; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ingresoEntero(int* n) {
    char s[10];
    while (true) {
        printf("Ingrese una clave numerica o '.' para nulo: ");
        if (fgets(s, sizeof(s), stdin) != NULL) {
            size_t len = strlen(s);
            if (len > 0 && s[len - 1] == '\n') {
                s[len - 1] = '\0';
            }

            if (validarEntero(s)) {
                *n = atoi(s);
                return true;
            } else if (s[0] == '.' && strlen(s) == 1) {
                return false;
            } else {
                printf("SOLO SE ACEPTAN NUMEROS ENTEROS\n");
            }
        }
    }
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
}
int a_ej3_alturarama(ArbolBinario A, int clave) {
    return altura_subarbol(a_raiz(A), clave);
}

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



void pre_orden_recursivo(NodoArbol N) {
    if (N == NULL) {
        printf(" .");
    } else {
        printf(" %d", N->datos->clave);
        pre_orden_recursivo(n_hijoizquierdo(N));
        pre_orden_recursivo(n_hijoderecho(N));
    }
}

bool validarEntero(char* cadena) {
    int i = 0;
    if (cadena[0] == '-') i = 1;

    for (; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ingresoEntero(int* n) {
    char s[10];
    while (true) {
        printf("Ingrese una clave numerica o '.' para nulo: ");
        if (fgets(s, sizeof(s), stdin) != NULL) {
            size_t len = strlen(s);
            if (len > 0 && s[len - 1] == '\n') {
                s[len - 1] = '\0';
            }

            if (validarEntero(s)) {
                *n = atoi(s);
                return true;
            } else if (s[0] == '.' && strlen(s) == 1) {
                return false;
            } else {
                printf("SOLO SE ACEPTAN NUMEROS ENTEROS\n");
            }
        }
    }
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
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
