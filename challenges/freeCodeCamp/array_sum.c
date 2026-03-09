/*
Given an array of numbers,
return the sum of all the numbers
*/



#include <stdio.h>

int sumArray(int* nums, int size);

int main() {

    printf("Daily Coding Challenge. March 09, 2026");

    int nums[] = {10, 20, 30, 40, 50}; // 150
    int size = sizeof(nums) / sizeof(nums[0]);
    int sum = sumArray(nums, size);

    printf("Sum: %d\n", sum);

    return 0;
}


int sumArray(int* nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum;
}