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
int menu_punto4(){
    int opcion, opcion2, opcion3, legajo_baja, legajo_modif, res, res2, existe;

    do{
        printf("  ============================================================================\n");
        printf(" |                                  PUNTO 4                                   |\n");
        printf("  ============================================================================\n");
        printf("1- Crear archivo\n");
        printf("2- ABM alumnos\n");
        printf("3- Mostrar archivo\n");
        printf("4- Mostrar TablaHash\n");
        printf("5- Terminar\n");
        printf("\nIngrese una opcion: ");
        res2 = scanf("%d", &opcion);

        switch (opcion){
            case 1:
                crear_archivo();
                break;
            case 2:
                printf("\n\t----MENU ABM----\n");
                printf("1- Alta alumno\n");
                printf("2- Baja alumno\n");
                printf("3- Modificacion alumno\n");
                printf("4- Terminar\n");
                printf("\nIngrese una opcion: ");
                scanf("%d", &opcion2);
            
                switch(opcion2){
                    case 1:
                        alta_alumno();
                        break;
                    case 2:
                        do{
                            printf("\nIngrese el legajo del alumno que quiere dar de baja: ");
                            res = scanf("%d", &legajo_baja);
                            getchar();

                            if(res != 1 || legajo_baja < 100000 || legajo_baja > 999999){
                                printf("Legajo invalido. Debe ser un numero de 6 digitos.\n");
                            }

                            existe = legajo_existe(legajo_baja);
                            if(existe == 0){
                                printf("\nEl legajo no existe o esta dado de baja, ingrese otro.\n");
                            }

                        } while (res != 1 || legajo_baja < 100000 || legajo_baja > 999999 || existe == 0); 

                        baja_alumno(legajo_baja);
                        break;
                    case 3:
                        do{
                            printf("\nIngrese el legajo del alumno que quiere modificar: ");
                            res = scanf("%d", &legajo_modif);
                            getchar();

                            if(res != 1 || legajo_modif < 100000 || legajo_modif > 999999){
                                printf("Legajo invalido. Debe ser un numero de 6 digitos.\n");
                            }

                            existe = legajo_existe(legajo_modif);
                            if(existe == 0){
                                printf("\nEl legajo no existe o esta dado de baja, ingrese otro.\n");
                            }

                        } while (res != 1 || legajo_modif < 100000 || legajo_modif > 999999 || existe == 0); 

                        modificacion_alumno(legajo_modif);
                        break;
                    case 4:
                        break;
                }
                break;
            case 3:
                printf("\n1- Mostrar archivo completo (altas y bajas).");
                printf("\n2- Mostrar archivo (solo altas).");
                printf("\nIngrese una opcion: ");
                scanf("%d", &opcion3);

                switch (opcion3){
                    case 1:
                        mostrar_archivo_completo();
                        break;
                    case 2:
                        mostrar_archivo_solo_altas();
                        break;
                }
                break;
            case 4:
                th_ej4_abm();
                break;
        }
    } while(res2 != 1 || opcion != 5);

    

    return 0;
}


//punto 5

//punto 6
void main_6b(TablaHash *th)
{
    int validador, fecha;
    unsigned int dia, mes, anio;
    bool fechaValida = false;
    while (!fechaValida)
    {
        // Cargar fecha
        printf("Ingresar la fecha de vacunacion\n");

        // Cargar dia
        printf("Dia: ");
        validador = scanf("%u", &dia);
        limpiarBuffer();
        while (validador != 1 || dia < 1 || dia > 31)
        {
            printf("\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n");
            pausar();
            printf("Dia: ");
            validador = scanf("%u", &dia);
            limpiarBuffer();
        }

        // Cargar mes
        printf("Mes: ");
        validador = scanf("%d", &mes);
        limpiarBuffer();
        while (validador != 1 || mes < 1 || mes > 12)
        {
            printf("\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n");
            pausar();
            printf("Mes: ");
            validador = scanf("%d", &mes);
            limpiarBuffer();
        }

        // Cargar anio
        printf("Anio: ");
        validador = scanf("%d", &anio);
        limpiarBuffer();
        while (validador != 1 || anio < 2020 || anio > 2025)
        {
            printf("\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n");
            pausar();
            printf("Anio: ");
            validador = scanf("%u", &anio);
            limpiarBuffer();
        }

        fechaValida = validarFecha(dia, mes, anio);
        printf("%s", fechaValida ? "\nLa fecha es valida\n" : "\nLa fecha no es valida, vuelva a ingresarla\n");
    }
    fecha = juntarNumeros(dia, mes, anio);
    int cant_vacunados = th_ej6_covid(*th, fecha);
    if (cant_vacunados != 0)
    {
        printf("se vacunaron %d personas en esa fecha \n", cant_vacunados);
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
    printf("Seleccione una opcion: ");
}

void main_punto6()
{   int tam_maximo = 50;
    bool salir_p6 = false;
    int opcion;
    TablaHash th = th_crear(tam_maximo, &FuncionHash_Punto6);
    while (!salir_p6)
    {
        menu_personas();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 2)
        {
            printf("Opcion incorrecta\n");
            printf("Seleccione una opcion: ");
            limpiarBuffer();
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            cargarPersona(&th);
            break;
        case 2:
            main_6b(&th);
            break;
        case 0:
            salir_p6 = true;
        }
    }
}


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
    printf("Seleccione una opcion: ");
}


void menu_punto6()
{
    int tam_max = 50;
    bool salir_p6 = false;
    int opcion;
    TablaHash th = th_crear(tam_max, FuncionHash_Punto6);
    while (!salir_p6)
    {
        menu_personas();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 2)
        {
            printf("Opcion incorrecta\n");
            printf("Seleccione una opcion: ");
            limpiarBuffer();
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            cargarPersona(&th);
            break;
        case 2:
            main_6b(&th);
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
    printf("  2   Comparacion en tiempos de acceso\n");
    printf("  3   Buscar vacunados por fecha\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("Seleccione una opcion: ");
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
            printf("Opcion incorrecta\n");
            printf("Seleccione una opcion: ");
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