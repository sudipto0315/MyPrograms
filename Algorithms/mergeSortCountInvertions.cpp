#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    int size = 0;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> arr; // Change this line
    // Input
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        cout << "Enter the " << i + 1 << " value in the array: ";
        cin >> temp;
        arr.push_back(temp); // Change this line
    }
    // Printing
    cout << "The entered array is: ";
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The number of inversions are: " << numberOfInversions(arr, size) << endl;
    return 0;
}
