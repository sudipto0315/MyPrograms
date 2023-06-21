#include <iostream>
#include<limits.h>
using namespace std;

int main()
{
    int n, i;
    cout << "Enter the size of the array:";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = arr[0], max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Sum: " << min + max << endl;
    return 0;
}
