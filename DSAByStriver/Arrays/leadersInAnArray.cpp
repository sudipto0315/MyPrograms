#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int>printLeaders(vector<int>&nums){
        int n=nums.size();
        vector<int>ans;
        int max=nums[n-1];
        ans.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>max){
                ans.push_back(nums[i]);
                max=nums[i];
            }
        }
        return ans;
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
    vector<int>ans=s.printLeaders(nums);
    cout << "Leaders are: ";
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
    cout<<endl;
    return 0;
}

