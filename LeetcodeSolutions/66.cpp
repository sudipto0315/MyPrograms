#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length=digits.size()-1;
        for(int i=length;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }else{
                digits[i]=0;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
int main(){
    Solution s;
    vector<int>digits={1,2,3};
    vector<int>ans=s.plusOne(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    digits={4,3,2,1};
    ans=s.plusOne(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    digits={0};
    ans=s.plusOne(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}