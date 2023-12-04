#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string maxGood = "";

        for (int i = 0; i < num.length() - 2; ++i) {
            string currentSubstr = num.substr(i, 3); // Get the current substring of length 3

            // Check if the substring is a good integer
            if (currentSubstr[0] == currentSubstr[1] && currentSubstr[1] == currentSubstr[2]) {
                // Update the maximum good integer
                maxGood = max(maxGood, currentSubstr);
            }
        }

        return maxGood;
    }
};

int main() {
    // Example usage:
    Solution solution;

    string num1 = "6777133339";
    cout << solution.largestGoodInteger(num1) << endl;  // Output: "777"

    string num2 = "2300019";
    cout << solution.largestGoodInteger(num2) << endl;  // Output: "000"

    string num3 = "42352338";
    cout << solution.largestGoodInteger(num3) << endl;  // Output: ""

    return 0;
}
