#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Transpose
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Reverse columns
        for (int i = 0; i < m; i++) {
            int start = 0, end = n - 1;
            while (start < end) {
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;
            }
        }
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix1);
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> matrix2 = {{5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
    s.rotate(matrix2);
    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> matrix3 = {{1}};
    s.rotate(matrix3);
    for (int i = 0; i < matrix3.size(); i++)
    {
        for (int j = 0; j < matrix3[0].size(); j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> matrix4 = {{1,2},{3,4}};
    s.rotate(matrix4);
    for (int i = 0; i < matrix4.size(); i++)
    {
        for (int j = 0; j < matrix4[0].size(); j++)
        {
            cout << matrix4[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}