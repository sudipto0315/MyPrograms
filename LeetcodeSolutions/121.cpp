#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum=prices[0];
        int profit=0;
        int cost=0;
        for(int i=1;i<prices.size();i++){
            cost = prices[i]-minimum;
            profit = max(profit,cost);
            minimum = min(minimum,prices[i]);
        }
        return profit;
    }
};
int main(){
    Solution s;
    vector<int> nums1={7,1,5,3,6,4};
    cout<<s.maxProfit(nums1)<<endl;
    vector<int> nums2={7,6,4,3,1};
    cout<<s.maxProfit(nums2)<<endl;
    return 0;
}