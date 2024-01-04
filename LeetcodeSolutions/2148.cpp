#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
        int min=INT_MAX;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
            }
            if(nums[i]<min){
                min=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if((nums[i]>min)&&(nums[i]<max)){
                count++;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int>nums={11,7,2,15};
    cout<<s.countElements(nums)<<endl;
    nums={-3,3,3,90};
    cout<<s.countElements(nums)<<endl;
    return 0;
}