#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int>hmap;
    for(int i=0;i<n;i++){
        hmap[nums[i]]++;
    }
    for(auto it:hmap){
        cout<<it.first<<" : "<<it.second<<endl;
    }
    return 0;
}