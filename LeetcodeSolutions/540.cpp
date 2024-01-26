#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-2]!=nums[n-1]){
            return nums[n-1];
        }
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            // eliminate the left part
            if((mid%2==1&&nums[mid]==nums[mid-1])||(mid%2==0&&nums[mid]==nums[mid+1])){
                low=mid+1;
            }else{
                high=mid-1; // eliminate the right part
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    cout<<s.singleNonDuplicate(nums)<<endl;
    nums={3,3,7,7,10,11,11};
    cout<<s.singleNonDuplicate(nums)<<endl;
    return 0;
}