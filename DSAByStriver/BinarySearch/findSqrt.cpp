// ques: https://takeuforward.org/binary-search/finding-sqrt-of-a-number-using-binary-search/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int floorSqrt(int n){
        int low=1;
        int high=n;
        while (low<=high){
            long long mid=(low+high)/2;
            if(mid*mid==n){
                return mid;
            }
            else if(mid*mid<n){
                low=mid+1;
            }
            else{
                high=mid-1;
            }            
        }
        return high;
    }
};
int main(){
    Solution s;
    cout<<s.floorSqrt(36)<<endl;
    cout<<s.floorSqrt(262144)<<endl;
    cout<<s.floorSqrt(28)<<endl;
    return 0;
}