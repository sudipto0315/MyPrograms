// C program to implement iterative Binary Search
#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int a_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = 2*(l + (r - l)) / 3;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int b_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 4;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    int n, x;
    cout << "Enter the size of the input array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the input array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> x;
    int result, result_a, result_b;

    cout<<"The result for binary search: "<<endl;

    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
    {
        cout << "Element is not present in array" << endl;
    }
    else
    {
        cout << "Element is present at index " << result << endl;
    }

    cout<<"The result for alpha-search: "<<endl;

    result_a = a_search(arr, 0, n - 1, x);
    if (result == -1)
    {
        cout << "Element is not present in array" << endl;
    }
    else
    {
        cout << "Element is present at index " << result << endl;
    }

    cout<<"The result for beta-search: "<<endl;

    result_b = b_search(arr, 0, n - 1, x);
    if (result == -1)
    {
        cout << "Element is not present in array" << endl;
    }
    else
    {
        cout << "Element is present at index " << result << endl;
    }

    return 0;
}
