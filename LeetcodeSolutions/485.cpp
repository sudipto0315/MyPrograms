#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
    nums={1,0,1,1,0,1};
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}