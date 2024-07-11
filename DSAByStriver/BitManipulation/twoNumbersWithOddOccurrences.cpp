#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution{
    public:
    // vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    //     unordered_map<long long int,long long int> mpp;
    //     for(long long int i=0;i<N;i++){
    //         mpp[Arr[i]]++;
    //     }
    //     vector<long long int> res;
    //     for(auto it:mpp){
    //         if(it.second%2!=0){
    //             res.push_back(it.first);
    //         }
    //     }   
    //     sort(res.rbegin(), res.rend()); // Sort in descending order
    //     return res;
    // }
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long xorSum=0;
        for(int i=0;i<N;i++){
            xorSum^=Arr[i];
        }
        cout<<xorSum<<endl;
        // Finding the rightmost set bit
        long long setBitNo=xorSum & ~(xorSum - 1);
        cout<<setBitNo<<endl;
        long long x=0;
        long long y=0;
        for(int i=0;i<N;i++) {
            if(Arr[i] & setBitNo) {
                x ^= Arr[i];
            }else{
                y ^= Arr[i];
            }
        }
        if (x<y){
            swap(x, y);
        }
        return{x,y};
    }
};
int main(){
    Solution s;
    long long int Arr[]={1,7,5,7,5,4,7,4};
    // long long int Arr[]={4,2,4,5,2,3,3,1};
    long long int N=sizeof(Arr)/sizeof(Arr[0]);
    vector<long long int> res=s.twoOddNum(Arr,N);
    for(long long int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}