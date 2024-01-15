#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int>lostMatches;
        for(int i=0;i<n;i++){
            lostMatches[matches[i][1]]++;
        }
        vector<vector<int>>ans(2,vector<int>());
        for(int i=0;i<n;i++){
            if(lostMatches.find(matches[i][0])==lostMatches.end()&&lostMatches[matches[i][0]]==0){
                ans[0].push_back(matches[i][0]);
            }
            if(lostMatches[matches[i][1]]==1){
                ans[1].push_back(matches[i][1]);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>>matches;
    matches={{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>>ans=s.findWinners(matches);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    matches={{2,3},{1,3},{5,4},{6,4}};
    ans=s.findWinners(matches);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}