#include<iostream>
using namespace std;
class Solution {
public:
    int countVowels(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int mid=n/2;
        string s1;
        string s2;
        for(int i=0;i<mid;i++){
            s1+=s[i];
        }
        cout<<s1<<endl;
        for(int i=mid;i<n;i++){
            s2+=s[i];
        }
        cout<<s2<<endl;
        int count1=countVowels(s1);
        int count2=countVowels(s2);
        if(count1==count2){
            return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    string str="book";
    cout<<s.halvesAreAlike(str)<<endl;
    str="textbook";
    cout<<s.halvesAreAlike(str)<<endl;
    return 0;
}