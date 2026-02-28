


#include <stdio.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

int main() {
    // int nums1[] = {1,2,3,4,0,0,0};
    int nums1[] = {0,0,0};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    
    int nums2[] = {2,5,6};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    print_arr(nums1, nums1Size);
    merge(nums1, nums1Size, 0, nums2, nums2Size, 3); // [1,2,2,3,5,6]
    print_arr(nums1, nums1Size);

    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
   int i = m - 1;
   int j = n - 1;
   int k = m + n - 1;

   while (i >=0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
   }

   while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
   }
}