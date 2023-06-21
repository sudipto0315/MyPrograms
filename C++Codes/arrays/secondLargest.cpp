// Finding second largest value in a given array
#include <iostream>
#include <limits.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size], largest, secLargest;
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }

    //check if the input array has all the elements same like [5,5,5,5,5]
    int a = arr[0];
    int f = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != a)
            break;
        else
            f++;
    }
    if (f == size)
    {
        cout<<"The array has all elements same"<<endl;
        return -1;
    }

    //general case
    largest = INT_MIN;
    secLargest = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secLargest && arr[i] != largest)
        {
            secLargest = arr[i];
        }
    }
    cout << "The largest element in the array is: " << largest << endl;
    cout << "The second largest element in the array is: " << secLargest << endl;

    return 0;
}
