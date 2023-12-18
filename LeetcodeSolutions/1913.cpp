#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        int firstMax = 0;
        int secondMax = 0;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int num : nums) {
            if (num > firstMax) {
                secondMax = firstMax;
                firstMax = num;
            } else {
                secondMax = max(secondMax, num);
            }

            if (num < firstMin) {
                secondMin = firstMin;
                firstMin = num;
            } else {
                secondMin = min(secondMin, num);
            }
        }

        return (firstMax * secondMax) - (firstMin * secondMin);
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {5,6,2,7,4};
    cout << s.maxProductDifference(nums1) << endl;
    vector<int> nums2 = {4,2,5,9,7,4,8};
    cout << s.maxProductDifference(nums2) << endl;
    return 0;
}