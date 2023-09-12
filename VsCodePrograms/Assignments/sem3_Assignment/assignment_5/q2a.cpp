// worst case linear time algorithm to find k'th smallest element
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int c;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int findMedian(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

int select(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        c++;
        int n = r - l + 1;
        int i, median[(n + 2) / 3];
        for (i = 0; i < n / 3; i++)
            median[i] = findMedian(arr + l + i * 3, 3);
        if (i * 3 < n)
        {
            c++;
            median[i] = findMedian(arr + l + i * 3, n % 3);
            i++;
        }

        int medOfMed;
        if (i == 1)
        {
            c++;
            medOfMed = median[i - 1];
        }
        else
        {
            c++;
            medOfMed = select(median, 0, i - 1, i / 2);
        }

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
        {
            c++;
            return arr[pos];
        }
        if (pos - l > k - 1) // If position is more, recur for left
        {
            c++;
            return select(arr, l, pos - 1, k);
        }
        // Else recur for right subarray
        return select(arr, pos + 1, r, k - pos + l - 1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

int main()
{
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        int rnd = rand() % 100 + 1;
        arr[i] = rnd;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k;
    cout << "Enter the k'th value: ";
    cin >> k;
    cout << k << "'th smallest element is: " << select(arr, 0, n - 1, k) << endl;

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<"Comparisions: "<<c<<endl;
    return 0;
}
