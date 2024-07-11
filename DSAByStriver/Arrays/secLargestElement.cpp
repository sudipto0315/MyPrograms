#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int max=INT_MIN;
    int secMax=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]>max){
            secMax=max;
            max=nums[i];
        }
        else if(nums[i]>secMax && nums[i]!=max){
            secMax=nums[i];
        }
    }

    cout<<"The max element is: "<<max<<endl;
    cout<<"The Second Max element is: "<<secMax<<endl;
}