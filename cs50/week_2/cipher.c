#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Error: %s [word] [key_int]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[2]);

    for (int i = 0, len = strlen(argv[1]); i < len; i++){
        argv[1][i] += n;
    }
    printf("Cipher word:   %s\n", argv[1]);


    for (int i = 0, len = strlen(argv[1]); i < len; i++){
        argv[1][i] -= n;
    }
    printf("Original word: %s\n", argv[1]);


    return 0;
}