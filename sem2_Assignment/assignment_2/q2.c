#include <stdio.h>

int main() {
    int arr[50], n, i, largest, secLargest;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    for (i = 0; i < n; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }

    secLargest = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] != largest && secLargest < arr[i]) {
            secLargest = arr[i];
        }
    }

    printf("The largest element in the array is: %d\n",largest);
    printf("The second largest element in the array is: %d\n", secLargest);

    return 0;
}
