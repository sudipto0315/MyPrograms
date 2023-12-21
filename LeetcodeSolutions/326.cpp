#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }else if(n==0){
            return false;
        }else if(n<0){
            return false;
        }while(n>1){
            if(n%3!=0){
                return false;
            }else{
                n=n/3;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isPowerOfThree(27)<<endl;
    cout<<s.isPowerOfThree(0)<<endl;
    cout<<s.isPowerOfThree(-1)<<endl;
    return 0;
}