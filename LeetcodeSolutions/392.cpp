#include <iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int s_len = s.length(), t_len = t.length();
        while(i < s_len && j < t_len){
            if (s[i] == t[j]){
                i++;
                j++;
            }
            else
                j++;
        }
        if (i < s_len){
            return false;
        }
        else{
            return true;
        }
    }
};

int main() {
    Solution sol;
    cout << sol.isSubsequence("abc", "ahbgdc") << endl;
    cout << sol.isSubsequence("axc", "ahbgdc") << endl;
    return 0;
}