#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        sort(nums.begin(),nums.end());
        set<vector<int>>set;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target){
                    set.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
                }else if(sum<target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        for(auto triplets:set){
            ans.push_back(triplets);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=s.threeSum(nums);
    for(auto triplets:ans){
        for(auto element:triplets){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    nums={0,1,1};
    ans=s.threeSum(nums);
    for(auto triplets:ans){
        for(auto element:triplets){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    nums={0,0,0};
    ans=s.threeSum(nums);
    for(auto triplets:ans){
        for(auto element:triplets){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}