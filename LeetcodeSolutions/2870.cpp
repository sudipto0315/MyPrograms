#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMax(vector<int>& nums){
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        return max;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        int max=findMax(nums);
        int count=0;
        vector<int>freq(max+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==1){
                return -1;
            }
            if(freq[i]%3==0){
                count+=freq[i]/3;
            }else{
                count+=(freq[i]/3)+1;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int>nums={2,3,3,2,2,4,2,3,4};
    cout<<s.minOperations(nums)<<endl;
    nums={2,1,2,2,3,3};
    cout<<s.minOperations(nums)<<endl;
    return 0;
}