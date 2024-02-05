#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>dp;
    int n,k;
    int solve(int id, vector<int>&arr){
        if(id>=n){
            return 0;
        }
        if(dp[id]!=-1){
            return dp[id];
        }
        int maxVal=0;
        int ans=0;
        for(int i=id;i<min(n,id+k);i++){
            maxVal=max(maxVal,arr[i]);
            ans=max(ans,(i-id+1)*maxVal+solve(i+1,arr));
        }
        return dp[id]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        this->k=k;
        dp=vector<int>(n,-1);
        return solve(0,arr);
    }
};
int main(){
    Solution s;
    vector<int>arr={1,15,7,9,2,5,10};
    cout<<s.maxSumAfterPartitioning(arr,3)<<endl;
    arr={1,4,1,5,7,3,6,1,9,9,3};
    cout<<s.maxSumAfterPartitioning(arr,4)<<endl;
    arr={1};
    cout<<s.maxSumAfterPartitioning(arr,1)<<endl;
    return 0;
}