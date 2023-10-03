// https://www.codingninjas.com/studio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, dp);
    int down = f(i, j - 1, dp);
    return dp[i][j] = up + down;
}

int uniquePath(int m, int n)
{
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp);
}

int main(int argc, char const *argv[]) {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int result = uniquePath(m, n);
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << result << endl;

    return 0;
}