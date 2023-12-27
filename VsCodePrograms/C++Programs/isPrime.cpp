#include<iostream>
using namespace std;
class Solution{
public:
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i*i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isPrime(5)<<endl;
    cout<<s.isPrime(6)<<endl;
    return 0;
} 