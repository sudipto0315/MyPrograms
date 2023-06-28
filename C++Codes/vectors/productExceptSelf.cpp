#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
    vector<int> leftProduct(n, 1);
    vector<int> rightProduct(n, 1);
    vector<int> ans(n);

    for (int i = 1; i < n; i++) {
        leftProduct[i] = leftProduct[i - 1] * arr[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        rightProduct[i] = rightProduct[i + 1] * arr[i + 1];
    }

    for (int i = 0; i < n; i++) {
        ans[i] = leftProduct[i] * rightProduct[i];
    }

    return ans;
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
    vector<int> ans = productExceptSelf(arr);

    // Print the resulting array
    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
