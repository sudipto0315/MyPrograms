#include<stdio.h>

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
        printf("%d",a[i]);
    }
    printf("\n");

    bubbleSort(a,size);

    printf("The Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
