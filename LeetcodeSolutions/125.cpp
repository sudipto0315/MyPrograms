#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                s1+=tolower(s[i]);
            }
        }
        int n=s1.length();
        for(int i=0;i<n/2;i++){
            if(s1[i]!=s1[n-i-1]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<s.isPalindrome("race a car")<<endl;
    cout<<s.isPalindrome(" ")<<endl;
    return 0;
}