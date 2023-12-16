#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        vector<int> vis_s(26,0);
        vector<int> vis_t(26,0);
        for(int i=0;i<n;i++){
            vis_s[s[i]-'a']++;
            vis_t[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(vis_s[i]!=vis_t[i]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    string s1="anagram";
    string s2="nagaram";
    cout<<s.isAnagram(s1,s2)<<endl;
    string s3="rat";
    string s4="car";
    cout<<s.isAnagram(s3,s4)<<endl;
    return 0;
}