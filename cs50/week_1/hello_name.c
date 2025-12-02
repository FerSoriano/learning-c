#include <stdio.h>
#include <string.h>

void greetings(char*);

int main() {

    char name[50];
    printf("What's your name? ");

    fgets(name, sizeof(name), stdin);

    // fgets deja el enter '\n'
    // con este bucle se cambia por null '\0'
    // for (int i = 0; i < sizeof(name); i++) {
    //     if (name[i] == '\n') {
    //         name[i] = '\0';
    //         break;
    //     }
    // }

    // esta es una solucion mas optima para no iterar
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    greetings(name);
    return 0;
}

void greetings(char* name) {
    if (strlen(name) == 0) {
        printf("Invalid name\n");
    } else {
        printf("Hello, %s, welcome\n", name);
    }
}