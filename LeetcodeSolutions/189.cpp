#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverse(vector<int>&nums,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums,0,nums.size()-1); // rotate the full array
        reverse(nums,0,k-1); // rotate the first part of the array before kth position
        reverse(nums,k,nums.size()-1); // rotate the first part of the array after kth position
    }
};
int main(){
    Solution s;
    vector<int>nums={1,2,3,4,5,6,7};
    s.rotate(nums,3);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    nums={-1,-100,3,99};
    s.rotate(nums,2);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}