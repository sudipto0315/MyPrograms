// You are given an integer array nums of size n and a positive integer k.

// Divide the array into one or more arrays of size 3 satisfying the following conditions:

// Each element of nums should be in exactly one array.
// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
// Example 1:
// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
// Output: [[1,1,3],[3,4,5],[7,8,9]]
// Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
// The difference between any two elements in each array is less than or equal to 2.
// Note that the order of elements is not important.
// Example 2:
// Input: nums = [1,3,3,2,7,3], k = 3
// Output: []
// Explanation: It is not possible to divide the array satisfying all the conditions.
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
                    i++;
                } else {
                    temp.clear();
                }
            } else {
                if (*max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end()) <= k) {
                    res.push_back(temp);
                }
                temp.clear();
            }
        }
        if (temp.size() == 3 && *max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end()) <= k) {
            res.push_back(temp);
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> res1 = s.divideArray(nums1, k);
    for (auto i : res1) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout<<endl;
    vector<int> nums2 = {1,3,3,2,7,3};
    k = 3;
    vector<vector<int>> res2 = s.divideArray(nums2, k);
    for (auto i : res2) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout<<endl;
}