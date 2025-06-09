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
#include "../tablaHash/headers/tabla_hash.h"
#include "../tablaHash/headers/tp_thash.h"

//funciones de carga de datos
void cargarpila(Pila p);

int cargarTamano();

int cargarTamanoej3();

void cargarCola(Cola c, int tamano);

Cola cargarColaSinRepetidos(Cola cola, int tamano);

Cola cargarColaPositivos();

void cargar_arbol_binario(ArbolBinario A);

void cargar_arbol_binario_NoRepetidos(ArbolBinario A);

//funciones de mostrar
void l_mostrar_con_valor(Lista l);

void c_mostrar_con_valortf(Cola cola);

void pre_orden(NodoArbol N);

void in_orden(NodoArbol N);

void post_orden(NodoArbol N);

//funciones auxiliares
void limpiarBuffer();

void pausar();

int nivelNodo(ArbolBinario A, int N);

int a_altura(ArbolBinario arbol);

int FuncionHash_Punto6(int n);

void cargarPersona(TablaHash *th);

int juntarNumeros(int dia, int mes, int anio);

bool validarFecha(int dia, int mes, int anio);

struct PersonaRep
{
    int fecha;
    int dni;
    char nombre[20];
    char apellido[20];
};
typedef struct PersonaRep *Persona;





