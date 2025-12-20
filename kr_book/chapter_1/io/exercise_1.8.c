/*
    Write a program to count blanks, tasbs and new lines
*/


#include <stdio.h>

int main() {

    int blanks=0, tabs=0, lines=0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' '){
            blanks++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            lines++;
        }
    }

    printf("\nBlanks: %i, Tabs: %i, Lines: %i\n", blanks, tabs, lines);

    return 0;
}