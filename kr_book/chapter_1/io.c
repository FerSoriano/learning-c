#include <stdio.h>

int main() {

    /*
        se declara como int porque estamos obteniendo los bytes
        para representar su valor en ASCII.
        Tambien es INT porque getchar obtiene el EOF, que generalmente
        es un valor negativo (-1)
    */
    int c;

    // empieza a leer por consola, almacenando en buffer cada char
    c = getchar();

    // al presionar enter, empieza la ejecucion del bucle
    while (c != EOF)
    {
        putchar(c); // imprime por consola cada char del buffer
        c = getchar();
    }
}