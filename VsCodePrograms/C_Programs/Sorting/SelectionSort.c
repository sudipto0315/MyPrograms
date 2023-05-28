#include <stdio.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int a[], int n)
{
    int i,j;
    for (i=0;i<n-1;i++)
    {
        int min = i;
        for (j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if (min!=i)  
            swap(&a[i],&a[min]);      
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

    selectionSort(a, size);

    printf("The Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
