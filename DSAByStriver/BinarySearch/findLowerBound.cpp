//ques: https://takeuforward.org/arrays/implement-lower-bound-bs-2/
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
    vector<int>nums={1,2,3,7,8,9,9,9,11};
    int target=9;
    sort(nums.begin(),nums.end());
    cout<<"The target has been found at "<<s.binarySearch(nums,target)<<endl;
    cout<<"The lower bound had been found at "<<s.findLowerBound(nums,target)<<endl;
    return 0;
}