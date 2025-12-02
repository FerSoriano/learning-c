#include <stdio.h>

int main() {

    char name[50];

    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);

    printf("hello, %s\n", name);
    return 0;
}