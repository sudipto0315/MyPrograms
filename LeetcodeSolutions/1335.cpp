#include<iostream>
#include<vector>
#include<climits>
#include <cstring>
#include<algorithm>
using namespace std;
class Solution {
public:
    int dp[301][11];
    int solve(vector<int>&jobDifficulty,int n,int i,int d){
        if(d==1){
            return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
        }
        if(dp[i][d]!=-1){
            return dp[i][d];
        }
        int ans=INT_MAX;
        int currD=INT_MIN;
        for(int j=i;j<=n-d;j++){
            currD=max(currD,jobDifficulty[j]);
            ans=min(ans,currD+solve(jobDifficulty,n,j+1,d-1));
        }
        dp[i][d]=ans;
        return dp[i][d];

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp,-1,sizeof(dp));
        int n=jobDifficulty.size();
        if(n<d){
            return -1;
        }
        return solve(jobDifficulty,n,0,d); // jobDifficulty vector, size of jobDifficulty, starting index, days
    }
};

int main(){
    Solution s;
    vector<int> jobDifficulty={6,5,4,3,2,1};
    int d=2;
    cout<<s.minDifficulty(jobDifficulty,d)<<endl;
    jobDifficulty={9,9,9};
    d=4;
    cout<<s.minDifficulty(jobDifficulty,d)<<endl;
    jobDifficulty={1,1,1};
    d=3;
    cout<<s.minDifficulty(jobDifficulty,d)<<endl;
    return 0;
}