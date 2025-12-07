#include <stdio.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("hello, world\n");
    } else if (argc == 2) {
        printf("hello, %s\n", argv[1]);
    } else {
        printf("to much args.\n");
        return 1;
    }
    return 0;
}