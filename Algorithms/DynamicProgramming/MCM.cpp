#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int funRecursive(vector<int> &a,int s,int e,vector<vector<int>>dp){
    // cout<<"process at s:"<<s<<"e:"<<e<<endl;
    if(dp[s][e]!=-1) return dp[s][e];
    if(s==e||e-s==1) return 0;
    int mini=INT_MAX;
    for(int k=s+1;k<e;k++){
      int left=funRecursive(a,s,k,dp);
      int right=funRecursive(a,k,e,dp);
      int combine=a[s]*a[k]*a[e];
      int ans=left+right+combine;
      if(mini>ans) mini=ans;
    }
    return dp[s][e]=mini;
}

int fun2Iterative(vector<int>&a,int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    int min2=INT_MAX;
    for(int s=n-3;s>=0;s--){
        for(int e=s+2;e<n;e++){
            int min1=INT_MAX;
            for(int k=s+1;k<e;k++){
                int left=dp[s][k];
                int right=dp[k][e];
                int combo=a[s]*a[k]*a[e];
                int res=left+right+combo;
                if(min1>res) min1=res;
            }
              dp[s][e]=min1;
            // if(min1<min2) min2=min1;
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<endl;
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    // }
    return dp[0][n-1];
}


int matrixMultiplication(vector<int> &arr, int N) {
    // Write your code here.
     vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    
    // return fun(arr,0,N-1,dp) ;
    return fun2Iterative(arr,N);

}

int main(){
    int N;
    cin>>N;
    vector<int> a(N,0);
    for(int i=0;i<N;i++){
      cin>>a[i];
    }

    cout<<"ans:"<<matrixMultiplication(a,N);
}

