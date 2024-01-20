#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
int main(){
    Solution s;
    vector<int>nums={3,2,1,5,6,4};
    cout<<s.findKthLargest(nums,2)<<endl;
    nums={3,2,3,1,2,4,5,5,6};
    cout<<s.findKthLargest(nums,4)<<endl;
    return 0;
}