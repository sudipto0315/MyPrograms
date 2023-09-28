// question
// You are given a sorted array ofnelements which has been circularly shifted.
// For example,35,42,5,12,23,26 is a sorted array that has been circularly shifted by 2 positions.
// Give an O(logn) time algorithm to find the largest element in a circularly shifted array.
// (Thenumber of positions through which it has been shifted is unknown to you.)
#include <iostream>
#include <limits.h>
using namespace std;
int findLargest(int arr[], int low, int high)
{
    if (low == high)
        return arr[low - 1];
    else
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[mid+1])
            return arr[mid];
        else if (arr[low]>arr[mid])
            return findLargest(arr,low,mid);
        else if(arr[mid]>=arr[high])
            return findLargest(arr,mid+1,high);
        return(arr[high]);
    }
}

int main(int argc, char const *argv[])
{
    int size = 0;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    // input
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
    // printing
    cout << "The entered array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The largest element is: " << findLargest(arr, 0, size - 1) << endl;
    return 0;
}
