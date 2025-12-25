// Write a program to count the number of occurrences of each
// digit (0-9), white space and others chars


#include <stdio.h>


int main() {

    int c, blanks, others;

    blanks = others = 0;

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = 0; // -> set all initial values equal to zero.
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            arr[c - '0']++;
        } else if (c == ' ' || c == '\t' || c == '\n') {
            blanks++;
        } else {
            others++;
        }
    }

    printf("\nNumbers Count:\n");

    for (int i = 0; i < 10; i++) {
        printf("%i - %i\n", i, arr[i]);
    }

    printf("\nBlanks: %i, Others: %i\n", blanks, others);

    return 0;
}