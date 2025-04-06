#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "tp_1_recursividad.h"

//Punto 1
char detPalindromo(char cadena[], int inicio, int fin)
{
    //casos base
    if (inicio >= fin)
    {
        return 1;
    }
    if (cadena[inicio] != cadena[fin])
    {
        return 0;
    }
    //caso recursivo
    else
    {
        return detPalindromo(cadena, inicio + 1, fin - 1);
    }
}

bool palindromo(char *cadena) 
{
    return detPalindromo(cadena, 0, strlen(cadena) - 1);
}

//Punto 2
int producto(int m, int n)
{
    //caso base
    if (n == 0)
    {
        return m;
    }
    //caso recursivo    
    else 
    {
        return m + producto(m, n-1);
    }
}

//Punto 3
int terminoSeridFibonacciAUX(int k, int *m, int *n) {

	while (k < 0) {
        printf("%s: ", "valor invalido, ingrese un numero que no sea negativo");
        scanf("%d", &k);
	}

	int resultado = *m + *n;
	*m = *n;
	*n = resultado;

	if(k > 1) {
		return terminoSeridFibonacciAUX(k-1, m, n);
	}
	else {
		return resultado;
	}
}
int terminoSeridFibonacci(int k) {

	int m = 0;
	int n = 1;

	return terminoSeridFibonacciAUX(k, &m, &n);
}

//Punto 4

void divisionAUXDECIMAL(int m, int n, int contadorDecimal, int decimales, char* entero) {

    char castAux[7];
    char* decimal = (char*) malloc(sizeof(char) * 6);
    decimal[0] = '\0';

    if (m-n >= 0 && decimales > 0) {
        m = m-n;
        contadorDecimal++;
        divisionAUXDECIMAL(m, n, contadorDecimal, decimales, entero);
    }
    
    else
        if (m-n == 0) {
            m = m-n;
            contadorDecimal++;
            sprintf(castAux, "%d", contadorDecimal);
            strcat(decimal, castAux);
            strcat(entero, decimal);
        }
        else if (m-n < 0 && decimales > 0) {
            sprintf(castAux, "%d", contadorDecimal);
            strcat(decimal, castAux);
            strcat(entero, decimal);
            m *= 10;
            contadorDecimal = 0;
            divisionAUXDECIMAL(m, n, contadorDecimal, decimales-1, entero);
        }
    free(decimal);
}

 
void divisionAUX(int m, int n, int contador, char* resultado) {
 
    char castAux[20];
    char* entero = (char*) malloc(sizeof(char) * 50);
    entero[0] = '\0';

    if (m-n == 0) {
        m = m-n;
        contador++;
        sprintf(castAux, "%d", contador);
        strcat(entero, castAux);
    }
    else if (m-n > 0) {
        m = m-n;
        contador++;
        divisionAUX(m, n, contador, resultado);
    }
    else {
        sprintf(castAux, "%d", contador);
        strcat(entero, castAux);
        strcat(entero, ".");
        int contadorDecimal = 0;
        m *= 10;
        int decimales = 5;
        divisionAUXDECIMAL(m, n, contadorDecimal, decimales, entero);
        }
    strcat(resultado, entero);
    free(entero);
}

float division(int m, int n) {
    //primero se chequea el signo de los numeros
    int mNegativo = 1;
    if (m < 0) {
        mNegativo = -1;
    }

    int nNegativo = 1;
    if (n < 0) {
        nNegativo = -1;
    }
    m = abs(m);
    n = abs(n);


    char* resultado = (char*) malloc(sizeof(char) * 60);
    resultado[0] = '\0';
    int contador = 0;
    divisionAUX(m, n, contador, resultado);
    float resultadoCasteado = atof(resultado);
    resultadoCasteado = resultadoCasteado* (float) mNegativo * (float) nNegativo;
    return resultadoCasteado;
}

//Punto 5
void validacionesSeparadorMiles(char num[]) //usa las 2 funciones anteriores y ademas verifica que el numero no pase de los 100 caracteres
{
    while ((estaVacio(num)) || (strlen(num )> 99) || (!esNumero(num)))
    {
        printf("El dato ingresado no cumple los requisitos. Ingrese un número nuevamente: ");
        fflush(stdin);
        fgets(num, 100, stdin);
        size_t len = strlen(num);
        if (len > 0 && num[len - 1] == '\n') {
            num[len - 1] = '\0';
        } 
        else 
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

void agregarSeparadorMilesRecursivo(char *num, int len, int cont) //funcion recursiva
{
    if (len == 0)
    {
        printf("%c", num[len]);
    } 
    else
    {   
        if (cont == 3)
        {
            agregarSeparadorMilesRecursivo(num, len - 1, 1);
            printf(".");
            printf("%c", num[len]);
        }
        else
        {
            agregarSeparadorMilesRecursivo(num, len - 1, cont + 1);
            printf("%c", num[len]);
        }
    }
}

char * agregarSeparadorMiles(char numero[])//funcion que invoca a la funcion recursiva
{
    if (numero[0] == '-')
    {
        printf("-");
        agregarSeparadorMilesRecursivo(numero +1, strlen(numero +1)-2, 1);
    }
    else
    {
        agregarSeparadorMilesRecursivo(numero, strlen(numero)-2, 1);
    }
    printf("\n");
    return 0;
}

//Punto 6
bool MCrecursivo(int n, char * a){
    
    a = MCi(n,a);

    strcat(a,"(-.-)");
    
    a = MCd(n,a);

    printf("%s\n",a);
}

char * MCi(int nveces,char * a){
    if (nveces == 1)return a;

    strcat(a,"(-.");

    nveces = nveces - 1;

    MCi(nveces,a);
}
char * MCd(int nveces,char * a){
    if (nveces == 1)return a;

    strcat(a,".-)");

    nveces = nveces - 1;

    MCd(nveces,a);
}

char *reunionMafia(int nivel)
{
    char mct[100] = "";
    MCrecursivo(nivel,mct);
}

//Punto 7


//Punto 8


//Punto 9
bool divisiblePor7(int num)
{           /*(abs(restante)) */
  if (num < 70) 
  {
        return (num % 7 == 0);                /* evalua si el residuo es igual a 0 retorna un 1(verdadero) o un 0 (false) */
  }	
  int ultimo_digito = num % 10;            /*un ejemplo 622%10=2  me devuelve el residuo que es la ultima cifra de este */
  int numero_resultante = num / 10;        /*  622/10=62.2 el tipo de la variable es entero entonces descarta la parte flotante del numero y conseva la parte entera */
  int multiplicacion= 2*ultimo_digito ;       /* 2*2=4 queda guardado en multiplicacion    */
  int restante= numero_resultante - multiplicacion;
  return separa_multiplica(restante);    /* llamada recursiva de la funcion hasta que se cumpla que "restante" sea menor a 70 y confirme si es o no multiplo de 7 */
}

//Punto 10
void explotar(int n, int b, int resultado[]) 
{
    int indice = 0;
    if (n <= b) {
        resultado[indice++] = n;
        return;
    }
    int n1 = n / b;
    int n2 = n - n1;
    explotar(n1, b, resultado);
    explotar(n2, b, resultado);
}

int* explosion(int n, int b) {
    int resultado[1000];
    explotar(n, b, resultado);
    return resultado;
}