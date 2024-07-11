#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void findSubsets(vector<int>&nums,vector<vector<int>>&ans,vector<int>&subset,int index,int sum,int k){
        if(index==nums.size()){
            if(sum==k){
                ans.push_back(subset);
            }
            return;
        }
        subset.push_back(nums[index]);
        sum+=nums[index];
        findSubsets(nums,ans,subset,index+1,sum,k);
        subset.pop_back();
        sum-=nums[index];
        findSubsets(nums,ans,subset,index+1,sum,k);
    }
    vector<vector<int>> subsequencesSumsToK(vector<int>& nums,int k) {
        vector<vector<int>>ans;
        vector<int>subset;
        findSubsets(nums,ans,subset,0,0,k);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,2,1};
    vector<vector<int>>ans=s.subsequencesSumsToK(nums,2);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}