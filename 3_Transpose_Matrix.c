#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = (rows > 0) ? matrixColSize[0] : 0;

    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(sizeof(int) * cols);

    int** result = (int**)malloc(sizeof(int*) * cols);
    for (int j = 0; j < cols; j++) {
        (*returnColumnSizes)[j] = rows;
        result[j] = (int*)malloc(sizeof(int) * rows);
        for (int i = 0; i < rows; i++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}