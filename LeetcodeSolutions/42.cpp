#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max = max(left_max, height[i]);
            } else {
                sum += (right_max - height[j]);
                j--;
                right_max = max(right_max, height[j]);
            }
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height)<<endl;
    return 0;
}