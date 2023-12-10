#include <iostream>
using namespace std;

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;

    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or the other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        /* If key does not lie in the first half subarray,
        Divide the other half into two subarrays,
        such that we can quickly check if the key lies
        in the other half */
        return search(arr, mid + 1, h, key);
    }

    /* If arr[l..mid] first subarray is not sorted, then
    arr[mid... h] must be a sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);

    return search(arr, l, mid - 1, key);
}

// Driver program
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array in sorted and rotated order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int result = search(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Index: " << result << endl;
    else
        cout << "Key not found";

    return 0;
}
