/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <assert.h>
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int n = matSize;
    int m = matColSize[0];
    int orig_area = n * m;
    int new_area = r * c;
    if (orig_area != new_area) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    
    int **ans = malloc(r * sizeof(int *));
    int *cols = malloc(r * sizeof(int));
    *returnSize = r;
    for (int i = 0; i < r; i++) {
        ans[i] = malloc(c * sizeof(int));
        cols[i] = c;
    }
    *returnColumnSizes = cols;

    int ridx = 0;
    int cidx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            assert(ridx < r);
            if (cidx == c) {
                cidx = 0;
                ridx++;
            }
            ans[ridx][cidx++] = mat[i][j];
        }
    }

    return ans;
}
