// ques: https://takeuforward.org/data-structure/count-occurrences-in-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int lowerBound(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int countOccurences(vector<int>&nums,int target){
        int lower=lowerBound(nums,target);
        int upper=upperBound(nums,target);
        return upper-lower;
    }
};
int main(){
    Solution s;
    vector<int>nums={2,4,6,8,8,8,11,13};
    int target=8;
    cout<<s.countOccurences(nums,target)<<endl;
    cout<<s.lowerBound(nums,target)<<endl;
    cout<<s.upperBound(nums,target)<<endl;
    nums={1,1,2,2,2,2,2,3};
    target=2;
    cout<<s.countOccurences(nums,target)<<endl;
    return 0;
}