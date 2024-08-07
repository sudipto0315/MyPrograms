#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.size(), tn= t.size();
        int left = 0, right;
        int mp[64]={0}, tmp[64]={0};
        
        // Count the characters in string t
        for (char c : t){
            int idx=0x3f &c;
            tmp[idx]++;
        }
        
        int count = 0; // Counter for matching characters
        
        int minLength = INT_MAX; // Length of the minimum window
        int minLeft = 0; // Start index of the minimum window
        
        for (right = 0; right < n; right++) {
            char c = s[right];
            int idx= 0x3f & c;
            // Skip characters not present in string t
            if (tmp[idx] == 0) continue;
            
            // Increment the count of matching characters
            mp[idx]++;
            
            // Check if the current character count matches the required count
            if (mp[idx] <= tmp[idx]) count++;
            
            // If all characters of t are found in the current window
            if (count == tn) {
                // Try to minimize the window by moving the left pointer
                while (tmp[0x3f& s[left]]==0|| mp[0x3f& s[left]]>tmp[0x3f& s[left]]) {
                    if (mp[0x3f&s[left]]!=0) mp[0x3f&s[left]]--;
                    left++;
                }
                
                // Update the minimum window if necessary
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
            }
        }
        
        // If no valid window found, return an empty string
        if (minLength == INT_MAX) return "";
        
        // Return the minimum window substring
        return s.substr(minLeft, minLength);
    }
};
int main(){
    Solution s;
    cout<<s.minWindow("ADOBECODEBANC","ABC")<<endl;
    cout<<s.minWindow("a","a")<<endl;
    cout<<s.minWindow("a","aa")<<endl;
    return 0;
}