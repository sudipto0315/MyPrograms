#include <bits/stdc++.h>
using namespace std;
int cross_product(int *arr, int low, int high)
{
    int mid = low + (high - low) / 2;
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int product = 1;
    for (int i = mid; i >= 0; i--)
    {
        product = product * arr[i];
        if (product > max1)
        {
            max1 = product;
        }
        if (product < min1)
        {
            min1 = product;
        }
    }
    product = 1;
    int max2 = INT_MIN;
    int min2 = INT_MAX;
    for (int i = mid + 1; i <= high; i++)
    {
        product = product * arr[i];
        if (product > max2)
        {
            max2 = product;
        }
        if (product < min2)
        {
            min2 = product;
        }
    }
    return max((max1 * max2), (min1 * min2));
}
int product(int *arr, int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    int left = product(arr, low, mid);
    int right = product(arr, mid + 1, high);
    int cross = cross_product(arr, low, high);
    return max(left, max(right, cross));
}
int main()
{
    int n;
    cout << "enter number of elements in array";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter element";
        cin >> arr[i];
    }
    cout << "max product : " << product(arr, 0, n - 1) << endl;
}