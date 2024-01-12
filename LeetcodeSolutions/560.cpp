#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        map[0]=1;
        int count=0;
        int prefix_sum=0;
        for(int i=0;i<nums.size();i++){
            prefix_sum+=nums[i];
            int remove=prefix_sum-k;
            count+=map[remove];
            map[prefix_sum]++;
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,1,1};
    cout<<s.subarraySum(nums,2)<<endl;
    nums={1,2,3};
    cout<<s.subarraySum(nums,3)<<endl;
    return 0;
}