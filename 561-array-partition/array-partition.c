#include <stdlib.h>

// comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    int sum = 0;

    // take every alternate element
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }

    return sum;
}