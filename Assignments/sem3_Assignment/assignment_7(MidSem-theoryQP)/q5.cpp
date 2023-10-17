#include <iostream>
#include <limits.h>
#include <algorithm>
#include <time.h>
#include <random>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return (i + 1);
}

// Picks a random pivot element between
// l and r and partitions arr[l..r]
// around the randomly picked element
// using partition()
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return Partition(arr, l, r);
}

void MedianUtil(int arr[], int l, int r, int k, int &a, int &b)
{
    if (l <= r)
    {
        int partitionIndex = randomPartition(arr, l, r);

        // If partition index = k, then
        // we found the median of odd
        // number element in arr[]
        if (partitionIndex == k)
        {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }

        // If index = k - 1, then we get
        // a & b as middle element of
        // arr[]
        else if (partitionIndex == k - 1)
        {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }

        // If partitionIndex >= k then
        // find the index in first half
        // of the arr[]
        if (partitionIndex >= k)
            return MedianUtil(arr, l, partitionIndex - 1, k, a, b);

        // If partitionIndex <= k then
        // find the index in second half
        // of the arr[]
        else
            return MedianUtil(arr, partitionIndex + 1, r, k, a, b);
    }

    return;
}

// Function to find Median
void findMedian(int arr[], int n)
{
    int ans, a = -1, b = -1;

    // If n is odd
    if (n % 2 == 1)
    {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        ans = b;
    }

    // If n is even
    else
    {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        ans = (a + b) / 2;
    }

    // Print the Median of arr[]
    cout << "Median = " << ans;
}

// Driver program to test above methods
int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMedian(arr, n);
    return 0;
}
