
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int nums[], int len, int target);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Missing args\n");
        return -1;
    }

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int len = sizeof(nums) / sizeof(nums[0]);

    int target = atoi(argv[1]);

    int index = binarySearch(nums, len, target);
    if (index > -1){
        printf("Found in the position: [%d]\n", index);
    } else {
        printf("Number not found\n");
    }
    return 0;
}

int binarySearch(int nums[], int len, int target) {
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = left + ((right - left) / 2);

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}