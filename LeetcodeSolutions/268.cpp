#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int i;
        for(i=0;i<n;i++){
            if(hash[i]==0){
                break;
            }
        }
        return i;
    }
};
int main(){
    Solution s;
    vector<int> nums={3,0,1};
    cout<<s.missingNumber(nums)<<endl;
    vector<int> nums1={0,1};
    cout<<s.missingNumber(nums1)<<endl;
    nums={9,6,4,2,3,5,7,0,1};
    cout<<s.missingNumber(nums)<<endl;
    return 0;
}