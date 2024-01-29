#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=1;j<col;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int colStart=0;colStart<col;colStart++){
            for(int colEnd=colStart;colEnd<col;colEnd++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int curSum=0;
                for(int rowVal=0;rowVal<row;rowVal++){
                    curSum=curSum+matrix[rowVal][colEnd]-(colStart? matrix[rowVal][colStart-1]:0);
                    ans=ans+mp[curSum-target];
                    mp[curSum]++;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>>matrix={{0,1,0},{1,1,1},{0,1,0}};
    int target=0;
    cout<<s.numSubmatrixSumTarget(matrix,target)<<endl;
    matrix={{1,-1},{-1,1}};
    target=0;
    cout<<s.numSubmatrixSumTarget(matrix,target)<<endl;
    matrix={{904}};
    target=0;
    cout<<s.numSubmatrixSumTarget(matrix,target)<<endl;
    return 0;
}