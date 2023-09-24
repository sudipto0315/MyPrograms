#include <stdio.h>

#define ROWS 3
#define COLS 3

int main()
{
    int matrix[ROWS][COLS], sum = 0, i, j, scalar;
    printf("Enter the matrix elements:\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(j = 0; j < COLS; j++)
    {
        sum += matrix[0][j];
    }
    scalar = sum;
    printf("The Scalar that is to be multiplied is %d \n",scalar);

    printf("Resultant matrix after scalar multiplication:\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", scalar * matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
