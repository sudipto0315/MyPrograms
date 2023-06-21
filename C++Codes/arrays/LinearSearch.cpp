#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr, size, key);
    if (result == -1)
    {
        cout << "The element is not present";
    }
    else
        cout << "The element is present at index " << result << endl;
    return 0;
}
