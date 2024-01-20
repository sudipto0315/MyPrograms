#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=n-1;
        int num=1;
        while(top<=bottom&&left<=right&&num<=n*n){
            for(int i=left;i<=right;i++){
                ans[top][i]=num;
                num++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans[i][right]=num;
                num++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=num;
                    num++;
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=num;
                    num++;
                }
                left++;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>>ans=s.generateMatrix(3);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    ans=s.generateMatrix(1);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}