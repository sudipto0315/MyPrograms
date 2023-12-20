#include<iostream>
using namespace std;
class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        else if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true;
        else return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        int low=0,high=n-1;
        while(low<high){
            bool isLowVowel=isVowel(s[low]);
            bool isHighVowel=isVowel(s[high]);
            if(isLowVowel&&isHighVowel){
                swap(s[low],s[high]);
                low++;high--;
            }
            else if(isLowVowel==false){
                low++;
            }
            else if(isHighVowel==false){
                high--;
            }
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.reverseVowels("hello")<<endl; // holle
    cout<<s.reverseVowels("leetcode")<<endl; // leotcede
    return 0;
}