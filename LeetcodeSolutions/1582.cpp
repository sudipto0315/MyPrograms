#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int specialCount=0;
        for(int i = 0; i <mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]==1){
                    int rowSun = 0;
                    int columnSum = 0;
                    for (int k = 0; k < mat.size(); k++){
                        rowSun += mat[k][j];
                    }
                    for (int k = 0; k < mat[0].size(); k++){
                        columnSum += mat[i][k];
                    }
                    if (rowSun == 1 && columnSum == 1){
                        specialCount++;
                    }
                }
            }
        }
        return specialCount;
    }
};
int main() {
    Solution s;
    vector<vector<int>> mat1 = {{1,0,0},{0,0,1},{1,0,0}};
    cout << s.numSpecial(mat1) << endl;
    vector<vector<int>> mat2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << s.numSpecial(mat2) << endl;
    return 0;
}