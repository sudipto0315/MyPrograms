#include <iostream>
#include <algorithm>
using namespace std;

int findMissingElement(int arr[], int left, int right) {
    if (left > right) {
        return left + 1; // Missing element found
    }

    int mid = left + (right - left) / 2;

    // Compare the middle element with its index
    if (arr[mid] == mid + 1) {
        // The missing element is in the right subarray
        return findMissingElement(arr, mid + 1, right);
    } else {
        // The missing element is in the left subarray
        return findMissingElement(arr, left, mid - 1);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int missingElement = findMissingElement(arr, 0, n - 1);
    cout << "Missing element in the array: " << missingElement << endl;

    return 0;
}
