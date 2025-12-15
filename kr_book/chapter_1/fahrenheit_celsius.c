#include <stdio.h>

int main() {

    // C = (5/9)(F-32)

    int upper, lower, step;
    float celcius, fahrenheit;

    step = 20;
    // limits:
    lower = 0;
    upper = 300;

    fahrenheit = lower;
    while ( fahrenheit <= upper) {
        celcius = (5.0 / 9.0) * (fahrenheit - 32.0);
        printf("%3.0f \t %6.1f\n", fahrenheit, celcius);
        fahrenheit += step;
    }
    
    return 0;
}