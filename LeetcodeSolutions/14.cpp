#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        string result ="";
        sort(strs.begin(), strs.end()); //sorting in lexicographical order
        string firstStr = strs[0];
        string lastStr = strs[strs.size()-1];
        for (int i = 0; i < firstStr.size(); i++)
        {
            if (firstStr[i] == lastStr[i])
            {
                result += firstStr[i];
            }
            else
            {
                break;
            }
        }
        return result;       
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}