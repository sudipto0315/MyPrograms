#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void prefixSuffixSum(int n){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i+1; // or any other logic to fill the nums array
        }
        vector<int>prefSum(n,0);
        vector<int>suffSum(n,0);
        prefSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefSum[i]=prefSum[i-1]+nums[i];
        }
        suffSum[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffSum[i]=suffSum[i+1]+nums[i];
        }
        for(int i=0;i<suffSum.size();i++){
            cout<<suffSum[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<prefSum.size();i++){
            cout<<prefSum[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    s.prefixSuffixSum(8);
    return 0;
}