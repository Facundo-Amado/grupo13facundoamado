#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "tp_1_recursividad.h"

void limpiarBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Validaciones
bool estaVacio(char *num) // verifica que el numero ingresado no sea una cadena vacia
{
    if (num[0] == '\0' || num[0] == '\n')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool esNumero(char *num) // verifica que la cadena contenga solo numeros
{
    int i = 0;
    if (num[0] == '-')
    {
        i++;
    }
    while (num[i] != '\n')
    {
        if (!isdigit(num[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

void validacionesSeparadorMiles(char num[]) // usa las 2 funciones anteriores y ademas verifica que el numero no pase de los 100 caracteres
{
    while ((estaVacio(num)) || (strlen(num) > 99) || (!esNumero(num)))
    {
        printf("El dato ingresado no cumple los requisitos. Ingrese un número nuevamente: ");
        fflush(stdin);
        fgets(num, 100, stdin);
        size_t len = strlen(num);
        if (len > 0 && num[len - 1] == '\n')
        {
            num[len - 1] = '\0';
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}

bool esCadena(char cadena[])
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        if (!isalpha(cadena[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

bool NoNumerica(char *seniales)
{
    int i = 0;
    while (seniales[i] != '\n' && seniales[i] != '\0')
    {
        if (isdigit(seniales[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

void convertirAMayusculas(char *cadena)
{
    for (int i = 0; cadena[i]; i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
}

bool ValidarLH(char *seniales)
{
    int i = 0;
    while (seniales[i] != '\0')
    {
        if (seniales[i] != 'L' && seniales[i] != 'H')
        {
            return false;
        }
        i++;
    }
    return true;
}

void ValidarOnda(char *seniales)
{
    seniales[strcspn(seniales, "\n")] = '\0'; // eliminar '\n'
    convertirAMayusculas(seniales);           // convertir desde el principio

    while (!ValidarLH(seniales) || !NoNumerica(seniales))
    {
        printf("La cadena ingresada no es válida. Ingrese la cadena nuevamente: ");
        fflush(stdin);
        fgets(seniales, 100, stdin);
        seniales[strcspn(seniales, "\n")] = '\0';
        convertirAMayusculas(seniales);
    }
}

// Ejercicios
// Punto 1
int mainPalindromo()
{
    char cadena[100];
    printf("Ingrese una palabra: ");
    while (getchar() != '\n')
        ;
    fgets(cadena, 100, stdin);
    cadena[strcspn(cadena, "\n")] = 0; // quitar salto de línea

    while (!esCadena(cadena))
    {
        printf("El dato ingresado no cumple los requisitos. Ingrese una palabra nueva: ");
        fflush(stdin);
        fgets(cadena, 100, stdin);
        cadena[strcspn(cadena, "\n")] = 0;
    }

    bool resultado = palindromo(cadena);
    if (resultado)
    {
        printf("Es un palindromo");
    }
    else
    {
        printf("No es un palindromo");
    }
    return 0;
}

// Punto 2
int mainProducto()
{
    int a;
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    while (a < 0)
    {
        printf("dato invalido. ingrese un numero entero: ");
        scanf("%d", &a);
    }
    int b;
    printf("Ingrese otro numero: ");
    scanf("%d", &b);
    while (b < 0)
    {
        printf("dato invalido. ingrese un numero entero: ");
        scanf("%d", &b);
    }
    int res = producto(a, b);
    printf("%i", res);
    return 0;
}

// Punto 3
int mainFibonacci()
{

    printf("Ingrese n-esimo numero de la serie de fibonacci: ");
    int ingreso;
    scanf("%d", &ingreso);
    while (ingreso < 0)
    {
        limpiarBuffer();
        printf("Dato invalido. ingrese un numero entero: ");
        scanf("%d", &ingreso);
    }
    printf("El numero seria: %d", terminoSeridFibonacci(ingreso));

    return 0;
}

// Punto 4
int mainDivision()
{

    int m, n;
    printf("Ingrese dividendo: ");
    scanf("%d", &m);
    while (m < 0)
    {
        limpiarBuffer();
        printf("Invalido. Ingrese un numero entero: ");
    }

    printf("Ingrese divisor: ");
    scanf("%d", &n);
    while (n <= 0)
    {
        limpiarBuffer();
        printf("Invalido. Ingrese un numero entero (diferente a cero)");
    }

    float resultado = division(m, n);
    printf("----- %.5f -----", resultado);

    return 0;
}

// Punto 5
int mainSeparadorMiles() // main del ejercicio 5
{
    char *num = (char *)calloc(100, sizeof(char));
    printf("Ingrese un número entero: ");
    while (getchar() != '\n')
        ;
    fgets(num, 100, stdin);
    validacionesSeparadorMiles(num);
    agregarSeparadorMiles(num);
    return 0;
}

// Punto 6
int mainChinos()
{
    int nivel;
    int valido = 0;

    while (!valido)
    {
        printf("\nNivel de la reunion: ");
        if (scanf("%i", &nivel) != 1 || nivel < 1 || nivel > 12 || getchar() != '\n')
        {
            printf("Error: El nivel debe ser un número entero en el rango de 1 a 12.\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            valido = 1;
        }
    }

    char *resultado = reunionMafia(nivel);
    printf("%s\n", resultado);
    free(resultado);

    return 0;
}

// Punto 7
int mainOnda()
{
    char seniales[100];
    printf("Escriba la onda digital (L y H): ");
    fgets(seniales, sizeof(seniales), stdin);
    ValidarOnda(seniales);
    char *resultado = ondaDigital(seniales);
    printf("Onda digital:\n%s\n", resultado);
    return 0;
}

// Punto 8
/*int mainSubconjunto()
{
    return 0;
}*/

// Punto 9
int mainDivPor7()
{
    int num;
    printf("Ingrese un numero entero: \n");
    scanf("%d", &num);
    while (num < 0)
    {
        printf("Dato invalido. Ingrese un nuevo numero entero: ");
        scanf("%d", &num); // vacia el buffer
    }
    if (divisiblePor7(num))
    { /* si la funcion devuelve verdadero si numero es multiplo de 7 entonces ejecuta el cuerpo del if */
        printf("%d es divisible por 7 \n", num);
    }
    else
    {
        printf("%d no es divisible por  7 \n", num);
    }
    return 0;
}

// Punto 10
int mainBomba()
{
    int n, b;
    printf("Ingrese el numero (N): ");
    scanf("%d", &n);
    while (n < 0)
    {
        printf("dato invalido. ingrese un numero: ");
        scanf("%d", &n);
    }
    printf("Ingrese la bomba (B. debe ser menor a n): ");
    scanf("%d", &b);
    while (b < 0 || b >= n)
    {
        printf("dato invalido. ingrese otro numero: ");
        scanf("%d", &b);
    }
    int *res = explosion(n, b);
    printf("Resultado de la explosion:\n");
    for (int i = 0; res[i] != -1; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}

// Menu
void menu_principal()
{
    printf("\n");
    printf("  ============================================================================\n");
    printf(" |                             TP1 RECURSIVIDAD                              |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Palíndromo\n");
    printf("  2   Producto a partir de sumas sucesivas\n");
    printf("  3   Termino de la serie de Fibonacci\n");
    printf("  4   Cociente a partir de restas sucesivas\n");
    printf("  5   Punto de los miles\n");
    printf("  6   Mafia china\n");
    printf("  7   Onda digital\n");
    printf("  8   Subconjunto\n");
    printf("  9   Divisible por 7\n");
    printf("  10  Numero explosivo\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: ");
}

int main()
{
    bool salir = false;
    int opcion;

    while (!salir)
    {
        menu_principal();
        scanf("%i", &opcion);
        while (opcion < 0 || opcion > 10)
        {
            printf("Opción incorrecta\n");
            printf("Por favor seleccione una opción: ");
            while (getchar() != '\n')
                ;
            scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            mainPalindromo();
            getch();
            break;
        case 2:
            mainProducto();
            getch();
            break;
        case 3:
            mainFibonacci();
            getch();
            break;
        case 4:
            mainDivision();
            getch();
            break;
        case 5:
            mainSeparadorMiles();
            getch();
            break;
        case 6:
            mainChinos();
            getch();
            break;
        case 7:
            mainOnda();
            getch();
            break;
        case 8:
            // mainSubconjunto();
            getch();
            break;
        case 9:
            mainDivPor7();
            getch();
            break;
        case 10:
            mainBomba();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}