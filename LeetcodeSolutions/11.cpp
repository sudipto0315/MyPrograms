#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxArea=0;
        while(l<r){
            int currentArea=min(height[l],height[r])*(r-l);
            maxArea=max(maxArea,currentArea);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};
int main(){
    Solution s;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height)<<endl;
    height={1,1};
    cout<<s.maxArea(height)<<endl;
    return 0;
}