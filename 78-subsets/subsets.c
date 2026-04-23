/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

// Backtracking
void backtrack(int* nums, int numsSize, int start,
               int* path, int pathSize,
               int*** result, int* returnSize, int** columnSizes) {

    // store current subset
    (*result)[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    (*columnSizes)[*returnSize] = pathSize;

    for (int i = 0; i < pathSize; i++) {
        (*result)[*returnSize][i] = path[i];
    }
    (*returnSize)++;

    // explore further
    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i];  // choose

        backtrack(nums, numsSize, i + 1,
                  path, pathSize + 1,
                  result, returnSize, columnSizes);
        // no need to remove → overwrite handles backtracking
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int maxSize = 1 << numsSize; // 2^n subsets

    int** result = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));
    *returnSize = 0;

    int path[numsSize];

    backtrack(nums, numsSize, 0, path, 0,
              &result, returnSize, returnColumnSizes);

    return result;
}