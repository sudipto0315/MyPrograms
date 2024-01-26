#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
class Solution {
public:
    vector<vector<vector<int>>>dp;
    int m,n;
    int solve(int i,int j,int remMove){
        if(i==m||j==n||i<0||j<0){
            return 1;
        }
        if(remMove==0) return 0;
        if(dp[i][j][remMove]!=-1){
            return dp[i][j][remMove];
        }
        return dp[i][j][remMove]=((solve(i+1,j,remMove-1)
        +solve(i-1,j,remMove-1))%mod
        +(solve(i,j+1,remMove-1)
        +solve(i,j-1,remMove-1))%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m=m;
        this->n=n;
        dp=vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove);
    }
};
int main(){
    Solution s;
    cout<<s.findPaths(2,2,2,0,0)<<endl;
    cout<<s.findPaths(1,3,3,0,1)<<endl;
    return 0;
}