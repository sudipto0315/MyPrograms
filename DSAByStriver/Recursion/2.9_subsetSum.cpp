#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    void func(int index,int sum,vector<int>&arr,int n,vector<int>&subset){
        if(index==n){
            subset.push_back(sum);
            return;
        }
        //pick
        func(index+1,sum+arr[index],arr,n,subset);
        //not-pick
        func(index+1,sum,arr,n,subset);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>subset;
        func(0,0,arr,n,subset);
        sort(subset.begin(),subset.end());
        return subset;
    }
};
int main(){
    Solution s;
    vector<int>arr={2,3};
    int n=2;
    vector<int>ans=s.subsetSums(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}