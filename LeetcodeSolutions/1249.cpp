#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int openingBracket = 0;
        int closingBracket = 0;
        stack<char> stack;

        // Pass 1
        for (char ch : s)
        {
            if (ch == '(')
            {
                openingBracket++;
            }
            else if (ch == ')')
            {
                closingBracket++;
            }
            if (closingBracket > openingBracket)
            {
                closingBracket--;
                continue;
            }
            else
            {
                stack.push(ch);
            }
        }

        string result = "";

        // Pass 2
        while (!stack.empty())
        {
            char currentChar = stack.top();
            stack.pop();
            if (openingBracket > closingBracket && currentChar == '(')
            {
                openingBracket--;
            }
            else
            {
                result += currentChar;
            }
        }

        // Reverse the result string
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    Solution s;
    cout << s.minRemoveToMakeValid("lee(t(c)ode") << endl;
    // cout << s.minRemoveToMakeValid("a)b(c)d") << endl;

    return 0;
}