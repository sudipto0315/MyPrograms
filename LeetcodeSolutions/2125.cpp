#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int ans=0;
        for(string s:bank){
            int count=0;
            for(char c:s){
                if(c=='1'){
                    count++;
                }
            }
            if(count!=0){
                ans+=(prev*count);
                prev=count;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> bank={"011001","000000","010100","001000"};
    cout<<s.numberOfBeams(bank)<<endl;
    bank={"000","111","000"};
    cout<<s.numberOfBeams(bank)<<endl;
    return 0;
}