#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../tipoElemento/headers/tipo_elemento.h"
#include "../cola/headers/colas.h"
#include "../pila/headers/pilas.h"
#include "../listas/headers/listas.h"
#include "../arboles/headers/arbol-binario.h"
#include "../arboles/headers/nodo.h"
#include "../arboles/headers/arbol-avl.h"
#include "../arboles/headers/arbol-binario-busqueda.h"
#include "../tablaHash/headers/tabla_hash.h"
#include "../conjuntos/headers/conjuntos.h"

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

//ingreso de datos

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
            printf("elemento invalido. ingrese un numero entero positivo: ");
            limpiarBuffer();
        }
        elemento = (int)elemento;
        elem = te_crear(elemento);
        c_encolar(c, elem);
        i++;
    }
}

bool buscarElemCola(Cola c, int clave)
{
    TipoElemento x;
    Cola caux = c_crear();
    bool encontrado = false;
    while (!c_es_vacia(c) && !encontrado)
    {
        x = c_desencolar(c);
        if (clave == x->clave)
        {
            encontrado = true;
        }
        c_encolar(caux, x);
    }
    while(!c_es_vacia(caux))
    {
        c_encolar(c, c_desencolar(caux));
    }
    return encontrado;
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
            esRepetido = buscarElemCola(cola, elemento);
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
                esRepetido = buscarElemCola(cola, elemento);
            limpiarBuffer();
        }
        TipoElemento x = te_crear(elemento);
        c_encolar(cola, x);
    }
    c_mostrar(cola); // muestro la cola como quedo cargada
    printf("\n");
    return cola;
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

bool ingresoEntero(int* n){
    char s[10];
    bool resultado = true;
    *n=0;
    printf("Ingrese una clave numerica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = false;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
        }
    }
    return resultado;
}

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if(!a_es_lleno(A)){
        b= ingresoEntero(&n);
        if (b){
            X= te_crear(n);
            
            if(sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }    
}

/*Funcion que recibe el arbol a ser cargado y llama a la funcion recursiva que realiza
la carga nodo por nodo*/
void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}

int repetidos(NodoArbol raiz, int clave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->datos->clave == clave) {
        return 1;
    }

    int encontradoI = repetidos(raiz->hi, clave);

    if (encontradoI) {
        return 1;
    }

    return repetidos(raiz->hd, clave);
}

void Cargar_SubArbol_NoRepetidos(ArbolBinario A, NodoArbol N, int sa) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A)) {
        do {
            b = ingresoEntero(&n);
            if (!b) return;
            if (repetidos(a_raiz(A), n)) {
                printf("ERROR: Clave repetida. Ingrese una clave diferente.\n\n");
            }
        } while (repetidos(a_raiz(A), n));

        if (b) {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if (sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol_NoRepetidos(A, N1, -1);
            Cargar_SubArbol_NoRepetidos(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_NoRepetidos(ArbolBinario A) {
    Cargar_SubArbol_NoRepetidos(A, NULL, 0);
}

Conjunto cargarConjunto()
{
    int tamano, validador, claveIngresada;
    TipoElemento X;
    bool pertenece;
    Conjunto A = cto_crear();
    printf("Ingrese la cantidad de elementos del conjunto: ");
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf("Entrada invalida.\n");
        printf("Ingrese la cantidad de elementos del conjunto: ");
        limpiarBuffer();
        validador = scanf("%i", &tamano);
    }
    if (tamano > 0)
    {
        for (int i = 1; i <= tamano; i++)
        {
            printf("Ingrese el elemento #%d del conjunto: ", i);
            validador = scanf("%d", &claveIngresada);
            if (cto_es_vacio(A)) 
            {
                pertenece = false;
            } 
            else {
                pertenece = cto_pertenece(A, claveIngresada);
            }
            while ((validador != 1) || (claveIngresada <= -10000) || (claveIngresada >= 10000) ||
                   pertenece)
            {
                printf("Entrada invalida.\n");
                printf("Ingrese el elemento #%d del conjunto: ", i);
                limpiarBuffer();
                validador = scanf("%d", &claveIngresada);
            if (cto_es_vacio(A)) 
                {
                    pertenece = false;
                } 
                else 
                {
                    pertenece = cto_pertenece(A, claveIngresada);
                }
            }
            X = te_crear(claveIngresada);
            cto_agregar(A, X);
        }
        printf("El conjunto fue cargado con éxito \n");
        cto_mostrar(A);
    }
    else
        printf("El conjunto fue creado vacío \n");
    return A;
}

Conjunto cargarConjuntoPositivos()
{
    int tamano, validador, claveIngresada;
    TipoElemento X;
    bool pertenece;
    Conjunto A = cto_crear();
    printf("Ingrese la cardinalidad del conjunto: ");
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf("Entrada invalida.\n");
        printf("Ingrese la cardinalidad del conjunto: ");
        limpiarBuffer();
        validador = scanf("%i", &tamano);
    }
    if (tamano > 0)
    {
        for (int i = 1; i <= tamano; i++)
        {
            printf("Ingrese el elemento #%d del conjunto: ", i);
            validador = scanf("%d", &claveIngresada);
            if (cto_es_vacio(A)) 
            {
                pertenece = false;
            } 
            else {
                pertenece = cto_pertenece(A, claveIngresada);
            }            
            while ((validador != 1) || (claveIngresada < 0) || (claveIngresada >= 10000) || pertenece)
            {
                printf("Entrada invalida. Ingresar solo numero naturales (> 0)\n");
                printf("Ingrese el elemento #%d del conjunto: ", i);
                limpiarBuffer();
                validador = scanf("%d", &claveIngresada);
                if (cto_es_vacio(A)) 
                {
                    pertenece = false;
                } 
                else 
                {
                    pertenece = cto_pertenece(A, claveIngresada);
                }            
            }
            X = te_crear(claveIngresada);
            cto_agregar(A, X);
        }
        printf("El conjunto fue cargado con éxito \n");
        cto_mostrar(A);
    }
    else
        printf("El conjunto fue creado vacío \n");
    return A;
}


//funciones para mostrar

void l_mostrar_con_valor(Lista l)
{
    if (l_es_vacia(l)){

        printf("LISTA VACIA! \n");
        return;
    }
    printf("Contenido de la lista: ");
    for (int i = 1; i < l_longitud(l); i++) 
    {
        TipoElemento elem = l_recuperar(l, i);
        int valor = *(int*)elem->valor;
        printf("%d:%d ", elem->clave, valor);
    }
    printf("\n");
}

void c_mostrar_con_valortf(Cola cola)
{
    bool valor;
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
        valor = *(bool*) x->valor;
        printf("{%d: %s},", x->clave, (valor ? "true" : "false"));
        c_encolar(cola, x);
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void post_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}

//funciones auxiliares
/*Funcion recursiva que recibe un NodoArbol (inicialmente la raiz), la clave buscada,
 un apuntador a entero para poder devolver el nivel de la clave (si la encuentra) y 
 el nivel del NodoArbol Q*/
void nivelint(NodoArbol Q, int Cbuscada, int *h, int c){
    TipoElemento X;
    if (Q != NULL) {
        X= n_recuperar(Q);
        if (X->clave == Cbuscada) {
            *h = c;
        }else{
            nivelint(n_hijoizquierdo(Q), Cbuscada, h, c+1);
            nivelint(n_hijoderecho(Q), Cbuscada, h, c+1);
        }
    }
}

// Funcion que devuelve el nivel de una clave o -1 si esta no se encuentra en el arbol.
// Llama a la funcion recursiva que busca la clave y proporciona su nivel.
int nivelNodo(ArbolBinario A, int N){
    int nivel = -1;
    nivelint(a_raiz(A), N, &nivel, 0);
    return nivel;
}

void alturaSub(ArbolBinario arbol, NodoArbol nodo, int *altura, int cantidad){
    if(nodo==NULL){
        if(cantidad>*altura){*altura=cantidad;}       
    }    else{        
        alturaSub(arbol,n_hijoizquierdo(nodo),altura,cantidad+1);        
        alturaSub(arbol,n_hijoderecho(nodo),altura,cantidad+1);    
    }

}

int a_altura(ArbolBinario arbol){
    int altura=0;    
    alturaSub(arbol,a_raiz(arbol),&altura,0);    
    return altura;
}

bool esPrimo(int numero)
{
    if (numero <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(numero); i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }

    return true;
}

int numeroPrimoMasCercanoMenor(int numero)
{
    int numeroPrimo = numero - 1;

    while (numeroPrimo > 1)
    {
        if (esPrimo(numeroPrimo))
        {
            return numeroPrimo;
        }

        numeroPrimo--;
    }

    return -1; // No se encontró un número primo menor
}

void free_avl(NodoArbol Q)
{
    if (avl_es_rama_nula(Q))
    {
        return;
    }

    free_avl(n_hijoizquierdo(Q));
    free_avl(n_hijoderecho(Q));
    free(Q);
    Q = NULL;
}

int getRandom(int min, int max)
{
    int n_aleatorio;
    n_aleatorio = min + (rand() % (max - min + 1));
    return n_aleatorio;
}

void cargar_clave_AVL_HASH(TablaHash *th, ArbolAVL *A_AVL, int min, int max)
{
    TipoElemento X;
    int n_aleatorio;
    if (!avl_es_lleno(*A_AVL))
    {
        n_aleatorio = getRandom(min, max);
        while (avl_buscar(*A_AVL, n_aleatorio) != NULL)
        {
            n_aleatorio = getRandom(min, max);
        }
        X = te_crear(n_aleatorio);
        avl_insertar(*A_AVL, X);
        th_insertar(*th, X);
    }
}

int FuncionHash_Punto6(int n)
{
    return n % 47;
}

struct PersonaRep
{
    int fecha;
    int dni;
    char nombre[20];
    char apellido[20];
};
typedef struct PersonaRep *Persona;

//Funcion que dado un dia, mes y anio indica si la fecha es valida
bool validarFecha(int dia, int mes, int anio)
{
    int dia_maximo;
    bool fecha_correcta = false;

    if (mes >= 1 && mes <= 12)
    {
        switch (mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dia_maximo = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            dia_maximo = 30;
            break;

        case 2:
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
                dia_maximo = 29;
            else
                dia_maximo = 28;
        }
        if (dia >= 1 && dia <= dia_maximo)
            fecha_correcta = true;
    }
    return fecha_correcta;
}

int juntarNumeros(int dia, int mes, int anio)
{
    char fecha[9];
    sprintf(fecha, "%02u%02u%04u", dia, mes, anio);
    int entero = atoi(fecha);
    return entero;
}

bool sonLetras(char *cadena)
{
    bool res = true;
    for (int i = 0; i < strlen(cadena) - 1; i++)
    {
        if (!isalpha(cadena[i]))
        {
            res = false;
        }
    }
    return res;
}

void agregarATabla(TablaHash *th, Persona persona)
{

    TipoElemento X = th_recuperar(*th, persona->fecha);
    if (X == NULL)
    {
        Lista L = l_crear();
        X = te_crear_con_valor(0, persona);
        l_agregar(L, X);
        TipoElemento X1 = te_crear_con_valor(persona->fecha, L);
        th_insertar(*th, X1);
    }
    else
    {
        TipoElemento X1 = te_crear_con_valor(0, persona);
        Lista L = (Lista)X->valor;
        l_agregar(L, X1);
        X->valor = L;
        th_insertar(*th, X);
    }
}

void cargarPersona(TablaHash *th)
{
    Persona persona = malloc(sizeof(struct PersonaRep));
    int dia, mes, anio, validador;
    bool fechaValida = false;
    // Cargar DNI
    printf("DNI: ");
    validador = scanf("%d", &persona->dni);
    limpiarBuffer();
    while (validador != 1 || persona->dni < 1 || persona->dni > 99999999)
    {
        printf("DATO FUERA DE RANGO\n\n");
        pausar();
        printf("ingrese un DNI valido: ");
        validador = scanf("%d", &persona->dni);
        limpiarBuffer();
    }
    // Cargar nombre
    bool estado_nombre = true;
    do
    {
        if (!estado_nombre)
        {
            printf("ERROR\tNO ES UNA CADENA VALIDA\n");
        }
        printf("Nombre: ");
        fgets(persona->nombre, 20, stdin);
        persona->nombre[strcspn(persona->nombre, "\n")] = '\0'; // Eliminar el caracter de nueva linea
        estado_nombre = sonLetras(persona->nombre);
    } while (!estado_nombre);

    // Cargar apellido
    bool estado_apellido = true;
    do
    {
        if (!estado_apellido)
        {
            printf("ERROR\tNO ES UNA CADENA VALIDA\n");
        }
        printf("Apellido: ");
        fgets(persona->apellido, 20, stdin);
        persona->apellido[strcspn(persona->apellido, "\n")] = '\0'; // Eliminar el caracter de nueva linea
        estado_apellido = sonLetras(persona->apellido);
    } while (!estado_apellido);

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
        validador = scanf("%u", &mes);
        limpiarBuffer();
        while (validador != 1 || mes < 1 || mes > 12)
        {
            printf("\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n");
            pausar();
            printf("Mes: ");
            validador = scanf("%u", &mes);
            limpiarBuffer();
        }

        // Cargar anio
        printf("Anio: ");
        validador = scanf("%u", &anio);
        limpiarBuffer();
        while (validador != 1 || anio < 2020 || anio > 2025)
        {
            printf("\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n");
            printf("El rango es entre 2020 y 2025\n\n");
            pausar();
            printf("Anio: ");
            validador = scanf("%u", &anio);
            limpiarBuffer();
        }
        fechaValida = validarFecha(dia, mes, anio);
        printf("%s", fechaValida ? "La fecha es valida\n" : "La fecha no es valida, vuelva a ingresarla\n");
    }

    persona->fecha = juntarNumeros(dia, mes, anio);

    agregarATabla(th, persona);
    printf("\nPersona cargada correctamente!\n");
    pausar();
}

bool p2_pertenece(Conjunto A, Conjunto B){
    bool resultado = true;
    int card_A = cto_cantidad_elementos(A);
    int card_B = cto_cantidad_elementos(B);
    TipoElemento X;
    if (card_A <= card_B)
    {
        for (int i = 0; i < card_A; i++)
        {
            X = cto_recuperar(A, i);
            resultado = cto_pertenece(B, X->clave);
            if (resultado == false)
            {
                return resultado;
            }
        }
    }
    else{
        for (int i = 0; i < card_B; i++)
        {
            X = cto_recuperar(B, i);
            resultado = cto_pertenece(A, X->clave);
            if (resultado == false)
            {
                return resultado;
            }
        }
    }
    return resultado;
}


