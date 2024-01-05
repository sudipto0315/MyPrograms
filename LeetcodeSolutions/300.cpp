#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxLength=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLength=max(maxLength,dp[i]);
                }
            }
        }
        return maxLength;
    }
};
int main(){
    Solution s;
    vector<int>nums={10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(nums)<<endl;
    nums={0,1,0,3,2,3};
    cout<<s.lengthOfLIS(nums)<<endl;
    nums={7,7,7,7,7,7,7};
    cout<<s.lengthOfLIS(nums)<<endl;
    return 0;
}