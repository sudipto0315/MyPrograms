#include <stdio.h>
int main(){
    int n;
    printf("Enter the no of elements in the array ");
    scanf("%d",&n);
    printf("\nEnter the array elements \n");
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int min=0,max=0;
    if (n == 1)
        min=max=arr[0];
    if (arr[0] > arr[1]){
        max = arr[0];
        min = arr[1];
        }
    else{
        max = arr[1];
        min = arr[0];
    }
    for (int i = 2; i<n; i++){
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    printf("Minimum element: %d ", min);
    printf(" Maximum element: %d", max);
return 0;
}
