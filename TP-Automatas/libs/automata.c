#include <stdio.h>
#include <ctype.h>

// Funciones relacionadas al funcionamiento del automata y al alfabeto del lenguaje.
// Todas las funciones han sido desarrolladas por nosotros mismos.

/**
 * Verifica si todos los caracteres de una cadena pertenecen al alfabeto del lenguaje.
 * @param esCaracterDelLenguaje Puntero a una función que determina si un caracter pertenece al alfabeto del lenguaje.
 * @param s Cadena a verificar.
 * @return 1 si todos los caracteres pertenecen al alfabeto del lenguaje, 0 en caso contrario.
 */
int verificaElAlfabeto(int (*esCaracterDelLenguaje)(char), char *s)
{
    int i;
    for (i = 0; s[i]; i++)
    {
        if (!esCaracterDelLenguaje(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

/**
 * Incrementa los contadores correspondientes según el estado del autómata.
 *
 * @param estado El estado actual del autómata.
 * @param decimales Puntero al contador de números decimales reconocidos.
 * @param octales Puntero al contador de números octales reconocidos.
 * @param hexadecimales Puntero al contador de números hexadecimales reconocidos.
 * @param noReconocidos Puntero al contador de caracteres no reconocidos.
 */
void incrementarContadoresSegunEl(const int estado, int *decimales, int *octales, int *hexadecimales, int *noReconocidos)
{
    switch (estado)
    {
    case 2:
        (*decimales)++;
        break;
    case 3:
        (*decimales)++;
        break;
    case 4:
        (*octales)++;
        break;
    case 6:
        (*hexadecimales)++;
        break;
    default:
        (*noReconocidos)++;
        break;
    }
    return;
}

/**
 * Función que devuelve la columna correspondiente a un caracter en la tabla de transiciones de un autómata.
 * @param c Caracter a evaluar.
 * @return Entero que representa la columna correspondiente al caracter en la tabla de transiciones.
 *         Si el caracter no pertenece a ninguna de las columnas definidas, devuelve 5.
 */
int columnaNumeros(int c)
{
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 1;
    case '3':
        return 1;
    case '4':
        return 1;
    case '5':
        return 1;
    case '6':
        return 1;
    case '7':
        return 1;
    case '8':
        return 2;
    case '9':
        return 2;
    case '+':
        return 3;
    case '-':
        return 3;
    case 'x':
        return 4;
    case 'X':
        return 4;
    default:
        return 5;
    }
}

/**
 * Función que recibe una cadena de caracteres y reconoce los números que se encuentran en ella.
 * La función utiliza una matriz de transición de estados para determinar si un número es decimal, octal o hexadecimal.
 * Además, cuenta la cantidad de números decimales, octales, hexadecimales y no reconocidos en la cadena.
 *
 * @param cadena La cadena de caracteres a analizar.
 * @return void
 */
void reconocerNumeros(char *cadena)
{
    // Matriz de transición de estados para reconocer números
    const int tt[8][6] = {{3, 2, 2, 1, 7, 7},
                          {7, 2, 2, 7, 7, 7},
                          {2, 2, 2, 7, 7, 7},
                          {4, 4, 7, 7, 5, 7},
                          {4, 4, 7, 7, 7, 7},
                          {6, 6, 6, 7, 7, 6},
                          {6, 6, 6, 7, 7, 6},
                          {7, 7, 7, 7, 7, 7}};

    int estado = 0;
    int i = 0;
    int decimales = 0, octales = 0, hexadecimales = 0, noReconocidos = 0;
    int c = cadena[i];

    // Recorre la cadena de caracteres y actualiza el estado según la matriz de transición
    while (c != '\0')
    {
        if (c != '$')
        {
            estado = tt[estado][columnaNumeros(c)];
        }
        else
        {
            incrementarContadoresSegunEl(estado, &decimales, &octales, &hexadecimales, &noReconocidos);
            estado = 0;
        }
        c = cadena[++i];
    }
    incrementarContadoresSegunEl(estado, &decimales, &octales, &hexadecimales, &noReconocidos);

    // Imprime la cantidad de números decimales, octales, hexadecimales y no reconocidos en la cadena
    printf("Decimales:      %d\n", decimales);
    printf("Octales:        %d\n", octales);
    printf("Hexadecimales:  %d\n", hexadecimales);
    printf("No reconocidos: %d\n", noReconocidos);

    return;
}

/**
 * Función que devuelve la columna correspondiente a una operación matemática.
 *
 * @param c Caracter que representa la operación matemática.
 * @return Entero que representa la columna correspondiente a la operación matemática.
 *         Si el caracter no representa una operación matemática, devuelve 0.
 */
int columnaOperacion(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return 0;
    }
}

/**
 * Función que reconoce si una cadena representa una operación válida.
 * Utiliza una tabla de transición para determinar el estado final del autómata.
 * @param cadena La cadena a analizar.
 * @return 1 si la cadena representa una operación válida, 0 en caso contrario.
 * @archivo /Users/alexfiorenza/Documents/software_development/facultad/sintaxis_2023/TP-Automatas/libs/automata.c
 */
int reconoceOperacion(char *cadena)
{
    const int tt[4][3] = {{1, 2, 3},
                          {1, 2, 2},
                          {1, 3, 3},
                          {3, 3, 3}};
    int estado = 0;
    int i = 0;
    int c = cadena[i];

    while (c != '\0')
    {
        estado = tt[estado][columnaOperacion(c)];
        c = cadena[++i];
    }

    return estado == 1;
}