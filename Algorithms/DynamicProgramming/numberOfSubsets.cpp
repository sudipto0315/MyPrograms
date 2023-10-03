// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;

int f (int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0) return 1;
    if (ind == 0) return (num[0] == sum);
    if (dp[ind][sum]!= -1) return dp[ind][sum];
    int notTake = f(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum) take = f(ind - 1, sum-num[ind],num,dp);
    return dp[ind][sum] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int ways = findWays(num, target);

    cout << "Number of ways to form the target sum " << target << " is: " << ways << endl;

    return 0;
}
