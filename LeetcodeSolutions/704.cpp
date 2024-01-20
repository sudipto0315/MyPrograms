#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target);
    }
};
int main(){
    Solution s;
    vector<int>nums={-1,0,3,5,9,12};
    cout<<s.search(nums,9)<<endl;
    cout<<s.search(nums,2)<<endl;
    return 0;
}