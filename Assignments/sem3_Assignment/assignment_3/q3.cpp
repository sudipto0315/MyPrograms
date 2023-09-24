#include <iostream>
#include <limits.h>
#include <time.h>
#include <random>
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

int maxCrossingProduct(int arr[], int l, int m, int h)
{
    int product = 1;
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    for (int i = m; i >= l; i--)
    {
        product = product * arr[i];
        if (product > max1)
            max1 = product;
        else if (product < min1)
            min1 = product;
    }

    product = 1;
    int max2 = INT_MIN;
    int min2 = INT_MAX;
    for (int i = m + 1; i <= h; i++)
    {
        product = product * arr[i];
        if (product > max2)
            max2 = product;
        else if (product < min2)
            min2 = product;
    }

    return max((max1 * max2), (min1 * min2));
}

int maxSubArrayProduct(int arr[], int l, int h)
{
    if (l > h)
        return INT_MIN;
    if (l == h)
        return arr[l];

    int m = l + (h - l) / 2;

    return max(maxSubArrayProduct(arr, l, m - 1), maxSubArrayProduct(arr, m + 1, h), maxCrossingProduct(arr, l, m, h));
}

int main()
{
    // The following code will randomly generate positive and negetive numbers
    // int n=0;
    // srand((unsigned)time(0));
    // // srand(static_cast<unsigned>(time(0)));
    // cout<<"Enter the size of the array: ";
    // cin>>n;
    // cout<<endl;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int rnd = rand() % 201 - 100; //this will generate both positive and negative numbers
    //     // int rnd = rand() % 100 + 1; //this will generate only positive numbers
    //     arr[i] = rnd;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout<<endl;

    // an example for now ->
    // int arr[] = {97, -18, 91, -69, 97};
    // int arr[] = {2, 13, -4, 555, 7};
    // int arr[] = {21, -15, -4, 5, -7};
    int arr[] = {21, 15, -4, 5, -7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_Product = maxSubArrayProduct(arr, 0, n - 1);
    cout << "Maximum contiguous product is " << max_Product << endl;
    return 0;
}