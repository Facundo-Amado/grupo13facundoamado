#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/pila/headers/tp_3_pilas.h"

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}  

void pausar()
{
    limpiarBuffer();
    while (getchar() != '\n');
}

void cargarpila(Pila p)
{
    int i = 0, tamano, elemento;
    TipoElemento elem;
    printf("ingrese la cantidad de elementos que desea ingresar a la pila: ");
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 10))
    {
        printf("Dato invalido. Ingrese un numero entero entre 1 y 10: ");
        scanf("%d", &tamano);
        limpiarBuffer();
    }
    tamano = (int)tamano;
    while (i< tamano)
    {
        printf("ingrese un elemento de la pila. (solo se admiten numeros enteros): ");
        while (scanf("%d", &elemento) != 1)
        {
            printf("elemento invalido. ingrese un elemento de la pila: ");
            scanf("%d", &elemento);
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        p_apilar(p, elem);
        i++;
    }
}

//Punto 2
void crearpila(Pila p)
{
    printf("\n\t\t --- Carga de la pila --- \n");    
    cargarpila(p);
    printf("Pulse enter para volver al menu");
    return;
}

int mainBuscarClave(Pila p)
{
    int clave;
    if (p_es_vacia(p)) {
        printf("La pila esta vacia.\n");
    } 
    printf("ingrese el elemento que busca: ");
    while ((scanf("%d", &clave) != 1))
    {
        printf("dato invalido. ingrese un elemento valido: ");
        scanf("%d", &clave);
        limpiarBuffer();
    }
    if (p_ej2_existeclave(p, clave))
    {
        printf("La clave existe en la pila");
    }
    else
    {
        printf("La clave no existe en la pila");
    }
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

int mainInsertarEnPila(Pila p)
{
    Pila aux = p_crear();
    TipoElemento clave;
    int pos, clavetemp;
    if (p_es_vacia(p)) {
        printf("La pila esta vacia.\n");
    } 
    printf("ingrese el elemento para agregar en la pila: ");
    while ((scanf("%d", &clavetemp) != 1))
    {
        printf("dato invalido. ingrese un elemento valido: ");
        scanf("%d", &clavetemp);
        limpiarBuffer();
    }
    clave = te_crear(clavetemp);
    printf("ingrese la posicion en la que va a estar el elemento: ");
    while ((scanf("%d", &pos) != 1) || pos < 0)
    {
        printf("dato invalido. ingrese una posicion valida: ");
        scanf("%d", &pos);
        limpiarBuffer();
    }
    aux = p_ej2_colocarelemento(p, pos, clave);
    p_mostrar(aux);
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

int mainEliminarPorClave(Pila p)
{
    Pila aux = p_crear();
    int clave;
    if (p_es_vacia(p)) {
        printf("La pila esta vacia.\n");
    } 
    printf("ingrese el elemento que desea eliminar: ");
    while ((scanf("%d", &clave) != 1))
    {
        printf("dato invalido. ingrese un elemento valido: ");
        scanf("%d", &clave);
        limpiarBuffer();
    }
    aux = p_ej2_eliminarclave(p, clave);
    p_mostrar(aux);
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

int mainIntercambiar(Pila p)
{   
    Pila aux = p_crear();
    int pos1, pos2;
    if (p_es_vacia(p)) {
        printf("La pila esta vacia.\n");
    } 
    printf("ingrese la posicion del primer elemento: ");
    while(scanf("%d", &pos1) != 1 || pos1 < 0)
    {
        printf("dato invalido. ingrese un numero entero: ");
        scanf("%d", &pos1);
        limpiarBuffer();
    }
    printf("ingrese la posicion del segundo elemento: ");
    while(scanf("%d", &pos2) != 1 || pos2 < 0)
    {
        printf("dato invalido. ingrese un numero entero: ");
        scanf("%d", &pos1);
        limpiarBuffer();
    }
    aux = p_ej2_intercambiarposiciones(p, pos1, pos2);
    p_mostrar(aux);
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

int mainDuplicarPila(Pila p)
{
    Pila aux = p_crear();
    if (p_es_vacia(p)) {
        printf("La pila esta vacia.\n");
    } 
    aux = p_ej2_duplicar(p);
    p_mostrar(aux);
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

int mainContador(Pila p)
{
    int cant;
    if (p_es_vacia(p)) {
        printf("La pila esta vacia.\n");
    } 
    cant = p_ej2_cantidadelementos(p);
    printf("La cantidad de elementos de la pila es: %d", cant);
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

//Punto 3
void cargarPilas(Pila p, int tamano)
{
    int i = 0, elemento;
    TipoElemento elem;
    while (i< tamano)
    {
        printf("ingrese un elemento de la pila. (solo se admiten numeros enteros): ");
        while (scanf("%d", &elemento) != 1)
        {
            printf("elemento invalido. ingrese un elemento de la pila: ");
            scanf("%d", &elemento);
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        p_apilar(p, elem);
        i++;
    }
}
 
int mainComparaPilas() {
    int n1, n2;
    // Crear y llenar la Pila 1
    Pila p1 = p_crear();
    printf("Ingrese la cantidad de elementos para la Pila 1: ");
    while (scanf("%d", &n1) != 1 || n1 <= 0) {
        limpiarBuffer();
        printf("Error: ingrese un numero entero positivo para el tamano: ");
    }
    printf("\n\t\t --- Carga de la pila 1--- \n");    
    cargarPilas(p1, n1);

    // Crear y llenar la Pila 2
    Pila p2 = p_crear();
    printf("\n\nIngrese la cantidad de elementos para la Pila 2: ");
    while (scanf("%d", &n2) != 1 || n2 <= 0) {
        limpiarBuffer();
        printf("Error: ingrese un numero entero positivo para el tamano: ");
    }
    // Verificar si la longitud de la Pila 2 es menor que la de la Pila 1
    if (n2 != n1) {
        printf("Las pilas son de diferentes longitudes, no son iguales.\n");
        return 0;  // Terminar el programa si las longitudes son diferentes
    }
    printf("\n\t\t --- Carga de la pila 2--- \n");    
    cargarPilas(p2, n2);

    // Verificar si las pilas son iguales
    bool sonIguales = p_ej3_iguales(p1, p2);
    if (sonIguales) {
        printf("\nLas pilas son EXACTAMENTE IGUALES.\n");
    } 
    else {
        printf("\nLas pilas NO son iguales.\n");
    }
    printf("\n\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("la complejidad es de O(n), donde n es el numero de elementos en la pila.");
    return 0;
}

//Punto 4
void mostrarComplejidadEj4() {
    printf("=== Complejidad algoritmica ===");
    printf("La complejidad del algoritmo es O(log n), donde n representa el valor absoluto del numero decimal a convertir.");
    printf("Esto se debe a que, en cada iteracion del bucle principal, el numero n es dividido por la base b elegida con (2 <= b <= 16)");
    printf("reduciendo su tamanio en forma logaritmica.");
}

int mainConversorBases() {
    int numero;
    int base;

    printf("Ingrese el numero decimal que desea convertir: ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: Entrada invalida para numero.\n");
        return 0;
    }

    printf("Ingrese la base de destino (entre 2 y 16): ");
    if (scanf("%d", &base) != 1) {
        printf("Error: Entrada invalida para base.\n");
        return 0;
    }

    char* resultado = p_ej4_cambiarbase(numero, base);

    printf("El numero %d convertido a base %d es: %s\n", numero, base, resultado);
    mostrarComplejidadEj4();

    free(resultado);
    return 0;
}

//Punto 5
int mainInvertida(){
    Pila p = p_crear();
    Pila p_invertida = p_crear();
    printf("\n\t\t --- Carga de la pila ---\n");
    cargarpila(p);
    printf("\nPila ingresada: ");
    p_mostrar(p);
    p_invertida = p_ej5_invertir(p);
    printf("\nPila invertida: ");
    p_mostrar(p_invertida);
    printf("\n\nPila original sin modificar: \n");
    p_mostrar(p);
    printf("\n\t\t--- Complejidad algoritmica ---\n");
    printf("el ejercicio tiene complejidad algoritmica O(2n) en el peor de los casos, ya que contiene \ndos ciclos while separados que recorren la pila de tamano n.\n");
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

//Punto 6
int cargarClave(Pila p) {
    int a;
    printf("\nIngrese clave a borrar: ");
    while( scanf("%d", &a) != 1 ) {
        limpiarBuffer();
        printf("Invalido. Ingrese un numero entero: ");
    }
    limpiarBuffer();
    return a;
}

int mainEliminarIterativo() {

    Pila nueva_pila = p_crear();
    cargarpila(nueva_pila);
    printf("\n");
    int clave = cargarClave(nueva_pila);
    printf("\n");
    p_mostrar(nueva_pila);
    Pila nueva_pila2 = p_crear();
    nueva_pila2 = p_ej6_eliminarclave(nueva_pila, clave);
    p_mostrar(nueva_pila2);
    printf("\n\nPila original sin modificar: \n");
    p_mostrar(nueva_pila);
    printf("\n\t\t\t--- Complejidad algoritmica ---\n");
    printf("La complejidad algoritima es lineal, en este caso 3n, ya que hay tres ciclos while consecutivos \nque dependen de la cantidad de elementos (a mas elementos, mas tardaran los tres, a menos elementos, \nseran mas rapidos)\n");
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

int mainEliminarRecursivo()
{
    Pila nueva_pila = p_crear();
    cargarpila(nueva_pila);
    printf("\n");
    int clave = cargarClave(nueva_pila);
    Pila nueva_pila_r = p_crear();
    nueva_pila_r = p_ej6_eliminarclave_r(nueva_pila, clave);
    printf("Nueva pila: \n");
    p_mostrar(nueva_pila_r);
    printf("\nPila original sin modificar: \n");
    p_mostrar(nueva_pila);
    printf("\n\t\t\t--- Complejidad algoritmica ---\n");
    printf("La complejidad algoritmica es lineal, en este caso 5n, ya que hay cuatro ciclos while en la funcion \nprincipal, y luego la funcion auxiliar recursiva realiza un proceso equivalente a otro ciclo while \ndependiente de la cantidad de elementos\n");
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

//Punto 7
int mainElementosComunes()
{
    Pila p1 = p_crear();
    printf("\n\t\t --- Carga de la primera pila ---\n");
    cargarpila(p1);
    p_mostrar(p1);
    Pila p2 = p_crear();
    printf("\n\t\t --- Carga de la segunda pila ---\n");
    cargarpila(p2);
    p_mostrar(p2);
    Pila comunes = p_ej7_elementoscomunes(p1, p2);
    printf("\n\t --- Elementos en comun ---\n");
    p_mostrar(comunes);
    printf("\n\nPila 1 original sin modificar: \n");
    p_mostrar(p1);
    printf("\n\nPila 2 original sin modificar: \n");
    p_mostrar(p2);
    printf("\n\t\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("el ejercicio es de complejidad cuadratica (O(n*m)) ya que tiene 2 ciclos iterativos que recoren 2 pilas cuyos tamanos \npueden ser iguales o no, pero la complejidad aumenta dependiendo del tamano de las pilas. \n");
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

//Punto 8
void p_mostrar_con_valor(Pila pila){

    if (p_es_vacia(pila)){

        printf("PILA VACIA! \n");
        return;
    }
    Pila Paux = p_crear();
    Pila Paux2 = p_crear();
    TipoElemento X = te_crear(0);
    printf ("Contenido de la pila: ");
    while (p_es_vacia(pila) != true) 
    {
        X = p_desapilar(pila);
        p_apilar(Paux, X);
    }
    while (p_es_vacia(Paux) != true) 
    {
        p_apilar(Paux2, p_desapilar(Paux));
    }

    while (p_es_vacia(Paux2) != true){

        X = p_desapilar(Paux2);
        printf("{%d:%lld},", X->clave, (intptr_t)X->valor);
        p_apilar(Paux, X);
    }
    while (p_es_vacia(Paux) != true) 
    {
        p_apilar(pila, p_desapilar(Paux));
    }
    printf("\n");
}

int mainContadorValores(){

    Pila P1 = p_crear();
    Pila p2 = p_crear();
    printf("\n\t\t --- Carga de la pila --- \n");    
    cargarpila(P1);
    p2 = p_ej8_sacarrepetidos(P1);
    p_mostrar_con_valor(p2);
    printf("\n\t\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("La complejidad algoritmica O(n^2), donde n es el numero total de elementos en la pila original p. La complejidad es \nla misma tanto para la implementacion con punteros que para la implementacion con arreglos. \n");
    printf("\n\nPulse enter para volver al menu");
    return 0;
}

void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 TP3 PILAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con pilas\n");
    printf("  3   Pilas iguales\n");
    printf("  4   Conversor de base\n");
    printf("  5   Invertir pila\n");
    printf("  6   Eliminar item\n");
    printf("  7   Elementos en comun\n");
    printf("  8   Contador de valores\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opcion: ");
}

void menu_punto2()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                         2   Operaciones con pilas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Cargar pilas\n");
    printf("  2   Buscar elemento\n");
    printf("  3   Insertar elemento\n");
    printf("  4   Eliminar elemento\n");
    printf("  5   Intercambiar elementos\n");
    printf("  6   Duplicar pila\n");
    printf("  7   Contar elementos\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opcion: ");
}

void menu_punto5()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                         5   Eliminar elemento de la pila                   |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Ejecutar iterativamente\n");
    printf("  2   Ejecutar recursivamente\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opcion: ");
}

int main()
{
    Pila p = p_crear();
    bool pilaCargada = false;
    bool salir2 = false, salir1 = false, salir = false;
    int opc, opc1, opc2;
    while (!salir)
    {
        menu_principal();
        while (scanf("%i", &opc) != 1 || opc < 1 || opc > 8)
        {
            printf("Opcion incorrecta\n");
            printf("Por favor seleccione una opcion: ");
            scanf("%i", &opc);
            limpiarBuffer();
        }
        switch (opc)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                while (scanf("%i", &opc1)!= 1 || opc1 < 0 || opc > 7)
                {
                    printf("Opcion incorrecta\n");
                    printf("Por favor seleccione una opcion: ");
                    scanf("%i", &opc1);
                    while (getchar() != '\n');
                }
                switch (opc1)
                {
                case 1:
                    crearpila(p);
                    pilaCargada = true;
                    pausar();
                    break;
                case 2:
                    if (pilaCargada)
                    {
                        mainBuscarClave(p);
                    }
                    else
                    {
                        printf("Primero debe cargar las pilas (opcion 1).\n");
                        printf("Pulse enter para volver al menu");
                    }
                    pausar();
                    break;
                case 3:
                    if (pilaCargada)
                    {
                        mainInsertarEnPila(p);
                    }
                    else
                    {
                        printf("Primero debe cargar las pilas (opcion 1).\n");
                        printf("Pulse enter para volver al menu");
                    }
                    pausar();
                    break;
                case 4:
                    if (pilaCargada)
                    {
                        mainEliminarPorClave(p);
                    }
                    else
                    {
                        printf("Primero debe cargar las pilas (opcion 1).\n");
                        printf("Pulse enter para volver al menu");
                    }
                    pausar();
                    break;
                case 5:
                    if (pilaCargada)
                    {
                        mainIntercambiar(p);
                    }
                    else
                    {
                        printf("Primero debe cargar las pilas (opcion 1).\n");
                        printf("Pulse enter para volver al menu");
                    }
                    pausar();
                    break;
                case 6:
                    if (pilaCargada)
                    {
                        mainDuplicarPila(p);
                    }
                    else
                    {
                        printf("Primero debe cargar las pilas (opcion 1).\n");
                        printf("Pulse enter para volver al menu");
                    }
                    pausar();
                    break;
                case 7:
                    if (pilaCargada)
                    {
                        mainContador(p);
                    }
                    else
                    {
                        printf("Primero debe cargar las pilas (opcion 1).\n");
                        printf("Pulse enter para volver al menu");
                    }
                    pausar();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            mainComparaPilas();
            pausar();
            break;
        case 4:
            mainConversorBases();
            pausar();
            break;
        case 5:
            mainInvertida();
            pausar();
            break;
        case 6:
        while (!salir2)
        {
            menu_punto5();
            while (scanf("%i", &opc2) != 1 || opc2 < 0 || opc2 > 2)
            {
                printf("Opcion incorrecta\n");
                printf("  Por favor seleccione una opcion: ");
                scanf("%i", &opc2);
                while (getchar() != '\n');
            }
            switch (opc2)
            {
            case 1:
                mainEliminarIterativo();
                pausar();
                break;
            case 2:
                mainEliminarRecursivo();
                pausar();
                break;
            case 0:
                salir2 = true;
            }
        }
        break;
        menu_principal();
        case 7:
            mainElementosComunes();
            pausar();
            break;
        case 8:
            mainContadorValores();
            pausar();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}
