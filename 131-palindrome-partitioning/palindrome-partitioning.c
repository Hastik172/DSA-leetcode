#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 1000

// Check palindrome
int isPalindrome(char* s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return 0;
    }
    return 1;
}

// Backtracking
void backtrack(char* s, int start, int len,
               char**** result, int* returnSize, int* capacity,
               char** path, int pathSize,
               int** columnSizes) {

    // If complete partition found
    if (start == len) {

        // Resize if needed
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char**));
            *columnSizes = realloc(*columnSizes, (*capacity) * sizeof(int));
        }

        (*result)[*returnSize] = (char**)malloc(pathSize * sizeof(char*));
        (*columnSizes)[*returnSize] = pathSize;

        for (int i = 0; i < pathSize; i++) {
            (*result)[*returnSize][i] = strdup(path[i]);
        }

        (*returnSize)++;
        return;
    }

    for (int end = start; end < len; end++) {
        if (isPalindrome(s, start, end)) {

            int subLen = end - start + 1;
            char* substr = (char*)malloc(subLen + 1);
            strncpy(substr, s + start, subLen);
            substr[subLen] = '\0';

            path[pathSize] = substr;

            backtrack(s, end + 1, len,
                      result, returnSize, capacity,
                      path, pathSize + 1, columnSizes);

            free(substr); // backtrack
        }
    }
}

// Main function required by LeetCode
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {

    int capacity = INITIAL_CAPACITY;
    int n = strlen(s);

    char*** result = (char***)malloc(capacity * sizeof(char**));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    char* path[20]; // max length = 16 → safe

    backtrack(s, 0, n, &result, returnSize, &capacity,
              path, 0, returnColumnSizes);

    return result;
}