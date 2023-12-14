#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n, 0));
        vector<int> OnesRow(m, 0), ZerosRow(m, 0);
        vector<int> OnesCol(n, 0), ZerosCol(n, 0);

        // rows
        for (int i = 0; i < m; i++) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) ones++;
                else zeros++;
            }
            OnesRow[i] = ones;
            ZerosRow[i] = zeros;
        }

        // cols
        for (int j = 0; j < n; j++) {
            int ones = 0, zeros = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) ones++;
                else zeros++;
            }
            OnesCol[j] = ones;
            ZerosCol[j] = zeros;
        }

        // diff
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = OnesRow[i] + OnesCol[j] - ZerosRow[i] - ZerosCol[j];
            }
        }
        return diff;
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid1 = {{0,1,1},{1,0,1},{0,0,1}};
    vector<vector<int>> result1 = s.onesMinusZeros(grid1);
    for (int i = 0; i < result1.size(); i++)
    {
        for (int j = 0; j < result1[0].size(); j++)
        {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> result2 = {{1,1,1},{1,1,1}};
    for (int i = 0; i < result2.size(); i++)
    {
        for (int j = 0; j < result2[0].size(); j++)
        {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}