#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int diceIndex,int remTarget,int n,int k){
        if(diceIndex==n){
            return (remTarget==0);
        }
        if(remTarget<0){
            return 0;
        }
        if(dp[diceIndex][remTarget]!=-1){
            return dp[diceIndex][remTarget];
        }
        int ans=0;
        for(int face=1;face<=k;face++){
            ans=(ans+solve(diceIndex+1,remTarget-face,n,k))%mod;
        }
        return dp[diceIndex][remTarget]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(0,target,n,k);
    }
};
int main(){
    Solution s;
    cout<<s.numRollsToTarget(1,6,3)<<endl;
    cout<<s.numRollsToTarget(2,6,7)<<endl;
    cout<<s.numRollsToTarget(30,30,500)<<endl;
    return 0;
}