#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res; // mapping charCount to List of Anagrams

        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a'] += 1;
            }
            string key = "";
            for (int i : count) {
                key += to_string(i) + "#";
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& group : res) {
            result.push_back(group.second);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output = solution.groupAnagrams(input);

    // Print the result
    for (const auto& group : output) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << "\"" << word << "\", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
