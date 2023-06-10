#include<stdio.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int a[],int n)
{
    int flag,temp;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j=0; j<n-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag = 1;  
            }
        }
        if (flag==0)
            break;
    }
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
    scanf("%d",&size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("The Unsorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    int operation;
    printf("Available Algorithms:\n");
    printf("1: Bubble Sort ");
    printf("2: Selection Sort ");
    printf("3: Insertion Sort ");
    printf("0: Exit \n");
    printf("Select the Sorting Algorithm: ");
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        bubbleSort(a,size);
        break;
    case 2:
        selectionSort(a,size);
        break;
    case 3:
        insertionSort(a,size);
        break;
    case 0:
        printf("Thank You");
    default:
        printf("Invalid Input");
        break;
    }

    printf("The Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
