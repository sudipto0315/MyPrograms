#define MAX_ARRAY_SIZE 20
#define TRAILER -9999
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int array[MAX_ARRAY_SIZE];
    int array_size, item, i;
    printf("Please enter up to %d integers, Using %d as a trailer:\n",MAX_ARRAY_SIZE);
    for (array_size = 0; array_size < MAX_ARRAY_SIZE; array_size++)
    {
        scanf("%d",&item);
        if (item==TRAILER) 
        break;
        array[array_size] = item;
    }
    printf("\nYou have entered %d integers.\n",array_size);
    for(i=0;i<array_size;i++)
    {
        printf("Integer #%d = %d.\n",i+1, array[i]);
    }
    return 0;
}
