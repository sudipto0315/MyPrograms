#include <stdio.h>
int main()
{
    int array[5], i;
    printf("You are to enter 5 integers. \n\n");
    for (i = 1; i <= 5; i++)
    {
        printf ("enter integer #%d:",i);
        scanf("%d",&array[i]);
    }
    printf("\nThank You.\n\n");
    for (i = 1; i <= 5; i++)
    {
        printf("Integer #%d = %d.\n",i,array[i]);
    }
    return 0;
}