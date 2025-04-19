#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\listas\headers\tp_2_listas.h"
#include "..\libs\listas\headers\listas.h"

//Punto 2


//Punto 3
ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul resultado;
    resultado.esMultiplo = true;             // Inicializo en true, si no es multiplo se cambia a false
    // longitud de ambas listas
    int long1 = l_longitud(l1);
    int long2 = l_longitud(l2);
    TipoElemento elemL2, elemL1;
    // Iteradores para recorrer ambas listas simultáneamente.
    Iterador itL1 = iterador(l1);
    Iterador itL2 = iterador(l2);
    if (long1 != long2) {                   // Si las listas no son del mismo tamaño, no pueden ser múltiplos
        resultado.esMultiplo = false;
        resultado.escalar = false;
        return resultado;
    }

    int flag = 0;
    int escalar;

    while (hay_siguiente(itL1) && resultado.esMultiplo) { // Validar divisibilidad y escalar 
        elemL2 = siguiente(itL2); 
        elemL1 = siguiente(itL1); 
        if (elemL2->clave % elemL1->clave == 0 && flag == 0) {
            escalar = elemL2->clave / elemL1->clave;
            resultado.escalar = true;
        }
        else if (elemL2->clave % elemL1->clave != 0) {
            resultado.esMultiplo = false;
        } else { 
            int division = elemL2->clave / elemL1->clave;
            if (division != escalar) { 
                resultado.escalar = false;
            }
        }
    }
    if (resultado.escalar) { 
        resultado.numEscalar = escalar;
    }
    return resultado;
}

//Punto 4
int CompararListas (Lista l1, Lista l2){
    int l1T = l_longitud(l1);
    int l2T = l_longitud(l2);
    float pl1 = 0;
    float pl2 = 0;
    if(l1T != l2T){
        printf("\nError. las listas deben ser de igual tamaño\n");
        return -1;
    }        
    for (int i = 1; i <= l1T; i++)
    {
        if (l_recuperar(l1,i)->clave > l_recuperar(l2,i)->clave) pl1 = pl1 + 1;
        if (l_recuperar(l1,i)->clave < l_recuperar(l2,i)->clave) pl2 = pl2 + 1;
        if (l_recuperar(l1,i)->clave == l_recuperar(l2,i)->clave)
        {
            pl1 = pl1 + 1;
            pl2 = pl2 + 1;
        }
    }
    if (pl1 == pl2) return 0;
    if (pl1 > pl2) return 1;
    if (pl1 < pl2) return 2;
    else return -1;
}

//Punto 5
void hacerPolinomio(Lista list) {
    int grado;
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grado);

    if(grado < 0) {
        printf("Error: el grado del polinomio no puede ser negativo.\n");
        return;
    }

    for (int i = 0; i <= grado; i++) {
        printf("Ingrese el coeficiente de x^%d: ", i);
        float* coeficiente = malloc(sizeof(float));
        scanf("%f", coeficiente);                   

        TipoElemento te = te_crear_con_valor(i, coeficiente); // clave = grado del término
        l_agregar(list, te);
    }
}

double evaluarPolinomio(Lista list, double x) {
    Iterador ite = iterador(list);
    double result = 0.0;

    while (hay_siguiente(ite)) {
        TipoElemento te = siguiente(ite);
        float coef = *(float*)te->valor; // desreferenciar el puntero
        result += coef * pow(x, te->clave);
    }

    return result;
}
 
Lista calcularRango(Lista list, double x, double y, double sumando) {
    Lista rango = l_crear();

    int index = 0;
    for (double x_i = x; x_i <= y; x_i += sumando) {
        double* result = malloc(sizeof(double));
        *result = evaluarPolinomio(list, x_i);

        TipoElemento te = te_crear_con_valor(index, result);
        l_agregar(rango, te);

        index++;
    }

    return rango;
}

//Punto 6
bool esSublista(Lista l1, Lista l2)
{
    TipoElemento x, y;
    bool encontrado;
    bool res;
    Iterador iterl2 = iterador(l2);
    while (hay_siguiente(iterl2) && res == true)
    {
        encontrado = false;
        x = siguiente(iterl2);
        Iterador iterl1 = iterador(l1);
        while (hay_siguiente(iterl1) && encontrado == false)
        {
            y = siguiente(iterl1);
            if (y == x)
            {
                encontrado = true;
            }
        }
        if (encontrado == false)
        {
            res = false;
        }
    }
    return res;
}

