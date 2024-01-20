#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int maxProductSubArray(vector<int>&nums){
        int n=nums.size();
        int pre=1;
        int suff=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        return maxProductSubArray(nums);
    }
};
int main(){
    Solution s;
    vector<int>nums={2,3,-2,4};
    cout<<s.maxProduct(nums)<<endl;
    nums={-2,0,-1};
    cout<<s.maxProduct(nums)<<endl;
    return 0;
}