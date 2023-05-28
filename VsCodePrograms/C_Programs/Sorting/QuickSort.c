#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return (i + 1);
}

void quickSort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quickSort(a, l, j - 1);
        quickSort(a, j + 1, h);
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
        printf("%d ", a[i]);
    }
    printf("\n");

    quickSort(a, 0, size - 1);

    printf("The Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
