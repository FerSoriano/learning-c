#include <stdio.h>


int add(int a, int b);


int main(void) {

    int a, b;
    printf("X: ");
    scanf("%d", &a);

    printf("Y: ");
    scanf("%d", &b);

    printf("%d\n", add(a, b));

    return 0;
}


int add(int a, int b) {
    return a + b;
}