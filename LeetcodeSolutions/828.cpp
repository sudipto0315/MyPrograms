#include <iostream>
using namespace std;
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && s[l] != s[i]) l--;
            while (r < n && s[r] != s[i]) r++;
            ans += (i - l) * (r - i);
        }
        return ans;        
    }
};
int main() {
    Solution sol;
    cout << sol.uniqueLetterString("ABC") << endl;
    cout << sol.uniqueLetterString("ABA") << endl;
    cout << sol.uniqueLetterString("LEETCODE") << endl;
    return 0;
}