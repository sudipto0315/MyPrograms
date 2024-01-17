#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        unordered_set<int>set;
        for(auto it:freq){
            set.insert(it.second);
        }
        if(freq.size()!=set.size()){
            return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<int>arr={1,2,2,1,1,3};
    cout<<s.uniqueOccurrences(arr)<<endl;
    arr={1,2};
    cout<<s.uniqueOccurrences(arr)<<endl;
    arr={-3,0,1,-3,1,1,1,-3,10,0};
    cout<<s.uniqueOccurrences(arr)<<endl;
    return 0;
}