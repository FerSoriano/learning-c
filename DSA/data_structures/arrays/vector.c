

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int* data;
    int size; // current elements
    int capacity; // total slots
} Vector;

Vector* push_back(Vector* v, int val);
void print_vector(Vector* v);
void free_vector(Vector* v);

int main() {

    Vector* nums = NULL;
    nums = push_back(nums, 1); 
    nums = push_back(nums, 2); 
    nums = push_back(nums, 3); // increse to 4

    print_vector(nums);

    nums = push_back(nums, 10);
    nums = push_back(nums, 20); // increse to 8
    nums = push_back(nums, 30);
    nums = push_back(nums, 40);
    nums = push_back(nums, 50);

    print_vector(nums);

    nums = push_back(nums, 100); // increse to 16

    print_vector(nums);

    free_vector(nums); // free memory
    return 0;
}

Vector* push_back(Vector* v, int val) {
    if (v == NULL){
        v = (Vector*)malloc(sizeof(Vector));
        v->size = 0;
        v->capacity = 2; // default set by me
        v->data = (int*)malloc(sizeof(int) * v->capacity);
        if (v->data == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    if (v->size == v->capacity) {
        int old_capacity = v->capacity;
        v->capacity *= 2;
        int* tmp_size = (int*)realloc(v->data, sizeof(int) * v->capacity);
        if (tmp_size == NULL) {
            printf("Memory reallocation failed\n");
            free(v->data);
            free(v);
            exit(1);
        }
        v->data = tmp_size;
        printf("\nReallocate size from [%d] to [%d]\n", old_capacity, v->capacity);
    }

    v->data[v->size++] = val; // set new
    return v;
}

void print_vector(Vector* v) {
    for (int i = 0; i < v->size; i++) {
        printf("[%d]\n", v->data[i]);
    }
    printf("\n");
}

void free_vector(Vector* v) {
    if (v != NULL) {
        free(v->data);
        free(v);
    }
}