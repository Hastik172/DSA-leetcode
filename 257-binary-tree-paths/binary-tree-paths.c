/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Helper DFS
void dfs(struct TreeNode* root, char* path, int len,
         char*** result, int* returnSize) {

    if (root == NULL) return;

    // Add current node value to path
    len += sprintf(path + len, "%d", root->val);

    // If leaf node → store result
    if (root->left == NULL && root->right == NULL) {
        (*result)[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }

    // Add arrow
    path[len++] = '-';
    path[len++] = '>';

    // Go left and right
    dfs(root->left, path, len, result, returnSize);
    dfs(root->right, path, len, result, returnSize);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    // max possible paths ~100 (safe buffer)
    char** result = (char**)malloc(100 * sizeof(char*));

    char path[1000]; // buffer for path string

    dfs(root, path, 0, &result, returnSize);

    return result;
}