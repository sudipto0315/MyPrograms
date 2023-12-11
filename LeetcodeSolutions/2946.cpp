#include <iostream>
#include <vector>
using namespace std;
// You are given a 0-indexed m x n integer matrix mat and an integer k. You have to cyclically right shift odd indexed rows k times and cyclically left shift even indexed rows k times.
// Return true if the initial and final matrix are exactly the same and false otherwise.
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>mat2 (m, vector<int> (n, 0));
        k = k % n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    mat2[i][(j - k + n) % n] = mat[i][j];
                }
                else {
                    mat2[i][(j + k) % n] = mat[i][j];
                }
            }
        }
        if (mat == mat2) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    int k = 2;
    cout << sol.areSimilar(mat, k) << endl;
    return 0;
}