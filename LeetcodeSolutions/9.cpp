#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long long int rev = 0;
        long long int temp = x;
        while (temp != 0){
            long long int d = temp % 10;
            rev = rev * 10 + d;
            temp /= 10;
        }
        if (rev == x)
            return true;
        else
            return false;
    }
};
int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
    return 0;
}