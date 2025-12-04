#include <stdio.h>

double avg(double, double, double);
double avg_array(double* nums, size_t arr_len);

int main() {

    double a, b, c;
    printf("Num 1: ");
    scanf("%lf", &a);

    printf("Num 2: ");
    scanf("%lf", &b);

    printf("Num 3: ");
    scanf("%lf", &c);

    printf("Avg: %.2lf\n", avg(a, b, c));

    //

    double nums[3] = {a, b, c};
    size_t len = sizeof(nums) / sizeof(nums[0]);
    printf("\nAvg Array: %.2lf\n", avg_array(nums, len));

    return 0;
}


double avg_array(double* nums, size_t arr_len) {
    /*
        se necesita recibir el arr_len porque no se 
        puede calcular directamente en la funcion.
        Por que? porque lo que recibimos es un puntero no un
        array.
    */
    if (arr_len == 0) {
        return -1;
    }

    double sum = 0;
    for (size_t i = 0; i < arr_len; i++) {
        sum += nums[i];
    }

    return sum / arr_len;
}

double avg(double num1, double num2, double num3) {
    return (num1 + num2 + num3) / 3;
}
