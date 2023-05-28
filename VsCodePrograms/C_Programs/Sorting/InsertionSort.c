#include <stdio.h>

void insertionSort(int a[], int n)
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("The Unsorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    insertionSort(a, size);

    printf("The Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
