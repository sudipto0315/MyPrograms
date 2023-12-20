#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long int rev = 0;
        long long int temp = x;
        while (temp != 0){
            if(rev>INT_MAX/10||rev<INT_MIN/10){
                return 0;
            }
            long long int d = temp % 10;
            rev = rev * 10 + d;
            temp /= 10;
        }
        return rev;
    }
};
int main(){
    Solution s;
    cout<<s.reverse(123)<<endl; // 321
    cout<<s.reverse(-123)<<endl; // -321
    cout<<s.reverse(120)<<endl; // 21
    return 0;
}