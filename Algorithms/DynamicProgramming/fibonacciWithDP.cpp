#include <iostream>
#include <vector>
using namespace std;
int topDonwFibo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    else
        return dp[n] = topDonwFibo(n - 1, dp) + topDonwFibo(n - 2, dp);
}
int bottomUpFibo(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(int argc, char const *argv[])
{
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1); // initiate all the elements with -1
    cout << "Top Down DP: " << topDonwFibo(n, dp) << endl;
    cout << "Bottom up DP with constant space complexity: " << bottomUpFibo(n) << endl;
    return 0;
}
