// https://takeuforward.org/arrays/search-insert-position/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    int binarySearch(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int result=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                result=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }
        }
        return result;
    }
    //smallest index such that nums[i]>=x
    int findLowerBound(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int result=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
};  
int main(){
    Solution s;
    vector<int>nums={1,2,4,7};
    int target=6;
    sort(nums.begin(),nums.end());
    cout<<"The target has been found at "<<s.binarySearch(nums,target)<<endl;
    cout<<"The element should be inserted at "<<s.findLowerBound(nums,target)<<endl;
    return 0;
}