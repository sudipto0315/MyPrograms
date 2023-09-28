#include <iostream>
#include <limits.h>
#include <algorithm>
#include <time.h>
#include <random>
using namespace std;
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b, int c)
{
    return min(min(a, b), c);
}

int closestPairSplit(int arr[], int low, int mid, int high)
{
    int p = arr[mid];
    int q = arr[mid + 1];
    return abs(p - q);
}
int closestPair(int arr[], int low, int high)
{
    int n = sizeof(arr)/sizeof(arr[0]);
    if (n=1)
    {
        return INT_MAX;
    }
    else
    {
        if (n=2)
        {
            return abs(arr[1] - arr[2]);
        }
        else
        {
            sort(arr,arr+n);
            int mid = low + (high - low) / 2;
            int left[mid],right[n-mid];
            int leftSize=0;
            int rightSize=0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] <= mid)
                {
                    left[leftSize++]=arr[i];
                }
                else
                {
                    right[rightSize++]=arr[i];
                }
            }
            int d1 = closestPair(left, 0, leftSize-1);
            int d2 = closestPair(arr, 0, rightSize-1);
            int dSplit = closestPairSplit(arr, low, mid, high);
            int dMin = min(d1, d2, dSplit);
            return dMin;
        }
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
