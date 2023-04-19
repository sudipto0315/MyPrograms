#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, sum1 = 0, sum2 = 0, ab = 0;
    int arr[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("enter the element");
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                sum1 += arr[i][j];
            if (i + j == 2)
                sum2 += arr[i][j];
        }
    }
    int diff = sum1 - sum2;
    ab = abs(diff);
    printf("the absolute difference is= %d ", ab);
    return 0;
}
