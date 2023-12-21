#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1){
            return true;
        }else if(n==0){
            return false;
        }else if(n<0){
            return false;
        }while(n>1){
            if(n%4!=0){
                return false;
            }else{
                n=n/4;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isPowerOfFour(16)<<endl;
    cout<<s.isPowerOfFour(5)<<endl;
    cout<<s.isPowerOfFour(1)<<endl;
    return 0;
}