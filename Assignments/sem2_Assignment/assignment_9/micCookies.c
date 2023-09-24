#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the mixing operation on cookies
int mixCookies(int A[], int n, int k) {
    // Initialize the number of operations
    int operations = 0;

    // Sort the array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
            }
        }
    }

    // Perform the mixing operation until all cookies have sweetness >= k
    while (A[0] < k && n > 1) {
        // Combine the two least sweet cookies
        int combinedSweetness = A[0] + 2 * A[1];

        // Remove the two least sweet cookies
        for (int i = 2; i < n; i++) {
            A[i - 2] = A[i];
        }

        // Add the combined cookie to the array
        A[n - 2] = combinedSweetness;

        // Decrease the size of the array
        n -= 1;

        // Increment the number of operations
        operations += 1;

        // Sort the array after each operation
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    swap(&A[j], &A[j + 1]);
                }
            }
        }
    }

    // Check if all cookies have sweetness >= k
    for (int i = 0; i < n; i++) {
        if (A[i] < k) {
            return -1; // Not possible to achieve sweetness >= k
        }
    }

    return operations;
}

int main() {
    int n;
    printf("Enter the number of cookies: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the sweetness values of cookies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int k;
    printf("Enter the sweetness threshold: ");
    scanf("%d", &k);

    int minOperations = mixCookies(A, n, k);

    if (minOperations == -1) {
        printf("It is not possible to achieve sweetness >= %d\n", k);
    } else {
        printf("Minimum number of operations required: %d\n", minOperations);
        printf("Final array A: ");
        for (int i = 0; i < n - minOperations; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    return 0;
}
