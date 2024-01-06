#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
    int dp[50001];
    int findMaxProfit(vector<vector<int>>&jobs,vector<int>&start,int n,int id){
        if(id==n){
            return 0;
        }
        if(dp[id]!=-1){
            return dp[id];
        }
        int nextIndex=lower_bound(start.begin(),start.end(),jobs[id][1])-start.begin();
        int maxProfit=max(findMaxProfit(jobs,start,n,id+1),jobs[id][2]+findMaxProfit(jobs,start,n,nextIndex));
        return dp[id]=maxProfit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<profit.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        for(int i=0;i<profit.size();i++){
            startTime[i]=jobs[i][0];
        }
        return findMaxProfit(jobs,startTime,profit.size(),0);
    }
};
int main(){
    Solution s;
    vector<int>startTime={1,2,3,3};
    vector<int>endTime={3,4,5,6};
    vector<int>profit={50,10,40,70};
    cout<<s.jobScheduling(startTime,endTime,profit)<<endl;
    startTime={1,2,3,4,6};
    endTime={3,5,10,6,9};
    profit={20,20,100,70,60};
    cout<<s.jobScheduling(startTime,endTime,profit)<<endl;
    startTime={1,1,1};
    endTime={2,3,4};
    profit={5,6,4};
    cout<<s.jobScheduling(startTime,endTime,profit)<<endl;
    return 0;
}