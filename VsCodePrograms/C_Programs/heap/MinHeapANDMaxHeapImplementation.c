#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at given index
void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;   // Initialize smallest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapifyMin(arr, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    for (int i = startIdx; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

// Function to heapify a subtree rooted at given index
void heapifyMax(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapifyMax(arr, n, largest);
    }
}

// Function to build a max-heap
void buildMaxHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    for (int i = startIdx; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

// Function to print array elements
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to print level order traversal of the heap
void printLevelOrder(int arr[], int n)
{
    printf("Level Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Print the original array
    printf("Original Array: ");
    printArray(arr, n);

    buildMinHeap(arr, n);
    // Print the Min Heap
    printf("Min Heap: ");
    printArray(arr, n);
    // Level order traversal of the Min Heap
    printLevelOrder(arr, n);

    buildMaxHeap(arr, n);
    // Print the Max Heap
    printf("Max Heap: ");
    printArray(arr, n);
    // Level order traversal of the Max Heap
    printLevelOrder(arr, n);

    return 0;
}
