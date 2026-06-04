/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int n = matrixSize;
    int m = matrixColSize[0];
    int size = n * m;
    int *ans = malloc(size * sizeof(int));
    *returnSize = size;
    int idx = 0;

    int in = 0;
    for (int i = 0; i < size; ) {
        for (int j = in; j < m - in; j++) {
            ans[idx++] = matrix[in][j];
            if (idx >= size) goto out;
            i++;
        }
        for (int j = in + 1; j < n - in; j++) {
            ans[idx++] = matrix[j][m - in - 1];
            if (idx >= size) goto out;
            i++;
        }
        for (int j = m - in - 2; j >= in; j--) {
            ans[idx++] = matrix[n - in - 1][j];
            if (idx >= size) goto out;
            i++;
        }
        for (int j = n - in - 2; j >= in + 1; j--) {
            ans[idx++] = matrix[j][in];
            if (idx >= size) goto out;
            i++;
        }
        in++;
    }

out:
    return ans;
}
