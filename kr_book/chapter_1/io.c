#include <stdio.h>

int main() {

    /*
        se declara como int porque estamos obteniendo los bytes
        para representar su valor en ASCII.
        Tambien es INT porque getchar obtiene el EOF, que generalmente
        es un valor negativo (-1)
    */
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}