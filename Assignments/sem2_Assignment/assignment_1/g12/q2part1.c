#include <stdio.h>

int main()
{
    int matrix[10][10];
    int i, j, rows, cols, sum = 0;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements of the matrix:\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            if(i==j)
            {
                sum += matrix[i][j];
            }
        }
    }
    printf("The sum of diagonal elements of the matrix is: %d\n", sum);
    return 0;
}