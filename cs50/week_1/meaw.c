#include <stdio.h>

void meow();

int main(void) {
    int x = 3;

    while (x > 0) {
        meow();
        x--;
    }

    printf("\n\n");

    for (int i = 0; i < 3; i++) {
        meow();
    }

    return 0;
}

void meow() {
    printf("meaow\n");
}