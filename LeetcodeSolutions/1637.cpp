#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=0;
        int n=points.size();
        for(int i=1;i<n;i++){
            ans=max(ans,points[i][0]-points[i-1][0]);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> points={{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    cout<<s.maxWidthOfVerticalArea(points)<<endl;
    points={{8,7},{9,9},{7,4},{9,7}};
    cout<<s.maxWidthOfVerticalArea(points)<<endl;
    return 0;
}