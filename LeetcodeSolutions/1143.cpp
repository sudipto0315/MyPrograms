#include<iostream>
#include<vector>
using namespace std;
// tabulation approach
class Solution {
public:
    int lcs(string text1,string text2){
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    int ans1=dp[i-1][j];
                    int ans2=dp[i][j-1];
                    dp[i][j]=max(ans1,ans2);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return lcs(text1,text2);
    }
};
int main(){
    Solution s;
    string text1="abcde";
    string text2="ace";
    cout<<s.longestCommonSubsequence(text1,text2)<<endl;
    text1="abc";
    text2="abc";
    cout<<s.longestCommonSubsequence(text1,text2)<<endl;
    text1="abc";
    text2="def";
    cout<<s.longestCommonSubsequence(text1,text2)<<endl;
    return 0;
}