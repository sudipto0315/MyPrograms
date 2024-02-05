#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
class Solution {
public:
    int sumByDivisor(vector<int>&nums,int div){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)(nums[i])/(double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold){
            return -1;
        }
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        int low=1,high=max;
        while(low<=high){
            int mid=(low+high)/2;
            if(sumByDivisor(nums,mid)<=threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,2,5,9};
    cout<<s.smallestDivisor(nums,6)<<endl;
    nums={44,22,33,11,1};
    cout<<s.smallestDivisor(nums,5)<<endl;
    return 0;
}