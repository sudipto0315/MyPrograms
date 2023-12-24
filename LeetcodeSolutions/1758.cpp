#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int alternateOne=0;
        int alternateZero=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]=='0'){
                    alternateOne++;
                }else{
                    alternateZero++;
                }
            }else{
                if(s[i]=='1'){
                    alternateOne++;
                }else{
                    alternateZero++;
                }
            }
        }
        return min(alternateZero, alternateOne);
    }
};
int main(){
    Solution s;
    cout<<s.minOperations("0100")<<endl;
    cout<<s.minOperations("10")<<endl;
    cout<<s.minOperations("1111")<<endl;
    return 0;
}