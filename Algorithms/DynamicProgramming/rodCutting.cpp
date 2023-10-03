// https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return n * price[0];
    }
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int notTake = 0 + f(ind - 1, n, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= n)
    {
        take = price[ind] + f(ind, n - rodLength, price, dp);
    }
    return dp[ind][n] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the prices for each length from 1 to " << n << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }

    int maxProfit = cutRod(price, n);

    cout << "Maximum profit for cutting the rod of length " << n << " is: " << maxProfit << endl;

    return 0;
}
