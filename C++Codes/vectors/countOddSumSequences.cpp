#include <iostream>
#include <vector>

using namespace std;


int countOddSumSequences2(vector<int>& arr) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum = 0; // Reset sum for each new sequence

        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];

            if (sum % 2 != 0) {
                count++;
            }
        }
    }

    return count;
}

int countOddSumSequences(vector<int>& arr) {
    int count = 0;
    int sum = 0;
    int prefixSum = 0;
    int evenPrefixSums = 1;
    int oddPrefixSums = 0;

    for (int num : arr) {
        prefixSum += num;

        if (prefixSum % 2 == 0) {
            count += oddPrefixSums;
            evenPrefixSums++;
        } else {
            count += evenPrefixSums;
            oddPrefixSums++;
        }
    }

    return count;
}
int main() {
    int size= 0;
    cout << "Enter the size of the element: ";
    cin >> size;
    // enter the elements
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> arr[i];
    }
    int oddSequences = countOddSumSequences(arr);
    cout << "Number of Consecutive Sequences with Odd Sum: " << oddSequences << endl;

    return 0;
}
