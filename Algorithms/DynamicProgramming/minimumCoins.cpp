// https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=1?source=youtube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int f (int ind, int T, vector<int> &nums, vector<vector<int>> &dp)
{
    if (T == 0){
        if (T % nums[0] == 0)
        {
            return T / nums[0];
        }
        return 1e9;        
    }
    if (dp[ind][T]!= -1) return dp[ind][T];
    int notTake = 0 + f(ind - 1, T, nums, dp);
    int take = INT_MAX;
    if (nums[ind] <= T) take = 1 + f(ind - 1, T-nums[ind],nums,dp);
    return dp[ind][T] = min(take , notTake);

}

int findWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar+1,-1));
    int ans = f(n-1, tar, nums, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int minElements = findWays(nums, target);

    if (minElements == -1) {
        cout << "It's not possible to form the target sum " << target << " using the given elements." << endl;
    } else {
        cout << "Minimum number of elements needed to form the target sum " << target << " is: " << minElements << endl;
    }

    return 0;
}






