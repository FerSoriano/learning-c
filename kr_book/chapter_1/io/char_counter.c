
#include <stdio.h>


int main() {

    int c = 0;
    int lines = 0;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch != '\n') {
            c++;
        } else {
            lines++;
        }
    }
    
    printf("Number of characters: %i\n", c);
    printf("Number of lines: %i\n", lines);

    return 0;
}