#include<stdio.h>
int array[5] = {4,6,5,7,2};
int main(int argc, char const *argv[])
{
    int i;
    for ( i = 1; i <= 5; i++)
    {
        printf("Integer #%d = %d. \n",i,array[i-1]);
    }
    
    return 0;
}
