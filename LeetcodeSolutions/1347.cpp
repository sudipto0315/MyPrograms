#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26,0);
        int ans=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            freq[t[i]-'a']--;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                ans+=freq[i];
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.minSteps("bab","aba")<<endl;
    cout<<s.minSteps("leetcode","practice")<<endl;
    cout<<s.minSteps("anagram","mangaar")<<endl;    
    return 0;
}