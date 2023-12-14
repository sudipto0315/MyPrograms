#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return n;
        }

        int index = 1; // Index to place the next distinct element

        for (int i = 1; i < n; i++) {
            bool isDuplicate = false;

            // Check for duplicates
            for (int j = 0; j < index; j++) {
                if (nums[i] == nums[j]) {
                    isDuplicate = true;
                    break;
                }
            }

            // If not a duplicate, move it to the correct position
            if (!isDuplicate) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 1, 2};
    cout << s.removeDuplicates(nums1) << endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(nums2) << endl;
    for (int i = 0; i < nums2.size(); i++)
    {
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;
}