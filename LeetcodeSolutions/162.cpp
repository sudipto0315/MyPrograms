#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int peakElement(vector<int>&nums,int left,int right){
        if(left==right){
            return left;
        }
        int mid=(left+right)/2;
        if(nums[mid]<nums[mid+1]){
            return peakElement(nums,mid+1,right);
        }else{
            return peakElement(nums,left,mid);
        }
    }
    int findPeakElement(vector<int>& nums) {
        return peakElement(nums,0,nums.size()-1);
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,1};
    cout<<s.findPeakElement(nums)<<endl;
    nums={1,2,1,3,5,6,4};
    cout<<s.findPeakElement(nums)<<endl;
    return 0;
}