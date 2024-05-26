#include<iostream>
using namespace std;
class Solution {
public:
    bool palindrome(string st){
        int low=0;
        int high=st.length()-1;
        while(low<=high){
            if(st[low]!=st[high]){
                return false;
            }else{
                low++;
                high--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string str=s.substr(i,j-i+1);
                bool check=palindrome(str);
                if(check && str.length()>ans.length()){
                    ans=str;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str="abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
    cout<<s.longestPalindrome(str)<<endl;
    return 0;
}