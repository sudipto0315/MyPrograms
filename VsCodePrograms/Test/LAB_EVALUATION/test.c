#include<stdio.h>
#include<stdlib.h>
int triplets(int arr[], int n,int k)
{
	int calc = 0;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                calc = k-(arr[i]+(arr[j]/arr[k]));
                //if(k==arr[i]+(arr[j]/arr[k]))
                    if (arr[i]!=arr[j] && arr[j]!=arr[k] && arr[k]!=arr[i] && calc==0)
                        printf("%d %d %d \n",arr[i],arr[j],arr[k]);
            }
        }
	}
    return 0;
}
int main(int argc, char const *argv[])
{
    int n=0;
    printf("enter no of elements in the array: ");
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    printf("enter values to the array ");
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int k=0;
    printf("Enter the target value K");
    scanf("%d",&k);
    triplets(arr,n,k);
    return 0;
}