// ques: https://takeuforward.org/arrays/floor-and-ceil-in-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int findFloor(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<=target){
                ans=nums[mid];
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int findCeil(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=nums[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={3,4,4,7,8,10};
    int target=5;
    cout<<s.findFloor(nums,target)<<" "<<s.findCeil(nums,target)<<endl;
    nums={3,4,4,7,8,10};
    target=8;
    cout<<s.findFloor(nums,target)<<" "<<s.findCeil(nums,target)<<endl;
    return 0;
}