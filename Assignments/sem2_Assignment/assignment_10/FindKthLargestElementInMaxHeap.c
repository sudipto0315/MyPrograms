#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void buildMaxHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
    for (int i = size -1; i >= 0; i--)
    {
        swap(&array[0],&array[i]);
        heapify(array,i,0);
    }
    
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *array = (int*)malloc(size * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    buildMaxHeap(array, size);
    printf("Max-Heap array: ");
    printArray(array, size);

    int k = 0;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k > 0 && k <= size)
    {
        printf("The %dth largest element will be: %d", k, array[size - k]);
    }
    else
    {
        printf("Invalid value of k.");
    }

    free(array);

    return 0;
}
