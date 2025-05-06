#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/cola/headers/colas.h"
#include "../libs/cola/headers/tp_4_colas.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/listas/headers/listas.h"


void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}  

void pausar()
{
    limpiarBuffer();
    printf("\nPresione Enter para continuar...");
    while (getchar() != '\n');
}

int cargarTamano()
{
    int tamano;
    printf("ingrese la cantidad de elementos que desea ingresar a la cola: ");
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 10))
    {
        printf("Dato invalido. Ingrese un numero entero entre 1 y 10: ");
        limpiarBuffer();
    }
    tamano = (int)tamano;
    return tamano;
}

int cargarTamanoej3()
{
    int tamano;
    printf("ingrese la cantidad de elementos que desea ingresar a la cola(no mas de 5): "); //si ingresa mas de 5 la cola auxiliar de la funcion del ejercicio tendria mas elementos de los admitidos por la TAD
    while (scanf("%d", &tamano) != 1 || (tamano <= 0 || tamano > 5))
    {
        printf("Dato invalido. Ingrese un numero entero entre 1 y 5: ");
        limpiarBuffer();
    }
    tamano = (int)tamano;
    return tamano;
}

void cargarCola(Cola c, int tamano)
{
    int i = 0, elemento;
    TipoElemento elem;
    while (i< tamano)
    {
        printf("ingrese un elemento de la cola. (solo se admiten numeros enteros): ");
        while (scanf("%d", &elemento) != 1)
        {
            printf("elemento invalido. ingrese un elemento de la cola: ");
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        c_encolar(c, elem);
        i++;
    }
}

Cola cargarColaSinRepetidos(Cola cola, int tamano)
{
    int elemento, validador;
    bool esRepetido = false;
    limpiarBuffer();
    for (int i = 0; i < tamano; i++)
    {
        printf("Ingrese clave del elemento a cargar (mayor a 2 y sin repetir): ");
        validador = scanf("%d", &elemento);
        if (c_es_vacia(cola))
        {
            esRepetido = false;
        }
        else
        {
            esRepetido = c_ej2_existeclave(cola, elemento);
        }
        limpiarBuffer();
        while (validador != 1 || elemento < 2 || esRepetido)
        {
            printf("elemento invalido. ingrese un numero mayor a 2 sin repetir: ");
            scanf("%d", &elemento);
            limpiarBuffer();
            validador = scanf("%d", &elemento);
            if (c_es_vacia(cola))
                esRepetido = false;
            else
                esRepetido = c_ej2_existeclave(cola, elemento);
            limpiarBuffer();
        }
        TipoElemento x = te_crear(elemento);
        c_encolar(cola, x);
    }
    c_mostrar(cola); // muestro la cola como quedo cargada
    printf("\n");
    return cola;
}

void c_mostrar_con_valor(Cola cola)
{
    if (c_es_vacia(cola)){

        printf("COLA VACIA! \n");
        return;
    }
    Pila paux = p_crear();
    TipoElemento x = te_crear(0);
    printf ("\nContenido de la cola: ");
    while (!c_es_vacia(cola)) 
    {
        x = c_desencolar(cola);
        p_apilar(paux, x);
    }
    while (!p_es_vacia(paux)){

        x = p_desapilar(paux);
        printf("{%d:%lld},", x->clave, (intptr_t)x->valor);
        c_encolar(cola, x);
    }
}
void c_mostrar_con_valortf(Cola cola)
{
    int valor;
    Pila paux = p_crear();
    TipoElemento x = te_crear(0);
    if (c_es_vacia(cola)){

        printf("COLA VACIA! \n");
        return;
    }
    printf ("Contenido de la cola: ");
    while (!c_es_vacia(cola)) 
    {
        x = c_desencolar(cola);
        p_apilar(paux, x);
    }
    while (!p_es_vacia(paux)){

        x = p_desapilar(paux);
        valor = (int)(intptr_t)(x->valor);
        printf("{%d: %s},", x->clave, (valor ? "true" : "false"));
        c_encolar(cola, x);
    }
}

Cola cargarColaPositivos() {
    Cola resultante = c_crear();

    int tamano;
    printf("ingrese tamano de la cola: ");
    while(scanf("%d", &tamano) != 1 || tamano < 1 || tamano > 10) {
        limpiarBuffer();
        printf("invalido. ingrese numero entre 1 y 10: ");
    }
    limpiarBuffer();

    int dato;
    for(int i = 1; i <= tamano; i++) {
        printf("ingrese numero: ");
        while(scanf("%d", &dato) != 1 || dato < 1) {
            limpiarBuffer();
            printf("invalido, debe ser un numero, y mayor a cero: ");
        }
        limpiarBuffer();
        c_encolar(resultante, te_crear(dato));
    }

    return resultante;
}



//Punto 2
void crearCola(Cola c)
{
    printf("\n\t\t --- Carga de la cola --- \n");   
    int tamano = cargarTamano(); 
    cargarCola(c, tamano);
    printf("Pulse enter para volver al menú");
    return;
}
//item A
int mainBuscarElemento(Cola c)
{
    int clave;
    printf("ingrese la clave que busca: ");
    while(scanf("%d", &clave) !=1)
    {
        printf("Dato invalido. Ingrese un numero entero: ");
        limpiarBuffer();
    }
    if(c_ej2_existeclave(c, clave))
    {
        printf("la clave existe en la cola");
    }
    else
    {
        printf("la clave no existe en la cola");
    }
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//item B
int mainInsertar(Cola c)
{
    int posicion, clavetemp;
    Cola c2 = c_crear();
    TipoElemento clave;
    printf("ingrese el elemento para agregar en la cola: ");
    while ((scanf("%d", &clavetemp) != 1))
    {
        printf("dato invalido. ingrese un elemento valido: ");
        limpiarBuffer();
    }
    clave = te_crear(clavetemp);
    printf("ingrese la posicion en la que va a estar el elemento: ");
    while ((scanf("%d", &posicion) != 1) || posicion < 0)
    {
        printf("dato invalido. ingrese una posicion valida: ");
        limpiarBuffer();
    }
    c2 = c_ej2_colarelemento(c, posicion, clave);
    c_mostrar(c2);
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//item C
int mainEliminar(Cola c)
{
    int clave;
    Cola c2 = c_crear();
    printf("ingrese el elemento que desea eliminar: ");
    while ((scanf("%d", &clave) != 1))
    {
        printf("dato invalido. ingrese un elemento valido: ");
        limpiarBuffer();
    }
    c2 = c_ej2_sacarelemento(c, clave);    
    c_mostrar(c2);
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//item D
int mainContarElementos(Cola c)
{
    int cantidad = c_ej2_contarelementos(c);
    printf("\nCantidad de elementos en la cola: %d\n", cantidad);
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//item E
int mainClonar(Cola c)
{
    Cola aux = c_crear();
    aux = c_ej2_copiar(c);
    printf("\n\t\t --- Cola copiada ---");
    c_mostrar(aux);
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//item F
int mainInvertir(Cola c)
{
    Cola invertida = c_ej2_invertir(c);
    printf("Elementos en la cola invertida: ");
    c_mostrar(invertida);
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//Punto 3
int mainIguales(){
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    printf("\n\t\t --- tamaño de la cola 1 ---\n");
    int tamc1 = cargarTamanoej3();
    printf("\n\t\t --- tamaño de la cola 2 ---\n");
    int tamc2 = cargarTamanoej3();
    if (tamc2 != tamc1)
    {
        printf("Las colas son de distinta longitud. no pueden ser iguales");
    }
    else
    {
        printf("\n\t\t --- carga de la cola 1 ---\n");
        cargarCola(c1, tamc1);
        printf("\n\t\t --- carga de la cola 2 ---\n");
        cargarCola(c2, tamc2);
        if (c_ej3_iguales(c1, c2))
        {
            printf("Las colas son iguales");
        }
        else
        {
            printf("Las colas no son iguales");
        }
    }
    return 0;
}

//Punto 4
int mainNoRepetidos() {
    Cola c = c_crear();
    int tam = cargarTamano();
    cargarCola(c, tam);
    Cola resultado = c_ej4_colanorepetidos(c);
    printf("Cola sin elementos repetidos:\n");
    c_mostrar(resultado);
    printf("\n\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("La complejidad algoritmica es O(n^2) ya que la funcion utiliza 2 while anidados \nque dependen del tamaño de la cola principal del ejercicio.\n");
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//Punto 5
int mainDivisores()
{
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    printf("\n\t\t --- Carga de la cola --- \n");    
    int tamano = cargarTamano();
    cargarColaSinRepetidos(c1, tamano);
    c2 = c_ej5_divisortotal(c1);
    c_mostrar_con_valortf(c2);
    printf("\n\n\t\t\t--- Complejidad algoritmica del ejercicio ---\n");
    printf("La complejidad de la solución empleada es lineal O(n^2) porque hay varios ciclos que dependen de la cantidad de elementos \nde la cola, y ademas se encuentran anidados.");
    printf("\n\nPulse enter para volver al menú");
    return 0;
}

//Punto 6


//Punto 7
int mainAtenderClientes() {

    Cola c1 = cargarColaPositivos();
    Cola c2 = cargarColaPositivos();
    Cola c3 = cargarColaPositivos();
    c_mostrar(c1);
    c_mostrar(c2);
    c_mostrar(c3);

    int q;
    printf("ingrese tiempo de atencion: ");
    while(scanf("%d", &q) != 1 || q < 1) {
        limpiarBuffer();
        printf("Invalido. debe ser un numero, y mayor a cero: ");
    }
    limpiarBuffer();

    Cola resultados = c_ej7_atenderclientes(c1, c2, c3, q);
    printf("\nValores de las colas despues del proceso: \n");
    c_mostrar(c1);
    c_mostrar(c2);
    c_mostrar(c3);

    Cola resul_aux = c_crear();
    TipoElemento temp;
    while(!c_es_vacia(resultados)) {
        temp = c_desencolar(resultados);
        char *resul_texto;
        resul_texto = (char*) temp->valor;
        printf("Clave: %d Valor: %s\n", temp->clave, resul_texto);
        c_encolar(resul_aux, temp);
    }
    while(!c_es_vacia(resul_aux)) {
        c_encolar(resultados, c_desencolar(resul_aux));
    }
    c_mostrar(resultados);


    system("pause");

    return 0;
}


//menu
void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                                 TP4 COLAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con colas\n");
    printf("  3   Colas iguales\n");
    printf("  4   Elementos no repetidos\n");
    printf("  5   Divisores\n");
    printf("  6   Lista con valores comunes\n");
    printf("  7   Cola de clientes\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

//Menu del Punto 2: Operaciones con cola
void menu_punto2()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                         2   Operaciones con colas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Cargar Cola\n");
    printf("  2   Buscar elemento\n");
    printf("  3   Insertar elemento\n");
    printf("  4   Eliminar elemento\n");
    printf("  5   Contar los elementos\n");
    printf("  6   Realizar una copia\n");
    printf("  7   Invertir\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

int main()
{
    Cola c = c_crear();
    bool colaCargada = false, salir1 = false, salir = false;
    int opc1, opc2;
    int validador;
    while (!salir)
    {
        menu_principal();
        validador = scanf("%i", &opc1);
        while (getchar() != '\n')            ;
        while (validador != 1 || opc1 < 0 || opc1 > 8 || opc1 == 1)
        {
            printf("Opción incorrecta\n");
            printf("  Por favor seleccione una opción: ");
            validador = scanf("%i", &opc1);
            while (getchar() != '\n');
        }
        switch (opc1)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                validador = scanf("%i", &opc2);
                while (validador != 1 || opc2 < 0 || opc2 > 7)
                {
                    printf("Opción incorrecta\n");
                    printf("  Por favor seleccione una opción: ");
                    while (getchar() != '\n');
                    validador = scanf("%i", &opc2);
                }
                switch (opc2)
                {
                case 1:
                    crearCola(c);
                    colaCargada = true;
                    pausar();
                    break;
                case 2:
                    if(colaCargada)
                    {
                        mainBuscarElemento(c);
                    }
                    else
                    {
                        printf("Primero debe cargar la cola (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 3:
                    if(colaCargada)
                    {
                        mainInsertar(c);
                    }
                    else
                    {
                        printf("Primero debe cargar la cola (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 4:
                    if(colaCargada)
                    {
                        mainEliminar(c);
                    }
                    else
                    {
                        printf("Primero debe cargar la cola (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 5:
                    if(colaCargada)
                    {
                        mainContarElementos(c);
                    }
                    else
                    {
                        printf("Primero debe cargar la cola (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 6:
                    if(colaCargada)
                    {
                        mainClonar(c);
                    }
                    else
                    {
                        printf("Primero debe cargar la cola (opción 1).\n");
                        printf("Pulse enter para volver al menú");
                    }
                    pausar();
                    break;
                case 7:
                    if(colaCargada)
                    {
                        mainInvertir(c);
                    }
                    else
                    {
                        printf("Primero debe cargar la cola (opción 1).\n");
                        printf("Pulse enter para volver al menú");
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
            mainIguales();
            pausar();
            break;
        case 4:
            mainNoRepetidos();
            pausar();
            break;
        case 5:
            mainDivisores();
            pausar();
            break;
        case 6:
            //main_valores_comunes();
            // pausar();
            break;
        case 7:
            //main_ventanillas();
            // pausar();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}