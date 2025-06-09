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
#include "../libs/tablaHash/headers/tabla_hash.h"
#include "../libs/tablaHash/headers/tp_thash.h"


//punto 4

//punto 5

//punto 6

void mostrarPersonas(Lista L)
{
    Persona persona = malloc(sizeof(struct PersonaRep));
    TipoElemento X = te_crear(0);
    Iterador ite = iterador(L);

    while (hay_siguiente(ite))
    {
        X = siguiente(ite);
        persona = (Persona)X->valor;
        printf("\nNombre: %s\n", persona->nombre);
        printf("Apellido: %s\n", persona->apellido);
        printf("DNI: %d \n", persona->dni);
    }
    pausar();
}

int th_ej6_covid(TablaHash th, int fecha)
{
    TipoElemento X = th_recuperar(th, fecha);
    int vacunados = 0;
    if (X == NULL)
    {
        printf("\nNo hay personas vacunadas en esa fecha");
        pausar();
    }
    else
    {
        Lista L = (Lista)X->valor;
        printf("\n\nListado de personas que se vacunaron en esa fecha\n\n");
        mostrarPersonas(L);
        vacunados = l_longitud(L);
    }
    return vacunados;
}
