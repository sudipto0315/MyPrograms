#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int l=0;
        int r=n-1;
        while(l<r){
            if(nums[l]+nums[r]==k){
                count++;
                l++;
                r--;
            }else if(nums[l]+nums[r]>k){
                r--;
            }else{
                l++;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    int k=5;
    cout<<s.maxOperations(nums,k)<<endl;
    nums={3,1,3,4,3};
    k=6;
    cout<<s.maxOperations(nums,k)<<endl;
    return 0;
}