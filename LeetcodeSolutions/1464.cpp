#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1 - 1) * (max2 - 1);      
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {3,4,5,2};
    cout << s.maxProduct(nums1) << endl;
    vector<int> nums2 = {1,5,4,5};
    cout << s.maxProduct(nums2) << endl;
    vector<int> nums3 = {3,7};
    cout << s.maxProduct(nums3) << endl;
    return 0;
}