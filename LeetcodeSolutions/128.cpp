#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int>set;
        for(int i=0;i<n;i++){
            set.insert(nums[i]);
        }
        int count;
        int maxSequence=0;
        for(int i=0;i<n;i++){
            if(set.find(nums[i]-1)==set.end()){
                int currentNumber=nums[i];
                int currentConsecutiveSequence=1;
                while(set.find(currentNumber+1)!=set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                maxSequence=max(maxSequence,currentConsecutiveSequence);
            }
        }
        return maxSequence;
    }
};
int main(){
    Solution s;
    vector<int>nums={100,4,200,1,3,2};
    cout<<s.longestConsecutive(nums)<<endl;
    nums={0,3,7,2,5,8,4,6,0,1};
    cout<<s.longestConsecutive(nums)<<endl;
    return 0;
}