#include <stdio.h>
#include <stdbool.h>

int main() {

    //            tmp = 3
    //               i
    //                        k
    //            1, 2, 3, 4, 5
    int nums[] = {2, 5, 3, 1, 4, 7, 6, 9, 8, 0};

    size_t len = sizeof(nums) / sizeof(nums[0]);
    
    bool swapped;
    for (int i = 0; i < len; i++) {
        swapped = false;
        for (int k = 0; k < len - 1; k++) {
            int tmp;
            if (nums[k] > nums[k + 1]) {
                tmp = nums[k + 1];
                nums[k + 1] = nums[k];
                nums[k] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    for (int i = 0; i < len; i++) {
        printf("%i ", nums[i]);
    }

    printf("\n");

    return 0;
}