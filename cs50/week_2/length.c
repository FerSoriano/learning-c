#include <stdio.h>
#include <stdbool.h>
#include <string.h>

size_t length(const char* string, bool spaces);

int main() {
    char name[50];

    printf("Name: ");
    fgets(name, sizeof(name), stdin);

    char *n = strchr(name, '\n');
    
    if (n != NULL) {
        *n = '\0'; // direccion de '\n'
    }

    printf("Length: %zu\n", length(name, true));
    printf("Length without spaces: %zu\n", length(name, false));

    return 0;
}


size_t length(const char* string, bool count_spaces) {
    size_t n = 0;
    while (*string != '\0') {
        if (*string != ' ' || count_spaces) {
            n++;
        }
        string++;
    }
    return n;
}
