#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n) {
            if (temp.size() < 3) {
                if (temp.empty() || (nums[i] - *min_element(temp.begin(), temp.end()) <= k && *max_element(temp.begin(), temp.end()) - nums[i] <= k)) {
                    temp.push_back(nums[i]);
                } else {
                    temp.clear();
                }
            } 

            if (temp.size() == 3) {
                res.push_back(temp);
                temp.clear();
            }
            
            i++;  // Move the increment outside the if block
        }

        int resultRowSize = res.size();
        int resultColumnSize;
        if (resultRowSize > 0) {
            resultColumnSize = res[0].size();
        } else {
            resultColumnSize = 0;
        }

        if ((resultRowSize * resultColumnSize) != nums.size()) {
            return {};
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 2;
    vector<vector<int>> res = s.divideArray(nums, k);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    nums = {1, 3, 3, 2, 7, 3};
    k = 3;
    res = s.divideArray(nums, k);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
