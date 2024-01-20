#include <iostream>
#include <vector> 
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                high=mid-1;
                ans=mid;
            }else if(nums[mid]<target){
                low=mid+1;
            }
        }
        return ans;
    }
}; 
int main(){
    Solution s;
    vector<int> nums={1,3,5,6};
    cout<<s.searchInsert(nums,5)<<endl;
    cout<<s.searchInsert(nums,2)<<endl;
    cout<<s.searchInsert(nums,7)<<endl;
    return 0;
}
