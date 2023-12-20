#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; start++) {
            if (s[start] != ' ') {
                // Fill a gap with the next word
                if (idx != 0) s[idx++] = ' ';

                // Go to the end of the word
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // Reverse the word
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // Move to the next word
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end()); // trim the string
        return s;
    }
};

int main() {
    Solution obj;
    cout << obj.reverseWords("the sky is blue") << endl;
    cout << obj.reverseWords("  hello world!  ") << endl;
    cout << obj.reverseWords("a good   example") << endl;
    cout << obj.reverseWords("  Bob    Loves  Alice   ") << endl;
    cout << obj.reverseWords("Alice does not even like bob") << endl;
    return 0;
}