
#include <stdio.h>
#include <stdlib.h>


void print_arr(int* arr, int size);

int main() {
    int slots = 4;

    int* arr = (int*)malloc(sizeof(int) * slots);
    if (arr == NULL) exit(1);

    for (int i = 0; i < slots; i++) {
        arr[i] = i + 1;
    }

    print_arr(arr, slots);

    slots = 8; // change size
    int* tmp_arr = (int*)realloc(arr, sizeof(int) * slots);
    if (tmp_arr == NULL) {
        printf("Memory reallocation failed\n");
        free(arr);
        exit(1);
    }

    arr = tmp_arr; // update new address

    arr[slots - 1] = 22; // modify last element as example
    print_arr(arr, slots);

    free(arr); // -> also frees tmp_arr
    return 0;
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++){
        printf("[%d]: %d\n", i, arr[i]);
    }
    printf("\n");
}