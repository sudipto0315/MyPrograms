#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > transpose(n, vector<int>(m,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
};
int main(){
    int m, n;
    cout << "Enter the dimensions Matrix:" << endl;
    cout << "Enter the no of Rows: ";
    cin >> m;
    cout << "Enter the no of Columns: ";
    cin >> n;
    vector<vector<int>> array(m, vector<int>(n, 0));
    cout << "Enter the Matrix:" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Enter the " << i << ", " << j << " element: ";
            cin >> array[i][j];
        }
    }
    Solution s;
    vector<vector<int>> transpose = s.transpose(array);
    cout << "Transpose of the Matrix:" << endl;
    for(int i = 0; i < transpose.size(); i++){
        for(int j = 0; j < transpose[0].size(); j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}