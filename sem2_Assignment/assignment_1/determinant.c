#include <stdio.h>
#define MAX_SIZE 10

int determinant(int matrix[MAX_SIZE][MAX_SIZE], int order);

int main() {
    int order, matrix[MAX_SIZE][MAX_SIZE], det;

    printf("Enter the order of the matrix: ");
    scanf("%d", &order);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    det = determinant(matrix, order);

    printf("The determinant of the matrix is %d\n", det);

    return 0;
}

int determinant(int matrix[MAX_SIZE][MAX_SIZE], int order) {
    int det = 0, sign = 1;

    if (order == 1) {
        det = matrix[0][0];
    } else if (order == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (int i = 0; i < order; i++) {
            int submatrix[MAX_SIZE][MAX_SIZE], suborder = order - 1;

            for (int j = 1; j < order; j++) {
                for (int k = 0; k < order; k++) {
                    if (k < i) {
                        submatrix[j - 1][k] = matrix[j][k];
                    } else if (k > i) {
                        submatrix[j - 1][k - 1] = matrix[j][k];
                    }
                }
            }

            det += sign * matrix[0][i] * determinant(submatrix, suborder);
            sign = -sign;
        }
    }

    return det;
}