#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        if(n==1){
            return true;
        }
        vector<int> freq(26,0);
        for(string s:words){
            for(char c:s){
                freq[c-'a']++;
            }
        }
        for(int f:freq){
            if(f%n!=0){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<string> words={"abc","aabc","bc"};
    cout<<s.makeEqual(words)<<endl;
    words={"ab","a"};
    cout<<s.makeEqual(words)<<endl;
    return 0;
}