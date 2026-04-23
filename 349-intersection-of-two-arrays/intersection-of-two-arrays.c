/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* set = (int*)calloc(1001, sizeof(int)); // mark nums1
    int* result = (int*)malloc(1001 * sizeof(int));
    int count = 0;

    // mark elements of nums1
    for (int i = 0; i < nums1Size; i++) {
        set[nums1[i]] = 1;
    }

    // check nums2
    for (int i = 0; i < nums2Size; i++) {
        if (set[nums2[i]] == 1) {
            result[count++] = nums2[i];
            set[nums2[i]] = 0; // avoid duplicates
        }
    }

    *returnSize = count;
    return result;
}