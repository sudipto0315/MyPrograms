#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lcs_recc(string str1, string str2, int n, int m)
{
    int ans = 0;

    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (str1[n - 1] == str2[m - 1])
    {
        ans = 1 + lcs_recc(str1, str2, n - 1, m - 1);
    }
    else
    {
        int ans1 = lcs_recc(str1, str2, n - 1, m);
        int ans2 = lcs_recc(str1, str2, n, m - 1);

        ans += max(ans1, ans2);
    }

    return ans;
}

int lcs_memo(string str1, string str2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return dp[n][m] = 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (str1[n - 1] == str2[m - 1])
    {
        return dp[n][m] = 1 + lcs_memo(str1, str2, n - 1, m - 1, dp);
    }
    else
    {
        int ans1 = lcs_memo(str1, str2, n - 1, m, dp);
        int ans2 = lcs_memo(str1, str2, n, m - 1, dp);

        return dp[n][m] = max(ans1, ans2);
    }
}

int lcs_tab(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];
                dp[i][j] = max(ans1, ans2);
            }
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][m];
}

int main()
{
    cout << "Longest Common Subsequence(LCS)" << endl;
    // string str1 = "secret";
    // string str2 = "secretary";
    string str1;
    string str2;
    cout << "Enter the 1st string: ";
    cin >> str1;
    cout << "Enter the 2nd string: ";
    cin >> str2;

    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // cout << lcs_recc(str1, str2, n, m) << endl;
    // cout << lcs_memo(str1, str2, n, m, dp) << endl;
    cout << lcs_tab(str1, str2) << endl;

    return 0;
}
