#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        vector<int>hash(26,0);
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    cout<<s.firstUniqChar("leetcode")<<endl;
    cout<<s.firstUniqChar("loveleetcode")<<endl;
    cout<<s.firstUniqChar("aabb")<<endl;
    return 0;
}