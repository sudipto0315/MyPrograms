#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int longestSubarrayWithSumK(vector<int>&nums, long long k){
        int n=nums.size();
        int left=0;
        int right=0;
        int maxLen=0;
        long long sum=nums[0];
        while(right<n){
            while(left<=right&&sum>k){
                sum-=nums[left];
                left++;
            }
            if(sum==k){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
            if(right<n){
                sum+=nums[right];
            }
        }
        return maxLen;
    }
};
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    Solution s;
    cout<<s.longestSubarrayWithSumK(nums,k)<<endl;
    return 0;
}

