#include <stdio.h>
#include <ctype.h>
#include "utils.c"

// Funciones  encargadas de manejar el menu de inicializacion del programa
// Todas las funciones han sido desarrolladas por nosotros mismos.

/**
 * Lee el contenido de un archivo y lo guarda en una cadena de caracteres.
 *
 * @param fuente La ruta del archivo a leer.
 * @param cadena La cadena de caracteres donde se guardará el contenido del archivo.
 * @return 1 si se pudo leer el archivo correctamente, 0 si no se pudo abrir el archivo.
 */
int leerContenidoDelArchivo(const char *fuente, char *cadena)
{
    FILE *archivo;
    archivo = fopen(fuente, "rt");

    if (archivo == NULL)
    {
        printf("El archivo no existe\n");
        return 0;
    }

    fseek(archivo, 0, SEEK_SET);
    fscanf(archivo, "%s", cadena);
    fclose(archivo);
    return 1;
}

/**
 * La función reconocerNumerosMenu se encarga de mostrar un menú al usuario para que elija entre leer un archivo de texto con cadenas a reconocer o ingresar las cadenas manualmente. Luego verifica si las cadenas ingresadas cumplen con el alfabeto de números decimales, octales o hexadecimales y llama a la función reconocerNumeros para reconocer los números en las cadenas.
 *
 * @param respuesta La respuesta del usuario al menú.
 * @param cadena Un puntero a una cadena de caracteres donde se almacenará la cadena a reconocer.
 * @return void
 */
void reconocerNumerosMenu(int respuesta, char *cadena)
{
    green();
    printf("Ingrese:\n");
    reset();
    printf("0. Leer el archivo cadenasAReconocer.txt\n");
    printf("1. Escribir los numeros separandolos por $\n");
    scanf("%d", &respuesta);

    switch (respuesta)
    {
    case 0:
        if (!leerContenidoDelArchivo("cadenasAReconocer.txt", cadena))
        {
            return;
        }
        break;

    case 1:
        printf("Escriba los numeros separandolos por $ ");
        scanf("%s", cadena);
        break;

    default:
        red();
        printf("Respuesta no valida\n");
        reset();
        return;
    }

    if (!verificaElAlfabeto(esCharDecimalOctalOHexa, cadena))
    {
        red();
        printf("No verifica el alfabeto la cadena: %s\n", cadena);
        reset();
        return;
    }

    reconocerNumeros(cadena);
    return;
}

/**
 * Resuelve una operación aritmética ingresada por el usuario o leída desde un archivo.
 * @param respuesta La respuesta del usuario al menú de opciones.
 * @param cadena La cadena que contiene la operación aritmética.
 * @return void
 */
void resolverOperacionMenu(int respuesta, char *cadena)
{
    green();
    printf("Ingrese:\n");
    reset();
    printf("0. Leer el archivo expresionAritmetica.txt\n");
    printf("1. Escribir la operacion aritmetica simple\n");
    scanf("%d", &respuesta);

    switch (respuesta)
    {
    case 0:
        if (!leerContenidoDelArchivo("expresionAritmetica.txt", cadena))
        {
            return;
        }
        break;
    case 1:
        printf("Escriba una operacion aritmetica simple (puede tener multiples +, -, *, /):  ");
        scanf("%s", cadena);
        break;
    default:
        red();
        printf("Respuesta no valida\n");
        reset();
        break;
    }

    if (!verificaElAlfabeto(esCharDeOperacionAritmetica, cadena))
    {
        printf("La operacion tiene caracteres no validos\n");
        return;
    }
    if (!reconoceOperacion(cadena))
    {
        printf("Operacion no valida\n");
        return;
    }

    printf("El resultado es: %d\n", resolverOperacion(cadena));
    return;
}

/**
 * @brief Función que establece el color de la consola a verde
 *
 */
void green()
{
    printf("\033[0;32m");
}

/**
 * @brief Función que establece el color de la consola a rojo
 *
 */
void red()
{
    printf("\033[1;31m");
}

/**
 * @brief Función que resetea el color de la consola a su valor por defecto.
 *
 */
void reset()
{
    printf("\033[0m");
}