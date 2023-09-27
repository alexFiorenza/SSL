#include <stdio.h>
#include <ctype.h>

// Este archivo contiene funciones que son utilizadas por varios archivos del proyecto. Permite evitar la duplicación de código.
// Todas las funciones han sido desarrolladas por nosotros mismos.

/**
 * Convierte un caracter numérico en su valor decimal correspondiente.
 *
 * @param c El caracter numérico a convertir.
 * @return El valor decimal correspondiente al caracter numérico.
 */
int charADecimal(int c)
{
    return c - '0';
}

/**
 * Convierte una cadena de caracteres en su representación decimal.
 *
 * @param s La cadena de caracteres a convertir.
 * @return La representación decimal de la cadena.
 */
int cadenaADecimal(char *s)
{
    int i;
    int decimal = 0;
    for (i = 0; s[i]; i++)
    {
        decimal = decimal * 10 + charADecimal(s[i]);
    }
    return decimal;
}

/**
 * Determina si un carácter es un dígito decimal, octal o hexadecimal, o un signo o símbolo.
 * @param c El carácter a evaluar.
 * @return 1 si el carácter es un dígito decimal, octal o hexadecimal, o un signo o símbolo. 0 en caso contrario.
 */
int esCharDecimalOctalOHexa(char c)
{
    return c == '+' || c == '-' || c == 'x' || c == 'X' || isxdigit(c) || c == '$';
}

/**
 * Verifica si el caracter dado es un operador de suma o resta.
 *
 * @param operador El caracter a verificar.
 * @return 1 si el caracter es un operador de suma o resta, 0 en caso contrario.
 */
int esSumaOResta(char operador)
{
    return operador == '+' || operador == '-';
}

/**
 * Determina si un carácter es un carácter válido de operación aritmética.
 * Los caracteres válidos incluyen dígitos, símbolos de suma, resta, multiplicación y división.
 *
 * @param c El carácter a evaluar.
 * @return 1 si el carácter es un carácter válido de operación aritmética, 0 en caso contrario.
 */
int esCharDeOperacionAritmetica(char c)
{
    return isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/';
}

// Seccion de precendecia de operadores

/**
 * Calcula el resultado de una operación aritmética entre dos operandos.
 *
 * @param primerOperando El primer operando de la operación.
 * @param segundoOperando El segundo operando de la operación.
 * @param operador El operador aritmético a utilizar (+, -, *, /).
 * @return El resultado de la operación aritmética. Si el operador no es válido, retorna -1.
 */
int calcular(int primerOperando, int segundoOperando, char operador)
{
    switch (operador)
    {
    case '+':
        return primerOperando + segundoOperando;
        break;

    case '-':
        return primerOperando - segundoOperando;

    case '*':
        return primerOperando * segundoOperando;

    case '/':
        return primerOperando / segundoOperando;

    default:
        return -1;
    }
}

/**
 * Resuelve una expresión aritmética dada en forma de cadena y devuelve su resultado.
 * La expresión debe contener solo números enteros y los operadores de suma,resta,multiplicacion o division
 * @param expresionAritmetica La expresión aritmética a resolver.
 * @return El resultado de la expresión aritmética.
 */
int resolverOperacion(const char *expresionAritmetica)
{
    char operadores[50];
    int operandos[50];
    int i = 0, j = 0, k = 0;
    char enteroCadena[12];
    int terminos[50];

    if (esSumaOResta(expresionAritmetica[0])) // para que comience siempre con un signo
    {
        operadores[0] = expresionAritmetica[0];
        i++; // el siguiente bucle va a comenzar en la posición 1 del array
    }
    else
    {
        operadores[0] = '+';
    }

    for (; expresionAritmetica[i]; i++) // cargar operadores y operandos
    {
        if (isdigit(expresionAritmetica[i]))
        {
            enteroCadena[j++] = expresionAritmetica[i];
        }
        else
        {
            enteroCadena[j] = '\0';
            j = 0;
            operandos[k++] = cadenaADecimal(enteroCadena);

            operadores[k] = expresionAritmetica[i];
        }
    }
    enteroCadena[j] = '\0';
    operandos[k] = cadenaADecimal(enteroCadena);

    const int longitud = k;

    // mostrar operandos y operadores
    // printf("operandos: ");
    // for (i = 0; i < longitud; i++)
    // {
    //     printf("%d, ", operandos[i]);
    // }
    // printf("%d\n", operandos[longitud]);

    // printf("operadores: ");
    // for (i = 0; i < longitud; i++)
    // {
    //     printf("%c, ", operadores[i]);
    // }
    // printf("%c\n", operadores[longitud]);

    // resolver los terminos y cargarlos en el array terminos
    int primerOperando = operandos[0];
    j = 0;
    for (i = 1; i <= longitud; i++)
    {
        if (esSumaOResta(operadores[i]))
        {
            terminos[j++] = primerOperando;
            primerOperando = operandos[i];
        }
        else
        {
            primerOperando = calcular(primerOperando, operandos[i], operadores[i]);
        }
    }
    terminos[j] = primerOperando;

    // mostrar terminos
    // printf("terminos: ");
    // for (i = 0; i < j; i++)
    // {
    //     printf("%d, ", terminos[i]);
    // }
    // printf("%d\n", terminos[j]);

    // operar los terminos
    int resultado = 0;
    j = 0;
    for (i = 0; i <= longitud; i++)
    {
        if (esSumaOResta(operadores[i]))
        {
            resultado = calcular(resultado, terminos[j++], operadores[i]);
        }
    }

    return resultado;
}
