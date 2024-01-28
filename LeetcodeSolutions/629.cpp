#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
class Solution {
public:
    vector<int>dp;
    vector<int>prevDp;
    int kInversePairs(int n, int k) {
        dp=vector<int>(k+1,0);
        prevDp=vector<int>(k+1,0);
        prevDp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    dp[j]=prevDp[j]=1;
                    continue;
                }
                dp[j]=(prevDp[j]+dp[j-1])%mod;
                if(j>=i){
                    dp[j]=(dp[j]-prevDp[j-i]+mod)%mod;
                }
            }
            prevDp=dp;
        }
        return dp[k];
    }
};
int main(){
    Solution s;
    cout<<s.kInversePairs(3,0)<<endl;
    cout<<s.kInversePairs(3,1)<<endl;
    return 0;
}