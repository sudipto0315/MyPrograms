#include <iostream>
#include <limits.h>
using namespace std;
int mergeCountInversion(int arr[], int low, int high, int mid)
{
    int n1, n2;
    n1 = mid - low + 1;
    n2 = high - mid;
    int left[n1 + 1];
    int right[n2 + 1];
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int start = low;
    int count = 0;
    int i = 0;
    int j = 0;
    while (start < high)
    {
        if (left[i] <= right[j])
        {
            arr[start] = left[i];
            start++;
            i++;
        }
        else
        {
            arr[start] = right[j];
            start++;
            j++;
            count = count + (mid - i + 1);
        }
    }
    return count;
}
int mergeSortCountInversion(int arr[], int low, int high)
{
    int countInv = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        countInv += mergeSortCountInversion(arr, low, mid);
        countInv += mergeSortCountInversion(arr, mid + 1, high);
        countInv += mergeCountInversion(arr, low, high, mid);
    }
    return countInv;
}
int main(int argc, char const *argv[])
{
    int size = 0;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    // Input
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        cout << "Enter the " << i << " value in the array: ";
        cin >> temp;
        arr[i] = temp;
    }
    // Printing
    cout << "The entered array is: ";
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The number of inversions are: " << mergeSortCountInversion(arr, 0, size - 1) << endl;
    return 0;
}
