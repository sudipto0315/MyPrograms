// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;

long f(int ind, int T, vector<int> &a, vector<vector<int>> &dp)
{
    if (ind == 0) {
        return (T % a[0] == 0);
    }
    if (dp[ind][T] != -1) return dp[ind][T];
    long notTake = 0 + f(ind - 1, T, a, dp);
    long take = 0;
    if (a[ind] <= T) take = f(ind, T - a[ind], a, dp);
    return dp[ind][T] = take + notTake;
}

long countWaysToMakeChange(vector<int> &denominations, int value)
{
    int n = denominations.size();
    vector<vector<int>> dp(n, vector<int>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of denominations: ";
    cin >> n;

    vector<int> denominations(n);
    cout << "Enter the denominations:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> denominations[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    long ways = countWaysToMakeChange(denominations, target);

    cout << "Number of ways to make change for " << target << " using the given denominations is: " << ways << endl;

    return 0;
}
