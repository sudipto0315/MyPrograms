// https://www.codingninjas.com/studio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<iostream>
#include<vector>
using namespace std;
int f(int ind,vector<int>&nums,vector<int>&dp)
{
    if (ind==0) return nums[ind];
    if (ind<0) return 0;
    if (dp[ind]!=-1) return dp[ind];
    int pick = nums[ind]+f(ind-2,nums,dp);    
    int notpick = 0+f(ind-1,nums,dp);
    return dp[ind] = max(pick,notpick);    
}
int maxNonAdjacentSum(vector<int>&nums)
{
    int n = nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}
int houseRober(vector<int>& valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for (int i = 0; i < n; i++)
    {
        if (i != 0) temp1.push_back(valueInHouse[i]);
        if (i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maxNonAdjacentSum(temp1),maxNonAdjacentSum(temp2));
}
int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the value of n: ";
    cin>>size;
    vector<int> arr;
    for (int i = 0; i < size; i++) 
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    cout<<"The entered array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"Ans: "<<houseRober(arr);
    cout<<endl;
    return 0;
}
