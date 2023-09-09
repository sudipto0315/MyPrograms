#include <iostream>
using namespace std;
int countOccurrence(const int* arr, int target, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; ++i) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int findMajorityElement(const int* arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = left + (right - left) / 2;
    int leftMajority = findMajorityElement(arr, left, mid);
    int rightMajority = findMajorityElement(arr, mid + 1, right);

    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    int leftCount = countOccurrence(arr, leftMajority, left, right);
    int rightCount = countOccurrence(arr, rightMajority, left, right);

if (leftCount > rightCount) {
    return leftMajority;
} else {
    return rightMajority;
}
}

int majorityElement(const int* arr, int size) {
    return findMajorityElement(arr, 0, size - 1);
}

int main() {
     int size = 0;
    cout << "Enter the size of the input array: ";
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
    int result = majorityElement(arr, size);
    cout << "The majority element is: " << result <<endl;

    return 0;
}
