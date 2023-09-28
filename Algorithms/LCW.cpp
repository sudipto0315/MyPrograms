#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs_recc(string str1, string str2, int m, int n, int maxLength)
{
    // Base case: if either string is empty, return maxLength
    if (m == 0 || n == 0)
    {
        return maxLength;
    }

    // If the last characters of both strings match
    if (str1[m - 1] == str2[n - 1])
    {
        maxLength = lcs_recc(str1, str2, m - 1, n - 1, maxLength + 1);
    }

    // Recursively compute lengths by excluding the last character of either string
    maxLength = max(maxLength, max(
                                   lcs_recc(str1, str2, m - 1, n, 0),
                                   lcs_recc(str1, str2, m, n - 1, 0)));

    return maxLength;
}

int lcs_memo(string str1, string str2, int n, int m, int maxLength, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return dp[n][m] = maxLength;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (str1[n - 1] == str2[m - 1])
    {
        maxLength = lcs_memo(str1, str2, n - 1, m - 1, maxLength + 1, dp);
        dp[n][m] = maxLength;
    }
    else
    {
        maxLength = max(maxLength, max(
                                       lcs_memo(str1, str2, n - 1, m, maxLength, dp),
                                       lcs_memo(str1, str2, n, m - 1, maxLength, dp)));
        dp[n][m] = maxLength;
    }

    return dp[n][m] = maxLength;
}

int lcs_tab(string str1, string str2)
{
    int maxLength = 0;

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
                maxLength = max(maxLength, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
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

    return maxLength;
}

int main()
{
    cout << "Longest Common Subword(LCW)" << endl;
    // string str1 = "bisect";
    // string str2 = "secret";
    string str1;
    string str2;
    cout << "Enter the 1st string: ";
    cin >> str1;
    cout << "Enter the 2nd string: ";
    cin >> str2;
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // cout << lcs_recc(str1, str2, n, m, 0) << endl;
    // cout << lcs_memo(str1, str2, n, m, 0, dp) << endl;
    cout << lcs_tab(str1, str2) << endl;

    return 0;
}
