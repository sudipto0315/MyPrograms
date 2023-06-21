#include <iostream>
using namespace std;

int largest(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 49, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The largest in given array is " << largest(arr, size) << endl;
    return 0;
}
