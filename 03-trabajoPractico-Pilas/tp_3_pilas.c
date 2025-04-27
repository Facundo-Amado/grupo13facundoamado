#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pila/headers/pilas.h"
#include "../libs/pila/headers/tp_3_pilas.h"

Pila copiarpila(Pila p)
{
    Pila copia = p_crear();
    Pila aux = p_crear();
    TipoElemento elemento;
    while (!p_es_vacia(p)) {
        elemento = p_desapilar(p);
        p_apilar(aux, elemento);
        p_apilar(copia, elemento);
    }
    while (!p_es_vacia(aux)) {
        elemento = p_desapilar(aux);
        p_apilar(p, elemento);
    }
    return copia;
}

//Punto 2
bool p_ej2_existeclave(Pila pila, int clave) {
    Pila aux = p_crear();                                               
    bool encontrado = false;
    TipoElemento elem;                                       
    while (!p_es_vacia(pila)) {                               
        elem = p_desapilar(pila);             
        if (clave == elem->clave) {
            encontrado = 1;
        }
        p_apilar(aux, elem);                                
    }
    while (!p_es_vacia(aux)) 
    {
        elem =  p_desapilar(aux);
        p_apilar(pila, elem);                  
    }
    return encontrado;                                    
}

Pila p_ej2_colocarelemento(Pila pila, int posicion, TipoElemento valor) {
    Pila aux = p_crear();
    TipoElemento x;                                                       
    int i = 1;
    if (posicion <= 0 || p_es_vacia(pila)) 
    {
        return pila;
    }
    while (!p_es_vacia(pila) && i < posicion) 
    {   x = p_desapilar(pila);               
        p_apilar(aux, x);                          
        i++;
    }
    p_apilar(pila, valor);                                     
    while (!p_es_vacia(aux)) 
    {
        x =  p_desapilar(aux);
        p_apilar(pila, x);  
                
    }
    return pila;
}

Pila p_ej2_eliminarclave(Pila pila, int clave) {
    Pila aux = p_crear();
    TipoElemento elemento;                                                              
    bool eliminado = false;                                                             
    while (!p_es_vacia(pila) && !eliminado) {                                            
        elemento = p_desapilar(pila);                        
        if (elemento->clave == clave) 
        {               
            eliminado = true;                                                
        } 
        else 
        {
            p_apilar(aux, elemento);                                     
        }
    }                                    
    while (!p_es_vacia(aux)) { 
        elemento = p_desapilar(aux);                                                  
        p_apilar(pila, elemento);

    }
    return pila;
}

Pila p_ej2_intercambiarposiciones(Pila pila, int pos1, int pos2) {        
    Pila aux = p_crear();
    int cont = 1;
    TipoElemento x; 
    TipoElemento temp1;
    TipoElemento temp2;
    if (pos1 == pos2)
    {
        return pila;
    }
    else
    {
        while (!p_es_vacia(pila))
        { 
            x = p_desapilar(pila);
            if (cont == pos1)
            {
                temp1 = x;
            }
            else if (cont == pos2)
            {
                temp2 = x;
            }   
            p_apilar(aux, x);                         
            cont ++;
        }
        cont --;
        while(!p_es_vacia(aux))
        {
            x = p_desapilar(aux);
            if (cont == pos1)
            {
                p_apilar(pila, temp2);
            }
            else if (cont == pos2)
            {
                p_apilar(pila, temp1);
            }
            else
            {
                p_apilar(pila, x); 
            } 
            cont --;
        }
        return pila;
    }
}

Pila p_ej2_duplicar(Pila pila) {

    Pila duplicada = p_crear();
    Pila aux = p_crear();
    TipoElemento valor;
    while (!p_es_vacia(pila)) {
        valor = p_desapilar(pila);
        p_apilar(aux, valor);
        p_apilar(duplicada, valor);
    }
    while (!p_es_vacia(aux)) {
        valor = p_desapilar(aux);
        p_apilar(pila, valor);
    }
    return duplicada;
}

int p_ej2_cantidadelementos(Pila pila) {
    Pila aux = p_crear();                                        
    aux = copiarpila(pila);                                       
    int contador = 0;                                      
    // Desapilar todos los elementos para contar
    while (!p_es_vacia(pila)) {                            
        p_desapilar(pila);                                
        contador++;                                        
    }                                   
    while (!p_es_vacia(aux)) {                             
        p_apilar(pila, p_desapilar(aux));                  
    }
    return contador;                                         
}

//Punto 3

//Punto 4
char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase) {
    char* resultado;
    int longitud;
    bool esNegativo = false;

    if (nrobasedecimal < 0) {
        esNegativo = true;
        nrobasedecimal = -nrobasedecimal;
    }

    longitud = snprintf(NULL, 0, "%d", nrobasedecimal);
    resultado = (char*)malloc(longitud + 2); 

    if (nrootrabase < 2 || nrootrabase > 16) {
        sprintf(resultado, "%s%d", esNegativo ? "-" : "", nrobasedecimal);
        return resultado;
    }

    Pila p = p_crear();

    if (nrobasedecimal == 0) {
        TipoElemento te = te_crear(0);
        p_apilar(p, te);
    } else {
        while (nrobasedecimal > 0) {
            int resto = nrobasedecimal % nrootrabase;
            TipoElemento te = te_crear(resto);
            p_apilar(p, te);
            nrobasedecimal = nrobasedecimal / nrootrabase;
        }
    }

    int i = 0;

    if (esNegativo) {
        resultado[i++] = '-';
    }

    while (!p_es_vacia(p)) {
        TipoElemento te = p_desapilar(p);
        int valor = te->clave;

        if (valor < 10) {
            resultado[i++] = '0' + valor;
        } else {
            resultado[i++] = 'A' + (valor - 10);
        }

        free(te);
    }

    resultado[i] = '\0';

    return resultado;
}

//Punto 5
Pila  p_ej5_invertir(Pila p){
    Pila p_invertida = p_crear();
    Pila aux = p_crear();
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        p_apilar(p_invertida, elem);
        p_apilar(aux, elem);
    }
    while (!p_es_vacia(aux)){
        TipoElemento elemento = p_desapilar(aux);
        p_apilar(p, elemento);
    }
    return p_invertida;
}

//Punto 6
// Version iterativa
Pila p_ej6_eliminarclave(Pila p, int clave) {
    if (p_es_vacia(p)) {
        return NULL;
    }
    Pila paux = p_crear();
    Pila paux2 = p_crear();
    TipoElemento temp = te_crear(0);

    while(!p_es_vacia(p)) {
        temp = p_tope(p);
        p_apilar(paux, temp);
        temp = p_desapilar(p);
        p_apilar(paux2, temp);
    }

    while(!p_es_vacia(paux)) {
        temp = p_desapilar(paux);
        p_apilar(p, temp);
    }

    while(!p_es_vacia(paux2)) {
        temp = p_desapilar(paux2);
        if (temp->clave != clave) {
            p_apilar(paux, temp);
        }
    }
    return paux;
}

// Version recursiva
Pila p_ej6_eliminarclave_r(Pila p, int clave) {
    Pila paux = p_crear();
    TipoElemento temp = te_crear(0);
    if (p_es_vacia(p)) {
        return paux;
    }
    else {
        temp = p_desapilar(p);
        if (temp->clave != clave) {
            p_apilar(paux, temp);
        }
        p_ej6_eliminarclave_r(p, clave);
        p_apilar(p, temp);
    }
    return paux;
}

//Punto 7
Pila p_ej7_elementoscomunes(Pila p1, Pila p2)
{
    Pila elemcomunes = p_crear();
    Pila aux1 = p_crear();
    Pila aux2 = p_crear();
    TipoElemento te1;
    TipoElemento te2;
    if (p_es_vacia(p1) || p_es_vacia(p2)) 
    {
        return elemcomunes;
    }
    while (!p_es_vacia(p1))
    {
        te1 = p_desapilar(p1);
        p_apilar(aux1, te1);
        while (!p_es_vacia(p2))
        {
            te2 = p_desapilar(p2);
            p_apilar(aux2, te2);
            if (te1->clave == te2->clave)
            {
                p_apilar(elemcomunes, te1);
            }
        }   
        while (!p_es_vacia(aux2)) 
        {
            p_apilar(p2, p_desapilar(aux2));                  
        } 
    }
    while (!p_es_vacia(aux1)) 
    {
        p_apilar(p1, p_desapilar(aux1));                  
    }
    return elemcomunes;
}

//Punto 8

Pila p_ej8_sacarrepetidos(Pila p){
    Pila PR = p_crear();
    Pila aux1 = p_crear();
    Pila aux2 = p_crear();
    int contadorelemento = 0;
    TipoElemento te, teaux;
    ClonarPila(p, aux1);

    while(!p_es_vacia(aux1)){
        IntercambiarPilas(aux1, aux2);
        te = p_desapilar(aux2);
        contadorelemento = 1;

        while(!p_es_vacia(aux2)){
            teaux = p_desapilar(aux2);
            if(teaux->clave == te->clave){
                contadorelemento++;
            } else {
                p_apilar(aux1, teaux);
            }
        }

        TipoElemento nuevo_elemento = te_crear_con_valor(te->clave, (void *)(intptr_t)contadorelemento);
        p_apilar(PR, nuevo_elemento);
    }

    Pila PRR = p_crear();
    while(!p_es_vacia(PR)){
        te = p_desapilar(PR);
        p_apilar(PRR, te);
    }

    return PRR;
}
