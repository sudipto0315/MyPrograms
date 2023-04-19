#include <stdio.h>

int main() {
    int arr[10][10], transpose[10][10], order;

    printf("Enter the order of the matrix: ");
    scanf("%d", &order);
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Find transpose of matrix
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            transpose[i][j] = arr[j][i];
        }
    }

    // Print original matrix
    printf("The original matrix is:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Print transpose of matrix
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
