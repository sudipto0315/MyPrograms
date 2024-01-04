#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                count++;
            }
        }
        if(nums[0]<nums[n-1]){
            count++;
        }
        if(count>1){
            return false;
        }else{
            return true;
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={3,4,5,1,2};
    cout<<s.check(nums)<<endl;
    nums={2,1,3,4};
    cout<<s.check(nums)<<endl;
    nums={1,2,3};
    cout<<s.check(nums)<<endl;
    return 0;
}