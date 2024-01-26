#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        vector<int>ans;
        int duplicate=0;
        int missing=0;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=1;i<hash.size();i++){
            if(hash[i]==2){
                duplicate=i;
            }
            if(hash[i]==0){
                missing=i;
            }
        }
        ans.push_back(duplicate);
        ans.push_back(missing);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,2,2,4};
    vector<int>ans=s.findErrorNums(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    nums={1,1};
    ans=s.findErrorNums(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}