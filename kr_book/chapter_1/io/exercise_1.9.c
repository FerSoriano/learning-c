// Write a program to cpy its input to its output
// replacing each string of one or more blanks by a single blank.

#include <stdio.h>

int main() {

    int c, last_c = '\0';

    while ( (c = getchar()) != EOF ) { // ctrl + D -> activate EOF
        // version 1:
        // if (c == ' '){
        //     if (last_c == ' ') {
        //         c = '\0';
        //     } else {
        //         last_c = c;
        //     }
        // } else {
        //     last_c = '\0';
        // }
        // putchar(c);

        // version 2:
        if (c != ' ' || last_c != ' ') {
            putchar(c);
        }
        last_c = c;
    }

    return 0;
}