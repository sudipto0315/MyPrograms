#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==0){
            return 0;
        }else if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        cout<<"The dp table: ";
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        cout<<"The maximum amount to rob is: ";
        return dp[n-1];
    }        
};
int main(){
    Solution s;
    vector<int>vec={1,2,3,1};
    cout<<s.rob(vec)<<endl;
    return 0;
}