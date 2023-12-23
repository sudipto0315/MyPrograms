#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int pos = 0;
        int score = 0;
        while (s.length() != 0 && pos < s.length() - 1){
            string s1 = s.substr(0, pos + 1);
            string s2 = s.substr(pos + 1, s.length() - pos - 1);
            int leftZeros = count(s1.begin(), s1.end(), '0');
            int rightOnes = count(s2.begin(), s2.end(), '1');
            score = max(score, leftZeros + rightOnes);
            pos++;
        }
        return score;
    }
};
int main(){
    Solution s;
    cout << s.maxScore("011101") << endl;
    cout << s.maxScore("00111") << endl;
    cout << s.maxScore("1111") << endl;
    cout << s.maxScore("00") << endl;
    return 0;
}