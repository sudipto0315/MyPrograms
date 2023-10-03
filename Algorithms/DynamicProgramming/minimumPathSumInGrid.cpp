// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9; // 1e9 is INT_MAX
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + f(i - 1, j, grid, dp);
    int left = grid[i][j] + f(i, j - 1, grid, dp);
    return dp[i][j] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(m - 1, n - 1, grid, dp);
}

int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the elements of the grid:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = minSumPath(grid);
    cout << "Minimum sum path in the grid: " << result << endl;

    return 0;
}
