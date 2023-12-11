#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long mod = 1e9 + 7;
        vector<long long> pows(n);
        pows[0] = 1;
        for (int i = 1; i < n; i++) {
            pows[i] = (pows[i - 1] * 2) % mod;
        }
        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i] * (pows[i] - pows[n - i - 1])) % mod;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {2,1,3};
    cout << sol.sumSubseqWidths(nums1) << endl;
    vector<int> nums2 = {2};
    cout << sol.sumSubseqWidths(nums2) << endl;
    return 0;
}