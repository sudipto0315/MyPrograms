#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = smoothen(img, i, j);
            }
        }

        return res;
    }

private:
    int smoothen(const vector<vector<int>>& img, int x, int y) {
        int m = img.size();
        int n = img[0].size();
        int total = 0;
        int count = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    total += img[nx][ny];
                    count++;
                }
            }
        }

        return total / count;
    }
};
int main(){
    Solution s;
    vector<vector<int>>img={{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>>res=s.imageSmoother(img);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    img = {{100,200,100},{200,50,200},{100,200,100}};
    res = s.imageSmoother(img);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}