// ques: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int func(int mid,int n,int m){
        long long ans=1;
        for(int i=1;i<=m;i++){
            ans=ans*mid;
        }
        if(ans==n){
            return 1;
        }
        else if(ans<n){
            return 0;
        }
        else{
            return -1;
        }
    }
    int nthRoot(int n,int m){
        int low=1;
        int high=n;
        while (low<=high){
            int mid=(low+high)/2;
            int midN=func(mid,n,m);
            if(midN==1){
                return mid;
            }
            else if(midN==0){
                low=mid+1;
            }
            else{
                high=mid-1;
            }            
        }
        return -1;
    }
};
int main(){
    Solution s;
    cout<<s.nthRoot(27,3)<<endl;
    cout<<s.nthRoot(69,4)<<endl;
    return 0;
}