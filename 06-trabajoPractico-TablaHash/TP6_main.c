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

typedef struct{
    int legajo;
    char apellido[30];
    char nombre[30];
    char domicilio[50];
    char telefono[15];
    bool estado;
} t_alum;


//----------------------- Creacion, mostrar y ABM del Archivo -----------------------------------------

void crear_archivo(){
    FILE *fp = fopen("ej4_archivo_alumnos.dat", "rb");

    if (fp != NULL) {
        fclose(fp);
        printf("\nEl archivo ya existe.\n");
    } else {
        fp = fopen("ej4_archivo_alumnos.dat", "w+b");
        if (fp != NULL) {
            fclose(fp);
            printf("\nArchivo creado!\n");
        } else {
            printf("\nError al crear el archivo.\n");
        }
    }
}


void mostrar_archivo_completo(){
    FILE *fp = fopen("ej4_archivo_alumnos.dat", "rb");
    t_alum alumno;
    char estado[20];
    bool hay_datos = false;

    if(!fp){
        printf("\nNo se pudo abrir el archivo.\n");
        return;
    }

    while(fread(&alumno, sizeof(t_alum), 1, fp) == 1){
        hay_datos = true;
        strcpy(estado, alumno.estado ? "ACTIVO" : "DADO DE BAJA");
        printf("%i - %s %s - %s %s - %s\n", alumno.legajo, alumno.apellido, alumno.nombre, alumno.domicilio, alumno.telefono, estado);
    }

    if (!hay_datos){
        printf("\nEl archivo esta vacio.\n");
    }

    fclose(fp);
}

void mostrar_archivo_solo_altas() {
    FILE *fp = fopen("ej4_archivo_alumnos.dat", "rb");
    t_alum alumno;
    bool hay_activos = false;

    if(!fp){
        printf("\nNo se pudo abrir el archivo.\n");
        return;
    }

    while(fread(&alumno, sizeof(t_alum), 1, fp) == 1){
        if(alumno.estado){
            hay_activos = true;
            printf("%i - %s %s - %s %s\n", alumno.legajo, alumno.apellido, alumno.nombre, alumno.domicilio, alumno.telefono);
        }
    }

    if (!hay_activos){
        printf("\nNo hay alumnos activos en el archivo.\n");
    }

    fclose(fp);
}

int legajo_existe(int legajo_buscar){
    FILE *fp = fopen("ej4_archivo_alumnos.dat", "rb");
    t_alum alumno;

    if(!fp){
        printf("\nError al abrir el archivo\n");
        return 0;
    }

    while(fread(&alumno, sizeof(t_alum), 1, fp) == 1){
        if(alumno.legajo == legajo_buscar && alumno.estado == true){
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void crear_alumno(t_alum alumnoNuevo){
    FILE *fp = fopen("ej4_archivo_alumnos.dat", "ab");

    if(fp == NULL){
        printf("\nError al abrir el archivo\n");
        return;
    }

    fwrite(&alumnoNuevo, sizeof(t_alum), 1, fp);
    fclose(fp);
}

void alta_alumno(){
    t_alum alumnoNuevo;
    int legajo, existe;
    char apellido[30], nombre[30], domicilio[50], telefono[15];
    int res;

    do{
        printf("\nIngrese el legajo: ");
        res = scanf("%d", &legajo);
        getchar();

        if(res != 1 || legajo < 100000 || legajo > 999999){
            printf("Legajo invalido. Debe ser un numero de 6 digitos.\n");
        }

        existe = legajo_existe(legajo);
        if(existe == 1){
            printf("\nEl legajo ya existe, ingrese otro.\n");
        }

    } while (res != 1 || legajo < 100000 || legajo > 999999 || existe == 1);

    
    do {
        printf("\nIngrese el apellido: ");
        if (fgets(apellido, sizeof(apellido), stdin) == NULL) {
            printf("\nError al leer.\n");
            continue;
        }

        apellido[strcspn(apellido, "\n")] = '\0';

        if (apellido[0] == '\0')
            printf("\nNo puede estar vacio.\n");

    } while (apellido[0] == '\0');

    
    do {
        printf("\nIngrese el nombre: ");
        if (fgets(nombre, sizeof(nombre), stdin) == NULL) {
            printf("\nError al leer.\n");
            continue;
        }

        nombre[strcspn(nombre, "\n")] = '\0';

        if (nombre[0] == '\0')
            printf("\nNo puede estar vacio.\n");

    } while (nombre[0] == '\0');

    
    do {
        printf("\nIngrese el domicilio: ");
        if (fgets(domicilio, sizeof(domicilio), stdin) == NULL) {
            printf("\nError al leer.\n");
            continue;
        }

        domicilio[strcspn(domicilio, "\n")] = '\0';

        if (domicilio[0] == '\0')
            printf("\nNo puede estar vacio.\n");

    } while (domicilio[0] == '\0');


    do {
        printf("\nIngrese el telefono: ");
        if (fgets(telefono, sizeof(telefono), stdin) == NULL) {
            printf("\nError al leer.\n");
            continue;
        }

        telefono[strcspn(telefono, "\n")] = '\0';

        if (telefono[0] == '\0')
            printf("\nNo puede estar vacio.\n");

    } while (telefono[0] == '\0');

    alumnoNuevo.legajo = legajo;
    strcpy(alumnoNuevo.apellido, apellido);
    strcpy(alumnoNuevo.nombre, nombre);
    strcpy(alumnoNuevo.domicilio, domicilio);
    strcpy(alumnoNuevo.telefono, telefono);
    alumnoNuevo.estado = true;


    crear_alumno(alumnoNuevo);
}


void baja_alumno(int legajo_baja) {
    FILE *archivo = fopen("ej4_archivo_alumnos.dat", "r+b");
    t_alum alumno;
    int encontrado = 0;

    if(!archivo){
        printf("\nError abriendo el archivo.\n");
        return;
    }

    while(fread(&alumno, sizeof(t_alum), 1, archivo) == 1){
        if(alumno.legajo == legajo_baja && alumno.estado == true){
            alumno.estado = false;
            fseek(archivo, -(long)sizeof(t_alum), SEEK_CUR); 
            fwrite(&alumno, sizeof(t_alum), 1, archivo);
            encontrado = 1;
            break;
        }
    }

    fclose(archivo);

    if(encontrado){
        printf("\nAlumno dado de baja correctamente.\n");
    } else{
        printf("\nLegajo no encontrado o ya estaba dado de baja.\n");
    }
}


int menu_modif(){
    int opcion, res;
    do{
        printf("\n\t---Menu Modificaciones---\n");
        printf("1- Modificar Apellido\n");
        printf("2- Modificar Nombre\n");
        printf("3- Modificar Domicilio\n");
        printf("4- Modificar Telefono\n");
        printf("5- Terminar\n");
        res = scanf("%d", &opcion);
        while(getchar() != '\n');
    } while(res != 1 || opcion < 1 || opcion > 5);

    return opcion;
}

void modificacion_alumno(int legajo_modif){
    FILE* fp = fopen("ej4_archivo_alumnos.dat", "r+b");
    t_alum alumno;
    int legajo;
    char apellido[30], nombre[30], domicilio[50], telefono[15];
    int opcion;
    int encontrado = 0;

    if(!fp){
        printf("\nNo se pudo abrir el archivo.\n");
        return;
    }

    while(fread(&alumno, sizeof(t_alum), 1, fp) == 1){
        if(alumno.legajo == legajo_modif && alumno.estado){
            encontrado = 1;
            printf("\nAlumno encontrado: \n");
            
            do{
                opcion = menu_modif();

                switch(opcion){
                    case 1:
                        printf("\nApellido guardado: %s\n", alumno.apellido);
                        do {
                            printf("\nIngrese el apellido: ");
                            if (fgets(apellido, sizeof(apellido), stdin) == NULL) {
                                printf("\nError al leer.\n");
                                continue;
                            }

                            apellido[strcspn(apellido, "\n")] = '\0';

                            if (apellido[0] == '\0')
                                printf("\nNo puede estar vacio.\n");

                        } while (apellido[0] == '\0');

                        strcpy(alumno.apellido, apellido);
                        break;
                    case 2:
                        printf("\nNombre guardado: %s\n", alumno.nombre);
                        do {
                            printf("\nIngrese el nombre: ");
                            if (fgets(nombre, sizeof(nombre), stdin) == NULL) {
                                printf("\nError al leer.\n");
                                continue;
                            }

                            nombre[strcspn(nombre, "\n")] = '\0';

                            if (nombre[0] == '\0')
                                printf("\nNo puede estar vacio.\n");

                        } while (nombre[0] == '\0');

                        strcpy(alumno.nombre, nombre);
                        break;
                    case 3:
                        printf("\nDomicilio guardado: %s\n", alumno.domicilio);
                        do {
                            printf("\nIngrese el domicilio: ");
                            if (fgets(domicilio, sizeof(domicilio), stdin) == NULL) {
                                printf("\nError al leer.\n");
                                continue;
                            }

                            domicilio[strcspn(domicilio, "\n")] = '\0';

                            if (domicilio[0] == '\0')
                                printf("\nNo puede estar vacio.\n");

                        } while (domicilio[0] == '\0');

                        strcpy(alumno.domicilio, domicilio);
                        break;
                    case 4:
                        printf("\nTelefono guardado: %s\n", alumno.telefono);
                        do {
                            printf("\nIngrese el telefono: ");
                            if (fgets(telefono, sizeof(telefono), stdin) == NULL) {
                                printf("\nError al leer.\n");
                                continue;
                            }

                            telefono[strcspn(telefono, "\n")] = '\0';

                            if (telefono[0] == '\0')
                                printf("\nNo puede estar vacio.\n");

                        } while (telefono[0] == '\0');

                        strcpy(alumno.telefono, telefono);
                        break;
                    case 5:
                        break;
                }

                if(opcion != 5) {
                    fseek(fp, -(long)sizeof(t_alum), SEEK_CUR);
                    fwrite(&alumno, sizeof(t_alum), 1, fp);
                    fflush(fp); 
                    printf("\nModificaciones guardadas con exito!\n");
                }

            } while(opcion != 5);
            
        }
    }

    if(!encontrado){
        printf("\nLegajo no encontrado.\n");
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------

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
void main_punto5()
{
    const int N_MIN = 2;
    const int N_MAX = 2000;
    const int A_MAX = 10000;

    int min, max, repeticiones, clave, validador;
    // Cantidad de repeticiones
    printf("Ingrese la cantidad de repeticiones que se ejecutara la busqueda de un clave en las estructuras [2-100000]: ");
    validador = scanf("%d", &repeticiones);
    limpiarBuffer();
    while (validador != 1 || repeticiones < N_MIN || repeticiones > 100000)
    {
        printf("\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n");
        pausar();
        printf("Ingrese la cantidad de repeticiones que se ejecutara la busqueda de un clave en las estructuras [2-100000]: ");
        validador = scanf("%d", &repeticiones);
        limpiarBuffer();
    }

    // Cantidad de claves a cargar en cada estructura
    printf("Ingrese la cantidad de claves a cargar en cada estructura [%d-%d]: ", N_MIN, N_MAX);
    validador = scanf("%d", &clave);
    limpiarBuffer();
    while (validador != 1 || clave < N_MIN || clave > N_MAX)
    {
        printf("\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n");
        pausar();
        printf("Ingrese la cantidad de claves a cargar en cada estructura [%d-%d]: ", N_MIN, N_MAX);
        validador = scanf("%d", &clave);
        limpiarBuffer();
    }

    // Rango minimo
    printf("Ingrese el rango minimo de la serie aleatoria [1-%d]: ", A_MAX);
    validador = scanf("%d", &min);
    limpiarBuffer();
    while (validador != 1 || min < N_MIN || min > A_MAX)
    {
        printf("\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n");
        pausar();
        printf("Ingrese el rango minimo de la serie aleatoria [1-%d]: ", A_MAX);
        validador = scanf("%d", &min);
        limpiarBuffer();
    }

    // Rango maximo
    printf("Ingrese el rango maximo de la serie aleatoria [%d-999.999]\n", ((clave* 2)+min));
    printf("Tener en cuenta que la diferencia entre el maximo y el minimo tiene que ser superior a la cantidad de nodos x2: ");
    validador = scanf("%d", &max);
    limpiarBuffer();
    while ((validador != 1) || ((max - min) < (clave * 2)) || (max > 999999))
    {
        printf("ERROR\n");
        printf("Datos fuera de rango\nPor favor Ingrese nuevamente el rango maximo de la serie aleatoria [%d-999.999]: ", ((clave* 2)+min));
        validador = scanf("%d", &max);
        limpiarBuffer();
    }

    th_ej5_comparacion(clave, repeticiones, min, max);
    printf("\nEl tiempo de busqueda en un arbol AVL es logaritmico, a diferencia del tiempo de busqueda en una tabla hash que depende de la calidad de la funcion de hash utilizada y del porcentaje ocupado de la tabla.\nSi la funcion de hash distribuye uniformemente las claves en la tabla y el porcentaje ocupado es bajo, el tiempo de acceso  en promedio sera cercano a O(1). Sin embargo, si el porcentaje de ocupacion de la tabla es alto y hay muchas colisiones, el tiempo de acceso puede ser de O(n), donde n es el numero de elementos almacenados en la tabla.\nEn conclusion, en escenarios en los que la funcion de hash es efectiva y el porcentaje de ocupacion es bajo, la tabla hash tendra tiempos de acceso constantes O(1). En contraparte, el arbol AVL garantiza en promedio tiempos de acceso logaritmicos , lo que significa que es mas eficiente que una tabla hash cuando el porcentaje de ocupacion es grande.");
    pausar();
}

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
            main_punto5();
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
