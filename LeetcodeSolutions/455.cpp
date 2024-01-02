#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int i=0;
        while(i<m && count<n){
            if(g[count]<=s[i]){
                count++;
            }
            i++;
        }
        return count;
    }
};
int main(){
    Solution sol;
    vector<int> g={1,2,3};
    vector<int> s={1,1};
    cout<<sol.findContentChildren(g,s)<<endl;
    vector<int> g1={1,2};
    vector<int> s1={1,2,3};
    cout<<sol.findContentChildren(g1,s1)<<endl;
    return 0;
}