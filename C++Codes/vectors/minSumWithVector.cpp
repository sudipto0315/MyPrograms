#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minSum(const vector<int> &a, const vector<int> &b)
{
    int minA = INT_MAX, minB = INT_MAX, indexA = 0, indexB = 0;
    int min2A = INT_MAX, min2B = INT_MAX;

    for (int i = 0; i < a.size(); i++)
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

    return (indexA != indexB) ? minA + minB : min(min2A + minB, min2B + minA);
}

vector<int> getInputArray(int size, const string &prompt)
{
    vector<int> arr(size);
    cout << prompt << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
    return arr;
}

int main()
{
    int n;
    cout << "Enter the size of the arrays: ";
    cin >> n;

    vector<int> a = getInputArray(n, "Enter the elements of array a: ");
    vector<int> b = getInputArray(n, "Enter the elements of array b: ");

    int result = minSum(a, b);
    cout << "Minimum sum: " << result << endl;

    return 0;
}
