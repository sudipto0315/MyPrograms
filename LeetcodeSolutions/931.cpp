#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int minValue=INT_MAX;
                minValue=min(minValue,dp[i-1][j]);
                if(j-1>=0){
                    minValue=min(minValue,dp[i-1][j-1]);
                }
                if(j+1<m){
                    minValue=min(minValue,dp[i-1][j+1]);
                }
                dp[i][j]=minValue+matrix[i][j];
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};
int main(){
    vector<vector<int>>matrix={{2,1,3},{6,5,4},{7,8,9}};
    Solution s;
    cout<<s.minFallingPathSum(matrix)<<endl;
    matrix={{-19,57},{-40,-5}};
    cout<<s.minFallingPathSum(matrix)<<endl;
    return 0;
}