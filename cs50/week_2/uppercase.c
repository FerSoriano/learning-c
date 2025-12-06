#include <stdio.h>

void to_uppercase(char* message);


int main() {
    char message[] = "hello world!";
    to_uppercase(message);
    printf("%s\n", message);
    return 0;
}


void to_uppercase(char* message) {
    while (*message != '\0') {
        if (*message >= 'a' && *message <= 'z') {
            *message -= 32;  // differencia en ASCII.
        }
        message++;
    }
}