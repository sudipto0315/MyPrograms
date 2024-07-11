#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    int longestSubarrayWithSumZero(vector<int>&nums){
        int n=nums.size();
        int maxLen=0;
        unordered_map<int,int>map;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                maxLen=i+1;
            }else if(map.find(sum)!=map.end()){
                maxLen=max(maxLen,i-map[sum]);
            }else{
                map[sum]=i;
            }
        }
        return maxLen;
    }
};
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    int ans=s.longestSubarrayWithSumZero(nums);
    cout<<"SOLUTION: ";
    cout<<ans;
    cout<<endl;
    return 0;
}