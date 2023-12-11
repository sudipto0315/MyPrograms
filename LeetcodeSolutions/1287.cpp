#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cnt = 1;
        if (n == 1) return arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                cnt++;
                if (cnt > n / 4) return arr[i];
            } else {
                cnt = 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1,2,2,6,6,6,6,7,10};
    cout << sol.findSpecialInteger(arr1) << endl;
    vector<int> arr2 = {1,1};
    cout << sol.findSpecialInteger(arr2) << endl;
    return 0;
}