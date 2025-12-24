// Write a program that prints its input.
// Skip the commnets like /* comment */

#include <stdio.h>

#define NORMAL 1
#define POTENTIAL_COMMENT 2
#define IN_COMMENT 3
#define POTENTIAL_OUT_COMMENT 4


int main() {

    int c, status;

    status = NORMAL;
    while ((c = getchar()) != EOF) {
        if (status == NORMAL) {
            if (c == '/') {
                status = POTENTIAL_COMMENT;
            } else {
                putchar(c);
            }
        } else if (status == POTENTIAL_COMMENT) {
            if (c == '*') {
                status = IN_COMMENT;
            } else {
                status = NORMAL;
                putchar('/');
                putchar(c);
            }
        } else if (status == IN_COMMENT) {
            if (c == '*') {
                status = POTENTIAL_OUT_COMMENT;
            }
        } else if (status == POTENTIAL_OUT_COMMENT) {
            if (c == '/') {
                status = NORMAL;
            } else {
                status = IN_COMMENT;
            }
        }
    }

    return 0;
}
