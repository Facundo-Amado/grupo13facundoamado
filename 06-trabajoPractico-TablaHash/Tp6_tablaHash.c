#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <float.h>
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


//punto5
int primo;

int FuncionHash_Punto5(int n)
{
    return n % primo;
}

void th_ej5_comparacion(int claves, int repeticiones, int rango_min, int rango_max)
{
    srand(time(NULL)); // Establecer semilla
    int claveABuscar;
    struct timespec start, end;
    TipoElemento X;

    unsigned long long tiempo_minimo_avl, tiempo_maximo_avl, tiempo_suma_avl = 0, tiempo_actual_avl;
    unsigned long long tiempo_minimo_th, tiempo_maximo_th, tiempo_suma_th = 0, tiempo_actual_th;
    double tiempo_promedio_avl, tiempo_promedio_th, tiempo_no_esta_promedio_th, tiempo_no_esta_promedio_avl;
    unsigned long long tiempo_no_esta_avl = 0, tiempo_no_esta_th = 0;
    int no_esta_avl = 0, no_esta_th = 0;

    ArbolAVL A_AVL = avl_crear();
    primo = numeroPrimoMasCercanoMenor(claves);
    TablaHash th = th_crear(claves, &FuncionHash_Punto5);
    for (int i = 1; i <= claves; i++) // Repite n veces el proceso de carga de los nodos
    {
        cargar_clave_AVL_HASH(&th, &A_AVL, rango_min, rango_max);
    }
    // generar un random y buscar en las dos tablas tomando tiempo
    claveABuscar = getRandom(rango_min, rango_max);

    // Tiempo y búsqueda en hash
    clock_gettime(CLOCK_REALTIME, &start);
    X = th_recuperar(th, claveABuscar); // Busco la clave
    clock_gettime(CLOCK_REALTIME, &end);
    if (X == NULL)
    {
        tiempo_no_esta_th += (end.tv_nsec - start.tv_nsec);
        no_esta_th++;
    }
    // Estadísticas iniciales de hash
    tiempo_actual_th = (end.tv_nsec - start.tv_nsec);
    tiempo_minimo_th = tiempo_actual_th;
    tiempo_maximo_th = tiempo_actual_th;
    tiempo_suma_th += tiempo_actual_th;

    // Tiempo y búsqueda en avl
    clock_gettime(CLOCK_REALTIME, &start);
    X = avl_buscar(A_AVL, claveABuscar); // Busco la clave
    clock_gettime(CLOCK_REALTIME, &end);
    if (X == NULL)
    {
        tiempo_no_esta_avl += (end.tv_nsec - start.tv_nsec);
        no_esta_avl++;
    }
    // Estadísticas iniciales de avl
    tiempo_actual_avl = (end.tv_nsec - start.tv_nsec);
    tiempo_minimo_avl = tiempo_actual_avl;
    tiempo_maximo_avl = tiempo_actual_avl;
    tiempo_suma_avl += tiempo_actual_avl;

    for (int i = 1; i < repeticiones; i++)
    {
        // generar un random y buscar en las dos tablas tomando tiempo
        claveABuscar = getRandom(rango_min, rango_max);

        // Tiempo y búsqueda en hash
        clock_gettime(CLOCK_REALTIME, &start);
        X = th_recuperar(th, claveABuscar); // Busco la clave
        clock_gettime(CLOCK_REALTIME, &end);
        if (X == NULL)
        {
            tiempo_no_esta_th += (end.tv_nsec - start.tv_nsec);
            no_esta_th++;
        }

        // Estadísticas de hash
        tiempo_actual_th = (end.tv_nsec - start.tv_nsec);
        if (tiempo_minimo_th > tiempo_actual_th)
        {
            tiempo_minimo_th = tiempo_actual_th;
        }
        if (tiempo_maximo_th < tiempo_actual_th)
        {
            tiempo_maximo_th = tiempo_actual_th;
        }
        tiempo_suma_th += tiempo_actual_th;

        // Tiempo y búsqueda en avl
        clock_gettime(CLOCK_REALTIME, &start);
        X = avl_buscar(A_AVL, claveABuscar); // Busco la clave
        clock_gettime(CLOCK_REALTIME, &end);
        if (X == NULL)
        {
            tiempo_no_esta_avl += (end.tv_nsec - start.tv_nsec);
            no_esta_avl++;
        }

        // Estadísticas de avl
        tiempo_actual_avl = (end.tv_nsec - start.tv_nsec);
        if (tiempo_minimo_avl > tiempo_actual_avl)
        {
            tiempo_minimo_avl = tiempo_actual_avl;
        }
        if (tiempo_maximo_avl < tiempo_actual_avl)
        {
            tiempo_maximo_avl = tiempo_actual_avl;
        }
        tiempo_suma_avl += tiempo_actual_avl;
    }
    free(th);
    free_avl(avl_raiz(A_AVL));

    tiempo_promedio_th = tiempo_suma_th / repeticiones;
    tiempo_promedio_avl = tiempo_suma_avl / repeticiones;
    if (no_esta_th != 0)
    {
        tiempo_no_esta_promedio_th = tiempo_no_esta_th / no_esta_th;
    }
    if (no_esta_avl != 0)
    {
        tiempo_no_esta_promedio_avl = tiempo_no_esta_avl / no_esta_avl;
    }
    printf("\nSe realizaron %d búsquedas en las estructuras, las estadísticas son:\n", repeticiones);
    printf("El tiempo mínimo del arbol AVL es: %llu nanosegundos\n", tiempo_minimo_avl);
    printf("El tiempo máximo del arbol AVL es: %llu nanosegundos\n", tiempo_maximo_avl);
    printf("El tiempo promedio del arbol AVL es: %.2f nanosegundos\n", tiempo_promedio_avl);
    if (no_esta_avl != 0)
    {
        printf("El tiempo promedio del arbol AVL si no esta la clave es: %.2f nanosegundos\n", tiempo_no_esta_promedio_avl);
    }
    printf("El tiempo total del arbol AVL es: %llu nanosegundos\n\n", tiempo_suma_avl);
    printf("El tiempo mínimo de la tabla hash es: %llu nanosegundos\n", tiempo_minimo_th);
    printf("El tiempo máximo de la tabla hash es: %llu nanosegundos\n", tiempo_maximo_th);
    printf("El tiempo promedio de la tabla hash es: %.2f nanosegundos\n", tiempo_promedio_th);
    if (no_esta_avl != 0)
    {
        printf("El tiempo promedio de la tabla hash si no esta la clave es: %.2f nanosegundos\n", tiempo_no_esta_promedio_th);
    }
    printf("El tiempo total de la tabla hash es: %llu nanosegundos\n\n", tiempo_suma_th);
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
