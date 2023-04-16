/*
//linear search
#include <stdio.h>
#include <windows.h>
int search(int array [],int n, int x){
    // going through array sequencially
    for (int i=0;i<n;i++){
        if (array[i]==x)
        {
            return i;
        }
    return -1;
    }
}
// Driver's code
int main(void)
{
    //system("cls");
    int array[]= {2,3,4,10,40};
    int x = 10;
    int n = sizeof(array)/sizeof(array[0]);
    int result = search(array,n,x);
    (result == -1) ? printf("Element not found") : printf("Element found at index : %d",result);
    return 0;
}
*/
// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <stdio.h>

int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver's code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	int result = search(arr, N, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
