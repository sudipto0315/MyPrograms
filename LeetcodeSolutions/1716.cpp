#include <iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int monday = 1;
        int total = 0;
        while(n != 0){
            for(int i = 0; i < 7 && n > 0; i++){
                total += monday + i;
                n--;
            }
            monday++;
        }
        return total;
    }
};
int main(){
    Solution s;
    cout << s.totalMoney(4) << endl;
    cout << s.totalMoney(10) << endl;
    cout << s.totalMoney(20) << endl;
    return 0;
}