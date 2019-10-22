#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * ID: 260871301
 * Name: Ding Ma
 */

#define ROWS 5
#define COLS 5

void fillMatrix(int matrix[ROWS][COLS]) {
    srand(time(NULL));// allows ran() to have a different seed every time for pseudorandom
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            int numbToFill = rand() % 100 + 1; //generates a number between 1 and 100
            matrix[r][c] = numbToFill;
        }
    }
    
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            printf("%d ", matrix[r][c]);
            
        }
        printf("\n");
    }
    printf("\n");
}

void transposeMatrix(int matrix[ROWS][COLS]) {
    /*
     * a second * is needed to dereference the pointer in order to get the value
     *
     * basically we need to travel from left to right, from up to down
     * but we need to write from top to bottom, left to write.
     */
    int tmp;
    for (int r = 0; r < ROWS; r++) {
        for (int c = r + 1; c < COLS; c++) {
            tmp = *(*(matrix + r) + c);
            *(*(matrix + r) + c) = *(*(matrix + c) + r);
            *(*(matrix + c) + r) = tmp;
        }
    }
}

void multiplyMatrix(int m1[2][COLS], int m2[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    int matrix1[COLS][ROWS] = {0};
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < COLS; ++c) {
            matrix1[r][c] = m1[r][c];
        }
    }
    /*
     * 3 loops are needed here because we want to keep track of the bigCol for the result matrix
     * col and rows for the normal multiplication
     * m1 travels from bigCol and col
     * m2 travels from col to row.
     */
    int tempResult = 0;
    for (int bigCol = 0; bigCol < COLS; ++bigCol) {
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                int elemtOfMtx1 = matrix1[bigCol][col];
                int elemtOfMtx2 = m2[col][row];
                tempResult = tempResult + elemtOfMtx1 * elemtOfMtx2;
            }
            resultMatrix[bigCol][row] = tempResult;
            tempResult = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    int matrix[ROWS][COLS];
    fillMatrix(matrix);
    printMatrix(matrix);
    
    transposeMatrix(matrix);
    printMatrix(matrix);
    
    int matrix2[2][COLS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int resultMatrix[ROWS][COLS];
    multiplyMatrix(matrix2, matrix, resultMatrix);
    printMatrix(resultMatrix);
    return 0;
}


