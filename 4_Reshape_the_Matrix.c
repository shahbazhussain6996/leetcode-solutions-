#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = (m > 0) ? matColSize[0] : 0;

    // Check if reshape is possible and legal
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(sizeof(int) * m);
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
        }
        return mat;
    }

    // Allocate memory for the reshaped r x c matrix
    int** res = (int**)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    *returnSize = r;

    for (int i = 0; i < r; i++) {
        res[i] = (int*)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }

    // Fill in row-traversing order using a single flat index
    int total = m * n;
    for (int idx = 0; idx < total; idx++) {
        res[idx / c][idx % c] = mat[idx / n][idx % n];
    }

    return res;
}