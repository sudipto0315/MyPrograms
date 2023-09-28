#include <iostream>
#include <limits.h>
using namespace std;
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = l; i <= m; i++)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l > h)
        return INT_MIN;
    if (l == h)
        return arr[l];
    int m = l + (h - l) / 2;

    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */
    return max(maxSubArraySum(arr, l, m - 1), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}

int main()
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
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}