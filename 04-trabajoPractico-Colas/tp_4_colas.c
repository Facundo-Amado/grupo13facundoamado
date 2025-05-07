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


//Punto 2
//item a
bool c_ej2_existeclave(Cola c, int clave)
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

//item b
Cola c_ej2_colarelemento(Cola c, int pos, TipoElemento x)
{
    Cola caux = c_crear();
    int i = 1;
    TipoElemento x1;
    while(!c_es_vacia(c))
    {
        x1 = c_desencolar(c);
        if (i == pos)
        {
            c_encolar(caux, x);
        }
        c_encolar(caux, x1);
        i++;
    }
    while (!c_es_vacia(caux))
    {
        c_encolar(c, c_desencolar(caux));
    }
    return c;
}

//item c
Cola c_ej2_sacarelemento(Cola c, int clave)
{
    TipoElemento x;
    Cola caux = c_crear();
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        if (clave != x->clave)
        {
               c_encolar(caux, x);
        }
    }
    while (!c_es_vacia(caux))
    {
        c_encolar(c, c_desencolar(caux));
    }
    return c;   
}

//item d
int c_ej2_contarelementos(Cola c) 
{
    TipoElemento elem;
    Cola aux = c_crear();
    int resultado = 0;
    while (!c_es_vacia(c)) {
        elem = c_desencolar(c);
        resultado++;
        c_encolar(aux, elem);
    }
    while (!c_es_vacia(aux)) {
        elem = c_desencolar(aux);
        c_encolar(c, elem); // Restaura la cola original
    }
    return resultado; // Si esta vacia, no va a hacer el codigo de arriba y va a retornar 0.
}

//item e
Cola c_ej2_copiar(Cola c) 
{
    Cola copia = c_crear();
    Cola aux = c_crear();
    TipoElemento elem;

    // Desencolo elementos, copio y guardo en aux
    while (!c_es_vacia(c)) {
        elem = c_desencolar(c);
        c_encolar(aux, elem);
        c_encolar(copia, elem);
    }
    // Restauro los elementos en la cola original
    while (!c_es_vacia(aux)) {
        elem = c_desencolar(aux);
        c_encolar(c, elem);
    }
    return copia;
}

//item f
Cola c_ej2_invertir(Cola c) {
    Cola resultado = c_crear();
    Pila invertir = p_crear();
    Cola aux = c_crear();
    TipoElemento elem;
    // Paso 1: Pasar elementos de la cola a la pila y a una auxiliar
    while (!c_es_vacia(c)) {
        elem = c_desencolar(c);
        p_apilar(invertir, elem); // Guarda en orden inverso
        c_encolar(aux, elem);     // Guarda para restaurar la original
    }
    // Paso 2: Pasar de la pila a una nueva cola (inversion)
    while (!p_es_vacia(invertir)) {
        elem = p_desapilar(invertir);
        c_encolar(resultado, elem);
    }
    // Paso 3: Restaurar la cola original desde la auxiliar
    while (!c_es_vacia(aux)) {
        elem = c_desencolar(aux);
        c_encolar(c, elem);
    }
    return resultado;
}

//Punto 3
bool c_ej3_iguales(Cola c1, Cola c2){
    Cola aux = c_crear();
    bool sonIguales = true;
    TipoElemento elem1, elem2; 
    while(!c_es_vacia(c1) && !c_es_vacia(c2)){
        elem1 = c_desencolar(c1);
        elem2 = c_desencolar(c2);
        if(elem1->clave != elem2->clave)
        {
            sonIguales = false;
        }
                c_encolar(aux, elem1);
        c_encolar(aux, elem2);
    }
    while(!c_es_vacia(aux))
    {
        c_encolar(c1, c_desencolar(aux));
        c_encolar(c2, c_desencolar(aux));
    }
    return sonIguales;
}

//Punto 4
Cola c_ej4_colanorepetidos(Cola c) 
{  
    Cola aux = c_crear(), aux2 = c_crear(), sinRepetidos = c_crear();
    Pila paux = p_crear();
    TipoElemento x1, x2;
    bool repetido;
    while (!c_es_vacia(c)) 
    {
        x1 = c_desencolar(c);
        repetido = false;
        while (!c_es_vacia(c)) 
        {
            x2 = c_desencolar(c);
            if (x2->clave == x1->clave) {
                repetido = true;
            }
            c_encolar(aux2, x2);
        }
        if (!repetido) 
        {
            c_encolar(sinRepetidos, x2);
        }
        c_encolar(aux, x1);
        while (!c_es_vacia(aux2)) 
        {
            c_encolar(c, c_desencolar(aux2));
        }
    }
    while(!c_es_vacia(sinRepetidos))
    {
        p_apilar(paux, c_desencolar(sinRepetidos));
    }
    while(!p_es_vacia(paux))
    {
        c_encolar(sinRepetidos, p_desapilar(paux));
    }
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }
    return sinRepetidos;
}

//Punto 5
Cola c_ej5_divisortotal(Cola c)
{
    int contDiv = 0, tamano = 0;
    TipoElemento x, x2, elemtot, elemparcial;
    Cola aux = c_crear(), aux2 = c_crear(), temp = c_crear(), divTotales = c_crear(), divParciales = c_crear(), copia = c_crear();
    bool divTotal, divParcial;
    if (c_es_vacia(c))
    {
        return c;
    }
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        c_encolar(aux, x);
        c_encolar(aux2, x);
        c_encolar(copia, x);
        tamano ++;
    }
    while (!c_es_vacia(aux))
    {
        divTotal = false; 
        divParcial = false;
        contDiv = 0;
        x = c_desencolar(aux);
        while (!c_es_vacia(aux2))
        {
            x2 = c_desencolar(aux2);
            if (x2->clave % x->clave == 0)
            {
                contDiv ++;
            }
            c_encolar(temp, x2);
        }
        while (!c_es_vacia(temp))
        {
            c_encolar(aux2, c_desencolar(temp));
        }
        if (contDiv == tamano)
        {
            divTotal = true;
        }
        else if (contDiv >= tamano/2)
        {
            divParcial = true;
        }
        elemtot = te_crear_con_valor(x->clave, (void*)(intptr_t)divTotal);
        elemparcial = te_crear_con_valor(x->clave, (void*)(intptr_t)divParcial);
        c_encolar(divTotales, elemtot);
        c_encolar(divParciales, elemparcial);
    }
    while (!c_es_vacia(copia)) {
        c_encolar(c, c_desencolar(copia));
    }
    return divTotales;
}


//Punto 6
Lista c_ej6_comunesapilaycola(Pila p, Cola c)
{
    Cola caux = c_crear();
    Pila paux = p_crear();
    Lista comunes = l_crear();
    TipoElemento cx, px, elem;
    int ci, pi = 1;
    if(p_es_vacia(p) || c_es_vacia(c))
    {
        return comunes;
    }
    while (!p_es_vacia(p))
    {
        ci = 1;
        px = p_desapilar(p);
        while (!c_es_vacia(c))
        {
            cx = c_desencolar(c);
            if((cx->clave == px->clave))
            {
                char* descripcion = malloc(25);
                snprintf(descripcion, 25, "%d:%d", pi, ci);
                elem = te_crear_con_valor(px->clave, (void*)descripcion); 
                l_agregar(comunes, elem);
            }
            c_encolar(caux, cx);
            ci++;
        }
        p_apilar(paux, px);
        pi++;
        while (!c_es_vacia(caux))
        {
            c_encolar(c, c_desencolar(caux));
        }
    }
    while (!p_es_vacia(paux))
    {
        p_apilar(p, p_desapilar(paux));
    }
    return comunes;
}

//Punto 7
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion) {
    if(c_es_vacia(c1) || c_es_vacia(c2) || c_es_vacia(c3)) {
        printf("\nUna o mas colas estan vacias, se retorna cola vacia\n");
        return c_crear();
    }
    if(tiempoatencion < 1) {
        printf("\nTiempo de atencion menor a 1 (0 o negativo), se retorna cola vacia\n");
        return c_crear();
    }

    Cola resultados = c_crear();
    int c1Len = 0;
    int c2Len = 0;
    int c3Len = 0;
 
    TipoElemento temp;
    Cola c1aux = c_crear();
    Cola c1contenedor = c_crear();
    while(!c_es_vacia(c1)) {
        c1Len++;
        temp = c_desencolar(c1);
        c_encolar(c1aux, te_crear(temp->clave));
        c_encolar(c1contenedor, temp);
    }
    while(!c_es_vacia(c1contenedor)) {
        c_encolar(c1, c_desencolar(c1contenedor));
    }

    Cola c2aux = c_crear();
    Cola c2contenedor = c_crear();
    while(!c_es_vacia(c2)) {
        c2Len++;
        temp = c_desencolar(c2);
        c_encolar(c2aux, te_crear(temp->clave));
        c_encolar(c2contenedor, temp);
    }
    while(!c_es_vacia(c2contenedor)) {
        c_encolar(c2, c_desencolar(c2contenedor));
    }

    Cola c3aux = c_crear();
    Cola c3contenedor = c_crear();
    while(!c_es_vacia(c3)) {
        c3Len++;
        temp = c_desencolar(c3);
        c_encolar(c3aux, te_crear(temp->clave));
        c_encolar(c3contenedor, temp);
    }
    while(!c_es_vacia(c3contenedor)) {
        c_encolar(c3, c_desencolar(c3contenedor));
    }
    free(c1contenedor);
    free(c2contenedor);
    free(c3contenedor);

    TipoElemento temp2, temp3;
    int c1pos = 0;
    int c2pos = 0;
    int c3pos = 0;
    temp = c_recuperar(c1aux);
    temp2 = c_recuperar(c2aux);
    temp3 = c_recuperar(c3aux);

    while(c1Len >= 1 || c2Len >= 1 || c3Len >= 1) {

        temp->clave = temp->clave - tiempoatencion;
        if(temp->clave <= 0 && c1Len >= 1) {
            
            c1pos++;
            c1Len--;
            char *c1texto = (char*) malloc(sizeof(char) * 35);
            snprintf(c1texto, 35, "Cliente %d Cola 1", c1pos);
            c_encolar(resultados, te_crear_con_valor(1, c1texto));

            c_encolar(c1aux, temp);
            temp = c_desencolar(c1aux);
        }

        temp2->clave = temp2->clave - tiempoatencion;
        if(temp2->clave <= 0 && c2Len >= 1) {
            
            c2Len--;
            c2pos++;
            char *c2texto = (char*) malloc(sizeof(char) * 35);
            snprintf(c2texto, 35, "Cliente %d Cola 2", c2pos);
            c_encolar(resultados, te_crear_con_valor(2, c2texto));

            c_encolar(c2aux, temp2);
            temp2 = c_desencolar(c2aux);
        }


        temp3->clave = temp3->clave - tiempoatencion;
        if(temp3->clave <= 0 && c3Len >= 1) {

            c3Len--;
            c3pos++;
            char *c3texto = (char*) malloc(sizeof(char) * 35);
            snprintf(c3texto, 35, "Cliente %d Cola 3", c3pos);
            c_encolar(resultados, te_crear_con_valor(3, c3texto));

            c_encolar(c3aux, temp3);
            temp3 = c_desencolar(c3aux);
        }

    }

    free(c1aux);
    free(c2aux);
    free(c3aux);
    
    return resultados;
}