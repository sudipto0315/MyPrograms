#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int ans = 0, i = 0, j = 0;
        int count[256] = {0}; // Assuming ASCII characters //wh

        while (j < n)
        {
            if (count[s[j]] == 0)
            {
                count[s[j]]++;
                j++;
                ans = max(ans, j - i);
            }
            else
            {
                count[s[i]]--;
                i++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Example usage:
    string inputString = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(inputString);

    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}