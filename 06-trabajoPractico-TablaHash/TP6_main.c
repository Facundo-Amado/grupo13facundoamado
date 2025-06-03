#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/validaciones/FuncionesAuxiliares.h"
#include "../libs/tablaHash/headers/tabla_hash.h"
#include "../libs/tablaHash/headers/tp_thash.h"

//punto 4

//punto 5

//punto 6


void menu_alumnos()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 ABM Alumnos                                |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Dar de alta un alumno\n");
    printf("  2   Dar de baja un alumno\n");
    printf("  3   Modificar datos de un alumno\n");
    printf("  4   Mostrar archivo binario\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("Seleccione una opción: ");
}

void menu_punto4()
{
    bool salir_p4 = false;
    int opcion;
    //FILE *archivo;
    //crear_archivo_binario();
    //TablaHash th = th_crear(tamaño, FuncionHash);
    while (!salir_p4)
    {
        menu_alumnos();
        int validador = scanf("%i", &opcion);
        limpiarBuffer();
        while (validador != 1 || opcion < 0 || opcion > 4)
        {
            printf("Opción incorrecta\n");
            printf("Seleccione una opción: ");
            validador = scanf("%i", &opcion);
            limpiarBuffer();
        }
        switch (opcion)
        {
        case 1:
            //alta(th);
            break;
        case 2:
            //main_baja(th);
            break;
        case 3:
            //main_modificar(th);
            break;
        case 4:
            //mostrarArchivo();
            break;
        case 0:
            salir_p4 = true;
        }
    }
}

void menu_personas()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                  PUNTO 6                                   |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Agregar persona\n");
    printf("  2   Buscar por fecha\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("Seleccione una opción: ");
}

void menu_punto6()
{
    bool salir_p6 = false;
    int opcion;
    //TablaHash th = th_crear(tamaño, FuncionHash);
    while (!salir_p6)
    {
        menu_personas();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 2)
        {
            printf("Opción incorrecta\n");
            printf("Seleccione una opción: ");
            while (getchar() != '\n')
                ;
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            //cargarPersona(&th);
            break;
        case 2:
            //main_6b(&th);
            break;
        case 0:
            salir_p6 = true;
        }
    }
}

void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                               TP6 TABLA HASH                               |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   ABM Alumnos\n");
    printf("  2   Comparación en tiempos de acceso\n");
    printf("  3   Buscar por fecha\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("Seleccione una opción: ");
}

int main()
{
    bool salir = false;
    int opcion;

    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opcion);
        limpiarBuffer();
        while (validador != 1 || opcion < 0 || opcion > 3)
        {
            printf("Opción incorrecta\n");
            printf("Seleccione una opción: ");
            validador = scanf("%i", &opcion);
            limpiarBuffer();
        }

        switch (opcion)
        {

        case 1:
            menu_punto4();
            break;
        case 2:
            //main_punto5();
            break;
        case 3:
            menu_punto6();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}