#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int>findReaptingAndMissing(vector<int>&nums){
        int n=nums.size();
        int repeating=0;
        int missing=0;
        vector<int>hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        cout<<"The hash table is: ";
        for (int i=0;i<hash.size();i++)
        {
            cout<<hash[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            if(hash[i]>1){
                repeating=i;
            }
            else if(hash[i]==0){
                missing=i;
            }
        }
        return {repeating,missing};
    }
};
int main(){
    Solution s;
    vector<int>vec={3,1,2,5,3};
    vector<int>ans=s.findReaptingAndMissing(vec);
    cout<<"The repeating and missing numbers are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}