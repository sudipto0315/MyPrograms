// ques: https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int findNoOfRotations(vector<int>&nums){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){
                if(nums[low]<ans){
                    index=low;
                    ans=nums[low];
                }
                break;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<ans){
                    index=low;
                    ans=nums[low];
                }
                low=mid+1;
            }
            else{
                if(nums[mid]<ans){
                    index=mid;
                    ans=nums[mid];
                }
                high=mid-1;
            }
        }
        return index;
    }
};
int main(){
    Solution s;
    vector<int>nums={4,5,6,7,0,1,2,3};
    cout<<"The array is rotated "<<s.findNoOfRotations(nums)<<" times.\n"<<endl;
    return 0;
}