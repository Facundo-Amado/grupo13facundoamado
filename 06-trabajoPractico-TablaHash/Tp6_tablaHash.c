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
#define NUM_PRIMO 997


typedef struct{
    int legajo;
    char apellido[30];
    char nombre[30];
    char domicilio[50];
    char telefono[15];
    bool estado;
} t_alum;


//-------------------- Funcion Ej4 --------------------------------------------

int funcion_hash4(int a){
    int b = (a % NUM_PRIMO);
    return b;
}

void th_ej4_abm(){
    TablaHash Hash = th_crear(1000, funcion_hash4);
    TipoElemento X;
    int registronro = 0;
    int *posicion;
    bool hay_activos = false;
    FILE *fp = fopen("ej4_archivo_alumnos.dat", "r+b");

    if(!fp){
        printf("No se pudo abrir el archivo\n");
        return;
    }

    t_alum *alumno_th = malloc(sizeof(t_alum));

    while(fread(alumno_th, sizeof(t_alum), 1, fp) == 1){
        if(alumno_th->estado == true){
            posicion = malloc(sizeof(int));
            *posicion = registronro;
            X = te_crear_con_valor(alumno_th->legajo, posicion);
            th_insertar(Hash, X);
            printf("Legajo: %d -> Posicion fisica: %d\n", alumno_th->legajo, *posicion);
            hay_activos = true;
        }
        registronro++;
    }

    printf("\n");
    if (hay_activos) {
        th_mostrar_solo_ocupados(Hash);
    } else {
        printf("\nNo hay alumnos activos cargados en la tabla hash.\n");
    }

    fclose(fp);
}


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
