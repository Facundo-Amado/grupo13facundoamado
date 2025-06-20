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
#include "../libs/conjuntos/headers/conjuntos.h"
#include "../libs/conjuntos/headers/tp_conjunto.h"


//punto 2

//punto 3

//punto 4

//punto 5

//punto 6

//punto 7

//punto 8
bool c_ej8_soniguales(Conjunto a, Conjunto b)
{
    TipoElemento x = te_crear(0);
    int cantidad = cto_cantidad_elementos(a);

    for (int i = 1; i <= cantidad; i++)
    {
        x = cto_recuperar(a, i);
        if (!cto_pertenece(b, x->clave))
        {
            return false;
        }
    }
    return true;
}