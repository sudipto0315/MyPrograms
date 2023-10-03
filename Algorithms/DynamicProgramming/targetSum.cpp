// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;

bool f (int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0) return true;
    if (ind == 0) return (arr[0] == target);
    if (dp[ind][target]!= -1) return dp[ind][target];
    bool notTake = f(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) take = f(ind - 1, target-arr[ind],arr,dp);
    return dp[ind][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

bool canPartition(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += arr[n];
    if(totalSum % 2) return false;
    int target = totalSum / 2;
    return subsetSumToK(n, target, arr);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the target sum: ";
    cin >> k;

    if (subsetSumToK(n, k, arr)) {
        cout << "There is a subset of elements that sums up to " << k << "." << endl;
    } else {
        cout << "There is no subset of elements that sums up to " << k << "." << endl;
    }

    return 0;
}
