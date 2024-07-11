#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int start = arr[0][0];
        int end = arr[0][1];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= end) {
                end = max(end, arr[i][1]);
            } else {
                ans.push_back({start, end});
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }

};
int main()
{
    Solution s;
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = s.mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}