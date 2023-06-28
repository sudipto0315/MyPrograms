#include <stdio.h>

void findDuplicates(int arr[], int size) {
    // Create an array to store the frequency of each element
    int freqArray[size];
    for (int i = 0; i < size; i++) {
        freqArray[i] = -1; // Initialize the frequency array with -1
    }

    // Calculate the frequency of each element in the input array
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                // Mark the duplicate element as visited by setting its frequency to 0
                freqArray[j] = 0;
            }
        }
        if (freqArray[i] != 0) {
            freqArray[i] = count;
        }
    }

    // Print the duplicate elements along with their occurrences
    printf("Duplicate numbers and their occurrences:\n");
    for (int i = 0; i < size; i++) {
        if (freqArray[i] > 1) {
            printf("%d occurred %d times\n", arr[i], freqArray[i]);
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter %d elements to insert: ",i);
        scanf("%d", &arr[i]);
    }

    findDuplicates(arr, size);

    return 0;
}
