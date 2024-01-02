#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(hash[nums[i]]>=ans.size()){
                ans.push_back({}); // inserting a new list if the freq of the element is more than existing ans vector
            }
            ans[hash[nums[i]]].push_back(nums[i]);
            hash[nums[i]]++;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,3,4,1,2,3,1};
    vector<vector<int>> ans=s.findMatrix(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    nums={1,2,3,4};
    ans=s.findMatrix(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}