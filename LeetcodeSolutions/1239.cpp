#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<string>&arr,int index,string result){
        unordered_set<char>resultSet(result.begin(),result.end());
        if(result.size()!=resultSet.size()){
            return 0;
        }
        if(index>=arr.size()){
            return result.size();
        }
        int maxVal=result.size();
        maxVal=max(maxVal,findMaxLength(arr,index+1,result+arr[index]));
        maxVal=max(maxVal,findMaxLength(arr,index+1,result));
        return maxVal;
    }
    int maxLength(vector<string>& arr) {
        return findMaxLength(arr,0,"");
    }
};
int main(){
    Solution s;
    vector<string>arr={"un","iq","ue"};
    cout<<s.maxLength(arr)<<endl;
    arr={"cha","r","act","ers"};
    cout<<s.maxLength(arr)<<endl;
    arr={"abcdefghijklmnopqrstuvwxyz"};
    cout<<s.maxLength(arr)<<endl;
    return 0;
}