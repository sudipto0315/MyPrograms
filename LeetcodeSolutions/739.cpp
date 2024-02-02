#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().first<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top().second-i;
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(temperatures);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}