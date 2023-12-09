#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        for (int i = 0; i < n - m + 1; i++){
            for(int j = 0; j < m; j++){
                if (haystack[i+j] != needle[j]) break;
                if (j == m - 1) return i;  // needle found              
            }
        }
        return -1;
    }
};
int main() {
    Solution solution;
    cout << solution.strStr("sadbutsad", "sad") << endl;
    cout << solution.strStr("leetcode", "leeto") << endl;
    return 0;
}