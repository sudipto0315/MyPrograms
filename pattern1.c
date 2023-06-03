#include <stdio.h>
int isPrimeNumber(int num)
{
    int i, isPrime = 1;
    for (i = 2; i <= (num / 2); i++)
    {
        if (num % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    if (isPrime == 1 || num == 2)
        return 1;
    else
        return 0;
}

int main()
{
    int i, j, k, counter = 1, rows;
    printf("enter the no of rows: ");
    scanf("%d", &rows);
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }

        for (k = 1; k <= i; k++)
        {
            while (!isPrimeNumber(counter))
            {
                counter++;
            }
            printf("%d", counter);
            counter++;
            if (k != i)
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
