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
    for(int i=0;i<n;i++){
        if(nums[i]>max){
            max=nums[i];
        }
    }
    cout<<"The max element is: "<<max<<endl;
}