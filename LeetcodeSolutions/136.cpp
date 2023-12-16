#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans = ans^nums[i]; //Bitwise XOR 
        }
        // reason 
        // A^A=0
        // A^B^A=B
        // (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
        // Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums1={4,1,2,1,2};
    cout<<s.singleNumber(nums1)<<endl;
    vector<int> nums2={2,2,1};
    cout<<s.singleNumber(nums2)<<endl;
    vector<int> nums3={1};
    cout<<s.singleNumber(nums3)<<endl;
    return 0;
}