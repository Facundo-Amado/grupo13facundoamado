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
#include "../arboles/headers/arbol-binario.h"
#include "../arboles/headers/nodo.h"
#include "../arboles/headers/arbol-avl.h"
#include "../arboles/headers/arbol-binario-busqueda.h"


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

bool buscarElemCola(Cola c, int clave)
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
            esRepetido = buscarElemCola(cola, elemento);
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
                esRepetido = buscarElemCola(cola, elemento);
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

bool ingresoEntero(int* n){
    char s[10];
    bool resultado = true;
    *n=0;
    printf("Ingrese una clave numérica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = false;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
        }
    }
    return resultado;
}

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if(!a_es_lleno(A)){
        b= ingresoEntero(&n);
        if (b){
            X= te_crear(n);
            
            if(sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }    
}

/*Función que recibe el árbol a ser cargado y llama a la función recursiva que realiza
la carga nodo por nodo*/
void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
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
    bool valor;
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
        valor = *(bool*) x->valor;
        printf("{%d: %s},", x->clave, (valor ? "true" : "false"));
        c_encolar(cola, x);
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void post_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}

//funciones auxiliares
/*Función recursiva que recibe un NodoArbol (inicialmente la raíz), la clave buscada,
 un apuntador a entero para poder devolver el nivel de la clave (si la encuentra) y 
 el nivel del NodoArbol Q*/
void nivelint(NodoArbol Q, int Cbuscada, int *h, int c){
    TipoElemento X;
    if (Q != NULL) {
        X= n_recuperar(Q);
        if (X->clave == Cbuscada) {
            *h = c;
        }else{
            nivelint(n_hijoizquierdo(Q), Cbuscada, h, c+1);
            nivelint(n_hijoderecho(Q), Cbuscada, h, c+1);
        }
    }
}

// Funcion que devuelve el nivel de una clave o -1 si esta no se encuentra en el árbol.
// Llama a la función recursiva que busca la clave y proporciona su nivel.
int nivel_nodo(ArbolBinario A, int N){
    int nivel = -1;
    nivelint(a_raiz(A), N, &nivel, 0);
    return nivel;
}