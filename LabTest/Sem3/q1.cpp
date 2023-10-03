#include <iostream>
#include <vector>
using namespace std;

vector<int> findElement(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    int i = 0, j = n - 1;

    while (i < n && j >= 0)
    {
        if (arr[i][j] == k)
        {
            return {i, j};
        }
        else if (arr[i][j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return {-1, -1};
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the size: ";
    cin >> size;
    vector<vector<int>> arr(size, vector<int>(size, 0));
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
    // printing the array
    cout << "The entered array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    vector<int> position = findElement(arr, k);
    if (position[0] != -1 || position[1] != -1)
    {
        cout << "Element " << k << " found at position (" << position[0] << ", " << position[1] << ")" << endl;
    }
    else
    {
        cout << "Element " << k << " not found in the matrix" << endl;
    }

    return 0;
}
