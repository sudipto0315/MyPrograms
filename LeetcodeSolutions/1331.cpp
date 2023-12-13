#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        int count = 1;
        for (int i = 0; i < sortedArr.size(); i++){
            if (rankMap.find(sortedArr[i]) == rankMap.end()){
                rankMap[sortedArr[i]] = count;
                count++;
            }
        }
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++){
            ans[i] = rankMap[arr[i]];
        }
        return ans;
    }
};
#include <iostream> // Include the necessary header file

int main(){
    Solution s;
    vector<int> arr1 = {40,10,20,30};
    vector<int> arr2 = {100,100,100};
    vector<int> arr3 = {37,12,28,9,100,56,80,5,12};
    vector<int> ans1 = s.arrayRankTransform(arr1);
    vector<int> ans2 = s.arrayRankTransform(arr2);
    vector<int> ans3 = s.arrayRankTransform(arr3);
    for (int i = 0; i < ans1.size(); i++){
        cout << ans1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ans2.size(); i++){
        cout << ans2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ans3.size(); i++){
        cout << ans3[i] << " ";
    }
    cout << endl;
    return 0;
}