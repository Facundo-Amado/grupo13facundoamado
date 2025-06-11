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

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include "tabla_hash.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "arbol-avl.h"

#define TAMANIO_MAXIMO 2000

int hash_function(int clave) {
    return clave % 1997;
}

Lista generar_claves(int n, int rango_min, int rango_max) {
    Lista l_claves = l_crear();
    bool *existentes = calloc(rango_max - rango_min + 1, sizeof(bool));
    if (!existentes) {
        printf("Error: No se pudo asignar memoria para las claves existentes.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        int clave;
        do {
            clave = rango_min + rand() % (rango_max - rango_min + 1);
        } while (existentes[clave - rango_min]);

        existentes[clave - rango_min] = true;
        TipoElemento te = te_crear(clave);
        l_agregar(l_claves, te);
    }

    free(existentes);
    return l_claves;
}

Lista generar_claves_a_buscar(int n, int rango_min, int rango_max) {
    Lista l_claves_a_buscar = l_crear();
    for (int i = 0; i < n; i++) {
        int clave = rango_min + rand() % (rango_max - rango_min + 1);
        TipoElemento te = te_crear(clave);
        l_agregar(l_claves_a_buscar, te);
    }
    return l_claves_a_buscar;
}

#ifdef _WIN32

double get_current_time() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER time;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return (double)time.QuadPart / frequency.QuadPart;
}

#else

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

#endif

double medir_tiempo_hash(TablaHash th, Lista claves_buscadas) {
    double tiempo_total = 0.0;
    Iterador iter = iterador(claves_buscadas);

    while (hay_siguiente(iter)) {
        TipoElemento te_buscado = siguiente(iter);

        double inicio = get_current_time();
        th_recuperar(th, te_buscado->clave);
        double fin = get_current_time();

        tiempo_total += fin - inicio;
    }

    return tiempo_total;
}

double medir_tiempo_avl(ArbolAVL arbol, Lista claves_buscadas) {
    double tiempo_total = 0.0;
    Iterador iter = iterador(claves_buscadas);

    while (hay_siguiente(iter)) {
        TipoElemento te_buscado = siguiente(iter);

        double inicio = get_current_time();
        avl_buscar(arbol, te_buscado->clave);
        double fin = get_current_time();

        tiempo_total += fin - inicio;
    }

    return tiempo_total;
}

bool ValidarNumero(int *numero){
    bool esValido = false;
    char cadena[12];
    int i;
    bool esNegativo = false;

    while(esValido == false){

        printf("Ingresar numero: ");
        fgets(cadena, 12, stdin);

        if(cadena[0] == '-'){

            esNegativo = true;

            for (size_t i = 0; i < strlen(cadena); i++) {
                cadena[i] = cadena[i+1];
            }

        }

        if(strlen(cadena) == 1){
            printf("ERROR: Ingresa un numero.\n\n");
            continue;
        }

        if(cadena[strlen(cadena)-1] != '\n'){
            printf("ERROR: Ingresa un numero valido.\n\n");
            fflush(stdin);
            continue;
        }

        if(cadena[0] == ' '){
            printf("ERROR: Ingresa un numero.\n\n");
            continue;
        }

        for(i = 0; i < 12; i++){
            if(cadena[i] == '\n'){
                cadena[i] = '\0';
                break;
            }
        }

        bool esEntero = true;

        for(int i = 0; i < 12; i++){

            if(cadena[i] == '\0'){
                break;
            }
            if(!iswdigit(btowc(cadena[i]))){

                esEntero = false;
                break;
            }
        }

        if(esEntero == true){

            if(esNegativo == true){

                *numero = -atoi(cadena);
            }
            else{
                *numero = atoi(cadena);
            }
            esValido = true;
            return esValido;
        }
        else{
            printf("ERROR: no es un numero entero valido.\n\n");
        }
    }

    return esValido;
}



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
