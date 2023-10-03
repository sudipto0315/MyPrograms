// https://www.codingninjas.com/studio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;
int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[n - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + f(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);
    return dp[i][j] = min(down, diagonal);
}

int minPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, n, dp);
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of rows in the triangle: ";
    cin >> n;

    vector<vector<int>> triangle(n, vector<int>(n));

    cout << "Enter the elements of the triangle:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    int result = minPathSum(triangle, n);
    cout << "Minimum path sum in the triangle: " << result << endl;

    return 0;
}
