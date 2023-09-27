#include <stdio.h>
#include "libs/automata.c"
#include "libs/interface.c"
#define CARACTERES_MAXIMOS 100 // cantidad maxima de caracteres que puede tener la cadena

int main()
{
    char cadena[CARACTERES_MAXIMOS];
    int respuesta;

    do
    {
        green(); // Color verde
        printf("Ingrese:\n");
        reset(); // Color normal
        printf("0. reconocer numeros decimales, octales y/o hexadecimales\n");
        printf("1. Resolver una operacion aritmetica simple\n");
        printf("2. salir\n");
        scanf("%d", &respuesta);

        switch (respuesta)
        {
        case 0:
            reconocerNumerosMenu(respuesta, cadena);
            break;

        case 1:
            resolverOperacionMenu(respuesta, cadena);
            break;
        case 2:
            printf("Adios");
            break;
        default:
            red();
            printf("Respuesta no valida\n");
            reset(); // Color normal
            break;
        }
    } while (respuesta != 3);

    return 0;
}