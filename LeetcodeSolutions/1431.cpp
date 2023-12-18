#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>result (candies.size(),false);
        int max=*max_element(candies.begin(), candies.end());
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=max){
                result[i]=true;
            }
            else{
                result[i]=false;
            }
        }
        return result;
    }
};
int main(){
    vector<int> candies={2,3,5,1,3};
    int extraCandies=3;
    Solution s;
    vector<bool> result=s.kidsWithCandies(candies,extraCandies);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    vector<int> candies1={4,2,1,1,2};
    int extraCandies1=1;
    vector<bool> result1=s.kidsWithCandies(candies1,extraCandies1);
    for(int i=0;i<result1.size();i++){
        cout<<result1[i]<<" ";
    }
    cout<<endl;
    return 0;
}