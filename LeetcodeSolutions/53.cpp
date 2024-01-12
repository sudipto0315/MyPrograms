#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
    }
};
int main(){
    Solution s;
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(nums)<<endl;
    nums={1};
    cout<<s.maxSubArray(nums)<<endl;
    nums={5,4,-1,7,8};
    cout<<s.maxSubArray(nums)<<endl;
    return 0;
}