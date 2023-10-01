#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(arr[i], arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int findMedian(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.begin() + n);
    return arr[n / 2];
}

int select(vector<int> &arr, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr, n % 5);
            i++;
        }

        int medOfMed = (i == 1) ? median[i - 1] : select(arr, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
        {
            return select(arr, l, pos - 1, k);
        }
        return select(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}

pair<vector<int>, int> removeDuplicatesWithCount(const vector<int> &inputVec)
{
    vector<int> vec = inputVec;

    // Sort the vector to group duplicate elements together
    sort(vec.begin(), vec.end());

    // Use std::unique and std::vector::erase to remove duplicates
    auto new_end = unique(vec.begin(), vec.end());
    int countDuplicates = vec.size() - distance(vec.begin(), new_end);
    vec.erase(new_end, vec.end());

    return make_pair(vec, countDuplicates);
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++) // Change the loop to read 'size' elements
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k;
    cout << "Enter the k'th value: ";
    cin >> k;
    pair<vector<int>, int> result = removeDuplicatesWithCount(arr);
    vector<int> uniqueVec = result.first;
    int countDuplicates = result.second;
    int n = uniqueVec.size(); // Corrected size calculation
    int index = select(uniqueVec, 0, n - 1, k);
    int kLargest = n - index - 1 - countDuplicates;
    cout << k << "'th smallest element is: " << uniqueVec[kLargest] << endl;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
