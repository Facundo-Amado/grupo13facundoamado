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

void limpiarBuffer();

void pausar();

//funciones de carga de datos
void cargarpila(Pila p);

int cargarTamano();

int cargarTamanoej3();

void cargarCola(Cola c, int tamano);

Cola cargarColaSinRepetidos(Cola cola, int tamano);

Cola cargarColaPositivos();

//funciones de mostrar
void l_mostrar_con_valor(Lista l);

void c_mostrar_con_valortf(Cola cola);

