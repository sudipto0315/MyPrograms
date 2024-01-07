#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<ll, int>> dp(n); // dp[i][d]
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll diff = (ll) nums[i] - nums[j];

                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2, 4, 6, 8, 10};
    cout << s.numberOfArithmeticSlices(nums) << endl;
    nums = {7, 7, 7, 7, 7};
    cout << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}