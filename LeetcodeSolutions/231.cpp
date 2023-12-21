#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }else if(n%2!=0){
            return false;
        }else if(n==0){
            return false;
        }else{
            return isPowerOfTwo(n/2);
        }
    }
};
int main(){
    Solution s;
    cout<<s.isPowerOfTwo(1)<<endl;
    cout<<s.isPowerOfTwo(16)<<endl;
    cout<<s.isPowerOfTwo(3)<<endl;
    return 0;
}