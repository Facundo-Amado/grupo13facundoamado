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

/*4. Desarrollar un algoritmo que dado un archivo que contendra los datos de alumnos  
   (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave sera el legajo y se guardara como dato la posicion fisica 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 digitos. 
*/

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




//-------------------- Funcion TP6 --------------------------------------------

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
