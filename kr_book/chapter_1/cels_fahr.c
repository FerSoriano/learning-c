#include <stdio.h>

int main() {

    // C = (5/9)(F-32)

    int upper, lower, step;
    float celcius, fahrenheit;

    step = 10;
    // limits:
    lower = 0;
    upper = 150;

    printf("Cels \t Fahr\n");
    celcius = lower;
    while ( celcius <= upper) {
        fahrenheit = ((celcius * 9) / 5) + 32;
        printf("%6.1f \t %3.0f\n", celcius, fahrenheit);
        celcius += step;
    }
    
    return 0;
}