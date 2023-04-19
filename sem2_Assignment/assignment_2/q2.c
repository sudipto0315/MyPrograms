#include <stdio.h>

int main() {
    int arr[50], n, i, largest, secLargest;

    // Get size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get elements of array from user
    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find largest element
    largest = arr[0];
    for (i = 1; i < n; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }

    // Find second largest element
    secLargest = arr[0];
    for (i = 4; i < n; i++) {
        if (arr[i] != largest && secLargest < arr[i]) {
            secLargest = arr[i];
        }
    }

    // Print result
    printf("The second largest element in the array is: %d\n", secLargest);

    return 0;
}
