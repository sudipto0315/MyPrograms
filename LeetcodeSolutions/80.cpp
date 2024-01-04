#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0||i==1||nums[count-2]!=nums[i]){
                nums[count]=nums[i];
                count++;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> v={1,1,1,2,2,3};
    cout<<s.removeDuplicates(v)<<endl;
    v={0,0,1,1,1,1,2,3,3};
    cout<<s.removeDuplicates(v)<<endl;
    return 0;
}