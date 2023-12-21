#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        deque<int> dq;
        long long ans=0;
        int n=prices.size();
        int i=0;
        while(i<n){
            dq.push_back(prices[i]);
            while(i+1<n && (dq.back()-prices[i+1]==1)){
                dq.push_back(prices[i+1]);
                i++;
            }
            ans += (dq.size()*(dq.size()+1))/2;
            i++;
            dq.clear();
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> prices = {3,2,1,4};
    cout<<s.getDescentPeriods(prices)<<endl;
    prices = {8,6,7,7};
    cout<<s.getDescentPeriods(prices)<<endl;
    prices = {1};
    cout<<s.getDescentPeriods(prices)<<endl;
    return 0;
}