#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int result = 0;
        unordered_map<char, int> charCount;

        // Count characters in chars
        for (int i = 0; i < chars.length(); i++)
        {
            char ch = chars[i];
            charCount[ch] += 1;
        }

        // Check each word
        for (const string &word : words) //tell what does &word mean? why not just word? // &word is a reference to the word in the vector
        {
            unordered_map<char, int> wordCount;
            bool validWord = true;

            // Count characters in the current word
            for (int i = 0; i < word.length(); i++)
            {
                char ch = word[i];
                wordCount[ch] += 1;
            }

            // Check if the word can be formed from chars
            for (const auto &pair : wordCount)
            {
                if (charCount[pair.first] < pair.second)
                {
                    validWord = false;
                    break;
                }
            }

            // If the word is valid, add its length to the result
            if (validWord)
            {
                result += word.length();
            }
        }
        return result;
    }
};

int main()
{
    // Example usage
    Solution solution;
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    int result = solution.countCharacters(words, chars);

    cout << "Result: " << result << endl;

    return 0;
}
