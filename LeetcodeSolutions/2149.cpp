#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>negetive;
        vector<int>positive;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }else{
                negetive.push_back(nums[i]);
            }
        }
        for(int i=0;i<positive.size();i++){
            nums[2*i]=positive[i];
        }
        for(int i=0;i<negetive.size();i++){
            nums[2*i+1]=negetive[i];
        }
        return nums;
    }
};
int main(){
    Solution s;
    vector<int>nums={3,1,-2,-5,2,-4};
    vector<int>ans=s.rearrangeArray(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    nums={-1,1};
    ans=s.rearrangeArray(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}