#include <stdio.h>

void create_block(int height);

int main() {

    create_block(9);

    return 0;
}

void create_block(int height) {
    for (int i = 0; i < height; i++) {
        for (int k = 0; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}
