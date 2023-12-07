#include <iostream>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i = n - 1; // i is the index of the last digit
        while(i >= 0){
            if((num[i] - '0') % 2 == 1){
                break;
            }
            i--;
        }
        if(i == -1){
            return "";
        }
        else{
            return num.substr(0, i + 1);
        }
    }
};

int main(){
    Solution s;
    cout << s.largestOddNumber("52") << endl;
    cout << s.largestOddNumber("4206") << endl;
    cout << s.largestOddNumber("35427") << endl;
    return 0;
}