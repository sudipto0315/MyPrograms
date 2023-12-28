#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        string str;
        int cnt=1;
        for(int i=1;i<=n;i++){
            if(i==n||chars[i]!=chars[i-1]){
                str+=chars[i-1];
                if(cnt>1){
                    str+=to_string(cnt);
                }
                cnt=1; // reset the count
            }else{
                cnt+=1;
            }
        }
        chars.clear(); // clear the vector
        for(char ch : str){
            chars.push_back(ch);
        }
        return str.length();
    }
};
int main(){
    Solution s;
    vector<char> chars1={'a','a','b','b','c','c','c'};
    cout<<s.compress(chars1)<<endl;
    vector<char> chars2={'a'};
    cout<<s.compress(chars2)<<endl;
    vector<char> chars3={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout<<s.compress(chars3)<<endl;
    return 0;
}