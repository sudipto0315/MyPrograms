#include <iostream>
#include <limits.h>
using namespace std;
int minMaxSum(int a[], int b[], int n)
{
    int minA = INT_MAX, minB = INT_MAX, indexA = 0, indexB = 0;
    int min2A = INT_MAX, min2B = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < minA)
        {
            min2A = minA;
            minA = a[i];
            indexA = i;
        }
        else if (a[i] < min2A)
            min2A = a[i];
        if (b[i] < minB)
        {
            min2B = minB;
            minB = b[i];
            indexB = i;
        }
        else if (b[i] < min2B)
            min2B = b[i];
    }
    if (indexA != indexB)
        return minA + minB;
    return min(min2A + minB, min2B + minA);
}
int main(int argc, char const *argv[])
{
    int size = 0;
    cout << "Enter the size of the array 1: ";
    cin >> size;
    int arr1[size];
    // user input for array 1
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr1[i];
    }

    // user input for array 2
    int arr2[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr2[i];
    }

    int answer = minMaxSum(arr1, arr2, size);
    cout<<"The sum will be: "<<answer;
    cout << endl;
    return 0;
}
