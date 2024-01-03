#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMax(int num){
        int maxDigit=0;
        while(num>0){
            int digit=num%10;
            maxDigit=max(maxDigit,digit);
            num=num/10;
        }
        return maxDigit;
    }
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int sum=-1;
        for(int i=0;i<n;i++){
            int max1=findMax(nums[i]);
            for(int j=i+1;j<n;j++){
                int max2=findMax(nums[j]);
                if(max1==max2){
                    sum=max(sum,nums[i]+nums[j]);
                }
            }
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int> nums={51,71,17,24,42};
    cout<<s.maxSum(nums)<<endl;
    nums={1,2,3,4};
    cout<<s.maxSum(nums)<<endl;
    return 0;
}