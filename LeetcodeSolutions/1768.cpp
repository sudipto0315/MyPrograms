#include<iostream>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        string merged="";
        int i=0,j=0;
        while(i<n && j<m){
            merged+=word1[i];
            merged+=word2[j];
            i++;
            j++;
        }
        while(i<n){
            merged+=word1[i];
            i++;
        }
        while(j<m){
            merged+=word2[j];
            j++;
        }
        return merged;
    }
};
int main(){
    Solution s;
    cout<<s.mergeAlternately("abc","pqr");
}