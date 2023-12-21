#include<iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long num=n;
        double ans=1.0;
        if(num<0){
            x=1.0/x;
            num=-num;
        }
        while(num>0){
            if(num%2==0){
                num=num/2;
                x=x*x;
            }else{
                num=num-1;
                ans=ans*x;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.myPow(2.00000,10)<<endl;
    cout<<s.myPow(2.10000,3)<<endl;
    cout<<s.myPow(2.00000,-2)<<endl;
    return 0;
}