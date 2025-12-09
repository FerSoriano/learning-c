#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


int binarySearch(int nums[], int size, int target);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Missing args\n");
        return -1;
    }

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // obtenemos el largo
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int target = atoi(argv[1]);
    int result = binarySearch(nums, size, target);
    if (result == -1) {
        printf("Target not found\n");
    } else {
        printf("Found at index: %i\n", result);
    }
    
    return 0;
}

int binarySearch(int nums[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while ( left <= right ) {
        int mid = left + (( right - left ) / 2 );

        if ( nums[mid] == target ) {
            return mid;
        }

        if ( nums[mid] < target ) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}