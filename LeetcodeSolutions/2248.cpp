#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int maxSize = 0;
        for(const auto& row:nums) {
            maxSize=max(maxSize,*max_element(row.begin(),row.end()));
        }
        vector<int>hash(maxSize + 1, 0);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                hash[nums[i][j]]++;
            }
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==nums.size()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>>nums={{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    vector<int>ans=s.intersection(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    nums={{1,2,3},{4,5,6}};
    ans=s.intersection(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}