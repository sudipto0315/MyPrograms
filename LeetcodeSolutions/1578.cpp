#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0,max_cost=0,sum_cost=0;
        for(int i=0;i<colors.size();i++){
            if(i>0 && colors[i]!=colors[i-1]){
                res+=(sum_cost-max_cost);
                sum_cost=0;
                max_cost=0;
            }
            sum_cost+=neededTime[i];
            max_cost=max(max_cost,neededTime[i]);
        }
        res+=(sum_cost-max_cost);
        return res;
    }
};
int main(){
    Solution s;
    string colors1="abaac";
    vector<int> neededTime1={1,2,3,4,5};
    cout<<s.minCost(colors1,neededTime1)<<endl;
    string colors2="abc";
    vector<int> neededTime2={1,2,3};
    cout<<s.minCost(colors2,neededTime2)<<endl;
    string colors3="aabaa";
    vector<int> neededTime3={1,2,3,4,1};
    cout<<s.minCost(colors3,neededTime3)<<endl;
    return 0;
}