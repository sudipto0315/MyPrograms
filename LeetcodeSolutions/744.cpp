#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        int diff=INT_MAX;
        for(int i=0;i<letters.size();i++){
            int currDiff=(letters[i]-'a')-(target-'a');
            if(letters[i]>target && currDiff<diff){
                diff=currDiff;
                ans=letters[i];
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<char> v={'c','f','j'};
    cout<<s.nextGreatestLetter(v,'a')<<endl;
    v={'c','f','j'};
    cout<<s.nextGreatestLetter(v,'c')<<endl;
    v={'x','x','y','y'};
    cout<<s.nextGreatestLetter(v,'z')<<endl;
    return 0;
}