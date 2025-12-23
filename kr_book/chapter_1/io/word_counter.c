
#include <stdio.h>

#define IN  1  // inside a word
#define OUT 0  // outside a word

/* count new lines, words and characters */
int main() {

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = state = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nw++;
        }
    }

    printf("Lines: %i, Words: %i, Chars: %i\n", nl, nw, nc);

    return 0;
}