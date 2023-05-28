#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int m, int n)
{
    int **ans = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        ans[i] = (int *)calloc(n, sizeof(int));
    }
    return ans;
}

void initialize_matrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int **newMatrix(int **matrix, int m, int n, int i)
{
    int **new = createMatrix(m - 1, n - 1);
    int start = 0;
    int end = 0;
    for (int a = 1; a < m; a++)
    {

        for (int b = 0; b < n; b++)
        {
            if (b == i)
                continue;
            if (start > n - 2)
            {
                start = 0;
                end++;
            }
            new[end][start++] = matrix[a][b];
        }
    }
    return new;
}

int det(int **matrix, int m, int n)
{
    if (m == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        int sign = 1;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int d = det(newMatrix(matrix, m, n, i), m - 1, n - 1);
            ans = ans + sign * matrix[0][i] * d;
            sign = sign * -1;
        }
        return ans;
    }
}

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int **matrix1 = createMatrix(m, n);
    initialize_matrix(matrix1, m, n);
    int ans = det(matrix1, m, n);
    printf("%d ", ans);
}