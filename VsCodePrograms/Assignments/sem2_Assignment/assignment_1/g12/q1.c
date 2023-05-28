// Write a C program to find the frequency of occurrence of each element in the array and
// then remove the duplicate from the array.
#include <stdio.h>
#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE], freq[MAX_SIZE];
    int size, i, j, k;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements in array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }
    for (i = 0; i < size; i++)
    {
        int count = 1;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    printf("\nArray with frequency of each element:\n");
    for (i = 0; i < size; i++)
    {
        if (freq[i] != 0)
        {
            printf("%d occurs %d time(s)\n", arr[i], freq[i]);
        }
    }
    int newArr[MAX_SIZE], newSize = 0;
    for (i = 0; i < size; i++)
    {
        if (freq[i] != 0)
        {
            newArr[newSize++] = arr[i];
        }
    }
    printf("\nArray without duplicates:\n");
    for (i = 0; i < newSize; i++)
    {
        printf("%d ", newArr[i]);
    }

    return 0;
}
