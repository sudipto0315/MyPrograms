#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeSort2(int arr[], int l, int r)
{
    if (l < r)
    {
        int m1 = l + (r - l) / 4;
        int m2 = l + (r - l) / 2;
        int m3 = l + 3 * (r - l) / 4;

        mergeSort2(arr, l, m1);
        mergeSort2(arr, m1 + 1, m2);
        mergeSort2(arr, m2 + 1, m3);
        mergeSort2(arr, m3 + 1, r);

        merge(arr, l, m1, m2);
        merge(arr, m2 + 1, m3, r);
        merge(arr, l, m2, r);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int a[size], copy_a[size], new_a[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> a[i];
    }
    cout << "The Unsorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i];
    }
    // copying into copy_a array
    for (int i = 0; i < size; i++)
    {
        copy_a[i] = a[i];
    }
    cout << endl;
    mergeSort(a, 0, size - 1);

    cout << "The Sorted array is using 1: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << "\n";

    mergeSort2(copy_a, 0, size - 1);

    cout << "The Sorted array is using 2: ";
    for (int i = 0; i < size; i++)
    {
        cout << copy_a[i];
    }
    cout << "\n";
    return 0;
}
