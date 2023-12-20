#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using  namespace std;
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min=INT_MAX;
        int secMin=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<min){
                secMin=min;
                min=prices[i];
            }
            else if(prices[i]<secMin){
                secMin=prices[i];
            }
        }
        
        int leftover=money-(min+secMin);
        if(leftover>=0){
            return leftover;
        }
        else{
            return money;
        }
    }
};
int main(){
    Solution s;
    vector<int> prices={1,2,2};
    cout<<s.buyChoco(prices,3)<<endl; // 0
    prices={3,2,3};
    cout<<s.buyChoco(prices,3)<<endl;// 3
    prices={41,1,28,2,92,97,1,87};
    cout<<s.buyChoco(prices,68)<<endl;// 66
    return 0;
}