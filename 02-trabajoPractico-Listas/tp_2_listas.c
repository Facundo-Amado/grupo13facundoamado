#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "tipo_elemento.h"
#include "tp_2_listas.h"
#include "listas.h"

//Punto 2


//Punto 3


//Punto 4


//Punto 5


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

