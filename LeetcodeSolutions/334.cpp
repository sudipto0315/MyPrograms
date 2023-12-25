#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MAX;
        int second=INT_MAX;
        for (int i=0;i<n;i++) {
            if(nums[i]<=first) {
                // Update the smallest element
                first=nums[i];
            } else if(nums[i]<=second) {
                // Update the second smallest element
                second=nums[i];
            } else if(nums[i]>second){
                // We found a third element greater than both first and second
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.increasingTriplet(nums)<<endl;
    nums={5,4,3,2,1};
    cout<<s.increasingTriplet(nums)<<endl;
    nums={2,1,5,0,4,6};
    cout<<s.increasingTriplet(nums)<<endl;
    return 0;
}