/*
Given a String, return a message with the count of how many letters and numbers it contains.
        - Letters are A-Z and a-z
        - Numbers are 0-9
        - Ignore all other characters.

Return "The string has X letters and Y numbers."
If either count is 1, user singular form...
*/


#include <stdio.h>
#include <stdlib.h>

void countLettersNumbers(char* string);

int main() {

    char *p = "Daily Coding Challenge. February 26, 2026";
    countLettersNumbers(p);
}

void countLettersNumbers(char* s) {

    if (s == NULL) return;

    int letters, numbers;

    letters = numbers = 0;
    
    while (*s != '\0') {
        if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){
            letters++;
        } else if (*s >= '0' && *s <= '9'){
            numbers++;
        }
        s++;
    }

    char* str_let = (letters != 1) ? "letters" : "letter";
    char* str_num = (numbers != 1) ? "numbers" : "number";

    printf("The string has %d %s and %d %s.\n", letters, str_let, numbers, str_num);
}
