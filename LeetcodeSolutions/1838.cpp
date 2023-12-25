#include<iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int maxFreq=0,l=0,r=0,total=0;
        for(r=0;r<nums.size();r++){
            total+=nums[r];
            while(l+1<=r && (nums[r]*(r-l+1))>total+k){
                total-=nums[l];
                l++;
            }
            maxFreq=max(maxFreq,r-l+1);
        }
        return maxFreq;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,4};
    int k=5;
    cout<<s.maxFrequency(nums,k)<<endl;
    nums={1,4,8,13};
    k=5;
    cout<<s.maxFrequency(nums,k)<<endl;
    nums={3,9,6};
    k=2;
    cout<<s.maxFrequency(nums,k)<<endl;
    nums={1,5,3,7};
    k=2;
    cout<<s.maxFrequency(nums,k)<<endl;
    return 0;
}