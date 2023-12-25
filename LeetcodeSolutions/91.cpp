#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int,int>dp; // Recursive + Memoization (Top-Down Approach)
    int solve(int i,string &s){
        if(s[i]=='0'){
            return 0;
        }
        if(i>=s.length()-1){
            return 1;
        }
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        // The line if(dp.find(i)!=dp.end()) is checking if a value for the 
        // key i already exists in the map dp. The find function is a method 
        // provided by the map data structure in C++ to look for a key. If the 
        // key is found, find returns an iterator pointing to the key-value pair. 
        // If the key is not found, find returns an iterator pointing to the end 
        // of the map, denoted by dp.end().
        int ans=solve(i+1,s);
        if(stoi(s.substr(i,2))<=26){
            ans+=solve(i+2,s);
        }
        return dp[i]=ans;
        // The line dp[i]=ans is storing the value of ans in the map dp for the key i. 
    }
    int numDecodings(string s) {
        return solve(0,s);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)
// Code for the bottom-up approach And Space Optimized Approach is submitted in the leetcode submission link attached below.
// https://leetcode.com/problems/decode-ways/submissions/

int main(){
    Solution s;
    cout<<s.numDecodings("1226")<<endl;
    cout<<"The dp map of the above example: \n";
    for(auto it=s.dp.begin();it!=s.dp.end();it++){
        cout<<it->first<<" -> "<<it->second<<endl;
    }
    cout<<"Some other test cases: \n";
    cout<<s.numDecodings("12")<<endl;
    cout<<s.numDecodings("226")<<endl;
    cout<<s.numDecodings("06")<<endl;
    // print the dp map
    return 0;
}