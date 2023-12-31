#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int length=-1;
        int n=s.length();
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++){
            if(hash.find(s[i])!=hash.end()){
                length=max(length,i-hash[s[i]]-1);
            }else{
                hash[s[i]]=i;
            }
        }
        return length;
    }
};
int main(){
    Solution s;
    cout<<s.maxLengthBetweenEqualCharacters("aa")<<endl;
    cout<<s.maxLengthBetweenEqualCharacters("abca")<<endl;
    cout<<s.maxLengthBetweenEqualCharacters("cbzxy")<<endl;
    return 0;
}