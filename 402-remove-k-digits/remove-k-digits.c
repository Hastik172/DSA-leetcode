#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && stack[top] > num[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    // if k still remains → remove from end
    top -= k;

    // remove leading zeros
    int start = 0;
    while (start <= top && stack[start] == '0') {
        start++;
    }

    // if all removed → return "0"
    if (start > top) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    // build result
    int len = top - start + 1;
    char* res = (char*)malloc(len + 1);
    strncpy(res, stack + start, len);
    res[len] = '\0';

    return res;
}